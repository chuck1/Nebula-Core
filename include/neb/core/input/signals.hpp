#ifndef NEBULA_SIGNALS_HPP
#define NEBULA_SIGNALS_HPP

#include <boost/signals2.hpp>

#include <neb/core/util/combiner.hpp>
#include <neb/core/input/util/decl.hpp>

namespace neb { namespace fnd { namespace input { namespace signals {
	typedef int							ret_type;
	typedef std::shared_ptr<neb::fnd::input::source> const &	wnd_type;

	typedef boost::signals2::signal<ret_type (wnd_type, int, int, int),		neb::util::combiner>	MouseButtonFun;
	typedef boost::signals2::signal<ret_type (wnd_type, double, double),		neb::util::combiner>	CursorPosFun;
	typedef boost::signals2::signal<ret_type (wnd_type, int),			neb::util::combiner>	CursorEnterFun;
	typedef boost::signals2::signal<ret_type (wnd_type, double, double),		neb::util::combiner>	ScrollFun;
	typedef boost::signals2::signal<ret_type (wnd_type, int, int, int, int),	neb::util::combiner>	KeyFun;
	typedef boost::signals2::signal<ret_type (wnd_type, unsigned int),		neb::util::combiner>	CharFun;

	typedef boost::signals2::signal<ret_type (int, int),				neb::util::combiner>	JoystickButtonFun;
}}}}


#endif

