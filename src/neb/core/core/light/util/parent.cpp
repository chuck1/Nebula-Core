
#include <neb/core/core/actor/base.hpp>
#include <neb/core/core/shape/base.hpp>
#include <neb/core/core/light/base.hpp>
#include <neb/core/core/light/util/parent.hpp>

typedef neb::fnd::core::light::util::parent THIS;

void			THIS::callbackPose(neb::fnd::math::pose const & parent_gpose)
{	
	auto lamb = [&] (map_type::pointer p) {
		//auto shape = std::dynamic_pointer_cast<neb::fnd::core::shape::base>(p);
		//assert(shape);
		
		auto light = std::static_pointer_cast<neb::fnd::core::light::base>(p);

		auto gpose = parent_gpose * light->pose_;

		light->v_set_pose_data(gpose);
	};
	
	map_.for_each(lamb);
}
neb::fnd::app::Base * const	THIS::get_fnd_app()
{
	auto s = isShapeBase();
	assert(s);
	return s->get_fnd_app();
}


