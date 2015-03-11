#ifndef NEBULA_UTIL_PARENT_HPP
#define NEBULA_UTIL_PARENT_HPP

#include <iostream>

#include <gal/weak_ptr.hpp>
#include <gal/stl/verbosity.hpp>
#include <gal/stl/parent.hpp>
#include <gal/stl/deleter.hpp>
#include <gal/etc/timestep.hpp>

#include <neb/fnd/itf/shared.hpp>

namespace neb { namespace fnd { namespace util {
	template< typename CHILD, typename PARENT, typename S_ = std::shared_ptr<CHILD> >
	class parent:
		public gal::tmp::Verbosity< neb::fnd::util::parent <CHILD, PARENT, S_> >,
		virtual public gal::stl::parent<CHILD, S_>
	{
		public:
			using gal::tmp::Verbosity< neb::fnd::util::parent <CHILD, PARENT, S_> >::printv;
			typedef gal::stl::parent<CHILD, S_>			gal_parent;
			typedef typename gal::stl::parent<CHILD, S_>::MAP	map_type;
			typedef typename map_type::iterator			iterator;
			typedef typename map_type::S				S;
			//typedef std::shared_ptr<CHILD>			S;
			typedef std::weak_ptr<CHILD>				weak;
			typedef gal::weak_ptr<CHILD>				W;

			// create
			template<typename U>
			std::weak_ptr<U>		create()
			{
				U* up = new U;
				std::shared_ptr<U> u(up, gal::stl::deleter<U>());

				S s(u);

				gal_parent::insert(std::move(s));

				u->init(dynamic_cast<PARENT*>(this));

				return u;
			}
			// insert
			void				insert(S && s)
			{
				W w(s);
				gal_parent::insert(std::move(s));
				w->init(dynamic_cast<PARENT*>(this));
			}
			void				insert_no_init(S && s)
			{
				gal_parent::insert(std::move(s));
			}
			template<typename... A>
			void				initChildren(A... a)
			{
				printv_func(DEBUG);
				printv(DEBUG, "size = %i\n", gal_parent::size());
				for(auto it = gal_parent::begin(); it != gal_parent::end(); ++it)
				{
					auto p = it->second.ptr_;
					assert(p);
					p->init(a...);
				}
			}
			void				step(gal::etc::timestep const & ts)
			{
				printv_func(DEBUG);
				printv(DEBUG, "size = %i\n", gal_parent::size());
				
				auto l = [&] (S s) { s->step(ts); };

				gal_parent::for_each(l);
			}
			void				preloop()
			{
				printv_func(DEBUG);
				printv(DEBUG, "size = %i\n", gal_parent::size());

				auto l = [] (S s) { s->preloop(); };

				gal_parent::for_each(l);
			}
	};
}}}

#endif
