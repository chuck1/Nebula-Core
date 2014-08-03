#ifndef NEBULA_SHAPE_UTIL_FLAG_HH
#define NEBULA_SHAPE_UTIL_FLAG_HH

#include <gal/std/flag.hpp>

namespace neb { namespace core { namespace shape { namespace util {
	DEFINE_FLAG(Flag,
			((FOO)(1 << 0))
		   )
}}}}

#endif