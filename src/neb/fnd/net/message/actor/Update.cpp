#include <gal/itf/registry.hpp>

#include <neb/fnd/core/actor/Base.hpp>

#include <neb/fnd/net/message/actor/Update.hpp>

typedef neb::net::msg::actor::Update THIS;

void			THIS::load(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	typedef neb::fnd::core::actor::base T;
	
	gal::itf::index_type i;
	std::shared_ptr<neb::fnd::core::actor::base> actor;
	
	size_t size;
	ar >> size;
	
	auto reg = get_registry();
	
	for(size_t a = 0; a < size; ++a) {
		ar >> i;
		actor = std::dynamic_pointer_cast<T>(reg->get(i));
		ar >> *actor;
	}
}
void			THIS::save(
		boost::archive::polymorphic_oarchive & ar,
		unsigned int const & version) const
{
	typedef neb::fnd::core::actor::base T;

	size_t size = actors_.size();
	ar << size;

	gal::itf::index_type i;

	for(auto it = actors_.cbegin(); it != actors_.cend(); ++it) {
		std::shared_ptr<T> const & actor = *it;
		/** @todo why?!?!?!? */
		i = actor->get_index();
		ar << i;
		ar << *actor;
	}
}

