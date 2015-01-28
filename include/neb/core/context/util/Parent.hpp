#ifndef NEB_CORE_CONTEXT_UTIL_PARENT_HH
#define NEB_CORE_CONTEXT_UTIL_PARENT_HH

#include <neb/core/context/util/decl.hpp>
#include <neb/core/util/parent.hpp>
#include <neb/core/window/util/Cast.hpp>

namespace neb { namespace core { namespace context { namespace util {
	class Parent:
		virtual public neb::core::util::parent<neb::core::context::Base, Parent>,
		virtual public neb::core::window::util::Cast
	{
		public:
			typedef neb::core::context::Window C_W;
		public:
			virtual std::weak_ptr<neb::core::context::FBO>		createContextFBO() = 0;
			virtual std::weak_ptr<neb::core::context::FBOM>		createContextFBOMulti() = 0;
			virtual std::weak_ptr<C_W>				createContextWindow() = 0;
			virtual std::weak_ptr<C_W>				createContextVisDepth() = 0;

			virtual std::weak_ptr<C_W>		createContextTwo() = 0;
			virtual std::weak_ptr<C_W>		createContextThree() = 0;
			virtual std::weak_ptr<C_W>		createContextNormalMap() = 0;

	};
}}}}

#endif

