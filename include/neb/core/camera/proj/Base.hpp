#ifndef NEB_FND_CAMERA_PROJ_BASE_HPP
#define NEB_FND_CAMERA_PROJ_BASE_HPP

#include <memory>
#include <map>

#include <neb/core/itf/shared.hpp>
#include <neb/core/tmp/Child.hpp>
#include <neb/core/environ/util/decl.hpp>
//#include <neb/core/core/actor/util/decl.hpp>
//#include <neb/core/camera/view/Ridealong.hpp>

//#include <neb/gfx/window/Base.hpp>
//#include <neb/gfx/camera/view/Base.hpp>

namespace neb { namespace fnd { namespace camera { namespace proj {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::environ::Base>,
		virtual public neb::fnd::itf::shared
	{
	public:
		virtual void	init(parent_t * const & p) = 0;
	};
}}}}

#endif
