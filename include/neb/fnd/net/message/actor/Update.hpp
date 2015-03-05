#ifndef __GLUTPP_NETWORK_ACTOR_UPDATE_HPP__
#define __GLUTPP_NETWORK_ACTOR_UPDATE_HPP__

#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <neb/fnd/core/scene/util/decl.hpp>

//#include <neb/config.hh> // gru/config.hpp.in
//#include <neb/master.hh>
//#include <neb/core/scene/desc.hh>
//#include <neb/core/actor/desc.hh>
//#include <neb/core/actor/event.hh>
#include <neb/fnd/core/actor/util/decl.hpp>

//#include <neb/core/scene/Base.hh>

#include <neb/fnd/net/message/actor/Base.hpp>

namespace neb { namespace net { namespace msg { namespace actor {
	struct Update:
		virtual public neb::net::msg::actor::Base
	{	
		Update();
		Update&		operator<<(std::shared_ptr<neb::fnd::core::actor::base> actor);

		std::vector< std::shared_ptr<neb::fnd::core::actor::base> >	actors_;
		virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &);
		virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
		BOOST_SERIALIZATION_SPLIT_MEMBER();
	};
}}}}

#endif



