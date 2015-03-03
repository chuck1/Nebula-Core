
#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/plug/gfx/core/shape/Base.hpp>

#include <neb/fnd/plug/phx/core/actor/Base.hpp>

#include <neb/fnd/core/shape/Cuboid.hpp>

#include <neb/fnd/core/actor/rigidactor/Base.hpp>


typedef neb::fnd::core::actor::rigidactor::base THIS;

typedef neb::fnd::core::shape::base SHAPE;

/*
void				THIS::set_pose_global(
		gal::math::pose pose)
{
	abort();
}
*/
std::weak_ptr<SHAPE>		THIS::createShapeBoxUninitialized(
		glm::vec3 size)
{
	printv_func(DEBUG);
	
	//auto self(::std::dynamic_pointer_cast<neb::fin::core::actor::rigidactor::base>(shared_from_this()));

	typedef neb::fnd::core::shape::Cuboid T;

	std::shared_ptr<T> shape(new T(), gal::stl::deleter<T>());

	neb::fnd::core::shape::util::parent::insert(shape);
	
	shape->scale_ = size;
	
	return shape;
}
std::weak_ptr<SHAPE>		THIS::createShapeBox(
		gal::math::pose pose,
		glm::vec3 size)
{
	printv_func(DEBUG);

	auto shape = createShapeBoxUninitialized(size).lock();
	
	shape->init(this);

	//P::get_object()->setupFiltering();
	P::get_object()->init_physics();

	return shape;
}    

