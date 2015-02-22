#include <neb/core/context/Base.hpp>
#include <neb/core/context/util/Parent.hpp>
#include <neb/core/window/Base.hpp>
#include <neb/core/environ/Two.hpp>
#include <neb/core/environ/SceneDefault.hpp>
//#include <neb/core/environ/util/Parent.hpp>
#include <neb/core/environ/visualization/Depth.hpp>
#include <neb/core/environ/visualization/Normal.hpp>
#include <neb/core/environ/shadow/Directional.hpp>
#include <neb/core/environ/shadow/Point.hpp>

#include <neb/core/environ/util/Parent.hpp>

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
	
	std::shared_ptr<E> environ(new E(), gal::stl::deleter<E>());
	
	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}
	
	environ->init(this);

	c->setEnviron(environ);

	return environ;
}
std::weak_ptr<neb::fnd::environ::visualization::Normal>	THIS::createEnvironVisualizationNormal()
{
	typedef neb::fnd::environ::visualization::Normal E;
	
	std::shared_ptr<E> environ(new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();
	
	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}

	environ->init(this);

	c->setEnviron(environ);

	return environ;
}
std::weak_ptr<neb::fnd::environ::shadow::Directional>		THIS::createEnvironShadowDirectional()
{
	typedef neb::fnd::environ::shadow::Directional E;

	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}

	environ->init(this);
	
	c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::fnd::environ::Two>			THIS::createEnvironTwo()
{
	typedef neb::fnd::environ::Two E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();
	
	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}

	environ->init(this);

	c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::fnd::environ::visualization::Depth>		THIS::createEnvironVisualizationDepth()
{
	typedef neb::fnd::environ::visualization::Depth E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init(this);
	
	c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::fnd::environ::shadow::Point>		THIS::createEnvironShadowPoint()
{
	typedef neb::fnd::environ::shadow::Point E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();
	if(w) w->makeCurrent();

	environ->init(this);
	
	c->setEnviron(environ);
	
	return environ;
}


