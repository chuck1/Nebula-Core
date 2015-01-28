#ifndef NEB_CORE_WINDOW_BASE_HPP
#define NEB_CORE_WINDOW_BASE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/stl/child.hpp>

#include <neb/core/input/source.hpp>
#include <neb/core/input/callback.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/context/util/decl.hpp>
#include <neb/core/context/util/Parent.hpp>
#include <neb/core/window/util/decl.hpp>

namespace neb { namespace core { namespace window {

	class Base:
		virtual public gal::stl::child<neb::core::window::util::Parent>,
		virtual public neb::core::context::util::Parent,
		virtual public neb::core::input::source,
		virtual public neb::core::input::callback
	{
		public:
			typedef neb::core::window::util::Parent parent_t;
			typedef neb::core::util::parent<neb::core::context::Base, neb::core::context::util::Parent> contexts;
			
			//base();
			virtual ~Base() = 0;
			virtual void		init(parent_t * const & p) = 0;
			virtual void		release() = 0;
			
			virtual glm::vec2	getCursorPosNDC() = 0;
			
			/** @name Main Loop @{ */
			virtual void		render() = 0;
			virtual void		step(gal::etc::timestep const & ts) = 0;
			/** @} */
			virtual void		resize() = 0;

			virtual void		callback_window_pos_fun(GLFWwindow*,int,int) = 0;
			virtual void		callback_window_size_fun(GLFWwindow*,int,int) = 0;
			virtual void		callback_window_close_fun(GLFWwindow*) = 0;
			virtual void		callback_window_refresh_fun(GLFWwindow*) = 0;
			virtual void		callback_mouse_button_fun(GLFWwindow*,int,int,int) = 0;
			virtual void		callback_key_fun(GLFWwindow*,int,int,int,int) = 0;
			virtual void		callbackCharFun(GLFWwindow*,unsigned int) = 0;

			/*
			virtual std::weak_ptr<neb::core::context::FBO>		createContextFBO() = 0;
			virtual std::weak_ptr<neb::core::context::FBOM>		createContextFBOMulti() = 0;
			virtual std::weak_ptr<neb::core::context::Window>	createContextWindow() = 0;
			virtual std::weak_ptr<neb::core::context::Window>	createContextVisDepth() = 0;
			*/
	};
}}}

#endif


