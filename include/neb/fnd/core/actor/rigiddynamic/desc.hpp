#ifndef NEB_CORE_CORE_ACTOR_RIGIDDYNAMIC_DESC_HPP
#define NEB_CORE_CORE_ACTOR_RIGIDDYNAMIC_DESC_HPP

#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include <gal/itf/shared.hpp>

#include <neb/fnd/math/pose.hpp>
#include <neb/fnd/core/shape/desc.hpp>
#include <neb/fnd/core/actor/rigidbody/desc.hpp>


namespace neb { namespace fnd { namespace core { namespace actor { namespace rigiddynamic {

	struct Desc: neb::fnd::core::actor::rigidbody::desc
	{
		Desc();
		Desc(neb::fnd::math::pose npose);

		template<class Archive> void		serialize(Archive & ar, unsigned int const & version)
		{
			BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::actor::rigidbody::desc);
		}

		virtual std::shared_ptr<neb::fnd::core::actor::base>		visit(
				neb::fnd::core::scene::base * const scene
				) const;



	};

}}}}}


#endif

