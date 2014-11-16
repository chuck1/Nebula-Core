#ifndef NEB_CORE_CORE_SHAPE_HEIGHT_FIELD_HH
#define NEB_CORE_CORE_SHAPE_HEIGHT_FIELD_HH

namespace neb { namespace core { namespace core { namespace shape { namespace HeightField {

	class Base:
		virtual public neb::core::core::shape::base
	{
		public:
			typedef neb::core::core::shape::util::parent parent_t;

			Base();
			
			virtual void				init(parent_t * const & p) = 0;
			virtual void				release() = 0;
			virtual void				step(gal::etc::timestep  const & ts) = 0;

			virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &) = 0;
			virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const = 0;


			physx::PxReal				min_y_;
			physx::PxReal				max_y_;

			neb::core::core::shape::HeightField::desc	desc_;
	};



}}}}}


#endif


