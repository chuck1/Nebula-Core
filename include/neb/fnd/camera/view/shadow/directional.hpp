#ifndef NEB_FND_CAMERA_VIEW_SHADOW_DIRECTIONAL_H__
#define NEB_FND_CAMERA_VIEW_SHADOW_DIRECTIONAL_H__

#include <glm/glm.hpp>

#include <neb/fnd/camera/view/Base.hpp>
#include <neb/fnd/core/light/util/decl.hpp>

namespace neb { namespace fnd { namespace camera { namespace view { namespace shadow {
	/** @brief @Base */
	class Directional:
		virtual public neb::fnd::camera::view::Base
	{
		public:
			typedef std::weak_ptr<neb::fnd::core::light::Directional>	light_weak;
			/** @brief Constructor */
			Directional();
			/** @brief Get view matrix. */
			virtual glm::mat4			view();
			/** @brief Step
			 *
			 * @todo explain when in timeline this occurs and in which thread and why
			 */
			virtual void						step(gal::etc::timestep const & ts);
			std::shared_ptr<neb::fnd::core::light::Directional>	get_light();
			light_weak						light_;
	};
}}}}}

#endif


