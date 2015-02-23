#ifndef __NEBULA_UI_OBJECT_TEXTVIEW_HPP__
#define __NEBULA_UI_OBJECT_TEXTVIEW_HPP__

#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/gui/object/Base.hpp>

namespace neb { namespace fnd { namespace gui { namespace object {
	/** \brief %textview
	 * Display and optionally edit text
	 */
	class Textview:
		virtual public neb::fnd::gui::object::Base
	{
		public:
			Textview();
			void			clear_label();
			virtual void		draw(std::shared_ptr<neb::fnd::glsl::program::Base> p);
			//int			key(int, int, int, int);
			//int			key_down(int);
			//virtual int		enter();
			virtual int		keyFun(std::shared_ptr<neb::fnd::input::source> const &, int,int,int,int);
			virtual int		mouseButtonFun(std::shared_ptr<neb::fnd::input::source> const &, int,int,int);
			//virtual void		connect();
	};
}}}}

#endif
