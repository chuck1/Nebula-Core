#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <fstream>
#include <fstream>
#include <algorithm>
#include <map>

//#include <ft2build.h>
//#include FT_FREETYPE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/log/log.hpp>
#include <gal/dll/helper_info.hpp>
#include <gal/dll/helper.hpp>
#include <gal/console/base.hpp>
#include <gal/etc/stopwatch.hpp>
#include <gal/stl/deleter.hpp>
#include <gal/argparse/Parser.hpp>

#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/util/config.hpp> // neb/fnd/util/config.hpp.in

#include <neb/fnd/plug/gfx/app/Base.hpp>
#include <neb/fnd/plug/gfx/core/scene/Base.hpp>
#include <neb/fnd/plug/gfx/core/actor/Base.hpp>
#include <neb/fnd/plug/gfx/core/shape/Base.hpp>
#include <neb/fnd/plug/gfx/core/light/Base.hpp>
#include <neb/fnd/plug/gfx/window/Base.hpp>
#include <neb/fnd/plug/gfx/context/Base.hpp>
#include <neb/fnd/plug/gfx/environ/Base.hpp>
#include <neb/fnd/plug/gfx/camera/proj/Base.hpp>
#include <neb/fnd/plug/gfx/camera/view/Base.hpp>

#include <neb/fnd/plug/phx/app/Base.hpp>
#include <neb/fnd/plug/phx/core/scene/Base.hpp>
#include <neb/fnd/plug/phx/core/actor/Base.hpp>
#include <neb/fnd/plug/phx/core/shape/Base.hpp>
#include <neb/fnd/plug/gfx/app/Base.hpp>

#include <neb/fnd/free.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/window/Base.hpp>

#include <neb/fnd/game/weapon/util/decl.hpp>
#include <neb/fnd/game/map/base.hpp>

#include <neb/fnd/gui/layout/util/Parent.hpp>
#include <neb/fnd/gui/object/Terminal.hpp>

#include <neb/fnd/net/core/scene/Base.hpp>

#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/core/actor/rigiddynamic/Base.hpp>
#include <neb/fnd/core/actor/rigidstatic/base.hpp>
#include <neb/fnd/core/actor/rigidbody/desc.hpp>

#include <neb/fnd/core/shape/Cuboid.hpp>
#include <neb/fnd/core/shape/HeightField.hpp>

#include <neb/fnd/core/light/Point.hpp>

#define STRINGIZE2(x) #x
#define STRINGIZE(x) STRINGIZE2(x)




#include <neb/fnd/app/Base.hpp>

typedef neb::fnd::app::Base THIS;

