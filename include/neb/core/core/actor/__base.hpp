#ifndef NEBULA_ACTOR___BASE_HPP
#define NEBULA_ACTOR___BASE_HPP

#include <boost/thread.hpp>

#include <neb/core/itf/shared.hpp>
#include <neb/core/itf/serializable.hpp>


namespace neb {

	namespace core { namespace core { namespace actor { namespace util {
		class parent;
	}}}}


	namespace actor {
		class __base:
			virtual public neb::itf::shared,
			virtual public neb::serializable
		{
			public:
				virtual void		init(neb::core::core::actor::util::parent * const & p) = 0;
		};
	}
}

#endif
