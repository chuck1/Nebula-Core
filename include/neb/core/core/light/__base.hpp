#ifndef NEBULA_CORE_LIGHT___BASE_HPP
#define NEBULA_CORE_LIGHT___BASE_HPP

#include <gal/stl/child.hpp>

#include <neb/core/math/pose.hpp>
#include <neb/core/core/light/util/decl.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/itf/serializable.hpp>

namespace neb { namespace fnd { namespace core { namespace light {

	class __base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::itf::serializable,
		virtual public gal::stl::child<neb::fnd::core::light::util::parent>
	{
		public:
			virtual void		init(neb::fnd::core::light::util::parent * const & p) = 0;
			virtual void		callbackPose(neb::fnd::math::pose const &) = 0;

			virtual void		load(ba::polymorphic_iarchive & ar, unsigned int const &) = 0;
			virtual void		save(ba::polymorphic_oarchive & ar, unsigned int const &) const = 0;
			BOOST_SERIALIZATION_SPLIT_MEMBER();

	};

}}}}

#endif
