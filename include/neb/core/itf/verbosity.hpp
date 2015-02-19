#ifndef NEB_CORE_ITF_VERBOSITY_HPP
#define NEB_CORE_ITF_VERBOSITY_HPP

#include <gal/log/log.hpp>

namespace neb { namespace fnd { namespace itf {
	/**/
	class verbosity
	{
	protected:
		verbosity();
		template<typename... A>
		void			printv(
				int sev,
				const char * format, A... a)
		{
			if(sev >= _M_severity_level) printf(format, a...);
		}
	public:
		static int		_M_severity_level;
	};
}}}

#endif
