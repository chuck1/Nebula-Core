#ifndef __NEBULA_GUI_OBJECT_BASE_HPP__
#define __NEBULA_GUI_OBJECT_BASE_HPP__

#include <memory>

#include <boost/signals2.hpp>

#include <gal/stl/child.hpp>

#include <gal/stl/verbosity.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/math/color/color.hpp>
#include <neb/fnd/input/sink.hpp>
//#include <neb/fnd/type_traits.hpp>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/glsl/util/decl.hpp>
#include <neb/fnd/gui/object/__Base.hpp>
#include <neb/fnd/gui/object/util/Parent.hpp>
#include <neb/fnd/gui/object/util/flag.hpp>

namespace neb { namespace fnd { namespace gui { namespace object {
	class Base:
		public gal::tmp::Verbosity<neb::fnd::gui::object::Base>,
		virtual public neb::fnd::gui::object::__Base,
		virtual public neb::fnd::input::sink,
		virtual public neb::fnd::tmp::Child<neb::fnd::gui::object::util::Parent>,
		virtual public neb::fnd::gui::object::util::Parent
	{
		public:
			//typedef neb::fnd::util::parent<neb::gfx::gui::object::base, neb::gfx::gui::object::util::parent> parent_t;
			//typedef neb::gfx::gui::object::util::parent parent_t;
			//using neb::fnd::tmp::Child<neb::gfx::gui::object::util::parent>::get_fnd_app;
			using CHILD::get_fnd_app;
			Base();
			virtual ~Base();
			virtual void			init(parent_t * const & p);
			virtual void			draw(neb::fnd::RenderDesc const &) = 0;
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

