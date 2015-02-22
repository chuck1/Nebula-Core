#ifndef NEB_FND_PLUG_GFX_CORE_SHAPE_BASE_HPP
#define NEB_FND_PLUG_GFX_CORE_SHAPE_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/net/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/core/shape/util/decl.hpp>
#include <neb/fnd/math/pose.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace core { namespace shape {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::core::shape::base>
	{
		public:
			typedef neb::fnd::core::shape::base FND;
			virtual void			init(parent_t * const & p) = 0;
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
				//virtual void			v_set_pose_data(neb::fnd::math::pose const & pose) = 0;
	};
}}}}}}


#endif
