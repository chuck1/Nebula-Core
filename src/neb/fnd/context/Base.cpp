#include <neb/fnd/context/util/Parent.hpp>
#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::context::Base THIS;

void			THIS::init(parent_t * const & parent)
{
	setParent(parent);
	
	neb::fnd::environ::util::Parent::init(parent);
}
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

	auto lamb = [&] (E::S const & s)
	{
		s->resize(w, h);
	};
	
	E::for_each(lamb);

}

