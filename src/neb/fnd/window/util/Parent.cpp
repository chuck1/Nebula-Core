#include <neb/fnd/window/util/Parent.hpp>
#include <neb/fnd/app/Base.hpp>

typedef neb::fnd::window::util::Parent THIS;

neb::fnd::app::Base * const		THIS::get_fnd_app()
{
	auto a = dynamic_cast<neb::fnd::app::Base*>(this);
	assert(a);
	return a;
}
void					THIS::render()
{
	//LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	auto lamb = [&] (S const & s) {
		s->render();
	};

	for_each(lamb);
}

