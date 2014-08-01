#ifndef __NEBULA_APP___BASE_H__
#define __NEBULA_APP___BASE_H__

#include <boost/asio/io_service.hpp>

#include <gal/std/timestep.hpp>

#include <neb/core/app/util/Flag.hh>

namespace gal { namespace console {
class command_set;
}}

namespace neb { namespace core {
	namespace app {
		/** @brief %base */
		class __base {
			public:
				virtual void					init();
				
				static ::std::shared_ptr<neb::app::__base>	global();
			public:
				boost::asio::io_service				ios_;

				neb::app::util::flag				flag_;

				static ::std::shared_ptr<neb::app::__base>	g_app_;

				gal::std::timestep				ts_;

				::std::shared_ptr<gal::console::command_set>	command_set_;

		};
	}
}}

#endif



