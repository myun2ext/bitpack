#ifndef __github_com_myun2__bitpack__def_HPP__
#define __github_com_myun2__bitpack__def_HPP__

namespace myun2
{
	namespace bitpack
	{
		namespace defs
		{
			//
			//	Category A:
			//	  3 bits of type identify + 5 bits of value
			//
			namespace category_a
			{
				template <typename T, unsigned int _Identify>
				struct base {
					typedef T type;
					static const unsigned int identify = _Identify;
					static const unsigned int value_length = 0;

					static T mask(const T& v) { return v & 0xE0; }
					static bool is(const T& v) { return mask(v) == identify; }
				};
				
				//	Micro Unsigned Int. (B000xxxxx)
				//	  value is unsigned int at
				struct micro_unsigned_int : base<unsigned char, 0x00> {};
			}

			struct category_a_trait {
				static const unsigned int identify_bits = 3;
			};

			//
			//	Category B:
			//	  1byte(8bits) of type identify + any bytes value
			//
			namespace category_b
			{
			}
		}
	}
}

#endif//__github_com_myun2__bitpack__def_HPP__