THIS::Base()
{
}
THIS::~Base()
{
	printv_func(DEBUG);
}
void			THIS::init_boost_asio()
{
	// boost asio ioservice
	printv(DEBUG, "launch ios thread\n");

	auto l = [&] ()
	{
		boost::asio::io_service::work w(ios_);
		ios_.run();
		printv(DEBUG, "ios stopped\n");
	};

	std::thread t(l);
	t.detach();
}
void			THIS::init_register_types()
{
	/*
	 * register some types for serialization
	 */
	typedef neb::fnd::core::actor::desc T;
	typedef neb::fnd::core::actor::rigidbody::desc D;

	register_type(std::type_index(typeid(T)));
	register_type(std::type_index(typeid(D)));

	{
		std::function< std::shared_ptr<T>() > f(
				[]() { return std::shared_ptr<T>(new T()); }
				);

		gal::stl::factory<T>::default_factory_->add<T>(f);
	}
	{
		std::function< std::shared_ptr<T>() > f(
				[]() { return std::shared_ptr<D>(new D()); }
				);

		gal::stl::factory<T>::default_factory_->add<D>(f);
	}
}
void			THIS::init_python()
{
	char buffer[256];
	strcpy(buffer, "import sys\nsys.path.append(\"");
	strcat(buffer, NEB_SRC_DIR);
	strcat(buffer, "/components/python/build/dynamic");
	strcat(buffer, "\")");

	printf("%s\n", buffer);

	//auto app = global();
	
	auto me = std::dynamic_pointer_cast<THIS>(shared_from_this());

	//neb::p::app::Base py_app(me);

	try {
		console_->eval(buffer);
		console_->main_namespace_["neb"] = boost::python::import("libnebula_python");
		//console_->main_namespace_["app"] = py_app;
	} catch(bp::error_already_set const &) {
		printf("unhandled python execption\n");
		printf("%s\n", "libnebula_python.a");
		// print all other errors to stderr
		PyErr_Print();

		printf("lines: %lu\n", console_->lines_.size());

		abort();
	}
}
void			THIS::init(int ac, char ** av)
{
	printv_func(DEBUG);


	// parse args	
	gal::argparse::Parser parser;
	_M_args = parser.parse(ac, av, "");
	
	if(_M_args.has_long("python")) {
		auto filename = _M_args.get_value_from_long(
				"python");

		_M_preloop_scripts_python.push_back(
				filename);

		printv(DEBUG, "%s\n", filename.c_str());
	}
	
	if(_M_args.has_long("graphics")) {
		flag_.set(FLAG::PLUGIN_GRAPHICS);
	}
	
	
	assert(!flag_.any(neb::fnd::app::util::flag::INIT___BASE));

	// init containers
	neb::fnd::game::game::util::parent::init(0);
	neb::fnd::window::util::Parent::init(0);
	neb::fnd::timer::util::Parent::init(0);
	neb::fnd::gui::layout::util::Parent::init(0);


	init_boost_asio();

	// console
	console_.reset(new console_type);
	console_->init();

	flag_.set(neb::fnd::app::util::flag::INIT___BASE);

	/** @todo export class to python to implement exit() */

	init_register_types();

	// plugins
	open_graphics_plugin("../plugin/gfx1/build/dynamic/libnebula_plugin_gfx1.so");
	open_physics_plugin( "../plugin/phx1/build/dynamic/libnebula_plugin_phx1.so");
	open_network_plugin( "../plugin/net1/build/dynamic/libnebula_plugin_net1.so");

	init_python();

	read_config();	

	initRegistry();
}

