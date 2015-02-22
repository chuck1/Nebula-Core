#ifndef NEB_CORE_ENVIRON_SHADOW_BASE_HPP
#define NEB_CORE_ENVIRON_SHADOW_BASE_HPP

#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/core/light/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>

namespace neb { namespace fnd { namespace environ { namespace shadow {
	class Base:
		virtual public neb::fnd::environ::Base
	{
		public:
			virtual void		setLight(std::shared_ptr<neb::fnd::core::light::base> light);
			virtual void		setSceneEnviron(std::shared_ptr<neb::fnd::environ::Base> environ);
	};
}}}}

#endif

