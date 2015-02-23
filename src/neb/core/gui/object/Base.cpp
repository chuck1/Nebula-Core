#include <string.h>
#include <algorithm>

#include <neb/fnd/gui/object/Base.hpp>

typedef neb::fnd::gui::object::Base THIS;

THIS::Base():
	x_(0.0),
	y_(0.0),
	w_(0.3),
	h_(0.3),
	font_color_(neb::fnd::math::color::color::magenta()),
	bg_color_()
{
}
THIS::~Base()
{
}
void		THIS::init(parent_t * const & p)
{
	//neb::itf::shared::init(p);
}
int		THIS::mouseButtonFun(std::shared_ptr<neb::fnd::input::source> const & src, int,int,int)
{
	printf("%s\n", __PRETTY_FUNCTION__);

	font_color_ = neb::fnd::math::color::color::green();

	return 1;
}



