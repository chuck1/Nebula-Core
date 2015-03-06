#ifndef __NEBULA_APP___BASE_10_HPP
#define __NEBULA_APP___BASE_10_HPP

#include <gal/std/decl.hpp>

namespace neb { namespace fnd { namespace app {
	/** @brief %base */
	class Base10
	{
	public:
		typedef gal::dll::helper<gal::itf::shared> H;
		virtual std::shared_ptr<H>		get_graphics_plugin() = 0;
		virtual std::shared_ptr<H>		get_physics_plugin() = 0;
		virtual std::shared_ptr<H>		get_network_plugin() = 0;
	};
}}}

#endif