std::shared_ptr<THIS>		THIS::g_app_;
/*
std::shared_ptr<THIS>		THIS::global()
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;
	LOG(lg, neb::fnd::sl, debug) << "&g_app_  = " << &g_app_;
	LOG(lg, neb::fnd::sl, debug) << "g_app_   = " << g_app_.get();

	assert(g_app_);
	return g_app_;
}
*/
bool			THIS::is_valid()
{
	return (bool)g_app_;
}
void						THIS::release()
{
	printv_func(DEBUG);

	//typedef neb::fnd::core::scene::base S;
	//typedef neb::fnd::core::scene::util::parent P;


	neb::fnd::game::game::util::parent::clear();
	neb::fnd::window::util::Parent::clear();
	neb::fnd::timer::util::Parent::clear();
	neb::fnd::gui::layout::util::Parent::clear();

	G::reset();
	P::reset();

}
gal::math::pose				THIS::getPose() const
{
	return gal::math::pose();
}
gal::math::pose				THIS::getPoseGlobal() const
{
	return gal::math::pose();
}
std::weak_ptr<neb::fnd::game::game::base>		THIS::createGame()
{
	printv_func(DEBUG);

	typedef neb::fnd::game::game::base T;

	std::shared_ptr<T> g(new T(), gal::stl::deleter<T>());

	neb::fnd::game::game::util::parent::insert(g);

	g->init(this);

	return g;
}
std::weak_ptr<neb::fnd::game::game::base>		THIS::createGame(
		neb::fnd::game::game::desc const & desc)
{
	printv_func(DEBUG);

	typedef neb::fnd::game::game::base T;
	
	T* t = new T();
	std::shared_ptr<T> g(t, gal::stl::deleter<T>());
	
	g->_M_desc = desc;

	neb::fnd::game::game::util::parent::insert(g);

	g->init(this);

	return g;
}
void				THIS::open_graphics_plugin(std::string filename)
{
	printv_func(DEBUG);

	if(!flag_.any(FLAG::PLUGIN_GRAPHICS)) return;

	typedef neb::fnd::plug::gfx::app::Base APP;
	typedef neb::fnd::plug::gfx::core::scene::Base SC;
	typedef neb::fnd::plug::gfx::core::actor::Base AC;
	typedef neb::fnd::plug::gfx::core::shape::Base SH;
	typedef neb::fnd::plug::gfx::core::light::Base LI;

	typedef neb::fnd::plug::gfx::window::Base W;
	typedef neb::fnd::plug::gfx::context::Base C;
	typedef neb::fnd::plug::gfx::environ::Base E;

	typedef neb::fnd::plug::gfx::camera::proj::Base CP;
	typedef neb::fnd::plug::gfx::camera::view::Base CV;

	_M_graphics_plugin.reset(new H(filename));

	_M_graphics_plugin->open();

	_M_graphics_plugin->template add<APP, int>("app");
	_M_graphics_plugin->template add<SC,  int>("scene");
	_M_graphics_plugin->template add<AC,  int>("actor");
	_M_graphics_plugin->template add<SH,  int>("shape");
	_M_graphics_plugin->template add<LI,  int>("light");

	_M_graphics_plugin->template add<W,   int>("window");
	_M_graphics_plugin->template add<C,   int>("context");
	_M_graphics_plugin->template add<E,   int>("environ");

	_M_graphics_plugin->template add<CP,  int>("camera_proj");
	_M_graphics_plugin->template add<CV,  int>("camera_view");

	G::make_object<THIS, int>(_M_graphics_plugin, 0);
}
void				THIS::open_physics_plugin(std::string filename)
{
	printv_func(DEBUG);
	printv_func(INFO);

	typedef neb::fnd::plug::phx::app::Base APP;
	typedef neb::fnd::plug::phx::core::scene::Base SC;
	typedef neb::fnd::plug::phx::core::actor::Base AC;
	typedef neb::fnd::plug::phx::core::shape::Base SH;

	_M_physics_plugin.reset(new H(filename));

	_M_physics_plugin->open();

	_M_physics_plugin->template add<APP, int>("app");
	_M_physics_plugin->template add<SC,  int>("scene");
	_M_physics_plugin->template add<AC,  int>("actor");
	_M_physics_plugin->template add<SH,  int>("shape");

	P::make_object<THIS, int>(_M_physics_plugin, 0);
}
void				THIS::open_network_plugin(std::string filename)
{
	printv_func(DEBUG);
	printv_func(INFO);

	typedef neb::fnd::net::core::scene::Base S;

	_M_network_plugin.reset(new H(filename));

	_M_network_plugin->open();

	// the integer argument will indicate local or remote
	//_M_network_plugin->template add<S, int>("scene");

}
std::shared_ptr<THIS::H>				THIS::get_graphics_plugin()
{
	assert(_M_graphics_plugin);
	return _M_graphics_plugin;
}
std::shared_ptr<THIS::H>				THIS::get_physics_plugin()
{
	assert(_M_physics_plugin);
	return _M_physics_plugin;
}
std::shared_ptr<THIS::H>				THIS::get_network_plugin()
{
	assert(_M_network_plugin);
	return _M_network_plugin;
}
void			THIS::render()
{
	printv_func(DEBUG);

	neb::fnd::window::util::Parent::render();
}








