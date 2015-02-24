#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/window/Base.hpp>
#include <neb/fnd/plug/gfx/window/Base.hpp>

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
void			THIS::makeCurrent()
{
	if(_M_graphics_object)
		_M_graphics_object->makeCurrent();
}
void			THIS::render()
{
	if(_M_graphics_object)
		_M_graphics_object->render();
}
int			THIS::get_height()
{
	if(_M_graphics_object)
		_M_graphics_object->get_height();

	return 0;
}
int			THIS::get_width()
{
	if(_M_graphics_object)
		return _M_graphics_object->get_width();

	return 0;
}
void			THIS::step(gal::etc::timestep const & ts)
{
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
void			THIS::callback_mouse_button_fun(int button, int action, int mods)
{
	//LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	auto self = std::dynamic_pointer_cast<THIS>(shared_from_this());

	sig_.mouseButtonFun_(self, button, action, mods);
}
void			THIS::callback_key_fun(
		int key,
		int scancode,
		int action,
		int mods)
{
	//LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	auto self = std::dynamic_pointer_cast<THIS>(shared_from_this());

	if(action == GLFW_PRESS)
	{
		switch(key)
		{
			case GLFW_KEY_F1:
				if(callback_.key_press_.F1_) if(callback_.key_press_.F1_(key, scancode, action, mods)) return;
				break;
		}
	}

	sig_.keyFun_(self, key, scancode, action, mods);
}
void			THIS::callbackCharFun(unsigned int codepoint)
{
	//LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	auto self = std::dynamic_pointer_cast<THIS>(shared_from_this());

	sig_.charFun_(self, codepoint);
}
void		THIS::release()
{
	neb::fnd::context::util::Parent::clear();

	if(_M_graphics_object) {
		_M_graphics_object->release();
		_M_graphics_object.reset();
	}
}
void		THIS::resize()
{
	if(_M_graphics_object)
		_M_graphics_object->resize();
}
glm::vec2	THIS::getCursorPosNDC()
{
	if(_M_graphics_object)
		return _M_graphics_object->getCursorPosNDC();

	return glm::vec2();
}
void		THIS::callback_window_pos_fun(int x,int y)
{
	//if(_M_graphics_object)
	//	_M_graphics_object->callback_window_pos_fun(w,x,y);
}
void		THIS::callback_window_size_fun(int,int)
{
}
void		THIS::callback_window_close_fun()
{
}
void		THIS::callback_window_refresh_fun()
{
}



