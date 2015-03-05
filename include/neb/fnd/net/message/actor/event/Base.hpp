#ifndef __GLUTPP_NETWORK_ACTOR_EVENT_H__
#define __GLUTPP_NETWORK_ACTOR_EVENT_H__

#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

/*
#include <neb/config.hh> // gru/config.hpp.in
#include <neb/master.hh>
#include <neb/scene/desc.hh>
#include <neb/actor/desc.hh>
#include <neb/actor/addr.hh>
#include <neb/actor/event.hh>
#include <neb/actor/raw_factory.hh>
#include <neb/actor/actor.hh>
*/

#include <gal/stl/wrapper.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

#include <neb/fnd/net/message/actor/Base.hpp>

namespace neb { namespace net { namespace msg { namespace actor { namespace Event {
	/** @brief %Base */
	class Base:
		virtual public neb::net::msg::actor::Base
	{
		public:
	};
}}}}}


#endif



