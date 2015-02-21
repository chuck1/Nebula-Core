#ifndef NEB_FND_PLUG_GFX_CORE_SHAPE_BASE_HPP
#define NEB_FND_PLUG_GFX_CORE_SHAPE_BASE_HPP

#include <neb/core/tmp/Child.hpp>
#include <neb/core/net/util/decl.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/glsl/program/util/decl.hpp>
#include <neb/core/core/shape/util/decl.hpp>
#include <neb/core/math/pose.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace core { namespace shape {
	typedef neb::fnd::core::shape::base FND;
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<FND>
	{
		public:
			virtual void			init(parent_t * const & p) = 0;
			virtual void			v_set_pose_data(
					FND * const & p,
					neb::fnd::math::pose const & global_pose);
			virtual void			draw(
					neb::fnd::glsl::program::Base const * const & program,
					neb::fnd::math::pose const & pose) = 0;
				//virtual void			v_set_pose_data(neb::fnd::math::pose const & pose) = 0;
	};
}}}}}}

#endif
