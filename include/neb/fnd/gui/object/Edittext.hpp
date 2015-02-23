#ifndef __NEBULA_UI_OBJECT_EDITTEXT_H__
#define __NEBULA_UI_OBJECT_EDITTEXT_H__

#include <neb/fnd/gui/object/Textview.hpp>

namespace neb { namespace fnd { namespace gui { namespace object {
	class Edittext:
		virtual public neb::fnd::gui::object::Textview
	{
		public:
			Edittext();
			virtual void		draw();
			virtual void		connect();
			virtual int		key_fun(int,int,int,int);
			virtual int		mouse_button_fun(int,int,int);
			virtual int		enter();
	};
}}}}

#endif


