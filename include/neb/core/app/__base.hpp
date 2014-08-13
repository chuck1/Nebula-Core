#ifndef __NEBULA_APP___BASE_H__
#define __NEBULA_APP___BASE_H__

#include <boost/asio/io_service.hpp>

#include <gal/std/timestep.hpp>

#include <neb/core/app/util/Flag.hh>

namespace neb {
	namespace core {
		namespace app {
			/** @brief %base */
			class __base {
				public:
					virtual ~__base() {};
				protected:
					void							__init();
				public:
					static ::std::shared_ptr<neb::core::app::__base>	global();
				public:
					boost::asio::io_service					ios_;
					neb::core::app::util::flag				flag_;
					static ::std::shared_ptr<neb::core::app::__base>	g_app_;
					gal::std::timestep					ts_;
			};
		}
	}
}

#endif



