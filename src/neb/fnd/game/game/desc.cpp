#include <neb/fnd/game/game/desc.hpp>

typedef neb::fnd::game::game::desc THIS;

THIS::desc():
	_M_net_type(0)
{
}
THIS::~desc()
{
}
THIS&				THIS::operator=(THIS const & t)
{
	_M_net_type = t._M_net_type;

	return *this;
}
void				THIS::release()
{
}
void				THIS::load(
		boost::archive::xml_iarchive & ar,
		unsigned int const & version)
{
}
void				THIS::save(
		boost::archive::xml_oarchive & ar,
		unsigned int const & version) const
{
}
std::shared_ptr<neb::fnd::game::game::base>		THIS::visit(
		neb::fnd::app::Base * const
		) const
{
	return std::shared_ptr<neb::fnd::game::game::base>();
}

