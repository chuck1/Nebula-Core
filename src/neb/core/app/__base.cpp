#include <thread>
#include <fstream>

#include <gal/log/log.hpp>
#include <gal/dll/helper_info.hpp>

#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/util/config.hpp>
#include <neb/fnd/core/actor/rigidbody/desc.hpp>
#include <neb/fnd/net/core/scene/Base.hpp>

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



typedef neb::fnd::app::Base THIS;

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
THIS::~Base()
{
	printv_func(DEBUG);
}
void			THIS::__init()
{
	printv_func(DEBUG);

	assert(!flag_.any(neb::fnd::app::util::flag::INIT___BASE));

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

	// console
	console_.reset(new console_type);
	console_->init();
	flag_.set(neb::fnd::app::util::flag::INIT___BASE);

	/** @todo export class to python to implement exit() */

	// module search path
	//gal::dll::helper_info::search_path_ = NEB_MOD_DIR;


	/*
	 * register some types for serialization
	 */
	typedef neb::fnd::core::actor::desc T;
	typedef neb::fnd::core::actor::rigidbody::desc D;

	gal::itf::shared::register_type(std::type_index(typeid(T)));
	gal::itf::shared::register_type(std::type_index(typeid(D)));

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


	// plugins
	open_graphics_plugin("../plugin/gfx1/build/dynamic/libnebula_plugin_gfx1.so");
}
void						THIS::__release()
{
	printv_func(DEBUG);

	typedef neb::fnd::core::scene::base S;
	typedef neb::fnd::core::scene::util::parent P;


	neb::fnd::core::scene::util::parent::clear();
	neb::fnd::game::game::util::parent::clear();
	neb::fnd::window::util::Parent::clear();
	neb::fnd::timer::util::Parent::clear();
	neb::fnd::gui::layout::util::Parent::clear();


	//neb::fnd::util::parent<S, P>::clear();
}
void						THIS::__step(gal::etc::timestep const & ts)
{
	printv_func(DEBUG);
	neb::fnd::core::scene::util::parent::step(ts);
	neb::fnd::game::game::util::parent::step(ts);
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

	std::shared_ptr<T> g(new T(), gal::stl::deleter<T>());

	neb::fnd::game::game::util::parent::insert(g);

	g->init(this);

	return g;
}
void							THIS::open_graphics_plugin(std::string filename)
{
	printv_func(DEBUG);

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
void							THIS::open_network_plugin(std::string filename)
{
	printv_func(DEBUG);

	typedef neb::fnd::net::core::scene::Base S;

	_M_network_plugin.reset(new H(filename));

	_M_network_plugin->open();

	// the integer argument will indicate local or remote
	_M_network_plugin->template add<S, int>("scene");

}
void			THIS::render()
{
	printv_func(DEBUG);

	neb::fnd::window::util::Parent::render();
}

