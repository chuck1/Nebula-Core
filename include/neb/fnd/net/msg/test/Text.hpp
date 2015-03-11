#ifndef __GLUTPP_NETWORK_MSG_TEST_TEXT_H__
#define __GLUTPP_NETWORK_MSG_TEST_TEXT_H__

#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <neb/fnd/net/msg/Base.hpp>

namespace neb { namespace fnd { namespace net { namespace msg { namespace test {
	class Text:
		virtual public neb::fnd::net::msg::Base
	{
		public:
			virtual void		load(
					boost::archive::polymorphic_iarchive & ar,
					unsigned int const & version);	
			virtual void		save(
					boost::archive::polymorphic_oarchive & ar,
					unsigned int const & version) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
			std::string		_M_text;
	};
}}}}}

#endif


