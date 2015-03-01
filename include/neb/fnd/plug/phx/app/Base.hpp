#ifndef NEB_FND_PLUG_PHX_APP_BASE_HPP
#define NEB_FND_PLUG_PHX_APP_BASE_HPP

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/math/color/color.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace phx { namespace app {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::phx::app::Base,
				neb::fnd::app::Base>
	{
		public:
			virtual void		init(parent_t * const & p) = 0;
	};
}}}}}

#endif
