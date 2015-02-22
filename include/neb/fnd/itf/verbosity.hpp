#ifndef NEB_CORE_ITF_VERBOSITY_HPP
#define NEB_CORE_ITF_VERBOSITY_HPP

#include <gal/log/log.hpp>

namespace neb { namespace fnd { namespace itf {
	/*
	 * the CRTP is used to dsambiguate multiple inheritances of this class
	 */
	template<typename T>
	class verbosity
	{
	protected:
		verbosity()
		{
		}
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

template<typename T> int neb::fnd::itf::verbosity<T>::_M_severity_level = 1;

#endif
