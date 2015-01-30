#ifndef NEBULA_CORE_ENVIRON_NORMAL_MAP_HPP
#define NEBULA_CORE_ENVIRON_NORMAL_MAP_HPP

#include <neb/core/environ/Base.hpp>

namespace neb { namespace core { namespace environ { namespace visualization {
	/** @brief Normal
	 */
	class Normal:
		virtual public neb::core::environ::Base
	{
		public:
			typedef std::shared_ptr<neb::gfx::glsl::program::base>		program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::base>		proj_shared;
		public:
			//virtual void		init();
			//virtual void		step(gal::etc::timestep const & ts);
	};
}}}}

#endif
