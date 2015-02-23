#ifndef NEBULA_CORE_ENVIRON_VIS_DEPTH_HPP
#define NEBULA_CORE_ENVIRON_VIS_DEPTH_HPP

#include <neb/fnd/environ/Single.hpp>

namespace neb { namespace fnd { namespace environ { namespace visualization {
	/** @brief base
	 */
	class Depth:
		virtual public neb::fnd::environ::single<neb::fnd::camera::view::Base>
	{
	};
}}}}

#endif
