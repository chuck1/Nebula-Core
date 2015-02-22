#ifndef NEB_CORE_INPUT_CALLBACK_HPP
#define NEB_CORE_INPUT_CALLBACK_HPP

#include <functional>

namespace neb { namespace fnd { namespace input {

	namespace func
	{
		typedef std::function<int(int,int,int,int)> keyFun;
	}

	class callback
	{
		public:

			struct
			{
				struct
				{
					neb::fnd::input::func::keyFun		F1_;
				} key_press_;
			} callback_;

	};

}}}

#endif

