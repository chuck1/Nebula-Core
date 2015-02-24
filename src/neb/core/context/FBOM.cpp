#include <neb/fnd/context/FBOM.hpp>

typedef neb::fnd::environ::shadow::Point ESP;
typedef neb::fnd::environ::shadow::Directional ESD;

typedef neb::fnd::context::FBOM THIS;

std::weak_ptr<ESP>		THIS::createEnvironShadowPoint()
{
	return std::weak_ptr<ESP>();
}
std::weak_ptr<ESD>		THIS::createEnvironShadowDirectional()
{
	return std::weak_ptr<ESD>();
}
/*
   void				THIS::setTexture(std::shared_ptr<neb::fnd::itf::shared> texture)
   {
   }
   */
void				THIS::init(parent_t * const parent)
{
	setParent(parent);
}

