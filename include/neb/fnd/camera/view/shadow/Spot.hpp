#ifndef NEB_FND_CAMERA_VIEW_SHADOW_SPOT_
#define NEB_FND_CAMERA_VIEW_SHADOW_SPOT_

#include <glm/glm.hpp>

#include <neb/fnd/camera/view/shadow/Base.hpp>
#include <neb/fnd/core/light/util/decl.hpp>

namespace neb { namespace fnd {namespace camera {namespace view { namespace shadow {
	/** @brief @Base */
	class Spot:
		virtual public neb::fnd::camera::view::shadow::Base
	{
		public:
			typedef std::weak_ptr<neb::fnd::core::light::Spot>	light_weak;
			/** @brief Constructor */
			Spot();
			/** @brief Get view matrix. */
			virtual glm::mat4			view();
			/** @brief Step
			 *
			 * @todo explain when in timeline this occurs and in which thread and why
			 */
			virtual void				step(gal::etc::timestep const & ts);

			glm::vec3				look_;
			glm::vec3				up_;

			light_weak				light_;
	};
}}}}}

#endif


