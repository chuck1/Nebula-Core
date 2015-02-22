#ifndef NEBULA_CORE_CORE_ACTOR_UTIL_CAST_HH
#define NEBULA_CORE_CORE_ACTOR_UTIL_CAST_HH

#include <gal/itf/shared.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace util {
	class Cast:
		virtual public gal::itf::shared
	{
		public:
			std::shared_ptr<neb::fnd::core::actor::base>			is_fnd_actor_base();
			std::shared_ptr<neb::fnd::core::actor::rigidactor::base>	is_fnd_actor_rigidactor_base();
	};
}}}}}

#endif

