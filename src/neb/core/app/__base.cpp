#include <thread>
#include <fstream>

#include <gal/log/log.hpp>
#include <gal/dll/helper_info.hpp>

#include <neb/core/util/debug.hpp>
#include <neb/core/app/__base.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/core/actor/rigidbody/desc.hpp>

#include <neb/core/app/__core.hpp>

typedef neb::core::app::base THIS;

std::shared_ptr<THIS>		THIS::g_app_;

std::shared_ptr<THIS>		THIS::global()
{
	assert(g_app_);
	return g_app_;
}

bool			THIS::is_valid()
{
	return (bool)g_app_;
}

THIS::~base()
{
	LOG(lg, neb::core::sl, info) << __FUNCSIG__;
}

void			THIS::__init()
{

	LOG(lg, neb::core::sl, debug) << __FUNCSIG__;
	
	assert(!flag_.any(neb::core::app::util::flag::INIT___BASE));

	// boost asio ioservice
	LOG(lg, neb::core::sl, debug) << "launch ios thread";

	std::thread t([&](){
			boost::asio::io_service::work w(ios_);
			ios_.run();

			LOG(lg, neb::core::sl, debug) << "ios stopped";
			});
	t.detach();

	// console
	console_.reset(new console_type);
	console_->init();
	flag_.set(neb::core::app::util::flag::INIT___BASE);

	/** @todo export class to python to implement exit() */

	// module search path
	gal::dll::helper_info::search_path_ = NEB_MOD_DIR;


	/*
	 * register some types for serialization
	 */
	typedef neb::core::core::actor::desc T;
	typedef neb::core::core::actor::rigidbody::desc D;

	gal::itf::shared::register_type(std::type_index(typeid(T)));
	gal::itf::shared::register_type(std::type_index(typeid(D)));

	{
		std::function< std::shared_ptr<T>() > f(
				[]() { return std::shared_ptr<T>(new T()); }
				);

		gal::stl::factory<T>::default_factory_->add(typeid(T).hash_code(), f);
	}
	{
		std::function< std::shared_ptr<T>() > f(
				[]() { return std::shared_ptr<D>(new D()); }
				);

		gal::stl::factory<T>::default_factory_->add(typeid(D).hash_code(), f);
	}

}



void				THIS::__release()
{
	nc::util::parent<neb::core::core::scene::base, neb::core::core::scene::util::parent>::clear();
}
void				THIS::__step(gal::etc::timestep const & ts)
{
	nc::core::scene::util::parent::step(ts);
	nc::game::game::util::parent::step(ts);
}
neb::core::math::pose				THIS::getPose() const
{
	return neb::core::math::pose();
}
neb::core::math::pose				THIS::getPoseGlobal() const
{
	return neb::core::math::pose();
}
std::shared_ptr<nc::game::game::base>		THIS::createGame(
		nc::game::game::desc const & desc
		)
{
	typedef nc::game::game::base T;
	
	std::shared_ptr<T> g(new T(), gal::stl::deleter<T>());

	nc::game::game::util::parent::insert(g);
	
	g->init(this);
	
	return g;
}








