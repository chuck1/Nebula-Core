#ifndef NEB_FND_PLUG_PHX_CORE_SCENE_BASE_HPP
#define NEB_FND_PLUG_PHX_CORE_SCENE_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/net/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/core/scene/util/decl.hpp>
#include <gal/math/pose.hpp>
#include <neb/fnd/DebugBuffer.hpp>
#include <neb/fnd/RenderDesc.hpp>
#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace phx { namespace core { namespace scene {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::gfx::core::scene::Base,
				neb::fnd::core::scene::base>
	{
		public:
			typedef neb::fnd::core::scene::base FND;
			virtual void			init(parent_t * const & p) = 0;
			virtual neb::fnd::DebugBuffer	get_debug_buffer() = 0;
/*
			virtual void			v_set_pose_data(
					FND * const & ptr,
					gal::math::pose const & global_pose) = 0;
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
