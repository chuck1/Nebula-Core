#ifndef NEBULA_UTIL_PARENT_HPP
#define NEBULA_UTIL_PARENT_HPP

#include <iostream>

#include <gal/stl/parent.hpp>
#include <gal/stl/deleter.hpp>
#include <gal/etc/timestep.hpp>

#include <neb/fnd/itf/shared.hpp>

namespace neb { namespace fnd { namespace util {
	template<typename CHILD, typename PARENT>
	class parent:
		virtual public gal::stl::parent<CHILD>
	{
		public:
			typedef gal::stl::parent<CHILD>						gal_parent;
			typedef typename gal::stl::parent<CHILD>::MAP				map_type;
			typedef typename map_type::iterator					iterator;
			typedef typename map_type::pointer					pointer;
			typedef std::shared_ptr<CHILD>	shared;
			typedef std::weak_ptr<CHILD>	weak;

			// create
			template<typename U> std::weak_ptr<U>				create()
			{
				U* up = new U;
				std::shared_ptr<U> u(up, gal::stl::deleter<U>());

				gal_parent::insert(u);

				u->init(dynamic_cast<PARENT*>(this));

				return u;
			}
			// insert
			void								insert(shared t)
			{
				gal_parent::insert(t);
				t->init(dynamic_cast<PARENT*>(this));
			}
			void								insert_no_init(shared t)
			{
				gal_parent::insert(t);
			}


			template<typename... A> void		initChildren(A... a)
			{
				for(auto it = gal_parent::begin(); it != gal_parent::end(); ++it)
				{
					auto p = it->second.ptr_;
					assert(p);
					p->init(a...);
				}
			}


			void		step(gal::etc::timestep const & ts)
			{
				//std::cout << __PRETTY_FUNCTION__ << std::endl;
				gal_parent::for_each([&] (pointer p) { p->step(ts); });
			}
			void		preloop()
			{
				auto l = [] (pointer p) { p->preloop(); };
				gal_parent::for_each(l);
			}
	};
}}}

#endif
