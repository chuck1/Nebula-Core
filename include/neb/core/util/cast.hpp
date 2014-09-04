#ifndef NEB_CORE_UTIL_CAST_HPP
#define NEB_CORE_UTIL_CAST_HPP

namespace neb {

	template<typename T, typename U> U*	cast(std::shared_ptr<T> const & t)
	{
#if defined _DEBUG
		U* u = dynamic_cast<U*>(t.get());

		assert(u);
#elif defined NDEBUG
		U* u = static_cast<U*>(t.get());
#endif
		return u;
	}

#endif

