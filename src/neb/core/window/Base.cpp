#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/window/Base.hpp>

typedef neb::fnd::window::Base THIS;

THIS::~Base()
{
}


void			THIS::init(parent_t * const & p)
{
	// callback
	callback_.key_press_.F1_ = [this](int,int,int,int)->int {
		print_screen();
		return 1;
	};
}
void			THIS::create_object_graphics()
{
	auto app = get_fnd_app();
	
	typedef neb::fnd::plug::gfx::window::Base T;

	assert(app->_M_graphics_plugin);

	_M_graphics_object = app->_M_graphics_plugin->template make_shared<T>();
}
void			THIS::print_screen()
{
	if(_M_graphics_object)
		_M_graphics_object->printScreen();
}


/*
virtual void		callback_window_pos_fun(GLFWwindow* w, int x,int y)
{
	if(_M_graphics_object)
		_M_graphics_object->callback_window_pos_fun(w,x,y);
}
virtual void		callback_window_size_fun(GLFWwindow*,int,int);
virtual void		callback_window_close_fun(GLFWwindow*);
virtual void		callback_window_refresh_fun(GLFWwindow*);
virtual void		callback_mouse_button_fun(GLFWwindow*,int,int,int);
virtual void		callback_key_fun(GLFWwindow*,int,int,int,int);
virtual void		callbackCharFun(GLFWwindow*,unsigned int);
*/
