#ifndef NEB_FIN_CORE_SHAPE_FRUSTRUM_HPP
#define NEB_FIN_CORE_SHAPE_FRUSTRUM_HPP

//#include <neb/gfx/camera/util/decl.hpp>

#include <neb/fnd/camera/util/decl.hpp>

#include <neb/fnd/core/shape/base.hpp>

namespace neb { namespace fnd { namespace core { namespace shape {
	/** @ brief */
	class frustrum:
		virtual public neb::fnd::core::shape::base
	{
		public:
			frustrum();

			//virtual void				init() = 0;
			//virtual void				release() = 0;
			//virtual void				step(gal::etc::timestep  const & ts) = 0;
			
			std::weak_ptr<neb::fnd::camera::proj::Base>	camera_;
			
			virtual physx::PxGeometry*			to_geo();
	};
}}}}

#endif

