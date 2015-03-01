#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::context::Base THIS;

void			THIS::render()
{
	//if(G::has_object())
	G::get_object()->render();
}
void			THIS::step(gal::etc::timestep const & ts)
{
}
void			THIS::resize(int w, int h)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	
	typedef neb::fnd::environ::util::Parent E;

	auto lamb = [&] (E::map_type::pointer p)
	{
		p->resize(w, h);
	};
	
	E::map_.for_each(lamb);

}

