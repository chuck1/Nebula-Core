
#include <neb/fnd/window/Base.hpp>

#include <neb/fnd/gui/layout/Base.hpp>
#include <neb/fnd/gui/object/Edittext.hpp>

typedef neb::fnd::gui::object::Edittext THIS;

THIS::Edittext()
{
}
void	THIS::draw()
{
}
void	THIS::connect()
{
}
int	THIS::mouse_button_fun(int button, int action, int mods)
{
	return 0;
}
int	THIS::key_fun(int key, int scancode, int action, int mods)
{
	char k = 'a' - GLFW_KEY_A + key;

	if(action == GLFW_PRESS) {
		switch(key) {
			case GLFW_KEY_BACKSPACE:
				if(!label_.empty()) {
					label_.pop_back();
				}
				return 1;
			case GLFW_KEY_A:
			case GLFW_KEY_Z:
				label_.push_back(k);
				return 1;
			case GLFW_KEY_ENTER:
				return enter();
			default:
				return 0;
		}
	}
	
	return 0;
}
int	THIS::enter()
{
	return 1;	
}

