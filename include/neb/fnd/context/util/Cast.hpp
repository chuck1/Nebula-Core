#ifndef NEB_CORE_CONTEXT_UTIL_CAST_HPP
#define NEB_CORE_CONTEXT_UTIL_CAST_HPP

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/context/util/decl.hpp>

namespace neb { namespace fnd { namespace context { namespace util {
	/** @brief %Cast
	 */
	class Cast:
		virtual public neb::fnd::itf::shared
	{
		public:
			std::shared_ptr<neb::fnd::context::Base>			is_fnd_context_Base();
			std::shared_ptr<neb::fnd::context::Window>			is_fnd_context_Window();
			std::shared_ptr<neb::fnd::context::FBO>			is_fnd_context_FBO();
			std::shared_ptr<neb::fnd::context::FBOM>			is_fnd_context_FBOM();
	};
}}}}

#endif
