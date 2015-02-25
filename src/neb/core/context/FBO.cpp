//#include <neb/gfx/texture/Base.hpp>

#include <neb/fnd/context/FBO.hpp>

#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::context::FBO THIS;
typedef neb::fnd::environ::shadow::Directional ESD;

void			THIS::init(parent_t * const parent)
{
	setParent(parent);
	
	//auto app = get_fnd_app();

	/// @TODO make FBO and FBOM types
	//G::make_object<THIS, int>(app->_M_graphics_plugin, 0);
}
/*
void			THIS::render()
{
	//if(G::has_object())
	G::get_object()->render();
}
*/
std::weak_ptr<ESD>	THIS::createEnvironShadowDirectional()
{
	return neb::fnd::environ::util::Parent::createEnvironShadowDirectional();
}
void			THIS::setTexture(
		std::shared_ptr<neb::fnd::itf::shared> tex)
{
	abort();
	//if(_M_graphics_object)
	//	_M_graphics_object->render();

	//auto t = std::dynamic_pointer_cast<neb::gfx::texture::Base>(tex);
	//texture_ = t;
}

