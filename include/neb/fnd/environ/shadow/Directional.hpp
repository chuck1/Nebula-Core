#ifndef NEB_CORE_ENVIRON_SHADOW_DIRECTIONAL_HPP
#define NEB_CORE_ENVIRON_SHADOW_DIRECTIONAL_HPP

#include <neb/fnd/environ/Single.hpp>
#include <neb/fnd/environ/SceneDefault.hpp>
#include <neb/fnd/environ/shadow/Base.hpp>
#include <neb/fnd/camera/view/shadow/Directional.hpp>
#include <neb/fnd/core/light/Directional.hpp>


namespace neb { namespace fnd { namespace environ { namespace shadow {
	class Directional:
		virtual public neb::fnd::environ::shadow::Base<neb::fnd::core::light::Directional>,
		virtual public neb::fnd::environ::single<neb::fnd::camera::view::shadow::Directional>
	{
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}}

#endif

