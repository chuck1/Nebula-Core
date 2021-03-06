#ifndef NEB_FND_GLSL_PROGRAM_BASE_HPP
#define NEB_FND_GLSL_PROGRAM_BASE_HPP

#include <neb/fnd/itf/shared.hpp>
#include <gal/stl/verbosity.hpp>

namespace neb { namespace fnd { namespace glsl { namespace program {
	/**/
	class Base:
		public gal::tmp::Verbosity<neb::fnd::glsl::program::Base>,
		virtual public neb::fnd::itf::shared
	{
		public:
			//Base(std::string);
			virtual ~Base();
			virtual void		step(gal::etc::timestep const & ts);
			//virtual void		init();
			//void			restoreDefaultShaderFlags();
			//void			add_shader(std::string, GLenum);
			//void			add_shaders(std::vector<neb::gfx::glsl::shader>);
			//void			compile();
			virtual void		use() const = 0;
			//void			locate();
			//void			scanUniforms();
			virtual int		get_attrib_table_value(int key) const = 0;
			virtual int		get_uniform_table_value(int key) const = 0;
	};
}}}}

#endif
