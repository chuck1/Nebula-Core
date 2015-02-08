#ifndef NEB_CORE_FREE_HPP
#define NEB_CORE_FREE_HPP

#include <fstream>

#include <boost/archive/polymorphic_xml_iarchive.hpp>

#include <gal/stl/deleter.hpp>
#include <gal/stl/wrapper.hpp>

#include <neb/core/util/log.hpp>
#include <neb/core/util/config.hpp>

template<typename B, typename D> void	makeDefaultFunc()
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;

	gal::itf::shared::register_type(std::type_index(typeid(B)));
	gal::itf::shared::register_type(std::type_index(typeid(D)));

	std::function< std::shared_ptr<B>() > f(
			[]() { return std::shared_ptr<D>(new D(), gal::stl::deleter<D>()); }
			);

	gal::stl::factory<B>::default_factory_->add(typeid(D).hash_code(), f);
}
template<typename B, typename D> void	makeDLLFunc()
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;

	gal::itf::shared::register_type(std::type_index(typeid(B)));
	gal::itf::shared::register_type(std::type_index(typeid(D)));
	
	//typedef neb::fin::gfx_phx::core::scene::base		D;
	typedef gal::dll::helper<D>				H;
	//typedef gal::dll::deleter				DEL;
	
	auto lamb = [](gal::dll::helper_info& hi) {
		
		std::shared_ptr<H> h(new H(hi.file_name, hi.object_name));
		
		h->open();
		
		std::shared_ptr<B> d = h->make_shared();

		return d;
	};

	std::function< std::shared_ptr<B>(gal::dll::helper_info&) > f(lamb);

	gal::stl::factory<B>::default_factory_->add(typeid(D).hash_code(), f);
}
template<typename B, typename D> gal::stl::wrapper<B>		loadDLL(std::string file_name, std::string object_name)
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;

	LOG(lg, neb::fnd::sl, debug) << "B " << typeid(B).name() << " " << typeid(B).hash_code();
	LOG(lg, neb::fnd::sl, debug) << "D " << typeid(D).name() << " " << typeid(D).hash_code();

	typedef gal::dll::helper<D>	H;
	
	std::shared_ptr<H> h(new H(file_name, object_name));

	h->open();
	
	std::shared_ptr<D> p = h->make_shared();
	
	gal::stl::wrapper<B> w(p);
	
	return w;
}
template<typename T> std::shared_ptr<T>		loadXML(std::string filename)
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;

	std::ifstream ifs;
	ifs.open(filename);
	if(!ifs.is_open())
	{
		std::cout << "file error: " << filename << std::endl;
		abort();
	}

	gal::stl::wrapper<T> w;

	boost::archive::polymorphic_xml_iarchive ar(ifs);

	w.load(ar,0);

	return w.ptr_;
}

#endif
