#include <neb/fnd/context/FBOM.hpp>
#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::environ::shadow::Point ESP;
typedef neb::fnd::environ::shadow::Directional ESD;

typedef neb::fnd::context::FBOM THIS;

void				THIS::init(parent_t * const parent)
{
	setParent(parent);

	//neb::gfx::context::fbo_multi::init(parent);
	//if(G::M_graphics_object) 
	//	_M_graphics_object->init(this);
}



std::weak_ptr<ESP>		THIS::createEnvironShadowPoint()
{
	return std::weak_ptr<ESP>();
}
std::weak_ptr<ESD>		THIS::createEnvironShadowDirectional()
{
	return std::weak_ptr<ESD>();
}
/*
std::weak_ptr<neb::fnd::environ::shadow::Directional>		THIS::createEnvironShadowDirectional()
{
	return neb::fnd::environ::util::Parent::createEnvironShadowDirectional();
}
std::weak_ptr<neb::fnd::environ::shadow::Point>		THIS::createEnvironShadowPoint()
{
	return neb::fnd::environ::util::Parent::createEnvironShadowPoint();
}
*/


