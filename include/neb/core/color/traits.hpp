#ifndef GRU_color_TRAITS_HPP
#define GRU_color_TRAITS_HPP


namespace neb { namespace core { namespace color {

	template<int BITS> struct uchar;
	
	template<typename T> struct traits {};

	template<> struct traits< uchar<6> > {
		static const unsigned int	bits = 6;
		static const unsigned char	min = 0;
		static const unsigned char	max = 63;
	};

	template<> struct traits< uchar<8> > {
		static const unsigned int	bits = 8;
		static const unsigned char	min = 0;
		static const unsigned char	max = 255;
	};


	
	template<int BITS> struct uchar {
		uchar(unsigned char nc) {
			if(nc > traits< uchar<BITS> >::max) {
				c = traits< uchar<BITS> >::max;
			} else {
				c = nc;
			}
		}
		operator unsigned int() const
		{
			return (unsigned int)c;
		}
		operator unsigned char() const
		{
			return c;
		}
		unsigned int	operator<<(unsigned int s) const
		{
			return (unsigned int)c << s;
		}
		unsigned char	c;
	};

	struct uchar6: uchar<6> {
		uchar6(): uchar<6>(0) {}
		uchar6(unsigned char nc): uchar<6>(c) {}
	};

	struct uchar8: uchar<8> {
		uchar8(): uchar<8>(0) {}
		uchar8(unsigned char nc): uchar<8>(c) {}
	};


	template<> struct traits<uchar6> {
		typedef unsigned char		pod;
		static const unsigned int	bits = 6;
		static const pod		min = 0;
		static const pod		max = 63;
		static const pod		rand() {
			return ::rand() % 64;
		}
	};

	template<> struct traits<uchar8> {
		typedef unsigned char		pod;
		static const unsigned int	bits = 8;
		static const pod		min = 0;
		static const pod		max = 255;
		static const pod		rand() {
			return ::rand() % 256;
		}
	};

	template<> struct traits<float> {
		static const unsigned int	bits = 32;
		static constexpr float		min = 0.0f;
		static constexpr float		max = 1.0f;
		static const float		rand() {
			return (float)(::rand() % 256) / 256.0f;
		}
	};

}}}

#endif

