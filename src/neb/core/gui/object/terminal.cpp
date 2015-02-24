#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/log/log.hpp>

#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/gui/object/Terminal.hpp>
#include <neb/fnd/plug/gfx/app/Base.hpp>

//#include <neb/gfx/app/base.hpp>
//#include <neb/gfx/free.hpp>
//#include <neb/gfx/util/log.hpp>

typedef gal::console::temp<gal::console::backend::python, gal::console::frontend::store> console_type;

namespace NS = neb::fnd::gui::object;

typedef neb::fnd::gui::object::Terminal THIS;

THIS::Terminal():
	history_current_(0),
	page_offset_(0),
	max_line_count_(20)
{
}
void			THIS::preloop()
{
	//LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	auto app = get_fnd_app();

	for(auto s: app->_M_preloop_scripts_python) {
		auto console = console_.lock();
		assert(console);

		console->eval("execfile(\"" + s + "\")");
	}
}
void			THIS::init(
		parent_t * const & p)
{
	//LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	setParent(p);

	neb::fnd::gui::object::Base::init(p);

	auto app = get_fnd_app();

	console_ = app->console_;
}
void 			THIS::draw(
		neb::fnd::RenderDesc const & desc)
{
	printv(debug, "%s\n", __PRETTY_FUNCTION__);
	
	//typedef neb::gfx::glsl::program::base P;

	auto app = get_fnd_app();
	auto g = app->get_object();

	auto console(console_.lock());
	if(!console) return;

	if(!flag_.any(neb::gfx::gui::object::util::flag::ENABLED)) return;

	float sx = 1.0/ 600.0;
	float sy = 1.0/ 600.0;
	float x = x_ - 0.9;
	float y = y_ + 0.9;
	float line_height = 0.075;

	//draw_quad(x_, y_, w_, h_, bg_color_);

	printv(debug, "copy lines\n", __PRETTY_FUNCTION__);

	std::vector<std::string> lines(console->lines_.begin(), console->lines_.end());
	int b, e;

	printv(debug, "determine begin and end\n", __PRETTY_FUNCTION__);

	if(lines.size() < max_line_count_) {
		b = 0;
		e = lines.size();
	} else {
		b = lines.size() - page_offset_ - max_line_count_;
		e = lines.size() - page_offset_;
	}

	printv(debug, "draw lines b = %i e = %i size = %lu offset = %i\n", b, e, lines.size(), page_offset_);
		
	for(int i = b; i < e; i++) {
		g->draw_text(
				x,
				y,
				sx,
				sy,
				font_color_,
				lines[i].c_str(),
				0);
		y -= line_height;
	}

	printv(debug, "draw lines end\n", __PRETTY_FUNCTION__);

	std::string line = console->prompt_end_ + console->line_.container;

	g->draw_text(
			x,
			y,
			sx,
			sy,
			font_color_,
			line.c_str(),
			console->line_.pos + console->prompt_end_.size());
}
int			THIS::charFun(
		std::shared_ptr<neb::fnd::input::source> const & window,
		unsigned int codepoint)
{
	printv(debug, "%s\n", __PRETTY_FUNCTION__);

	auto console(console_.lock());
	if(!console) return 0;

	if(flag_.any(neb::gfx::gui::object::util::flag::ENABLED)) {
		console->push(codepoint);
	}
	return 1;
}
int			THIS::keyFun(
		std::shared_ptr<neb::fnd::input::source> const & window,
		int key,
		int scancode,
		int action,
		int mods)
{
	printv(debug, "%s\n", __PRETTY_FUNCTION__);

	auto console(console_.lock());
	if(!console) return 0;

	if(!flag_.any(neb::gfx::gui::object::util::flag::ENABLED) && !(key == GLFW_KEY_ESCAPE)) {
		return 0;
	}

	size_t N = console->lines_.size();

	if((action == GLFW_PRESS) || (action == GLFW_REPEAT)) {
		switch(key) {
			case GLFW_KEY_ESCAPE:
				flag_.toggle(neb::gfx::gui::object::util::flag::ENABLED);
				break;
			case GLFW_KEY_DELETE:
				console->line_.del();
				break;
			case GLFW_KEY_BACKSPACE:
				console->line_.backspace();
				break;
			case GLFW_KEY_HOME:
				console->line_.home();
				break;
			case GLFW_KEY_END:
				console->line_.end();
				break;
			case GLFW_KEY_ENTER:
				if(!console->line_.container.empty())
					history_.push_back(console->line_.container);

				history_current_ = history_.size();

				console->enter();
				break;
			case GLFW_KEY_PAGE_UP:
				page_offset_ += max_line_count_;

				if(max_line_count_ >= N) {
					page_offset_ = 0;
					break;
				}

				if((page_offset_ + max_line_count_) > N) {
					page_offset_ = N - max_line_count_;
					break;
				}

				//LOG(lg, neb::gfx::sl, info)
				//	<< "page offset = " << page_offset_;
				break;
			case GLFW_KEY_PAGE_DOWN:
				if(page_offset_ > max_line_count_)
					page_offset_ -= max_line_count_;
				else
					page_offset_ = 0;

				//LOG(lg, neb::gfx::sl, info)
				//	<< "page offset = " << page_offset_;
				break;
			case GLFW_KEY_UP:
				if(history_.empty()) break;

				if(history_current_ > 0) {
					history_current_--;
					console->line_ = history_[history_current_];
				}
				break;
			case GLFW_KEY_DOWN:
				if(history_.empty()) break;
				if(history_current_ == history_.size()) break;

				history_current_++;

				if(history_current_ == history_.size()) {
					console->line_.clear();
				} else {
					console->line_ = history_[history_current_];
				}
				break;
			case GLFW_KEY_LEFT:
				console->line_.down();
				break;
			case GLFW_KEY_RIGHT:
				console->line_.up();
				break;
		}
	}

	// block everything
	return 1;
}




