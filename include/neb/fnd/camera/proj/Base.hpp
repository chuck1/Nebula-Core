#ifndef NEB_FND_CAMERA_PROJ_BASE_HPP
#define NEB_FND_CAMERA_PROJ_BASE_HPP

#include <memory>
#include <map>

#include <glm/glm.hpp>

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/environ/util/decl.hpp>
#include <neb/fnd/core/shape/util/decl.hpp>

#include <neb/fnd/plug/gfx/camera/util/decl.hpp>

//#include <neb/fnd/camera/view/Ridealong.hpp>

//#include <neb/gfx/window/Base.hpp>
//#include <neb/gfx/camera/view/Base.hpp>

namespace neb { namespace fnd { namespace camera { namespace proj {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::environ::Base>,
		virtual public neb::fnd::itf::shared
	{
	public:
		virtual void	init(parent_t * const & p) = 0;
		glm::mat4	proj();
		virtual void		calculate_geometry();

		// instead of holding a physx geometry, hold a pointer to a shape which will hold a
		// physx geometry
		//physx::PxGeometry*	_M_px_geometry;
		std::weak_ptr<neb::fnd::core::shape::base>	_M_shape;

		std::shared_ptr<neb::fnd::plug::gfx::camera::proj::Base>	_M_graphics_object;
	};
}}}}

#endif
