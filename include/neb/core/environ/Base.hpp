#ifndef NEB_CORE_ENVIRON_BASE_HPP
#define NEB_CORE_ENVIRON_BASE_HPP

#include <neb/core/tmp/Child.hpp>
#include <neb/core/environ/util/Parent.hpp>
#include <neb/core/camera/util/decl.hpp>

namespace neb { namespace fnd { namespace environ {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::environ::util::Parent>
	{
		public:
			typedef std::shared_ptr<neb::fnd::camera::proj::Base>		proj_shared;
			virtual ~Base() = 0;
			proj_shared						proj_;
	};
}}}

#endif
