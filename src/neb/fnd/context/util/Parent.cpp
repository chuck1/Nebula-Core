#include <neb/fnd/context/util/Parent.hpp>
#include <neb/fnd/context/Window.hpp>
#include <neb/fnd/context/FBO.hpp>
#include <neb/fnd/context/FBOM.hpp>
#include <neb/fnd/window/util/Parent.hpp>
#include <neb/fnd/context/Base.hpp>

typedef neb::fnd::context::util::Parent THIS;

typedef neb::fnd::context::Window C_W;

neb::fnd::app::Base * const	THIS::get_fnd_app()
{
	auto w = is_fnd_window_base();
	assert(w);
	return w->get_fnd_app();
}
void				THIS::render()
{
	auto lamb = [&] (pointer p) {
		p->render();
	};

	map_.for_each(lamb);
}
std::weak_ptr<C_W>		THIS::createContextTwo()
{
	//auto self = is_gfx_window_base();
	//assert(self);
	
	std::weak_ptr<C_W> w;
	{
		auto context = createContextWindow().lock();
		//auto context(make_shared<>(self));
		//assert(context);
		//insert(context);

		auto environ = context->createEnvironTwo().lock();

		context->init(this);

		w = context;
	}
	assert(!w.expired());
	return w;
}
std::weak_ptr<C_W>		THIS::createContextThree()
{
	//auto self = is_gfx_window_base();
	//assert(self);

	std::weak_ptr<C_W> w;
	{
		auto context = createContextWindow().lock();
		//	auto context = std::make_shared<neb::gfx::context::window>(self);
		//	assert(context);
		//	insert(context);

		auto environ = context->createEnvironSceneDefault().lock();

		context->init(this);

		//assert(environ->view_);
		//environ->view_->connect(self);

		w = context;
	}
	assert(!w.expired());
	return w;
}
std::weak_ptr<C_W>		THIS::createContextNormalMap()
{
	//auto self = is_gfx_window_base();
	//assert(self);

	std::weak_ptr<C_W> w;
	{
		auto context = createContextWindow().lock();
		//	auto context = std::make_shared<neb::gfx::context::window>(self);
		//	assert(context);
		//	insert(context);

		auto environ = context->createEnvironVisualizationNormal().lock();

		context->init(this);

		//assert(environ->view_);
		//environ->view_->connect(self);

		w = context;
	}
	assert(!w.expired());
	return w;
}
std::weak_ptr<C_W>		THIS::createContextWindow()
{
	//auto self = isWindowBase();
	//assert(self);
	
	return create<neb::fnd::context::Window>();
	/*
	std::shared_ptr<C_W> context(new C_W());
	
	insert(context);
	
	context->init();
	
	return context;*/
}
std::weak_ptr<neb::fnd::context::FBO>		THIS::createContextFBO()
{

	return create<neb::fnd::context::FBO>();
/*
	auto self = isWindowBase();
	assert(self);

	std::shared_ptr<C_FBO> context(new C_FBO(self));
	
	insert(context);

	context->init();

	return context;*/
}
std::weak_ptr<neb::fnd::context::FBOM>		THIS::createContextFBOMulti()
{
	return create<neb::fnd::context::FBOM>();
}
std::weak_ptr<C_W>		THIS::createContextVisDepth()
{
	return create<neb::fnd::context::Window>();
}


