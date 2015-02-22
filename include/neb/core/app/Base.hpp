#ifndef __NEBULA_APP___BASE_H__
#define __NEBULA_APP___BASE_H__

#include <boost/asio/io_service.hpp>

#include <gal/etc/timestep.hpp>

#include <gal/console/console.hpp>

#include <neb/core/util/decl.hpp>
#include <neb/core/app/util/Flag.hh>
#include <neb/core/context/util/decl.hpp>
#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/core/scene/util/parent.hpp>
#include <neb/core/game/game/util/parent.hpp>
#include <neb/core/game/game/util/decl.hpp>
#include <neb/core/glsl/program/util/decl.hpp>
#include <neb/core/window/util/Parent.hpp>
#include <neb/core/timer/util/Parent.hpp>

#include <neb/core/plug/gfx/util/decl.hpp>

namespace neb { namespace fnd { namespace app {
	/** @brief %base */
	class Base:
		virtual public neb::fnd::core::scene::util::parent,
		virtual public neb::fnd::game::game::util::parent,
		virtual public neb::fnd::window::util::Parent,
		virtual public neb::fnd::timer::util::Parent
	{
		public:
			typedef gal::console::temp<
				gal::console::frontend::store,
				gal::console::backend::python> console_type;
			/***/
			virtual ~Base();
			/***/
			neb::fnd::math::pose					getPose() const;
			/***/
			neb::fnd::math::pose					getPoseGlobal() const;
			/***/
			std::weak_ptr<neb::fnd::game::game::base>		createGame();
			/***/
			std::weak_ptr<neb::fnd::game::game::base>		createGame(
					neb::fnd::game::game::desc const &
					);
		protected:
			//virtual void						init();
		protected:
			void							__init();
			void							__release();
			void							__step(gal::etc::timestep const &);
			void							render();
		public:
			/***/
			static bool						is_valid();
			/***/
			virtual std::weak_ptr<neb::fnd::window::Base>		createWindow() = 0;
			/***/
			virtual std::weak_ptr<neb::fnd::gui::layout::Base>	createLayout(
					std::shared_ptr<neb::fnd::window::Base> window,
					std::shared_ptr<neb::fnd::context::Base> context) = 0;
			/***/
			virtual std::weak_ptr<neb::fnd::core::scene::base>	createScene() = 0;
			/***/
			virtual std::weak_ptr<neb::fnd::core::scene::base>	createSceneDLL(std::string) = 0;
			/***/
			//virtual std::shared_ptr<neb::fnd::glsl::program::Base>		get_program_text() = 0;
			//virtual std::shared_ptr<neb::fnd::glsl::program::Base>		get_program_tex() = 0;
			//virtual std::shared_ptr<neb::fnd::glsl::program::Base>		get_program_simple3() = 0;
			/***/
			void							open_graphics_plugin(std::string filename);
			/***/
			void							open_network_plugin(std::string filename);
			/***/
			boost::asio::io_service					ios_;
			/***/
			neb::fnd::app::util::flag				flag_;
			/***/
			gal::etc::timestep					ts_;
			/***/
			std::shared_ptr<console_type>				console_;
			/***/
			std::vector< std::string >				_M_preloop_scripts_python;
			/***/
			static std::shared_ptr<neb::fnd::app::Base>		g_app_;
			typedef gal::dll::helper<gal::itf::shared> H;
			/*
			 * shared library helper for networking plugin
			 */
			std::shared_ptr<H>					_M_network_plugin;
			/*
			 * shared library helper for physics plugin
			 */
			std::shared_ptr<H>					_M_physics_plugin;
			/*
			 * shared library helper for graphics plugin
			 */
			std::shared_ptr<H>					_M_graphics_plugin;
			std::shared_ptr<neb::fnd::plug::gfx::app::Base>		_M_graphics_object;
	};

}}}

#endif



