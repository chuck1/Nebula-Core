#ifndef __GLUTPP_NETWORK_MESSAGE_H__
#define __GLUTPP_NETWORK_MESSAGE_H__

#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

//#include <neb/config.hh> // gru/config.hpp.in
//#include <Nebulahh>
//#include <neb/fnd/core/scene/util/Address.hh>
//#include <neb/fnd/actor/Util/Event.hh>
#include <neb/fnd/core/actor/Base.hpp>

namespace neb { namespace net { namespace msg { namespace scene {
	class Create {
		public:
			typedef neb::fnd::core::scene::base S;
			Create();
			void load(std::shared_ptr<S> scene);
			template<class Archive>
			void	serialize(
					Archive & ar,
					unsigned int const & version)
			{
				ar & scene_;
			}

			gal::stl::wrapper<S>			scene_;
	};
}}}}

#endif



