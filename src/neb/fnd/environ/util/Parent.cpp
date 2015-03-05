#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/context/util/Parent.hpp>
#include <neb/fnd/window/Base.hpp>
#include <neb/fnd/environ/Two.hpp>
#include <neb/fnd/environ/SceneDefault.hpp>
//#include <neb/fnd/environ/util/Parent.hpp>
#include <neb/fnd/environ/visualization/Depth.hpp>
#include <neb/fnd/environ/visualization/Normal.hpp>
#include <neb/fnd/environ/shadow/Directional.hpp>
#include <neb/fnd/environ/shadow/Point.hpp>

#include <neb/fnd/environ/util/Parent.hpp>

typedef neb::fnd::environ::util::Parent THIS;



neb::fnd::app::Base* const			THIS::get_fnd_app()
{
	auto context = is_fnd_context_Base();
	assert(context);
	return context->get_fnd_app();
}
std::weak_ptr<neb::fnd::environ::SceneDefault>			THIS::createEnvironSceneDefault()
{
	typedef neb::fnd::environ::SceneDefault E;
	
	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();

	if(w) w->makeCurrent();
	
	//std::shared_ptr<E> environ(new E(), gal::stl::deleter<E>());
	auto environ = create<E>().lock();
	
	assert(w);
	w->resize();
	
	//environ->init(this);

	//c->setEnviron(environ);

	return environ;
}
std::weak_ptr<neb::fnd::environ::visualization::Normal>	THIS::createEnvironVisualizationNormal()
{
	typedef neb::fnd::environ::visualization::Normal E;
	
	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();

	if(w) w->makeCurrent();

	//std::shared_ptr<E> environ(new E(), gal::stl::deleter<E>());
	auto environ = create<E>().lock();

	//environ->init(this);

	//c->setEnviron(environ);

	return environ;
}
std::weak_ptr<neb::fnd::environ::shadow::Directional>		THIS::createEnvironShadowDirectional()
{
	typedef neb::fnd::environ::shadow::Directional E;

	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();

	if(w) w->makeCurrent();

	//std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());
	auto environ = create<E>().lock();

	//environ->init(this);
	
	//c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::fnd::environ::Two>				THIS::createEnvironTwo()
{
	typedef neb::fnd::environ::Two E;
	
	auto c = is_fnd_context_Base();
	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}

	//std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());
	auto environ = create<E>().lock();

	//environ->init(this);

	//c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::fnd::environ::visualization::Depth>		THIS::createEnvironVisualizationDepth()
{
	typedef neb::fnd::environ::visualization::Depth E;
	
	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();

	if(w) w->makeCurrent();

	//std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());
	auto environ = create<E>().lock();

	//environ->init(this);
	
	//c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::fnd::environ::shadow::Point>		THIS::createEnvironShadowPoint()
{
	typedef neb::fnd::environ::shadow::Point E;
	
	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();

	if(w) w->makeCurrent();

	//std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());
	auto environ = create<E>().lock();

	//environ->init(this);
	
	//c->setEnviron(environ);
	
	return environ;
}


