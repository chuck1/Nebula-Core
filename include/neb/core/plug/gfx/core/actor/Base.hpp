#ifndef NEB_FND_PLUG_GFX_CORE_ACTOR_BASE_HPP
#define NEB_FND_PLUG_GFX_CORE_ACTOR_BASE_HPP

#include <neb/core/tmp/Child.hpp>
#include <neb/core/net/util/decl.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/glsl/program/util/decl.hpp>
#include <neb/core/core/ACTOR/util/decl.hpp>
#include <neb/core/math/pose.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace core { namespace actor {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::core::actor::base>
	{
		public:
			typedef neb::fnd::core::actor::base FND;
			virtual void			init(parent_t * const & p) = 0;
/*
			virtual void			v_set_pose_data(
					FND * const & ptr,
					neb::fnd::math::pose const & global_pose) = 0;
			virtual void			draw(
					FND * const & ptr,
					neb::fnd::glsl::program::Base const * const & p,
					neb::fnd::math::pose const & pose) = 0;
			virtual void			model_load(
					FND * const & ptr,
					neb::fnd::glsl::program::Base const * const & p,
					neb::fnd::math::pose const & pose) = 0;
					*/
				//virtual void			v_set_pose_data(neb::fnd::math::pose const & pose) = 0;
	};
}}}}}}


#endif
