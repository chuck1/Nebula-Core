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

namespace neb { namespace core { namespace app {
	/** @brief %base */
	class base:
		virtual public neb::core::core::scene::util::parent,
		virtual public neb::core::game::game::util::parent
	{
		public:
			typedef gal::console::temp<
				gal::console::frontend::store,
				gal::console::backend::python> console_type;
			/***/
			virtual ~base();
			/***/
			neb::core::math::pose					getPose() const;
			/***/
			neb::core::math::pose					getPoseGlobal() const;
			/***/
			std::shared_ptr<neb::core::game::game::base>		createGame(
					neb::core::game::game::desc const &
					);
		protected:
			//virtual void						init();
		protected:
			void							__init();
			void							__release();
			void							__step(gal::etc::timestep const &);
		public:
			/***/
			static std::shared_ptr<neb::core::app::base>		global();
			/***/
			static bool						is_valid();
			/***/
			virtual std::weak_ptr<neb::core::window::Base>		createWindow() = 0;
			/***/
			virtual std::weak_ptr<neb::core::gui::layout::Base>	createLayout(
					std::shared_ptr<neb::core::window::Base> window,
					std::shared_ptr<neb::core::context::Base> context) = 0;
			/***/
			virtual std::weak_ptr<neb::core::core::scene::base>	createScene() = 0;
			/***/
			virtual std::weak_ptr<neb::core::core::scene::base>	createSceneDLL(std::string) = 0;
			/***/
			boost::asio::io_service					ios_;
			/***/
			neb::core::app::util::flag				flag_;
			/***/
			gal::etc::timestep					ts_;
			/***/
			std::shared_ptr<console_type>				console_;
			/***/
			std::vector< std::string >				_M_preloop_scripts_python;
			/***/
			static std::shared_ptr<neb::core::app::base>		g_app_;
	};

}}}

#endif



