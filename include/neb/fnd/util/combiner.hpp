#ifndef NEBULA_UTIL_COMBINER_HPP
#define NEBULA_UTIL_COMBINER_HPP

#include <gal/stl/verbosity.hpp>

namespace neb { namespace util {
	class combiner:
		public gal::tmp::Verbosity<neb::util::combiner>
	{
	public:
		typedef int result_type;	
		template<typename InputIterator>
		result_type		operator()(InputIterator first, InputIterator last) const
		{
			static const char * func = "combiner::operator()";

			printv(DEBUG, "%s\n", func);

			result_type f;
			
			while (first != last) {
				printv(DEBUG, "%s first\n", func);
				f = *first;
				
				printv(DEBUG, "%s *first = %i\n", func, f);
				
				if(f) break;

				printv(DEBUG, "%s inc\n", func);
				++first;
			}

			return 0;
		}
	};

}}

#endif



