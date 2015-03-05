#ifndef NEBULA_MESSAGE_BASE_HPP
#define NEBULA_MESSAGE_BASE_HPP

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

#include <gal/net/message.hpp>

#include <neb/fnd/itf/shared.hpp>

#include <neb/fnd/net/message/util/decl.hpp>

namespace neb { namespace net { namespace msg {
	/** \brief %Base
	 */
	class Base:
		virtual public neb::fnd::itf::shared
	{
	protected:
		Base();
	public:
		virtual ~Base();
		virtual void			load(
				boost::archive::polymorphic_iarchive & ar,
				unsigned int const & version) = 0;	
		virtual void			save(
				boost::archive::polymorphic_oarchive & ar,
				unsigned int const & version) = 0;
		BOOST_SERIALIZATION_SPLIT_MEMBER();
		std::shared_ptr<gal::net::message>	msg_;
	};
}}}

#endif

/** \example Nebula/message/example.cc
 * Example.
 */


