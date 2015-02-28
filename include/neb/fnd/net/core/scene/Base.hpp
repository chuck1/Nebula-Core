#ifndef NEB_FND_NET_CORE_SCENE_BASE_HPP
#define NEB_FND_NET_CORE_SCENE_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/net/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>

namespace neb { namespace fnd { namespace net { namespace core { namespace scene {
	typedef neb::fnd::core::scene::base FND;
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<FND>
	{
		public:
			typedef neb::fnd::net::core::scene::Local L;
			typedef neb::fnd::net::core::scene::Remote R;
			virtual std::shared_ptr<L>	is_local() = 0;
			virtual std::shared_ptr<R>	is_remote() = 0;
			virtual void			init(parent_t * const & p) = 0;
			virtual void			visit_step(
					FND * const & p,
					gal::etc::timestep const & ts) = 0;
			//virtual void			v_set_pose_data(gal::math::pose const & pose) = 0;
	};
	class Local:
		virtual public neb::fnd::net::core::scene::Base
	{
		public:
			typedef neb::fnd::net::core::scene::Local L;
			typedef neb::fnd::net::core::scene::Remote R;
			virtual std::shared_ptr<L>	is_local();
			virtual std::shared_ptr<R>	is_remote();
			virtual void			init(parent_t * const & p);
			virtual void			visit_step(
					FND * const & p,
					gal::etc::timestep const & ts) = 0;
	};
	class Remote:
		virtual public neb::fnd::net::core::scene::Base
	{
		public:
			typedef neb::fnd::net::core::scene::Local L;
			typedef neb::fnd::net::core::scene::Remote R;
			virtual std::shared_ptr<L>	is_local();
			virtual std::shared_ptr<R>	is_remote();
			virtual void			init(parent_t * const & p);
			virtual void			visit_step(
					FND * const & p,
					gal::etc::timestep const & ts) = 0;
	};
}}}}}

#endif
