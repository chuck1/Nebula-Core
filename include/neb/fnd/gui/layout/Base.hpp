#ifndef NEB_CORE_GUI_LAYOUT_BASE_HPP
#define NEB_CORE_GUI_LAYOUT_BASE_HPP

#include <glm/glm.hpp>

#include <neb/fnd/input/sink.hpp>
#include <neb/fnd/input/util/decl.hpp>

#include <neb/fnd/gui/layout/Base.hpp>
#include <neb/fnd/gui/layout/util/decl.hpp>

//#include <neb/gfx/util/decl.hpp>
//#include <neb/gfx/gui/object/Base.hh>
//#include <neb/gfx/gui/object/util/decl.hpp>
#include <neb/fnd/gui/object/util/Parent.hpp>
#include <neb/fnd/drawable/Base.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/RenderDesc.hpp>
#include <neb/fnd/itf/shared.hpp>

namespace neb { namespace fnd { namespace gui { namespace layout {
	class Base:
		virtual public neb::fnd::drawable::Base,
		virtual public neb::fnd::gui::object::util::Parent,
		virtual public neb::fnd::tmp::Child<neb::fnd::gui::layout::util::Parent>,
		virtual public neb::fnd::input::sink
	{
		public:
			using CHILD::get_fnd_app;
			Base();
			virtual ~Base();
			virtual void					init(parent_t * const & p);
			virtual void					release();
			virtual void					step(gal::etc::timestep const & ts);
			virtual void					draw(neb::fnd::RenderDesc const &);
			void						connect(
					std::shared_ptr<neb::fnd::input::source> const & window);
			int						search(
					std::shared_ptr<neb::fnd::input::source> const &,
					int button,
					int action,
					int mods);
			int						mouseButtonFun(
					std::shared_ptr<neb::fnd::input::source> const &,int button, int action, int mods);
			int						keyFun(
					std::shared_ptr<neb::fnd::input::source> const &,int,int,int,int);
			int						charFun(
					std::shared_ptr<neb::fnd::input::source> const &,
					unsigned int codepoint);
			std::weak_ptr<neb::fnd::gui::object::Terminal>	createObjectTerminal();
			glm::mat4x4					ortho_;
	};
}}}}

#endif