std::shared_ptr<neb::fnd::app::Base>		THIS::global()
{
	printv_func(DEBUG);

	assert(g_app_);
	return g_app_;
}
std::shared_ptr<THIS>		THIS::s_init(int ac, char ** av)
{
	printv_func(DEBUG);

	std::shared_ptr<THIS> app(new THIS(), gal::stl::deleter<THIS>());

	// continue init
	app->neb::fnd::app::Base::init(ac, av);
	
	
	//printv(DEBUG, "&g_app_ = %p\n", &g_app_);
	
	g_app_ = app;

	return app;
}
void				THIS::read_config()
{
	printv_func(DEBUG);

	assert(console_);

	boost::python::object o;

	// python
	try {
		console_->eval("execfile(\"../share/config.py\")");
		o = console_->main_namespace_["log"];
	} catch(bp::error_already_set const &) {
		printf("unhandled python execption\n");
		printf("%s\n", STRINGIZE(PY_LIB_NAME));
		// print all other errors to stderr
		PyErr_Print();
		printf("lines: %lu\n", console_->lines_.size());
		console_->print();
		abort();
	}

	// log levels

	struct Pair
	{
		char const *		c;
		int * const		sl;
	};

	// fnd
	typedef gal::tmp::VerbosityRegister VR;

	VR::reg<neb::fnd::input::sink>(				"neb fnd input sink");

	VR::reg<neb::fnd::game::weapon::SimpleProjectile>(	"neb core game weapon simple projectile");

	VR::reg<neb::fnd::core::scene::base>(			"neb fnd core scene base");
	VR::reg<neb::fnd::core::actor::base>(			"neb fnd core actor base");
	VR::reg<neb::fnd::core::shape::base>(			"neb fnd core shape base");
	VR::reg<neb::fnd::core::light::base>(			"neb fnd core light base");

	VR::reg<neb::fnd::game::map::Base>(			"neb fnd game map base");
	VR::reg<neb::fnd::game::game::base>(			"neb fnd game game base");
	VR::reg<neb::fnd::game::spawn::base>(			"neb fnd game spawn base");
	VR::reg<neb::fnd::game::spawn::util::parent>(		"neb fnd game spawn util parent");

	VR::reg<neb::fnd::window::Base>(			"neb fnd window base");
	VR::reg<neb::fnd::context::Base>(			"neb fnd context base");
	VR::reg<neb::fnd::environ::Base>(			"neb fnd environ base");
	
	VR::reg<neb::fnd::gui::layout::Base>(			"neb fnd gui layout base");
	VR::reg<neb::fnd::gui::object::Base>(			"neb fnd gui object base");
	VR::reg<neb::fnd::gui::object::Terminal>(		"neb fnd gui object terminal");

	VR::reg<neb::fnd::core::actor::control::rigidbody::base>("neb fnd core actor control rigidbody base");
	// phx


/*		{"neb gfx",					(int*)&neb::gfx::sl},
		{"neb gfx actor",				(int*)&neb::gfx::core::actor::sl},
		{"neb gfx shape",				(int*)&neb::gfx::core::shape::sl},
		{"neb gfx light",				(int*)&neb::gfx::core::light::sl},
		{"neb gfx core light base",			&gal::tmp::Verbosity<neb::gfx::core::light::base>::_M_severity_level},
		{"neb phx",					(int*)&neb::phx::sl},
		{"neb phx scene",				(int*)&neb::phx::core::scene::sl},
		{"neb phx actor",				(int*)&neb::phx::core::actor::sl},
		{"neb phx actor control rigidbody base",	&gal::tmp::Verbosity<neb::phx::core::actor::control::rigidbody::base>::_M_severity_level},
		{"neb phx shape",				(int*)&neb::phx::core::shape::sl}
	};
	*/

	std::map<std::string, int> map_val({
			{"debug",	DEBUG},
			{"info",	INFO},
			{"warning",	WARNING},
			{"error",	ERROR},
			{"critical",	CRITICAL}});


	boost::python::extract<boost::python::dict> e(o);
	assert(e.check());
	boost::python::dict py_dict = e;

	boost::python::list keys = py_dict.keys();

	std::map<std::string, std::string> m;

	console_->print();

	printf("log %lu\n", len(keys));
	for (int i = 0; i < len(keys); ++i) {
		boost::python::extract<std::string> extracted_key(keys[i]);  
		if(!extracted_key.check()){  
			printv(WARNING, "Key invalid, map might be incomplete\n");
			abort();
			continue;
		}
		std::string key = extracted_key;  
		
		printf("%s\n", key.c_str());

		boost::python::extract<std::string> extracted_val(py_dict[key]);  
		if(!extracted_val.check()){  
			printv(WARNING, "Value invalid, map might be incomplete\n");  
			abort();
			continue;                 
		}
		std::string value = extracted_val;  
		m[key] = value;  
	}

	for(auto p : m) {
		auto var = p.first;
		auto val = p.second;

		auto it_val = map_val.find(val);
		if(it_val == map_val.end()) {
			printv(CRITICAL, "Value invalid, map might be incomplete\n");  
			abort();
		}

		int level = it_val->second;

		gal::tmp::VerbosityRegister::set(var, level);
	}
}
void				THIS::initRegistry()
{
	//makeDLLFunc<neb::fnd::core::scene::base, neb::fnd::core::scene::base, neb::fin::core::scene::base>("scene");

	makeDefaultFunc<neb::fnd::core::actor::base,	neb::fnd::core::actor::rigiddynamic::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base,	neb::fnd::core::actor::rigiddynamic::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base,	neb::fnd::core::actor::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base,	neb::fnd::core::actor::rigidstatic::base>();

	makeDefaultFunc<neb::fnd::core::shape::base,	neb::fnd::core::shape::base>();
	makeDefaultFunc<neb::fnd::core::shape::base,	neb::fnd::core::shape::Cuboid>();
	makeDefaultFunc<neb::fnd::core::shape::base,	neb::fnd::core::shape::HeightField::Base>();

	/*	makeDefaultFunc<neb::fnd::core::light::__base, neb::gfx::core::light::spot>();
		makeDefaultFunc<neb::fnd::core::light::__base, neb::gfx::core::light::point>();
		*/
}
void				THIS::preloop()
{
	neb::fnd::gui::layout::util::Parent::preloop();
}
void				THIS::loop()
{
	//auto self(std::dynamic_pointer_cast<neb::fnd::app::Base>(shared_from_this()));
	//assert(self);

	auto g = G::get_object();

	preloop();

	while(!flag_.any(neb::fnd::app::util::flag::E::SHOULD_RELEASE)) {

		// check for exit condition

		if(!neb::fnd::window::util::Parent::front()) break;

		// update

		if(G::has_object())
			G::get_object()->update();
		

		// integrate

		//ts_.step(glfwGetTime());
		ts_.step(g->get_time());

		step(ts_);

		// render

		render();
	}
}
void							THIS::step(gal::etc::timestep const & ts)
{
	printv_func(DEBUG);
	neb::fnd::game::game::util::parent::step(ts);
	neb::fnd::window::util::Parent::step(ts);
	neb::fnd::gui::layout::util::Parent::step(ts);
}
void							THIS::set_should_release()
{
}
std::weak_ptr<neb::fnd::gui::layout::Base>	THIS::createLayout(
		std::shared_ptr<neb::fnd::window::Base> window,
		std::shared_ptr<neb::fnd::environ::Base> environ)
{
	printv_func(DEBUG);

	typedef neb::fnd::gui::layout::Base T;
	
	auto layout = neb::fnd::gui::layout::util::Parent::create<T>().lock();
	
	layout->connect(window);
	
	layout->createObjectTerminal();
	
	environ->set_drawable(layout);
	
	return layout;
}
std::weak_ptr<neb::fnd::window::Base>	THIS::createWindow()
{
	printv_func(DEBUG);

	auto window = neb::fnd::window::util::Parent::create<neb::fnd::window::Base>();

	if(G::has_object())
		G::get_object()->onFirstContext();

	return window;
}




