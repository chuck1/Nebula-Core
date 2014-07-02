#ifndef __GLUTPP_SCENE_H__
#define __GLUTPP_SCENE_H__

#include <vector>

#include <Galaxy-Standard/flag.hpp>
#include <Galaxy-Standard/map.hpp>



#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

#include <neb/typedef.hpp>
#include <neb/core/scene/util/Flag.hh>
#include <neb/core/scene/util/Types.hh>

//#include <neb/config.hh> // Nebula/config.hpp.in
//#include <neb/gfx/glsl/program.hh>


//#include <neb/core/actor/base.hpp>
#include <neb/core/actor/util/Parent.hh>

//#include <neb/gfx/Camera/View/Base.hh>
//#include <neb/gfx/drawable/base.hpp>


#define LIGHT_MAX 20

namespace neb { namespace core { namespace scene {


	/** 
	 * @ingroup group_core
	 * @brief Base
	 */
	class base:
		virtual public neb::core::actor::util::parent
	{
		public:
			base(sp::shared_ptr<neb::core::scene::util::parent>);
			virtual ~base();
			virtual void				init();
			virtual void				release();
			/** @name Main Loop @{ */
			/** @brief render */

			virtual void			step(gal::std::timestep const & ts);
			/** @} */

			virtual  void			serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version) {
				ar & boost::serialization::make_nvp("i",i_);
				ar & boost::serialization::make_nvp("flag",flag_);
			}
			virtual void			serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) {
				ar & boost::serialization::make_nvp("i",i_);
				ar & boost::serialization::make_nvp("flag",flag_);
			}
		public:
			neb::core::pose						getPose();
			neb::core::pose						getPoseGlobal();
		public:
			void							add_deferred(sp::shared_ptr<neb::core::actor::base>);


			/** @name convenience functions
			 * @{
			 */
			/** @brief create rigidstatic cube
			 *
			 * @note typeof returned actor will be determined by final implementation of this
			 */
			sp::weak_ptr<neb::core::actor::base>				createActorRigidStaticCube(neb::core::pose const & pose, real size);
			sp::weak_ptr<neb::core::actor::base>				createActorRigidDynamicCube(neb::core::pose const & pose, real size);
			/** @brief create empty actor with point light
			 */
			virtual sp::weak_ptr<neb::core::actor::base>			createActorLightPoint(vec3 p) = 0;
			/** @brief create rigidstatic
			 *
			 * @note typeof returned actor will be determined by final implementation of this
			 *
			 * @warning return actor is not initialized
			 */
			virtual sp::weak_ptr<neb::core::actor::base>			createActorRigidStaticUninitialized() = 0;
			virtual sp::weak_ptr<neb::core::actor::base>			createActorRigidDynamicUninitialized() = 0;
			/** @} */
		public:
			/** @brief parent
			 *
			 * @note WEAK
			 */
			sp::shared_ptr<neb::core::scene::util::parent>		parent_;

		public:
			neb::core::scene::util::Flag					flag_;

			::std::map< ::std::string, sp::shared_ptr<neb::core::actor::base> >		actors_deferred_;

			float		last_;
	};



}}}

#endif





