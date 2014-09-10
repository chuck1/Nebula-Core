#ifndef NEB_CORE_CORE_ACTOR_RIGIDBODY_DESC_HPP
#define NEB_CORE_CORE_ACTOR_RIGIDBODY_DESC_HPP

#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/archive/polymorphic_xml_iarchive.hpp>
#include <boost/archive/polymorphic_xml_oarchive.hpp>

#include <gal/itf/shared.hpp>

#include <neb/core/pose.hpp>
#include <neb/core/core/shape/desc.hpp>
#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/core/actor/util/decl.hpp>

namespace neb { namespace core { namespace core { namespace actor {

	struct desc: gal::itf::shared
	{
		desc() {}
		desc(neb::core::pose npose):
			pose(npose)
		{}
		template<class Archive> void		__load(Archive & ar, unsigned int const & version)
		{
			ar & boost::serialization::make_nvp("pose",pose);
		}
		template<class Archive> void		__save(Archive & ar, unsigned int const & version) const
		{
			ar & boost::serialization::make_nvp("pose",pose);
		}
		virtual void				load(
				boost::archive::polymorphic_iarchive & ar,
				unsigned int const & version)
		{
			__load(ar, version);
		}
		virtual void				save(
				boost::archive::polymorphic_oarchive & ar,
				unsigned int const & version) const
		{
			__save(ar, version);
		}
		virtual std::shared_ptr<neb::core::core::actor::base>		visit(
				neb::core::core::scene::base * const scene
				) const;

		BOOST_SERIALIZATION_SPLIT_MEMBER();

		neb::core::pose		pose;

	};
	namespace rigidbody {

		struct desc: neb::core::core::actor::desc {
			desc() {}
			desc(neb::core::pose npose):
				neb::core::core::actor::desc(npose)
			{}
			template<class Archive> void		__load(Archive & ar, unsigned int const & version)
			{
				ar & boost::serialization::make_nvp("foo",foo);
			}
			template<class Archive> void		__save(Archive & ar, unsigned int const & version) const
			{
				ar & boost::serialization::make_nvp("foo",foo);
			}
			virtual void				load(
					boost::archive::polymorphic_iarchive & ar,
					unsigned int const & version)
			{
				neb::core::core::actor::desc::__load(ar, version);

				__load(ar, version);
			}
			virtual void				save(
					boost::archive::polymorphic_oarchive & ar,
					unsigned int const & version) const
			{
				neb::core::core::actor::desc::__save(ar, version);

				__save(ar, version);
			};
			
			virtual std::shared_ptr<neb::core::core::actor::base>		visit(
					neb::core::core::scene::base * const scene
					) const;

			BOOST_SERIALIZATION_SPLIT_MEMBER();

			float					foo;

		};

	}

}}}}

#endif

