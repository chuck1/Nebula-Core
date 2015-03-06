#ifndef NEB_FND_CORE_ACTOR_CONTROL_RIGID_BODY_BASE_HPP
#define NEB_FND_CORE_ACTOR_CONTROL_RIGID_BODY_BASE_HPP

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/signals2.hpp>

#include <gal/etc/timestep.hpp>

#include <gal/stl/verbosity.hpp>
#include <neb/fnd/input/sink.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace control { namespace rigidbody {
	/** @brief Rigid Body
	 * An object (what did I mean by 'object' here, an actor?) makes no distinction between local and remote.
	 * In a remote scene, the actor will send a control update message.
	 * In a local scene, the actor will call upon stored values; it makes no difference to the
	 * actor whether these value were set by calls to key_fun or by a control update message.
	 * This creates requirements for how control works. All infomation needed to determine 
	 * force and torque at a given point in time must be stored in raw.
	 **/
	class base:
		public gal::tmp::Verbosity<neb::fnd::core::actor::control::rigidbody::base>,
		virtual public neb::fnd::input::sink
	{
	public:
		using gal::tmp::Verbosity<neb::fnd::core::actor::control::rigidbody::base>::printv;
		base();
		virtual ~base();
		base&				operator=(base const & base);
		virtual void			release();
		virtual int			keyFun(
				std::shared_ptr<neb::fnd::input::source> const &,
				int,
				int,
				int,
				int);
		virtual void			step(
				gal::etc::timestep const & ts) = 0;
		void				connect(std::shared_ptr<neb::fnd::input::source> src);
		void				connect(std::shared_ptr<neb::fnd::input::js> src);
		/**
		 * supply the body or global frame accumulated force and torque
		 */
		virtual glm::vec3		f_body() = 0;
		virtual glm::vec3		t_body() = 0;
		virtual glm::vec3		f_global() = 0;
		virtual glm::vec3		t_global() = 0;
		virtual void			serialize(
				boost::archive::polymorphic_iarchive & ar,
				unsigned int const & version);
		virtual void			serialize(
				boost::archive::polymorphic_oarchive & ar,
				unsigned int const & version);
		/** parent actor weak pointer */
		std::weak_ptr<neb::fnd::core::actor::rigidbody::base>		actor_;
	public:
	public:
		glm::quat				q_target_;
		glm::vec3				p_target_;
		/**
		 * store force and torque
		 */
		glm::vec3				f_;
		glm::vec3				t_;
		glm::vec3				force_;
		glm::vec3				torque_;
	public:
		//gal::control::control		pid_;
	};
}}}}}}

#endif
