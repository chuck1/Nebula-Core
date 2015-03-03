#ifndef NEB_FND_CORE_SHAPE_CUBOID_HPP
#define NEB_FND_CORE_SHAPE_CUBOID_HPP

#include <neb/fnd/core/shape/base.hpp>

namespace neb { namespace fnd { namespace core { namespace shape {
	class Cuboid:
		virtual public neb::fnd::core::shape::base
	{
	public:
		Cuboid();
		virtual ~Cuboid();
		virtual void		init(parent_t * const &);
		virtual void		release();
		virtual void		step(gal::etc::timestep const & ts);

		virtual void		load(ba::polymorphic_iarchive & ar, unsigned int const &);
		virtual void		save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
		BOOST_SERIALIZATION_SPLIT_MEMBER();
	};
}}}}

#endif
