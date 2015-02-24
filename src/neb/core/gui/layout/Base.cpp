

#include <string>
#include <algorithm>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/log/log.hpp>

#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/input/source.hpp>
#include <neb/fnd/gui/object/Base.hpp>
#include <neb/fnd/gui/object/Edittext.hpp>
#include <neb/fnd/gui/object/Terminal.hpp>
#include <neb/fnd/gui/layout/Base.hpp>
#include <neb/fnd/gui/layout/util/Parent.hpp>

//#include <neb/gfx/context/Base.hpp>
//#include <neb/gfx/util/log.hpp>

typedef neb::fnd::gui::layout::Base THIS;

THIS::Base()
{
	//LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;
}
THIS::~Base()
{
}
void		THIS::release()
{
	neb::fnd::gui::object::util::Parent::clear();
}
void		THIS::init(parent_t * const & p)
{
	//LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	setParent(p);
}
void		THIS::step(gal::etc::timestep const & ts)
{
//	LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

}
void			THIS::draw(neb::fnd::RenderDesc const & desc)
{	
//	LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	typedef neb::fnd::gui::object::util::Parent O;

	auto lamb = [&] (O::map_type::pointer p) {
		auto object = std::dynamic_pointer_cast<neb::fnd::gui::object::Base>(p);
		assert(object);
		object->draw(desc);
	};

	O::map_.for_each(lamb);

}
int			THIS::keyFun(
		std::shared_ptr<neb::fnd::input::source> const & src,
		int key,
		int scancode,
		int action,
		int mode)
{
//	LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	typedef neb::fnd::gui::object::util::Parent O;

	//O::map_.for_each_int<0>([&] (O::map_type::iterator<0> it) {
	for(O::map_type::iterator it = O::map_.begin(); it != O::map_.end(); ++it) {
		auto object = std::dynamic_pointer_cast<neb::fnd::gui::object::Base>(it->second.ptr_);
		assert(object);

		if(object->keyFun(src, key, scancode, action, mode)) return 1;
	};

	return 0;
}
int			THIS::charFun(
		std::shared_ptr<neb::fnd::input::source> const & window,
		unsigned int codepoint)
{
//	LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	typedef neb::fnd::gui::object::util::Parent O;

	for(O::map_type::iterator it = O::map_.begin(); it != O::map_.end(); ++it) {
		auto object = std::dynamic_pointer_cast<neb::fnd::gui::object::Base>(it->second.ptr_);
		assert(object);

		if(object->charFun(window, codepoint)) return 1;
	};

	return 0;
}
int			THIS::mouseButtonFun(
		std::shared_ptr<neb::fnd::input::source> const & src,
		int button,
		int action,
		int mods)
{

//	LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	assert(src);

	switch(action) {
		case GLFW_PRESS:
			switch(button)
			{
				case GLFW_MOUSE_BUTTON_LEFT:
					search(src, button, action, mods);
					break;
			}
			break;
		default:
			return 0;
	}

	return 0;
}
int			THIS::search(
		std::shared_ptr<neb::fnd::input::source> const & src,
		int button,
		int action,
		int mods)
{

//	LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	assert(src);

	/*
	double x, y;
	int w, h;
	glfwGetCursorPos(window->window_, &x, &y);
	glfwGetWindowSize(window->window_, &w, &h);

	printf("%f %f %i %i\n", x, y, w, h);

	x = x / (float)w * 2.0 - 1.0;
	y = y / (float)h * 2.0 - 1.0;

	printf("%f %f\n", x, y);
	*/
	
	glm::vec2 c = src->getCursorPosNDC();
	
	typedef neb::fnd::gui::object::util::Parent O;

	std::shared_ptr<neb::fnd::gui::object::Base> object;
	std::shared_ptr<neb::fnd::gui::object::Base> objecttmp;

	auto lamb = [&] (O::map_type::pointer p) {
		objecttmp = std::dynamic_pointer_cast<neb::fnd::gui::object::Base>(p);
		assert(objecttmp);
		printf("object %f %f %f %f\n",
				objecttmp->x_,
				objecttmp->y_,
				objecttmp->w_,
				objecttmp->h_);	

		if(c.x <   objecttmp->x_) return O::map_type::CONTINUE;
		if(c.x > ( objecttmp->x_ + objecttmp->w_)) return O::map_type::CONTINUE;
		if(c.y >  -objecttmp->y_) return O::map_type::CONTINUE;
		if(c.y < (-objecttmp->y_ - objecttmp->h_)) return O::map_type::CONTINUE;

		object = objecttmp;

		return O::map_type::BREAK;
	};

	O::map_.for_each_int(lamb);

	if(object) return object->mouseButtonFun(src, button, action, mods);

	return 0;
}
std::weak_ptr<neb::fnd::gui::object::Terminal>		THIS::createObjectTerminal()
{

	return neb::fnd::gui::object::util::Parent::create<neb::fnd::gui::object::Terminal>();

	//auto term = sp::make_shared<neb::gfx::gui::object::terminal>();
	//insert(term);
	//term->init();
	//return term;
}




void			THIS::connect(std::shared_ptr<neb::fnd::input::source> const & src)
{
	printf("%s\n", __PRETTY_FUNCTION__);

	connectKeyFun(src, 10);
	connectCharFun(src, 10);
	connectMouseButtonFun(src, 10);
}


