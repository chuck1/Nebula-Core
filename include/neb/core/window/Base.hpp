#ifndef NEB_CORE_WINDOW_BASE_HPP
#define NEB_CORE_WINDOW_BASE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <neb/core/tmp/Child.hpp>
#include <neb/core/input/source.hpp>
#include <neb/core/input/callback.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/context/util/decl.hpp>
#include <neb/core/context/util/Parent.hpp>
#include <neb/core/window/util/decl.hpp>

namespace neb { namespace fnd { namespace window {

	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::window::util::Parent>,
		virtual public neb::fnd::context::util::Parent,
		virtual public neb::fnd::input::source,
		virtual public neb::fnd::input::callback
	{
		public:
			using CHILD::get_fnd_app;
			typedef neb::fnd::window::util::Parent parent_t;
			typedef neb::fnd::util::parent<neb::fnd::context::Base, neb::fnd::context::util::Parent> contexts;
			
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
			virtual void		makeCurrent() = 0;

			virtual void		callback_window_pos_fun(GLFWwindow*,int,int) = 0;
			virtual void		callback_window_size_fun(GLFWwindow*,int,int) = 0;
			virtual void		callback_window_close_fun(GLFWwindow*) = 0;
			virtual void		callback_window_refresh_fun(GLFWwindow*) = 0;
			virtual void		callback_mouse_button_fun(GLFWwindow*,int,int,int) = 0;
			virtual void		callback_key_fun(GLFWwindow*,int,int,int,int) = 0;
			virtual void		callbackCharFun(GLFWwindow*,unsigned int) = 0;

			virtual int		get_width() = 0;
			virtual int		get_height() = 0;

			/*
			virtual std::weak_ptr<neb::fnd::context::FBO>		createContextFBO() = 0;
			virtual std::weak_ptr<neb::fnd::context::FBOM>		createContextFBOMulti() = 0;
			virtual std::weak_ptr<neb::fnd::context::Window>	createContextWindow() = 0;
			virtual std::weak_ptr<neb::fnd::context::Window>	createContextVisDepth() = 0;
			*/
	};
}}}

#endif


