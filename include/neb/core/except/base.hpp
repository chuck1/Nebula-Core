#ifndef NEB_CORE_UTIL_EXCEPTION_HPP
#define NEB_CORE_UTIL_EXCEPTION_HPP

#include <exception>

namespace neb { namespace core { namespace except {
	class NotImplemented: public std::exception
	{
		public:
			virtual const char *	what() const noexcept
			{
				return "Nebula: Not Implemented";
			}
	};
}}}

#endif
