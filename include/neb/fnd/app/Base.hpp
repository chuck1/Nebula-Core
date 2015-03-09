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

#include <neb/fnd/net/server/util/Parent.hpp>
#include <neb/fnd/net/client/util/Parent.hpp>

#include <neb/fnd/game/game/util/parent.hpp>
#include <neb/fnd/game/game/util/decl.hpp>
#include <neb/fnd/gui/layout/util/Parent.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/window/util/Parent.hpp>
#include <neb/fnd/timer/util/Parent.hpp>

#include <neb/fnd/plug/ObjectParent.hpp>
#include <neb/fnd/plug/gfx/util/decl.hpp>
#include <neb/fnd/plug/phx/util/decl.hpp>
#include <neb/fnd/plug/net/util/decl.hpp>

namespace neb { namespace fnd { namespace app {
	/** @brief %base */
	class Base:
		public gal::tmp::VerbosityRegister,
		public gal::tmp::Verbosity<neb::fnd::app::Base>,
		virtual public neb::fnd::app::Base10,
		virtual public gal::itf::registry,
		virtual public neb::fnd::net::server::util::Parent,
		virtual public neb::fnd::net::client::util::Parent,
		virtual public neb::fnd::game::game::util::parent,
		virtual public neb::fnd::window::util::Parent,
		virtual public neb::fnd::timer::util::Parent,
		virtual public neb::fnd::gui::layout::util::Parent,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::app::Base>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::phx::app::Base>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::net::app::Base>
	{
		public:
			typedef std::weak_ptr<neb::fnd::window::Base> window_w;
			typedef std::weak_ptr<neb::fnd::core::scene::base> scene_w;
			using gal::tmp::Verbosity<neb::fnd::app::Base>::printv;
			typedef gal::dll::helper<gal::itf::shared> H;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::app::Base> G;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::phx::app::Base> P;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::net::app::Base> N;
			typedef gal::console::temp<
				gal::console::frontend::store,
				gal::console::backend::python> console_type;
			typedef std::shared_ptr<neb::fnd::input::js>		S_JS;
			typedef std::shared_ptr<neb::fnd::app::Base>		S_A;
			typedef std::weak_ptr<neb::fnd::gui::layout::Base>	W_L;
			typedef neb::fnd::app::util::flag			FLAG;
			typedef std::weak_ptr<neb::fnd::game::game::base>	W_G;
			typedef std::weak_ptr<neb::fnd::net::server::Base>	W_SRV;
			typedef std::weak_ptr<neb::fnd::net::client::Base>	W_CLI;
			typedef std::shared_ptr<boost::asio::io_service>	S_IOS;
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
			W_SRV				create_server(int portno);
			W_CLI				create_client(
					std::string ip,
					int portno);
			virtual window_w		createWindow();
			virtual W_L			createLayout(
					std::shared_ptr<neb::fnd::window::Base> window,
					std::shared_ptr<neb::fnd::environ::Base> environ);
			W_G				createGame();
			W_G				createGame(
					neb::fnd::game::game::desc const &);
		public:
			void				open_graphics_plugin(std::string filename);
			void				open_physics_plugin(std::string filename);
			void				open_network_plugin(std::string filename);
			std::shared_ptr<H>		get_graphics_plugin();
			std::shared_ptr<H>		get_physics_plugin();
			std::shared_ptr<H>		get_network_plugin();
		protected:
			void				init_register_types();
			void				init_boost_asio();
			void				init_python();
			void				initRegistry();
			void				init(int ac, char ** av);
			void				read_config();
			void				render();
		public:
			std::vector<std::string>	get_preloop_scripts_python();
		//private:
			static S_A			_G_app;
			S_IOS				_M_ios;
			FLAG				_M_flag;
			gal::etc::timestep		_M_ts;
			std::shared_ptr<console_type>	_M_console;
			std::vector<std::string>	_M_preloop_scripts_python;
			gal::argparse::Args		_M_args;
			std::shared_ptr<H>		_M_network_plugin;
			std::shared_ptr<H>		_M_physics_plugin;
			std::shared_ptr<H>		_M_graphics_plugin;
	};

}}}

#endif



