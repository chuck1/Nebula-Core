#ifndef NEBULA_ACTOR_UTIL_CAST_HH
#define NEBULA_ACTOR_UTIL_CAST_HH

#include <gal/std/shared.hpp>

#include <neb/core/core/actor/util/Types.hh>

using namespace std;

namespace neb {
	namespace core {
		namespace actor {
			namespace util {
				class cast: virtual public gal::std::shared {
					public:
						shared_ptr<neb::core::actor::base>				isActorBase();
				};
			}
		}
	}
}

#endif

