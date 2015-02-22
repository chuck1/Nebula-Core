#ifndef NEB_CORE_INPUT_SINK_HPP
#define NEB_CORE_INPUT_SINK_HPP

#include <boost/signals2.hpp>

#include <gal/itf/shared.hpp>

#include <neb/fnd/itf/verbosity.hpp>
#include <neb/fnd/input/util/decl.hpp>

namespace neb { namespace fnd { namespace input {
	class sink:
		public neb::fnd::itf::verbosity<neb::fnd::input::sink>,
		virtual public gal::itf::shared
	{
		public:
			using neb::fnd::itf::verbosity<neb::fnd::input::sink>::printv;
			virtual ~sink();
			void			connectKeyFun(std::shared_ptr<neb::fnd::input::source> const & src, int i);
			void			connectCharFun(std::shared_ptr<neb::fnd::input::source> const & src, int i);
			void			connectMouseButtonFun(std::shared_ptr<neb::fnd::input::source> const & src, int i);
			virtual int		mouseButtonFun(
					std::shared_ptr<neb::fnd::input::source> const &,
					int button,
					int action,
					int mods);
			virtual int		keyFun(
					std::shared_ptr<neb::fnd::input::source> const &,
					int,
					int,
					int,
					int);
			virtual int		charFun(
					std::shared_ptr<neb::fnd::input::source> const &,
					unsigned int codepoint);

			// connections
			struct
			{
				boost::signals2::connection		mouse_button_fun_;
				boost::signals2::connection		key_fun_;
				boost::signals2::connection		charFun_;
			} conns_;
	};
}}}

#endif
