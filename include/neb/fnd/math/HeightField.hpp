#ifndef NEB_CORE_MATH_HEIGHT_FIELD_HPP
#define NEB_CORE_MATH_HEIGHT_FIELD_HPP

#include <gal/stl/verbosity.hpp>

namespace neb { namespace fnd { namespace math { namespace HeightField {

	class Base:
		public gal::tmp::Verbosity<neb::fnd::math::HeightField::Base>
	{
		public:
			Base(unsigned int r, unsigned int c);

			void			alloc();
			void			createRandom();
			float const		min() const;
			float const		max() const;
			int			at(int i, int j) const;
			void			filterc(float factor);
			void			filter(unsigned int width);
			void			normalize(float a, float b);
			float const		get(int i, int j) const;
			float			get(int i, int j);
			void			operator+=(Base const & hf);

			Base*			mipmap(int down);

			void			slope(float dx, float dy);

			float*			_M_z;
			unsigned int		_M_r;
			unsigned int		_M_c;
			float*			_M_dzdx;
			float*			_M_dzdy;
	};

}}}}

#endif
