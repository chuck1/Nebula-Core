#ifndef __NEBULA_APP___BASE_H__
#define __NEBULA_APP___BASE_H__

#include <boost/asio/io_service.hpp>

#include <gal/etc/timestep.hpp>
#include <gal/stl/verbosity.hpp>
#include <gal/console/console.hpp>
#include <gal/itf/registry.hpp>
#include <gal/argparse/Args.hpp>

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/app/Base10.hpp>
#include <neb/fnd/app/util/Flag.hh>
#include <neb/fnd/context/util/decl.hpp>
#include <neb/fnd/environ/util/decl.hpp>
//#include <neb/fnd/core/scene/util/decl.hpp>
#include <neb/fnd/game/game/util/parent.hpp>
#include <neb/fnd/game/game/util/decl.hpp>
#include <neb/fnd/gui/layout/util/Parent.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/window/util/Parent.hpp>
#include <neb/fnd/timer/util/Parent.hpp>

#include <neb/fnd/plug/ObjectParent.hpp>
#include <neb/fnd/plug/gfx/util/decl.hpp>
#include <neb/fnd/plug/phx/util/decl.hpp>

namespace neb { namespace fnd { namespace app {
	/** @brief %base */
	class Base:
		public gal::tmp::VerbosityRegister,
		public gal::tmp::Verbosity<neb::fnd::app::Base>,
		virtual public neb::fnd::app::Base10,
		virtual public gal::itf::registry,
		virtual public neb::fnd::game::game::util::parent,
		virtual public neb::fnd::window::util::Parent,
		virtual public neb::fnd::timer::util::Parent,
		virtual public neb::fnd::gui::layout::util::Parent,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::app::Base>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::phx::app::Base>
	{
		public:
			typedef std::weak_ptr<neb::fnd::window::Base> window_w;
			typedef std::weak_ptr<neb::fnd::core::scene::base> scene_w;
			using gal::tmp::Verbosity<neb::fnd::app::Base>::printv;
			typedef gal::dll::helper<gal::itf::shared> H;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::app::Base> G;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::phx::app::Base> P;
			typedef gal::console::temp<
				gal::console::frontend::store,
				gal::console::backend::python> console_type;
			typedef std::shared_ptr<neb::fnd::input::js> S_JS;
			typedef std::shared_ptr<neb::fnd::app::Base> S_A;
			typedef neb::fnd::app::util::flag FLAG;
			static S_A			global();
			static S_A			s_init(int ac, char ** av);
			Base();
			virtual ~Base();
			gal::math::pose			getPose() const;
			gal::math::pose			getPoseGlobal() const;
			void				release();
			virtual void			step(gal::etc::timestep const & ts);
			void				preloop();
			void				loop();
			void				set_should_release();
			S_JS				get_joystick(int i = -1);
			static bool			is_valid();
			virtual window_w		createWindow();
			virtual std::weak_ptr<neb::fnd::gui::layout::Base>	createLayout(
					std::shared_ptr<neb::fnd::window::Base> window,
					std::shared_ptr<neb::fnd::environ::Base> environ);
			std::weak_ptr<neb::fnd::game::game::base>		createGame();
			std::weak_ptr<neb::fnd::game::game::base>		createGame(
					neb::fnd::game::game::desc const &);
		public:
			void				open_graphics_plugin(std::string filename);
			void				open_physics_plugin(std::string filename);
			void				open_network_plugin(std::string filename);
			std::shared_ptr<H>		get_graphics_plugin();
			std::shared_ptr<H>		get_physics_plugin();
			std::shared_ptr<H>		get_network_plugin();
			boost::asio::io_service		ios_;
			FLAG				flag_;
			gal::etc::timestep				ts_;
			std::shared_ptr<console_type>			console_;
			std::vector<std::string>			_M_preloop_scripts_python;
			static std::shared_ptr<neb::fnd::app::Base>		g_app_;
			gal::argparse::Args					_M_args;
		protected:
			void			init_register_types();
			void			init_boost_asio();
			void			init_python();
			void			init(int ac, char ** av);
			void			render();
			void							initRegistry();
			void							read_config();
		private:
			std::shared_ptr<H>					_M_network_plugin;
			std::shared_ptr<H>					_M_physics_plugin;
			std::shared_ptr<H>					_M_graphics_plugin;
	};

}}}

#endif



