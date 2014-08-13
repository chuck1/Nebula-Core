#include <thread>

#include <gal/log/log.hpp>

#include <neb/core/debug.hh>
#include <neb/core/app/__base.hpp>
#include <neb/core/util/config.hpp>

using namespace std;

shared_ptr<neb::core::app::__base>	neb::core::app::__base::g_app_;

void		neb::core::app::__base::__init() {
	
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb app", debug) << __FUNCSIG__;
	
	if (!flag_.any(neb::core::app::util::flag::INIT___BASE)) {
		if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb app", debug) << "launch ios thread";
	
		std::thread t([&](){
			boost::asio::io_service::work w(ios_);
			ios_.run();

			if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb app", debug) << "ios stopped";
			});
		t.detach();

		flag_.set(neb::core::app::util::flag::INIT___BASE);
	}

	/** @todo export class to python to implement exit() */
}

