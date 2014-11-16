
#include <neb/core/core/actor/rigidbody/desc.hpp>

#include <neb/core/app/__core.hpp>

typedef neb::core::app::__core THIS;

std::weak_ptr<nc::app::__core>	THIS::global()
{
	auto app(dynamic_pointer_cast<THIS>(g_app_));
	assert(app);
	return app;
}
void				THIS::__init()
{
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
	neb::util::parent<neb::core::core::scene::base, neb::core::core::scene::util::parent>::clear();
}
void				THIS::__step(gal::etc::timestep const & ts)
{
	neb::core::core::scene::util::parent::step(ts);
	neb::game::game::util::parent::step(ts);
}
neb::core::pose			THIS::getPose() const {
	return neb::core::pose();
}
neb::core::pose			THIS::getPoseGlobal() const {
	return neb::core::pose();
}
std::shared_ptr<neb::game::game::base>		THIS::createGame(
		neb::game::game::desc const & desc
		)
{
	typedef neb::game::game::base T;
	
	std::shared_ptr<T> g(new T(), gal::stl::deleter<T>());

	neb::game::game::util::parent::insert(g);
	
	g->init(this);
	
	return g;
}


