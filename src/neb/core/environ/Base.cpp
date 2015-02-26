#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/plug/gfx/environ/Base.hpp>


#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/camera/proj/Perspective.hpp>
#include <neb/fnd/camera/proj/Ortho.hpp>

#include <neb/fnd/plug/gfx/camera/proj/Perspective.hpp>

typedef neb::fnd::environ::Base THIS;

THIS::~Base()
{
}
void		THIS::release()
{
}
void		THIS::step(gal::etc::timestep const & ts)
{
}
void		THIS::render(neb::fnd::context::Base * const & context)
{
	G::get_object()->render(context);
}
void		THIS::set_drawable(std::shared_ptr<neb::fnd::drawable::Base> d)
{
	drawable_ = d;
}
void			THIS::init(parent_t * const & p)
{
	setParent(p);

}
THIS::proj_shared	THIS::createCameraPerspective()
{

	typedef neb::fnd::camera::proj::Perspective C;
	//typedef neb::fnd::plug::gfx::camera::proj::Perspective G;
	
	auto c = new C();
	proj_ = THIS::proj_shared(c);

	proj_->init(this);

	return proj_;
}
THIS::proj_shared	THIS::createCameraOrtho()
{
	typedef neb::fnd::camera::proj::Ortho C;

	auto c = new C;
	proj_.reset(c);

	proj_->init(this);

	return proj_;
}



