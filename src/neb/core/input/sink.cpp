#include <neb/fnd/input/sink.hpp>
#include <neb/fnd/input/source.hpp>

typedef neb::fnd::input::sink THIS;

THIS::~sink()
{
	printv(debug, "%s %p\n", __PRETTY_FUNCTION__, this);
}
void		THIS::connectKeyFun(std::shared_ptr<neb::fnd::input::source> const & src, int i)
{
	printv(debug, "%s %p\n", __PRETTY_FUNCTION__, this);

	conns_.key_fun_ = src->sig_.keyFun_.connect(
			i,
			neb::fnd::input::signals::KeyFun::slot_type(
				&THIS::keyFun,
				this,
				_1,
				_2,
				_3,
				_4,
				_5
				).track_foreign(shared_from_this())
			);
}
void		THIS::connectCharFun(std::shared_ptr<neb::fnd::input::source> const & src, int i)
{
	printv(debug, "%s %p\n", __PRETTY_FUNCTION__, this);

	conns_.charFun_ = src->sig_.charFun_.connect(
			i,
			neb::fnd::input::signals::CharFun::slot_type(
				&THIS::charFun,
				this,
				_1,
				_2
				).track_foreign(shared_from_this())
			);
}
void		THIS::connectMouseButtonFun(std::shared_ptr<neb::fnd::input::source> const & src, int i)
{
	printv(debug, "%s %p\n", __PRETTY_FUNCTION__, this);

	conns_.mouse_button_fun_ = src->sig_.mouseButtonFun_.connect(
			i,
			neb::fnd::input::signals::MouseButtonFun::slot_type(
				&THIS::mouseButtonFun,
				this,
				_1,
				_2,
				_3,
				_4
				).track_foreign(shared_from_this())
			);

}



int			THIS::mouseButtonFun(
		std::shared_ptr<neb::fnd::input::source> const &,
		int button,
		int action,
		int mods)
{
	printv(debug, "%s %p\n", __PRETTY_FUNCTION__, this);
	return 0;
}
int			THIS::keyFun(
		std::shared_ptr<neb::fnd::input::source> const &,
		int,
		int,
		int,
		int)
{
	printv(debug, "%s %p\n", __PRETTY_FUNCTION__, this);
	return 0;
}
int			THIS::charFun(
		std::shared_ptr<neb::fnd::input::source> const &,
		unsigned int codepoint)
{
	printv(debug, "%s %p\n", __PRETTY_FUNCTION__, this);
	return 0;
}




