#include <neb/core/context/util/Cast.hpp>
#include <neb/core/context/Base.hpp>
#include <neb/core/context/Window.hpp>
#include <neb/core/context/FBO.hpp>
#include <neb/core/context/FBOM.hpp>

typedef neb::core::context::util::Cast THIS;

std::shared_ptr<neb::core::context::Base>			THIS::is_fnd_context_Base()
{
	auto c = std::dynamic_pointer_cast<neb::core::context::Base>(shared_from_this());
	return c;
}
std::shared_ptr<neb::core::context::Window>			THIS::is_fnd_context_Window()
{
	auto c = std::dynamic_pointer_cast<neb::core::context::Window>(shared_from_this());
	return c;
}
std::shared_ptr<neb::core::context::FBO>			THIS::is_fnd_context_FBO()
{
	auto c = std::dynamic_pointer_cast<neb::core::context::FBO>(shared_from_this());
	return c;
}
std::shared_ptr<neb::core::context::FBOM>			THIS::is_fnd_context_FBOM()
{
	auto c = std::dynamic_pointer_cast<neb::core::context::FBOM>(shared_from_this());
	return c;
}

