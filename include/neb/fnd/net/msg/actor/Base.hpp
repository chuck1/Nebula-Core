#ifndef NEBULA_MESSAGE_ACTOR_BASE_HPP
#define NEBULA_MESSAGE_ACTOR_BASE_HPP

#include <neb/fnd/net/msg/Base.hpp>

namespace neb { namespace net { namespace msg { namespace actor {
	class Base:
		virtual public neb::fnd::net::msg::Base
	{
		public:
			/** @brief index
			 *
			 * index of actor
			 */
			gal::itf::index_type			index_;
		private:
			Base&			operator=(Base const &);
		public:
			virtual void		load(
					boost::archive::polymorphic_iarchive & ar,
					unsigned int const & version)
			{
				ar & index_;
			}
			virtual void		save(
					boost::archive::polymorphic_oarchive & ar,
					unsigned int const & version)
			{
				ar & index_;
			}
			BOOST_SERIALIZATION_SPLIT_MEMBER();
	};
}}}}

#endif

