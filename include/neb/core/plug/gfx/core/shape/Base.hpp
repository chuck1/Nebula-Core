#ifndef NEB_FND_PLUG_GFX_CORE_SHAPE_BASE_HPP
#define NEB_FND_PLUG_GFX_CORE_SHAPE_BASE_HPP

#include <neb/core/tmp/Child.hpp>
#include <neb/core/net/util/decl.hpp>
#include <neb/core/itf/shared.hpp>

typedef neb::fnd::game::map::Base		T0;
typedef neb::mod::maze::Base			T1;

extern "C" T0*	map_create()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return new T1;
}
extern "C" void	map_destroy(T0* t)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	delete t;
}


namespace neb { namespace fnd { namespace plug { namespace gfx { namespace core { namespace scene {
	typedef neb::fnd::core::scene::base FND;
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<FND>
	{
		public:
			typedef neb::fnd::net::core::scene::Local L;
			typedef neb::fnd::net::core::scene::Remote R;
			//virtual std::shared_ptr<L>	is_local() = 0;
			//virtual std::shared_ptr<R>	is_remote() = 0;
			virtual void			init(parent_t * const & p) = 0;
			virtual void			v_set_pose_data(
					FND * const & p,
					neb::fnd::math::pose & const global_pose);
			//virtual void			v_set_pose_data(neb::fnd::math::pose const & pose) = 0;
	};
}}}}}}

#endif
