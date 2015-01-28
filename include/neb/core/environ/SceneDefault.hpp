#ifndef NEBULA_FND_ENVIRON_SCENE_DEF_HPP
#define NEBULA_FND_ENVIRON_SCENE_DEF_HPP

#include <neb/core/core/actor/util/decl.hpp>
#include <neb/core/environ/SceneDefault.hpp>

#include <neb/gfx/util/decl.hpp>
#include <neb/gfx/camera/util/decl.hpp>
#include <neb/gfx/glsl/util/decl.hpp>
#include <neb/gfx/environ/three.hpp>
#include <neb/gfx/environ/single.hpp>

namespace neb { namespace core { namespace environ {
	/** @brief base
	 *
	 * Abstract class that contains functions and data needed to render a specific kind of drawable.
	 */
	class SceneDefault:
		virtual public neb::core::environ::Base
	{
		/*
		public:
			typedef std::shared_ptr<neb::gfx::glsl::program::base>	program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::base>		proj_shared;
		public:
		
			virtual void		init();

			//virtual void		step(gal::etc::timestep const & ts);

			virtual void		render(
					std::shared_ptr<neb::gfx::context::base> context);

			std::weak_ptr<neb::gfx::camera::view::ridealong>		createViewridealong(
					std::weak_ptr<neb::core::core::actor::base> actor);
		public:
		*/
	};
}}}

#endif
