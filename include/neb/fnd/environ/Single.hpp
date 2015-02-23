#ifndef NEB_FND_ENVIRON_SINGLE_HPP
#define NEB_FND_ENVIRON_SINGLE_HPP

namespace neb { namespace fnd { namespace environ {
	/***/
	template<typename VIEW> class single:
		virtual public neb::fnd::environ::base
	{
		public:
			std::shared_ptr<VIEW>		view_;
	};
	/***/
	template<typename VIEW> class multiple:
		virtual public neb::fnd::environ::base
	{
		public:
			std::shared_ptr<VIEW>		view_[6];
	};
}}}

#endif
