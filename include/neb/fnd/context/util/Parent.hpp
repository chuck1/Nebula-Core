#ifndef NEB_CORE_CONTEXT_UTIL_PARENT_HH
#define NEB_CORE_CONTEXT_UTIL_PARENT_HH

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/context/util/decl.hpp>
#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/window/util/Cast.hpp>

namespace neb { namespace fnd { namespace context { namespace util {
	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::context::Base, Parent>,
		virtual public neb::fnd::window::util::Cast
	{
		public:
			typedef neb::fnd::context::Window C_W;
			neb::fnd::app::Base * const				get_fnd_app();
			virtual std::weak_ptr<neb::fnd::context::FBO>		createContextFBO();
			virtual std::weak_ptr<neb::fnd::context::FBOM>		createContextFBOMulti();
			virtual std::weak_ptr<C_W>				createContextWindow();
			virtual std::weak_ptr<C_W>				createContextVisDepth();
			virtual std::weak_ptr<C_W>				createContextTwo();
			virtual std::weak_ptr<C_W>				createContextThree();
			virtual std::weak_ptr<C_W>				createContextNormalMap();
	};
}}}}

#endif

