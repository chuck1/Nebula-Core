//#include <neb/gfx/texture/Base.hpp>

#include <neb/fnd/context/FBO.hpp>

#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::context::FBO THIS;
typedef neb::fnd::environ::shadow::Directional ESD;

void			THIS::init(parent_t * const parent)
{
	setParent(parent);

	if(_M_graphics_object)
		_M_graphics_object->init(this);
}
void			THIS::render()
{
	if(_M_graphics_object)
		_M_graphics_object->render();
}
std::weak_ptr<ESD>	THIS::createEnvironShadowDirectional()
{
	return neb::fnd::environ::util::Parent::createEnvironShadowDirectional();
}
void			THIS::setTexture(
		std::shared_ptr<neb::fnd::itf::shared> tex)
{
	if(_M_graphics_object)
		_M_graphics_object->render();

	//auto t = std::dynamic_pointer_cast<neb::gfx::texture::Base>(tex);
	//texture_ = t;
}

