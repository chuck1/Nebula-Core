#include <thread>

#include <gal/log/log.hpp>

#include <neb/core/debug.hh>
#include <neb/core/app/__base.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>

using namespace std;

shared_ptr<neb::core::app::__base>	neb::core::app::__base::g_app_;

shared_ptr<neb::core::app::__base>	neb::core::app::__base::global() {
	assert(g_app_);
	return g_app_;
}
void		neb::core::app::__base::__init() {

	if(DEBUG_NEB) LOG(lg, neb::core::sl, debug) << __FUNCSIG__;
	
	assert(!flag_.any(neb::core::app::util::flag::INIT___BASE));

	// boost asio ioservice
	if(DEBUG_NEB) LOG(lg, neb::core::sl, debug) << "launch ios thread";

	std::thread t([&](){
			boost::asio::io_service::work w(ios_);
			ios_.run();

			if(DEBUG_NEB) LOG(lg, neb::core::sl, debug) << "ios stopped";
			});
	t.detach();

	// console
	console_.reset(new console_type);
	console_->init();
	try {
		console_->main_namespace_["neb"] = boost::python::import("libnebula_python");
	} catch(bp::error_already_set const &) {
		std::cout << "unhandled execption\n";
		// print all other errors to stderr
		PyErr_Print();
	}
	flag_.set(neb::core::app::util::flag::INIT___BASE);

	/** @todo export class to python to implement exit() */
}

