#include <neb/fnd/app/Base.hpp>

#include <neb/fnd/plug/net/server/Base.hpp>

#include <neb/fnd/net/server/Base.hpp>

typedef neb::fnd::net::server::Base THIS;

void	THIS::init(parent_t * const & parent)
{
	printv_func(DEBUG);
	
	setParent(parent);

	neb::fnd::net::comm::util::Parent::init(parent);

	//auto app = get_fnd_app();
	
	/*
	if(app->N::has_object())
		if(!N::has_object())
			N::make_object<THIS, int>(
					app->get_network_plugin(),
					0);
					*/
}
void	THIS::release()
{
	printv_func(DEBUG);
	//N::reset();
	neb::fnd::net::comm::util::Parent::clear();
}
std::shared_ptr<THIS::COMM>	THIS::create_communicating()
{
	printv_func(DEBUG);

	auto app = get_fnd_app();

	auto h = app->get_network_plugin();

	std::shared_ptr<THIS::COMM> c = h->template make_shared<COMM, int>(0);
	
	return c;
}

