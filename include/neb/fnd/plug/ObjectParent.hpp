#ifndef NEB_FND_PLUG_OBJECT_PARENT_HPP
#define NEB_FND_PLUG_OBJECT_PARENT_HPP

#include <gal/itf/shared.hpp>
#include <gal/dll/helper.hpp>

namespace neb { namespace fnd { namespace plug {
	template<typename P>
	class Parent
	{
	protected:
		typedef gal::dll::helper<gal::itf::shared>  H;
		template<typename... ARGS>
		void			make_object(
				std::shared_ptr<H> h,
				ARGS... args)
		{
			_M_object = h->template make_shared<P, ARGS...>(
					args...);
			_M_object->init(this);
		}
		void			reset()
		{
			_M_object.reset();
		}
	public:
		bool			has_object()
		{
			return bool(_M_object);
		}
		std::shared_ptr<P>	get_object()
		{
			assert(_M_object);
			return _M_object;
		}
	private:
		std::shared_ptr<P>	_M_object;
	};
}}}

#endif
