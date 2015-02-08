#ifndef NEB_CORE_ITF_VERBOSITY_HPP
#define NEB_CORE_ITF_VERBOSITY_HPP

#include <gal/log/log.hpp>

namespace neb { namespace fnd { namespace itf {
	/**/
	class verbosity
	{
	protected:
		verbosity(): severity_level_(warning) {}
		template<typename... A> void	printv(int sev,
				const char * format, A... a)
		{
			if(sev >= severity_level_) printf(format, a...);
		}
		int				severity_level_;
	};
}}}

#endif
