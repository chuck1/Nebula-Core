#include <neb/fnd/app/Base.hpp>

#include <neb/fnd/plug/net/server/Base.hpp>

#include <neb/fnd/net/server/Base.hpp>

typedef neb::fnd::net::server::Base THIS;

void	THIS::init(parent_t * const & parent)
{
	setParent(parent);
	
	auto app = get_fnd_app();
	
	if(app->N::has_object())
		if(!N::has_object())
			N::make_object<THIS, int>(
					app->get_network_plugin(),
					0);
}
void	THIS::release()
{
	N::reset();
}

