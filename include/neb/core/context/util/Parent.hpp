#ifndef NEB_CORE_CONTEXT_UTIL_PARENT_HH
#define NEB_CORE_CONTEXT_UTIL_PARENT_HH

#include <neb/core/context/util/decl.hpp>

namespace neb { namespace core { namespace context { namespace util {
	class Parent
	{
		public:
			typedef neb::core::context::Window C_W;
		public:
			virtual std::weak_ptr<neb::gfx::context::fbo>		createContextFBO() = 0;
			virtual std::weak_ptr<neb::gfx::context::fbo_multi>	createContextFBOMulti() = 0;
			virtual std::weak_ptr<C_W>				createContextWindow() = 0;
			virtual std::weak_ptr<C_W>				createContextVisDepth() = 0;
	};
}}}}

#endif

