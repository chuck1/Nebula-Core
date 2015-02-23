#ifndef NEBULA_CORE_ENVIRON_TWO_HPP
#define NEBULA_CORE_ENVIRON_TWO_HPP

#include <neb/fnd/environ/Single.hpp>

namespace neb { namespace fnd { namespace environ {
	/** @brief base
	 *
	 * Abstract class that contains functions and data needed to render a specific kind of drawable
	 */
	class Two:
		virtual public neb::fnd::environ::single<neb::fnd::camera::view::Base>
	{
		public:
			//virtual void		render(std::shared_ptr<neb::gfx::context::base> context) = 0;
			//std::shared_ptr<neb::gfx::drawable::two>		drawable_;
	};
}}}

#endif
