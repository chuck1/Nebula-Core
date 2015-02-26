#ifndef NEB_FND_CAMERA_VIEW_SHADOW_POINT_
#define NEB_FND_CAMERA_VIEW_SHADOW_POINT_

#include <glm/glm.hpp>

#include <neb/fnd/camera/view/Base.hpp>
#include <neb/fnd/core/light/util/decl.hpp>

namespace neb { namespace fnd {namespace camera {namespace view { namespace shadow {
	/** @brief @Base */
	class Point:
		virtual public neb::fnd::camera::view::Base
	{
		public:
			typedef std::weak_ptr<neb::fnd::core::light::Point>	light_weak;
			/** @brief Constructor */
			Point();
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


