#include <thread>

#include <gal/log/log.hpp>

#include <gal/console/backend/command_set.hpp>
#include <gal/console/backend/command.hpp>

#include <neb/core/debug.hh>
#include <neb/core/app/__base.hpp>

void		neb::core::app::__base::init() {
	
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

	// command set
	
	command_set_ = ::std::make_shared<gal::console::command_set>();

	command_set_->init();	
	
	// exit command
	
	auto cmd_exit = ::std::make_shared<gal::console::command>();

	cmd_exit->func_ = [&] (::std::shared_ptr<gal::console::base> term, bpo::variables_map vm) {
		auto app = neb::core::app::__base::global();
		app->flag_.set(neb::core::app::util::flag::SHOULD_RELEASE);
	};

	command_set_->map_["exit"] = cmd_exit;
	
	

}

