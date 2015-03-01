#ifndef NEB_FND_PLUG_PHX_CORE_ACTOR_BASE_HPP
#define NEB_FND_PLUG_PHX_CORE_ACTOR_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/net/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>
#include <gal/math/pose.hpp>

namespace neb { namespace fnd { namespace plug { namespace phx { namespace core { namespace actor {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::core::actor::base>
	{
		public:
			typedef neb::fnd::core::actor::base FND;
			virtual void			init(parent_t * const & p) = 0;
	};
}}}}}}


#endif
