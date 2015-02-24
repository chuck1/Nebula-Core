#ifndef NEB_CORE_ENVIRON_SHADOW_BASE_HPP
#define NEB_CORE_ENVIRON_SHADOW_BASE_HPP

#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/core/light/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>

namespace neb { namespace fnd { namespace environ { namespace shadow {
	template<typename LIGHT>
	class Base:
		virtual public neb::fnd::environ::Base
	{
		public:
			typedef neb::fnd::environ::SceneDefault ES;
			typedef std::weak_ptr<ES> environ_scene_weak;
			virtual void			setLight(std::shared_ptr<neb::fnd::core::light::base> light)
			{
				assert(light);
				auto l = std::dynamic_pointer_cast<LIGHT>(light);
				assert(l);
				_M_light = l;
			}
			virtual void			setSceneEnviron(std::shared_ptr<neb::fnd::environ::Base> environ)
			{
				//auto es = environ->is_fnd_environ_scene_default();
				auto es = std::dynamic_pointer_cast<ES>(environ);
				assert(es);
				environ_scene_ = es;
			}
			std::weak_ptr<LIGHT>		_M_light;

			/** environ that uses the shadow map
			 * frustrum used to determine which shadowmaps need to be rendered
			 */
			environ_scene_weak			environ_scene_;
	};
}}}}

#endif

