
#include <neb/fnd/core/scene/util/parent.hpp>
#include <neb/fnd/app/Base.hpp>

typedef neb::fnd::core::scene::util::parent THIS;

neb::fnd::app::Base * const	THIS::get_fnd_app()
{
	auto app = dynamic_cast<neb::fnd::app::Base * const>(this);
	assert(app);
	return app;
}

