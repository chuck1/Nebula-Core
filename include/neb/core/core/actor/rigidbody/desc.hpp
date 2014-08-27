#ifndef NEB_CORE_CORE_ACTOR_RIGIDBODY_DESC_HPP
#define NEB_CORE_CORE_ACTOR_RIGIDBODY_DESC_HPP

namespace neb { namespace core { namespace core { namespace actor { namespace rigidbody {

	struct desc {
		desc() {}
		desc(neb::core::pose pose):
			pose_(pose)
		{}

		neb::core::pose		pose_;
	};

}}}}}

#endif

