
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/shape/base.hpp>
#include <neb/fnd/core/light/base.hpp>
#include <neb/fnd/core/light/util/parent.hpp>

typedef neb::fnd::core::light::util::parent THIS;

void			THIS::callbackPose(gal::math::pose const & parent_gpose)
{	
	auto lamb = [&] (map_type::pointer p) {
		//auto shape = std::dynamic_pointer_cast<neb::fnd::core::shape::base>(p);
		//assert(shape);
		
		auto light = std::static_pointer_cast<neb::fnd::core::light::base>(p);

		auto gpose = parent_gpose * light->pose_;

		light->v_set_pose_data(gpose);
	};
	
	for_each(lamb);
}
neb::fnd::app::Base * const	THIS::get_fnd_app()
{
	auto s = isShapeBase();
	assert(s);
	return s->get_fnd_app();
}


