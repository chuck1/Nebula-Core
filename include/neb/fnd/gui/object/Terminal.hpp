#ifndef __NEBULA_UI_OBJECT_TERMINAL_H__
#define __NEBULA_UI_OBJECT_TERMINAL_H__

#include <deque>

#include <gal/stl/verbosity.hpp>
#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/gui/object/Base.hpp>

namespace neb { namespace fnd { namespace gui { namespace object {
	class Terminal:
		public gal::tmp::Verbosity<neb::fnd::gui::object::Terminal>,
		virtual public neb::fnd::gui::object::Base
	{
		public:
			using gal::tmp::Verbosity<neb::fnd::gui::object::Terminal>::printv;
			//typedef typename neb::fnd::gui::object::base::parent_t parent_t;
			Terminal();
			virtual void			init(parent_t * const & p);
			virtual void			step(gal::etc::timestep const &) {}
			virtual void			draw(RenderDesc const &);
			virtual void			preloop();
			virtual int			keyFun(
					std::shared_ptr<neb::fnd::input::source> const &, int,int,int,int);
			virtual int			charFun(
					std::shared_ptr<neb::fnd::input::source> const &,
					unsigned int codepoint);
			std::weak_ptr<neb::fnd::app::Base::console_type>	console_;
			// display
			std::vector<std::string>	history_;
			unsigned int			history_current_;
			unsigned int			page_offset_;
			unsigned int			max_line_count_;
	};
}}}}

#endif

