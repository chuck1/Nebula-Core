#ifndef NEBULA_CORE_LIGHT___BASE_HPP
#define NEBULA_CORE_LIGHT___BASE_HPP

#include <neb/core/itf/shared.hpp>

namespace neb { namespace core {
	
	class pose;

	namespace light {

	class __base: virtual public neb::itf::shared {
		public:
			virtual void		callbackPose(neb::core::pose const &) = 0;
	};

}}}

#endif
