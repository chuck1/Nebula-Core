#ifndef __NEBULA_UI_OBJECT_BASE_HPP__
#define __NEBULA_UI_OBJECT_BASE_HPP__

#include <memory>

#include <boost/signals2.hpp>

#include <gal/stl/child.hpp>

#include <neb/core/itf/verbosity.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/math/color/color.hpp>
#include <neb/core/input/sink.hpp>
//#include <neb/core/type_traits.hpp>

#include <neb/gfx/tmp/Child.hpp>
#include <neb/gfx/util/decl.hpp>
#include <neb/gfx/glsl/util/decl.hpp>
#include <neb/gfx/gui/object/util/parent.hpp>
#include <neb/gfx/gui/object/util/flag.hpp>

namespace neb { namespace gfx { namespace gui { namespace object {
	class base:
		public neb::fnd::itf::verbosity<neb::gfx::gui::object::base>,
		virtual public neb::fnd::input::sink,
		virtual public neb::fnd::itf::shared,
		virtual public neb::gfx::tmp::Child<neb::gfx::gui::object::util::parent>,
		virtual public neb::gfx::gui::object::util::parent
	{
		public:
			//typedef neb::fnd::util::parent<neb::gfx::gui::object::base, neb::gfx::gui::object::util::parent> parent_t;
			typedef neb::gfx::gui::object::util::parent parent_t;
			//using neb::fnd::tmp::Child<neb::gfx::gui::object::util::parent>::get_fnd_app;
			using CHILD::get_fnd_app;
			base();
			virtual ~base() {}
			
			virtual void			init(parent_t * const & p);
			virtual void			draw(neb::gfx::RenderDesc const &) = 0;
			virtual void			preloop() = 0;
			virtual int			keyFun(
					std::shared_ptr<neb::fnd::input::source> const &, int, int, int, int) = 0;
			virtual int			mouseButtonFun(
					std::shared_ptr<neb::fnd::input::source> const &, int, int, int);
			virtual int			charFun(
					std::shared_ptr<neb::fnd::input::source> const &,
					unsigned int codepoint) {return 0;}

			//virtual void			connect();
			bool				active_;


			template<class Archive> void	serialize(Archive & ar, unsigned int const & version) {
				ar & boost::serialization::make_nvp("x",x_);
				ar & boost::serialization::make_nvp("y",y_);
				ar & boost::serialization::make_nvp("w",w_);
				ar & boost::serialization::make_nvp("h",h_);
				ar & boost::serialization::make_nvp("font_color",font_color_);
				ar & boost::serialization::make_nvp("bg_color",bg_color_);
				ar & boost::serialization::make_nvp("label",label_);

			}
		public:
			std::shared_ptr<neb::gfx::gui::object::util::parent>	parent_;

			neb::gfx::gui::object::util::flag			flag_;

			float							x_;
			float							y_;
			float							w_;
			float							h_;

			neb::fnd::math::color::color				font_color_;
			neb::fnd::math::color::color				bg_color_;

			std::string						label_;
			// connections
			struct
			{
				boost::signals2::connection		mouse_button_fun_;
				boost::signals2::connection		key_fun_;
			} conns_;



	};
}}}}

#endif

