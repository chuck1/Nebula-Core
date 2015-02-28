#ifndef NEB_CORE_ENVIRON_BASE_HPP
#define NEB_CORE_ENVIRON_BASE_HPP

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/environ/util/Parent.hpp>
#include <neb/fnd/environ/util/Cast.hpp>
#include <neb/fnd/camera/util/decl.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>

#include <neb/fnd/plug/ObjectParent.hpp>
#include <neb/fnd/plug/gfx/environ/util/decl.hpp>

namespace neb { namespace fnd { namespace environ {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::environ::util::Parent>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::environ::Base>,
		virtual public neb::fnd::environ::util::Cast
	{
		public:
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::environ::Base> G;
			typedef std::shared_ptr<neb::fnd::glsl::program::Base>		program_shared;
			typedef std::shared_ptr<neb::fnd::camera::view::Base>		view_shared;
			typedef std::shared_ptr<neb::fnd::camera::proj::Base>		proj_shared;
			//typedef neb::gfx::core::light::directional			light_type;
			//typedef std::shared_ptr<light_type>				light_shared;
			//typedef std::weak_ptr<light_type>				light_weak;
			virtual ~Base();
			virtual void		init(parent_t * const & p);
			virtual void		release();
			virtual void		step(gal::etc::timestep const & ts);
			void			render(neb::fnd::context::Base * const & context);
			virtual view_shared	get_view(int i = 0) = 0;
			virtual proj_shared	createCameraPerspective();
			virtual proj_shared	createCameraOrtho();
			void			set_drawable(std::shared_ptr<neb::fnd::drawable::Base> drawable);

			std::weak_ptr<neb::fnd::drawable::Base>			drawable_;
			proj_shared						proj_;
	};
}}}

#endif
