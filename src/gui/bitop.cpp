
#include <assert.h>

#include "bitop.h"

namespace bitop {

void self_test(void) {
    // DEBUG
    static_assert(bitcount2masklsb<0u>() == 0u, "whoops");
    static_assert(bitcount2masklsb<1u>() == 1u, "whoops");
    static_assert(bitcount2masklsb<2u>() == 3u, "whoops");
    static_assert(bitcount2masklsb<2u,1u>() == 6u, "whoops");
    static_assert(bitcount2masklsb<2u,uint8_t>() == 3u, "whoops");
    static_assert(bitcount2masklsb<2u,0u,uint8_t>() == 3u, "whoops");
    static_assert(bitcount2masklsb<2u,1u,uint8_t>() == 6u, "whoops");
    static_assert(bitcount2masklsb<type_bits<>()>() == allones(), "whoops");
    static_assert(allones<uint32_t>() == (uint32_t)0xFFFFFFFFUL, "whoops");
    static_assert(allzero<uint32_t>() == (uint32_t)0, "whoops");
    static_assert(allones<uint64_t>() == (uint64_t)0xFFFFFFFFFFFFFFFFULL, "whoops");
    static_assert(allzero<uint64_t>() == (uint64_t)0, "whoops");
    static_assert((~allones<uint32_t>()) == allzero<uint32_t>(), "whoops");
    static_assert((~allzero<uint32_t>()) == allones<uint32_t>(), "whoops");
    assert(type_bits<uint64_t>() == 64u);
    assert(type_bits<uint32_t>() == 32u);
    assert(type_bits<uint16_t>() == 16u);
    assert(type_bits<uint8_t>() == 8u);
    assert(bit2mask(0u) == 1u);
    assert(bit2mask(8u) == 256u);
    assert(bit2mask<8u>() == 256u);
    static_assert(bit2mask<9u>() == 512u, "whoops");
    static_assert(bit2mask<33u,uint64_t>() == (1ull << 33ull), "whoops");
    static_assert(bitlength<0u>() == 0u, "whoops");
    static_assert(bitlength<1u>() == 1u, "whoops");
    static_assert(bitlength<2u>() == 2u, "whoops");
    static_assert(bitlength<3u>() == 2u, "whoops");
    static_assert(bitlength<4u>() == 3u, "whoops");
    static_assert(bitlength<7u>() == 3u, "whoops");
    static_assert(bitlength<8u>() == 4u, "whoops");
    static_assert(bitlength<~0u>() == type_bits(), "whoops");
    static_assert(type_msb_mask<uint8_t>() == 0x80u, "whoops");
    static_assert(type_msb_mask<uint16_t>() == 0x8000u, "whoops");
    static_assert(type_msb_mask<uint32_t>() == 0x80000000ul, "whoops");
    static_assert(type_msb_mask<uint64_t>() == 0x8000000000000000ull, "whoops");

    static_assert(bitseqlengthlsb<0u>() == 0u, "whoops"); // 0
    static_assert(bitseqlengthlsb<1u>() == 1u, "whoops"); // 1
    static_assert(bitseqlengthlsb<2u>() == 0u, "whoops"); // 10
    static_assert(bitseqlengthlsb<3u>() == 2u, "whoops"); // 11
    static_assert(bitseqlengthlsb<4u>() == 0u, "whoops"); // 100
    static_assert(bitseqlengthlsb<5u>() == 1u, "whoops"); // 101
    static_assert(bitseqlengthlsb<6u>() == 0u, "whoops"); // 110
    static_assert(bitseqlengthlsb<7u>() == 3u, "whoops"); // 111
    static_assert(bitseqlengthlsb<8u>() == 0u, "whoops"); // 1000
    static_assert(bitseqlengthlsb<9u>() == 1u, "whoops"); // 1001
    static_assert(bitseqlengthlsb<10u>() == 0u, "whoops"); // 1010
    static_assert(bitseqlengthlsb<11u>() == 2u, "whoops"); // 1011
    static_assert(bitseqlengthlsb<12u>() == 0u, "whoops"); // 1100
    static_assert(bitseqlengthlsb<15u>() == 4u, "whoops"); // 1111
    static_assert(bitseqlengthlsb<23u>() == 3u, "whoops"); // 10111
    static_assert(bitseqlengthlsb<31u>() == 5u, "whoops"); // 11111
    static_assert(bitseqlengthlsb<~0u>() == type_bits(), "whoops");
}

}
