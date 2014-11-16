#ifndef NEBULA_STATE_HPP
#define NEBULA_STATE_HPP

namespace neb { namespace core { namespace flow { namespace state {

	/** @brief Base.
	 * Construction and Destruction alters behavior of rendering and stepping, producing
	 * a temporary change in the state of the program. */
	class Base {
		public:
			virtual ~Base() {}
	};

}}}}

#endif


