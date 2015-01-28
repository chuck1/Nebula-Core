#ifndef NEB_CORE_WINDOW_BASE_HPP
#define NEB_CORE_WINDOW_BASE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <neb/core/itf/shared.hpp>
#include <neb/core/context/util/decl.hpp>

namespace neb { namespace core { namespace window {

	class Base:
		virtual public neb::core::itf::shared
	{
		public:
			virtual void		callback_window_pos_fun(GLFWwindow*,int,int) = 0;
			virtual void		callback_window_size_fun(GLFWwindow*,int,int) = 0;
			virtual void		callback_window_close_fun(GLFWwindow*) = 0;
			virtual void		callback_window_refresh_fun(GLFWwindow*) = 0;
			virtual void		callback_mouse_button_fun(GLFWwindow*,int,int,int) = 0;
			virtual void		callback_key_fun(GLFWwindow*,int,int,int,int) = 0;
			virtual void		callbackCharFun(GLFWwindow*,unsigned int) = 0;

			virtual std::weak_ptr<neb::core::context::FBO>		createContextFBO() = 0;
			virtual std::weak_ptr<neb::core::context::FBOM>		createContextFBOMulti() = 0;
			virtual std::weak_ptr<neb::core::context::Window>	createContextWindow() = 0;
			virtual std::weak_ptr<neb::core::context::Window>	createContextVisDepth() = 0;
	};
}}}

#endif


