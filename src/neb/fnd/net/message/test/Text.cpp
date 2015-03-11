#include <neb/fnd/net/msg/test/Text.hpp>

typedef neb::fnd::net::msg::test::Text THIS;

void			THIS::load(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	ar >> _M_text;

	printf("message received: %s\n", _M_text.c_str());
}
void			THIS::save(
		boost::archive::polymorphic_oarchive & ar,
		unsigned int const & version) const
{
	ar << _M_text;

	printf("serializing message: %s\n", _M_text.c_str());
}

