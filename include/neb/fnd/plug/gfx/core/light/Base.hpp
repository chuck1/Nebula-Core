#ifndef NEB_FND_PLUG_GFX_CORE_LIGHT_BASE_HPP
#define NEB_FND_PLUG_GFX_CORE_LIGHT_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/net/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/core/light/util/decl.hpp>
#include <gal/math/pose.hpp>
#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace core { namespace light {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::gfx::core::light::Base,
				neb::fnd::core::light::base>
	{
		public:
			typedef neb::fnd::core::light::base FND;
			virtual void			init(parent_t * const & p) = 0;
			virtual void			v_set_pose_data(
					FND * const & ptr,
					gal::math::pose const & global_pose) = 0;
			/*
			virtual void			draw(
					FND * const & ptr,
					neb::fnd::glsl::program::Base const * const & p,
					gal::math::pose const & pose) = 0;
			virtual void			model_load(
					FND * const & ptr,
					neb::fnd::glsl::program::Base const * const & p,
					gal::math::pose const & pose) = 0;
					*/
				//virtual void			v_set_pose_data(gal::math::pose const & pose) = 0;
	};
}}}}}}


#endif
