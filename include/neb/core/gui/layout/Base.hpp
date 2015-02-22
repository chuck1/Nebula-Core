#ifndef NEB_CORE_GUI_LAYOUT_BASE_HPP
#define NEB_CORE_GUI_LAYOUT_BASE_HPP

#include <neb/core/itf/shared.hpp>

namespace neb { namespace fnd { namespace gui { namespace layout {
	class Base:
		virtual public neb::fnd::itf::shared
	{
		public:
			virtual ~Base();
			void		connect(std::shared_ptr<neb::fnd::input::source> const & src);
	};
}}}}

#endif
