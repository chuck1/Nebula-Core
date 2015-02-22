#ifndef color_DYNAMIC_HPP__
#define color_DYNAMIC_HPP__

#include <stdlib.h>

#include <neb/fnd/math/color/color.hpp>

namespace neb { namespace fnd { namespace math { namespace color {

	template <typename TR, typename TG, typename TB, typename TA, class R, class G, class B> class Dynamic: neb::fnd::math::color::color_rgba<TR, TG, TB, TA> {
		public:
			/*	struct type {
				enum e: char {
				CONST,
				SINE,
				SAW,
				SQUARE,
				};
				};*/

			Dynamic() {
				//fr = fg = fb = 0.0;
				//tr = tg = tb = type::e::CONST;
			}
			Dynamic(TR nr, TG ng, TB nb, TA na): color_rgba<TR,TB,TG,TA>(nr,ng,nb,na) {}
			Dynamic(TR newr, TG newg, TB newb, TA newA, char newtr, char newtg, char newtb) {
				/*
				   tr = newtr;
				   tg = newtg;
				   tb = newtb;

				   switch(tr)
				   {
				   case type::e::SINE:
				   r = 0.0;
				   fr = newr;
				   break;
				   case type::e::SAW:
				   r = 0.0;
				   fr = newr;
				   break;
				   case type::e::CONST:
				   default:
				   r = newr;
				   fr = 0.0;
				   break;

				   }
				   switch(tb)
				   {
				   case type::e::SINE:
				   b = 0.0;
				   fb = newb;
				   break;
				   case type::e::SAW:
				   b = 0.0;
				   fb = newb;
				   break;
				   case type::e::CONST:
				   default:

				   b = newb;
				   fb = 0.0;
				   break;

				   }
				   switch(tr)
				   {
				   case type::e::SINE:
				   g = 0.0;
				   fg = newg;
				   break;
				   case type::e::SAW:
				   g = 0.0;
				   fg = newg;
				   break;
				   case type::e::CONST:
				   default:
				   g = newg;
				   fg = 0.0;
				   break;

				   }

				   a = newA;
				 */
			}
			Dynamic(const color_rgba<TR,TB,TG,TA> & rhs): color_rgba<TR,TB,TG,TA>(rhs) {

				/*	fr = rhs.fr;
					fg = rhs.fg;
					fb = rhs.fb;
					tr = rhs.tr;
					tg = rhs.tg;
					tb = rhs.tb;*/
			}


			~Dynamic() {}

			void			step(double time)
			{
				//MATH_DEBUG_1_FUNCTION;

				color_rgba<TR,TB,TG,TA>::r = r_.step(time);
				color_rgba<TR,TB,TG,TA>::g = g_.step(time);
				color_rgba<TR,TB,TG,TA>::b = b_.step(time);
				/*
				   switch(tr) {
				   case type::e::CONST:
				   break;
				   case type::e::SINE:
				   r = 0.5 * sin(2.0 * M_PI * fr * time) + 0.5;
				   printf("sine r = %f\n", r);
				   break;
				   case type::e::SAW:
				   r = saw(time, fr);
				   break;

				   }
				   switch(tg) {
				   case type::e::CONST:
				   break;
				   case type::e::SINE:
				   g = 0.5 * sin(2.0 * M_PI * fg * time) + 0.5;
				   printf("g = %f\n", g);
				   break;
				   case type::e::SAW:
				   g = saw(time, fg);
				   break;
				   }
				   switch(tb) {
				   case type::e::CONST:
				   break;
				   case type::e::SINE:
				   b = 0.5 * sin(2.0 * M_PI * fb * time) + 0.5;
				   break;
				   case type::e::SAW:
				   b = saw(time, fb);
				   break;
				   }*/

			}
			math::color::color_rgba<TR,TB,TG,TA>		operator*(double f) {
				math::color::color_rgba<TR,TB,TG,TA> ret(*this);
				ret *= f;
				return ret;
			}
			operator double* () const {
				return (double*)this;
			}
			operator double const * () const {
				return (double*)this;
			}

			//constructors
		public:
			R	r_;
			G	g_;
			B	b_;

			/*
			   T	fr;
			   T	fg;
			   T	fb;
			   char	tr;
			   char	tg;
			   char	tb;	*/
	};
}}}}

#endif


