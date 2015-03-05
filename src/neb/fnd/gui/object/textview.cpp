#include <stdio.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <neb/fnd/gui/object/Textview.hpp>
#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/plug/gfx/app/Base.hpp>
//#include <neb/gfx/free.hpp>

typedef neb::fnd::gui::object::Textview THIS;

THIS::Textview()
{
}
void			THIS::clear_label()
{
	label_.clear();
}
void			THIS::draw(std::shared_ptr<neb::fnd::glsl::program::Base> p)
{
	//printf("%s\n",__PRETTY_FUNCTION__);

	float sx = 1.0/600.0;
	float sy = 1.0/600.0;

	auto g = get_fnd_app()->G::get_object();

	g->draw_quad(x_, y_, w_, h_, bg_color_);
	g->draw_text(x_, y_, sx, sy, font_color_, label_, 0);
}
int			THIS::mouseButtonFun(
		std::shared_ptr<neb::fnd::input::source> const & src,
		int button,
		int action,
		int mods)
{
	printf("%s\n", __PRETTY_FUNCTION__);

	return neb::fnd::gui::object::Base::mouseButtonFun(src, button, action, mods);
}
int			THIS::keyFun(
		std::shared_ptr<neb::fnd::input::source> const & src,
		int key,
		int scancode,
		int action,
		int mods)
{
	printf("%s\n", __PRETTY_FUNCTION__);
	return 0;
}




