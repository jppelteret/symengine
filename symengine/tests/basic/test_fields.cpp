#include "catch.hpp"
#include <iostream>

#include <symengine/basic.h>
#include <symengine/fields.h>
#include <symengine/symengine_rcp.h>
#include <symengine/dict.h>

using SymEngine::RCP;
using SymEngine::GaloisField;
// using SymEngine::gf;
using SymEngine::integer_class;
using SymEngine::map_uint_mpz;

using namespace SymEngine::literals;

TEST_CASE("GaloisField : Basic", "[basic]")
{
    // RCP<const GaloisField> r1, r2, r3, r4;
    // std::vector<integer_class> a = {2_z, 3_z, 4_z};
    // std::vector<integer_class> b = {3_z, 3_z, 6_z, 6_z};
    // r1 = gf(a, 5_z);
    // r2 = gf(b, 5_z);
    // // std::cout << *r1 << "\n";
    // map_uint_mpz mp = r1->dict_;
    // REQUIRE(mp[0] == 2);
    // REQUIRE(mp[1] == 3);
    // REQUIRE(mp[2] == 4);
    // // std::cout << *r2 << "\n";
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 3);
    // REQUIRE(mp[1] == 3);
    // REQUIRE(mp[2] == 1);
    // REQUIRE(mp[3] == 1);
    // r3 = r1->gf_add(r2);
    // mp = r3->dict_;
    // REQUIRE(mp[1] == 1);
    // REQUIRE(mp[3] == 1);
    // r3 = r1->gf_sub(r2);
    // mp = r3->dict_;
    // REQUIRE(mp[0] == 4);
    // REQUIRE(mp[2] == 3);
    // REQUIRE(mp[3] == 4);
    // r3 = r1->gf_mul(r2);
    // mp = r3->dict_;
    // REQUIRE(mp[0] == 1);
    // REQUIRE(mp[2] == 3);
    // REQUIRE(mp[3] == 2);
    // REQUIRE(mp[4] == 2);
    // REQUIRE(mp[5] == 4);

    // a = {};
    // r1 = gf(a, 11_z);
    // r2 = r1->gf_neg();
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = r1->gf_add_ground(0_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = r1->gf_sub_ground(0_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = r1->gf_add_ground(3_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 3);
    // r2 = r1->gf_sub_ground(3_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 8);
    // r2 = r1->gf_mul_ground(0_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = r1->gf_mul_ground(3_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = gf(a, 11_z);
    // r3 = r1->gf_add(r2);
    // mp = r3->dict_;
    // REQUIRE(mp.empty());
    // r3 = r1->gf_sub(r2);
    // mp = r3->dict_;
    // REQUIRE(mp.empty());
    // a = {2_z};
    // r2 = gf(a, 11_z);
    // r3 = r1->gf_add(r2);
    // mp = r3->dict_;
    // REQUIRE(mp[0] == 2);
    // r3 = r1->gf_sub(r2);
    // mp = r3->dict_;
    // REQUIRE(mp[0] == 9);
    // r2 = r1->gf_quo_ground(3_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());

    // a = {1_z};
    // r1 = gf(a, 11_z);
    // r2 = r1->gf_neg();
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 10);
    // r2 = r1->gf_add_ground(10_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = r1->gf_add_ground(4_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 5);
    // r2 = r1->gf_sub_ground(1_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = r1->gf_sub_ground(4_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 8);
    // r2 = r1->gf_mul_ground(0_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = r1->gf_mul_ground(3_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 3);
    // r2 = r1->gf_quo_ground(3_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 4);

    // a = {1_z, 2_z, 3_z};
    // r1 = gf(a, 11_z);
    // r2 = r1->gf_neg();
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 10);
    // REQUIRE(mp[1] == 9);
    // REQUIRE(mp[2] == 8);
    // r2 = r1->gf_add_ground(4_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 5);
    // REQUIRE(mp[1] == 2);
    // REQUIRE(mp[2] == 3);
    // r2 = r1->gf_sub_ground(1_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 0);
    // REQUIRE(mp[1] == 2);
    // REQUIRE(mp[2] == 3);
    // r2 = r1->gf_mul_ground(0_z);
    // mp = r2->dict_;
    // REQUIRE(mp.empty());
    // r2 = r1->gf_mul_ground(7_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 7);
    // REQUIRE(mp[1] == 3);
    // REQUIRE(mp[2] == 10);

    // a = {3_z, 2_z, 1_z};
    // b = {8_z, 9_z, 10_z};
    // r1 = gf(a, 11_z);
    // r2 = gf(b, 11_z);
    // mp = r1->gf_sub(r2)->dict_;
    // REQUIRE(mp[0] == 6);
    // REQUIRE(mp[1] == 4);
    // REQUIRE(mp[2] == 2);
    // a = {3_z, 0_z, 0_z, 6_z, 1_z, 2_z};
    // b = {4_z, 0_z, 1_z, 0_z};
    // r1 = gf(a, 11_z);
    // r2 = gf(b, 11_z);
    // mp = r1->gf_mul(r2)->dict_;
    // REQUIRE(mp[0] == 1);
    // REQUIRE(mp[1] == 0);
    // REQUIRE(mp[2] == 3);
    // REQUIRE(mp[3] == 2);
    // REQUIRE(mp[4] == 4);
    // REQUIRE(mp[5] == 3);
    // REQUIRE(mp[6] == 1);
    // REQUIRE(mp[7] == 2);
    // REQUIRE(mp[8] == 0);

    // a = {0_z, 1_z, 2_z, 3_z, 4_z, 5_z};
    // b = {0_z, 3_z, 2_z, 1_z};
    // r1 = gf(a, 7_z);
    // r2 = gf(b, 7_z);
    // r1->gf_div(r2, outArg(r3), outArg(r4));
    // mp = r3->dict_;
    // REQUIRE(mp[0] == 0);
    // REQUIRE(mp[1] == 1);
    // REQUIRE(mp[2] == 5);
    // mp = r4->dict_;
    // REQUIRE(mp[0] == 0);
    // REQUIRE(mp[1] == 1);
    // REQUIRE(mp[2] == 6);
    // REQUIRE(eq(*r3, *(r1->gf_quo(r2))));

    // a = {0_z, 1_z, 2_z, 3_z, 4_z, 5_z};
    // b = {3_z, 2_z, 1_z};
    // r1 = gf(a, 7_z);
    // r2 = gf(b, 7_z);
    // r1->gf_div(r2, outArg(r3), outArg(r4));
    // mp = r3->dict_;
    // REQUIRE(mp[0] == 6);
    // REQUIRE(mp[1] == 0);
    // REQUIRE(mp[2] == 1);
    // REQUIRE(mp[3] == 5);
    // mp = r4->dict_;
    // REQUIRE(mp[0] == 3);
    // REQUIRE(mp[1] == 3);
    // REQUIRE(eq(*r3, *(r1->gf_quo(r2))));

    // a = {1_z};
    // b = {3_z, 2_z, 1_z};
    // r1 = gf(a, 7_z);
    // r2 = gf(b, 7_z);
    // r1->gf_div(r2, outArg(r3), outArg(r4));
    // REQUIRE(r3->dict_.empty());
    // mp = r4->dict_;
    // REQUIRE(mp[0] == 1);

    // a = {};
    // r1 = gf(a, 7_z);
    // r2 = r1->gf_lshift(5_z);
    // REQUIRE(r2->dict_.empty());
    // r1->gf_rshift(5_z, outArg(r2), outArg(r3));
    // REQUIRE(r2->dict_.empty());
    // REQUIRE(r2->dict_.empty());
    // a = {5_z, 4_z, 3_z, 2_z, 1_z};
    // r1 = gf(a, 7_z);
    // mp = r1->gf_lshift(1_z)->dict_;
    // REQUIRE(mp[0] == 0);
    // REQUIRE(mp[1] == 5);
    // REQUIRE(mp[2] == 4);
    // REQUIRE(mp[3] == 3);
    // REQUIRE(mp[4] == 2);
    // REQUIRE(mp[5] == 1);
    // mp = r1->gf_lshift(2_z)->dict_;
    // REQUIRE(mp[0] == 0);
    // REQUIRE(mp[1] == 0);
    // REQUIRE(mp[2] == 5);
    // REQUIRE(mp[3] == 4);
    // REQUIRE(mp[4] == 3);
    // REQUIRE(mp[5] == 2);
    // REQUIRE(mp[6] == 1);
    // r1->gf_rshift(0_z, outArg(r2), outArg(r3));
    // REQUIRE(eq(*r1, *r2));
    // REQUIRE(r3->dict_.empty());
    // r1->gf_rshift(5_z, outArg(r2), outArg(r3));
    // mp = r2->dict_;
    // r1->gf_rshift(1_z, outArg(r2), outArg(r3));
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 4);
    // REQUIRE(mp[1] == 3);
    // REQUIRE(mp[2] == 2);
    // REQUIRE(mp[3] == 1);
    // REQUIRE(mp[4] == 0);
    // mp = r3->dict_;
    // REQUIRE(mp[0] == 5);
    // REQUIRE(mp[1] == 0);
    // r1->gf_rshift(3_z, outArg(r2), outArg(r3));
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 2);
    // REQUIRE(mp[1] == 1);
    // mp = r3->dict_;
    // REQUIRE(mp[0] == 5);
    // REQUIRE(mp[1] == 4);
    // REQUIRE(mp[2] == 3);

    // a = {8_z, 1_z, 0_z, 0_z, 1_z};
    // r1 = gf(a, 11_z);
    // r2 = r1->gf_pow(0_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 1);
    // REQUIRE(mp.size() == 1);
    // r2 = r1->gf_pow(1_z);
    // REQUIRE(eq (*r2, *r1));
    // r2 = r1->gf_pow(2_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 9);
    // REQUIRE(mp[1] == 5);
    // REQUIRE(mp[2] == 1);
    // REQUIRE(mp[4] == 5);
    // REQUIRE(mp[5] == 2);
    // REQUIRE(mp[8] == 1);
    // r2 = r1->gf_pow(5_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 10);
    // REQUIRE(mp[1] == 9);
    // REQUIRE(mp[2] == 5);
    // REQUIRE(mp[3] == 2);
    // REQUIRE(mp[4] == 5);
    // REQUIRE(mp[6] == 6);
    // REQUIRE(mp[7] == 6);
    // REQUIRE(mp[8] == 10);
    // REQUIRE(mp[9] == 6);
    // REQUIRE(mp[10] == 9);
    // REQUIRE(mp[11] == 10);
    // REQUIRE(mp[12] == 2);
    // REQUIRE(mp[13] == 6);
    // REQUIRE(mp[14] == 10);
    // REQUIRE(mp[16] == 7);
    // REQUIRE(mp[17] == 5);
    // REQUIRE(mp[20] == 1);
    // r2 = r1->gf_pow(8_z);
    // r3 = r1->gf_pow(4_z);

    // integer_class LC;
    // a = {};
    // r1 = gf(a, 11_z);
    // r1->gf_monic(LC, outArg(r2));
    // REQUIRE(LC == 0_z);
    // REQUIRE(eq(*r2, *r1));
    // a = {1_z};
    // r1 = gf(a, 11_z);
    // r1->gf_monic(LC, outArg(r2));
    // REQUIRE(LC == 1_z);
    // REQUIRE(eq(*r2, *r1));
    // a = {2_z};
    // r1 = gf(a, 11_z);
    // r1->gf_monic(LC, outArg(r2));
    // REQUIRE(LC == 2_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 1_z);
    // a = {4_z, 3_z, 2_z, 1_z};
    // r1 = gf(a, 11_z);
    // r1->gf_monic(LC, outArg(r2));
    // REQUIRE(LC == 1_z);
    // REQUIRE(eq(*r2, *r1));
    // a = {5_z, 4_z, 3_z, 2_z};
    // r1 = gf(a, 11_z);
    // r1->gf_monic(LC, outArg(r2));
    // REQUIRE(LC == 2_z);
    // mp = r2->dict_;
    // REQUIRE(mp[0] == 8);
    // REQUIRE(mp[1] == 2);
    // REQUIRE(mp[2] == 7);
    // REQUIRE(mp[3] == 1);

    // a = {};
    // r1 = gf(a, 11_z);
    // r2 = gf(a, 11_z);
    // REQUIRE(r1->gf_gcd(r2)->dict_.empty());
    // a = {2_z};
    // r1 = gf(a, 11_z);
    // mp = r1->gf_gcd(r2)->dict_;
    // REQUIRE(mp[0] == 1);
    // REQUIRE(eq(*r1->gf_gcd(r2), *r2->gf_gcd(r1)));
    // a = {0_z, 1_z};
    // r1 = gf(a, 11_z);
    // r3 = r1->gf_gcd(r2);
    // REQUIRE(eq(*r1, *r3));
    // REQUIRE(eq(*r3, *r2->gf_gcd(r1)));

    // a = {0_z, 3_z};
    // r1 = gf(a, 11_z);
    // r2 = gf(a, 11_z);
    // REQUIRE(eq(*r1->gf_gcd(r2), *r2->gf_gcd(r1)));
    // mp = r1->gf_gcd(r2)->dict_;
    // REQUIRE(mp[1] == 1);

    // a = {7_z, 8_z, 1_z};
    // r1 = gf(a, 11_z);
    // a = {7_z, 1_z, 7_z, 1_z};
    // r2 = gf(a, 11_z);
    // REQUIRE(eq(*r1->gf_gcd(r2), *r2->gf_gcd(r1)));
    // mp = r1->gf_gcd(r2)->dict_;
    // REQUIRE(mp[0] == 7);
    // REQUIRE(mp[1] == 1);

    // a = {};
    // r1 = gf(a, 11_z);
    // r2 = gf(a, 11_z);
    // REQUIRE(r1->gf_lcm(r2)->dict_.empty());
    // a = {2_z};
    // r1 = gf(a, 11_z);
    // REQUIRE(r1->gf_lcm(r2)->dict_.empty());
    // REQUIRE(eq(*r1->gf_lcm(r2), *r2->gf_lcm(r1)));
    // r2 = gf(a, 11_z);
    // mp = r1->gf_lcm(r2)->dict_;
    // REQUIRE(mp[0] == 1);
    // a = {0_z, 1_z};
    // r1 = gf(a, 11_z);
    // a = {};
    // r2 = gf(a, 11_z);
    // r3 = r1->gf_lcm(r2);
    // REQUIRE(r3->dict_.empty());
    // REQUIRE(eq(*r3, *r2->gf_lcm(r1)));
    // a = {0_z, 3_z};
    // r1 = gf(a, 11_z);
    // r2 = gf(a, 11_z);
    // REQUIRE(eq(*r1->gf_lcm(r2), *r2->gf_lcm(r1)));
    // mp = r1->gf_lcm(r2)->dict_;
    // REQUIRE(mp[1] == 1);
    // a = {7_z, 8_z, 1_z};
    // r1 = gf(a, 11_z);
    // a = {7_z, 1_z, 7_z, 1_z};
    // r2 = gf(a, 11_z);
    // REQUIRE(eq(*r1->gf_lcm(r2), *r2->gf_lcm(r1)));
    // mp = r1->gf_lcm(r2)->dict_;
    // REQUIRE(mp[0] == 7);
    // REQUIRE(mp[1] == 8);
    // REQUIRE(mp[2] == 8);
    // REQUIRE(mp[3] == 8);
    // REQUIRE(mp[4] == 1);
}
