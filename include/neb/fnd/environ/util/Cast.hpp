#ifndef NEB_FND_ENVIRON_UTIL_CAST_HPP
#define NEB_FND_ENVIRON_UTIL_CAST_HPP

#include <neb/fnd/itf/shared.hpp>

#include <neb/fnd/environ/util/decl.hpp>
//#include <neb/gfx/util/decl.hpp>

namespace neb { namespace fnd { namespace environ { namespace util {

	class Cast:
		virtual public neb::fnd::itf::shared
	{
		public:
			typedef neb::fnd::environ::Two TWO;
			typedef neb::fnd::environ::Three THREE;
			std::shared_ptr<TWO>		is_fnd_environ_two();
			std::shared_ptr<THREE>		is_fnd_environ_three();
	};

}}}}

#endif
