#ifndef NEB_FND_ENVIRON_SINGLE_HPP
#define NEB_FND_ENVIRON_SINGLE_HPP

#include <neb/fnd/environ/Base.hpp>

namespace neb { namespace fnd { namespace environ {
	/***/
	template<typename VIEW>
	class single:
		virtual public neb::fnd::environ::Base
	{
	public:
		typedef std::shared_ptr<neb::fnd::camera::view::Base> V;
		virtual V				get_view(int i = 0)
		{
			return view_;
		}
		std::shared_ptr<VIEW>			view_;
	};
	/***/
	template<typename VIEW>
	class multiple:
		virtual public neb::fnd::environ::Base
	{
	public:
		typedef std::shared_ptr<neb::fnd::camera::view::Base> V;
		virtual V				get_view(int i = 0)
		{
			return view_[i];
		}
		std::shared_ptr<VIEW>			view_[6];
	};
}}}

#endif
