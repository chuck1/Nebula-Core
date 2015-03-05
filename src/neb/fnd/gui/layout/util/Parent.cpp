#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/gui/layout/util/Parent.hpp>

typedef neb::fnd::gui::layout::util::Parent THIS;

neb::fnd::app::Base*		THIS::get_fnd_app()
{
	auto a = dynamic_cast<neb::fnd::app::Base*>(this);
	assert(a);
	return a;
}

