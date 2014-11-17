#include <neb/core/game/map/base.hpp>

typedef neb::core::game::map::base THIS;

THIS::base()
{}
void		THIS::init(parent_t * const & p)
{

	/** @todo move to createSpawn() */
	auto spawn(std::make_shared<nc::game::spawn::base>());

	nc::game::spawn::util::parent::insert(spawn);

}
void		THIS::release()
{
	nc::game::spawn::util::parent::clear();
}

