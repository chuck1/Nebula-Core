
#include <neb/core/core/actor/base.hpp>
#include <neb/core/core/shape/base.hpp>
#include <neb/core/core/light/base.hpp>
#include <neb/core/core/light/util/parent.hpp>

bool							neb::core::core::light::util::parent::hasScene()
{
	auto shape = isShapeBase();
	assert(shape);
	
	if(!shape->hasParent()) return false;

	auto parent = shape->getParent();
	
	auto actor = parent->isActorBase();
	if(actor) return actor->getScene();
	
	abort();
	return std::weak_ptr<neb::core::core::scene::base>();
}

std::weak_ptr<neb::core::core::scene::base>		neb::core::core::light::util::parent::getScene() {
	auto shape = isShapeBase();
	assert(shape);
	
	auto parent = shape->getParent();
	
	auto actor = parent->isActorBase();
	if(actor) return actor->getScene();

	abort();
	return std::weak_ptr<neb::core::core::scene::base>();
}
void							neb::core::core::light::util::parent::callbackPose(neb::core::pose const & parent_gpose) {
	
	auto lamb = [&] (map_type::pointer p) {
		//auto shape = std::dynamic_pointer_cast<neb::core::core::shape::base>(p);
		//assert(shape);
		
		auto light = std::static_pointer_cast<neb::core::core::light::base>(p);

		auto gpose = parent_gpose * light->pose_;

		light->callbackPose(gpose);
	};
	
	map_.for_each(lamb);
}


