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
		virtual ~Parent()
		{
		}
		template<typename PARENT, typename... ARGS>
		void			make_object(
				std::shared_ptr<H> h,
				ARGS... args)
		{
			printf("%s\n", __PRETTY_FUNCTION__);
			
			assert(!_M_object);

			_M_object = h->template make_shared<P, ARGS...>(
					args...);

			PARENT * p = dynamic_cast<PARENT*>(this);
			assert(p);

			_M_object->init(p);
		}
		void			reset()
		{
			printf("%s\n", __PRETTY_FUNCTION__);
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
