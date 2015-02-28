#ifndef NEB_CORE_CORE_ACTOR_RIGIDBODY_DESC_HPP
#define NEB_CORE_CORE_ACTOR_RIGIDBODY_DESC_HPP

#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include <gal/itf/shared.hpp>

#include <gal/math/pose.hpp>
#include <neb/fnd/core/shape/desc.hpp>
#include <neb/fnd/core/scene/util/decl.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>

namespace ba = boost::archive;

namespace neb { namespace fnd { namespace core { namespace actor {

	struct desc: gal::itf::shared
	{
		desc() {}
		desc(gal::math::pose npose):
			pose(npose)
		{}

		virtual void	release();

		template<class Archive> void		serialize(Archive & ar, unsigned int const & version)
		{
			ar & BOOST_SERIALIZATION_NVP(pose);
		}
		
		virtual std::shared_ptr<neb::fnd::core::actor::base>		visit(
				neb::fnd::core::scene::base * const scene
				) const;


		gal::math::pose		pose;

	};
	namespace rigidbody {

		struct desc: neb::fnd::core::actor::desc {
			desc() {}
			desc(gal::math::pose npose):
				neb::fnd::core::actor::desc(npose)
			{}
			template<class Archive> void		serialize(Archive & ar, unsigned int const & version)
			{
				ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::actor::desc);
				ar & boost::serialization::make_nvp("foo",foo);
			}
			
			virtual std::shared_ptr<neb::fnd::core::actor::base>		visit(
					neb::fnd::core::scene::base * const scene
					) const;


			float					foo;

		};

	}

}}}}

#endif

