#ifndef NEB_FND_CAMERA_VIEW_RIDEALONG_HPP
#define NEB_FND_CAMERA_VIEW_RIDEALONG_HPP

#include <memory>
#include <map>

#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/camera/view/Base.hpp>

namespace neb { namespace fnd { namespace camera { namespace view {
	class Ridealong:
		virtual public neb::fnd::camera::view::Base
	{
		public:
			virtual void		step(gal::etc::timestep const & ts);
			std::weak_ptr<neb::fnd::core::actor::base>	actor_;
	};
}}}}

#endif
