
//#include <neb/app/Base.hh>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/net/message/scene/Create.hpp>

typedef neb::net::msg::scene::Create THIS;

THIS::Create()
{
}
void			THIS::load(std::shared_ptr<neb::fnd::core::scene::base> scene)
{
	scene_.ptr_ = scene;
}



