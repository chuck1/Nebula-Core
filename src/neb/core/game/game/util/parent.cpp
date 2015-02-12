#include <gal/stl/deleter.hpp>

#include <neb/core/game/game/util/parent.hpp>
#include <neb/core/app/Base.hpp>

typedef neb::fnd::game::game::util::parent THIS;

THIS::parent()
{
}
THIS::~parent()
{
}
neb::fnd::app::Base * const	THIS::get_fnd_app()
{
	auto app = dynamic_cast<neb::fnd::app::Base*>(this);
	assert(app);
	return app;
}
void	THIS::__init()
{

}

