#ifndef NEBULA_CORE_CORE_ACTOR_UTIL_CAST_HH
#define NEBULA_CORE_CORE_ACTOR_UTIL_CAST_HH

#include <gal/itf/shared.hpp>

#include <neb/core/core/actor/util/decl.hpp>

namespace neb { namespace core { namespace core { namespace actor { namespace util {
	class Cast:
		virtual public gal::itf::shared
	{
		public:
			std::shared_ptr<neb::core::core::actor::base>			is_fnd_actor_base();
	};
}}}}}

#endif

