#ifndef NEB_CORE_CONTEXT_UTIL_CAST_HPP
#define NEB_CORE_CONTEXT_UTIL_CAST_HPP

#include <neb/core/itf/shared.hpp>
#include <neb/core/context/util/decl.hpp>

#include <neb/gfx/util/decl.hpp>

namespace neb { namespace core { namespace context { namespace util {
	/** @brief %Cast
	 */
	class Cast:
		virtual public neb::core::itf::shared
	{
		public:
			std::shared_ptr<neb::core::context::Base>			is_fnd_context_Base();
			std::shared_ptr<neb::core::context::Window>			is_fnd_context_Window();
			std::shared_ptr<neb::core::context::FBO>			is_fnd_context_FBO();
			std::shared_ptr<neb::core::context::FBOM>			is_fnd_context_FBOM();
	};
}}}}

#endif
