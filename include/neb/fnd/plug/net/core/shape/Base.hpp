#ifndef NEB_FND_PLUG_PHX_CORE_SHAPE_BASE_HPP
#define NEB_FND_PLUG_PHX_CORE_SHAPE_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/net/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/core/shape/util/decl.hpp>
#include <gal/math/pose.hpp>

namespace neb { namespace fnd { namespace plug { namespace phx { namespace core { namespace shape {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::core::shape::base>
	{
		public:
			typedef neb::fnd::core::shape::base FND;
			virtual void			init(parent_t * const & p) = 0;
	};
}}}}}}


#endif
