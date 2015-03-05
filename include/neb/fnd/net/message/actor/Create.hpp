#ifndef __GLUTPP_NETWORK_ACTOR_CREATE_H__
#define __GLUTPP_NETWORK_ACTOR_CREATE_H__

#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

#include <neb/fnd/net/message/actor/event/Base.hpp>

namespace neb { namespace net { namespace msg { namespace actor {
	class Create
	{
		public:
			void				load(std::shared_ptr<neb::fnd::core::actor::base> actor);

			template<class Archive> void	serialize(Archive & ar, unsigned int const & version) {
				ar & parent_i_;
				ar & i_;
				ar & wrapper_;
			}
		public:
			/** @brief parent index
			 *
			 * index of new object's parent
			 */
			gal::itf::index_type				parent_i_;
			/** @brief index
			 *
			 * index of new object
			 */
			gal::itf::index_type				i_;
			/** @brief Wrapper.
			 * wrapper to create the actor object
			 */
			gal::stl::wrapper<neb::fnd::core::actor::base>		wrapper_;
	};
}}}}




#endif


