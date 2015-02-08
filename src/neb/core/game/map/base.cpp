#include <neb/core/game/map/base.hpp>

typedef neb::fnd::game::map::base THIS;

THIS::base()
{}
void		THIS::init(parent_t * const & p)
{

	/** @todo move to createSpawn() */
	auto spawn(std::make_shared<neb::fnd::game::spawn::base>());

	neb::fnd::game::spawn::util::parent::insert(spawn);

}
void		THIS::release()
{
	neb::fnd::game::spawn::util::parent::clear();
}

