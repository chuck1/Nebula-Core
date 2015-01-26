#ifndef NEB_CORE_WINDOW_BASE_HPP
#define NEB_CORE_WINDOW_BASE_HPP

#include <neb/core/itf/shared.hpp>
#include <neb/core/context/util/decl.hpp>

namespace neb { namespace core { namespace window {

	class Base:
		virtual public neb::core::itf::shared
	{
		public:
			virtual std::weak_ptr<neb::core::context::FBO>		createContextFBO() = 0;
			virtual std::weak_ptr<neb::core::context::FBOM>		createContextFBOMulti() = 0;
			virtual std::weak_ptr<neb::core::context::Window>	createContextWindow() = 0;
			virtual std::weak_ptr<neb::core::context::Window>	createContextVisDepth() = 0;
	};
}}}

#endif


