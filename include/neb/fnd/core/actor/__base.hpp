#ifndef NEBULA_ACTOR___BASE_HPP
#define NEBULA_ACTOR___BASE_HPP

#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/tmp/Child.hpp>

namespace neb { namespace fnd { namespace core { namespace actor {
	class __base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::core::actor::util::parent>
	{
		public:
			virtual void				init(parent_t * const &) = 0;
	};
}}}}

#endif
