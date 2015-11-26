#include "catch.hpp"

#include <symengine/integer.h>
#include <symengine/rational.h>
#include <symengine/number.h>

using SymEngine::print_stack_on_segfault;
using SymEngine::RCP;
using SymEngine::Integer;
using SymEngine::integer;
using SymEngine::Rational;
using SymEngine::rational;
using SymEngine::Number;

TEST_CASE("Rational", "[rational]")
{
    RCP<const Integer> i2 = integer(2);
    RCP<const Integer> i5 = integer(5);
    RCP<const Integer> i10 = integer(10);
    RCP<const Integer> i25 = integer(25);
    
    RCP<const Number> q10_25 = Rational::from_two_ints(*i10, *i25);
    RCP<const Number> q2_5 = Rational::from_two_ints(*i2, *i5);
    RCP<const Rational> q = rational(2, 5);

    REQUIRE(q10_25->__eq__(*q2_5));
    REQUIRE(q10_25->__eq__(*q));
}

TEST_CASE("Rational is_power, nth root", "[rational is_power, nth root]")
{
    RCP<const Rational> q2_5 = rational(2,5);
    RCP<const Rational> qm1_27 = rational(-1, 27);
    RCP<const Rational> q9_25 = rational(9,25);
    RCP<const Rational> qm1_3 = rational(-1,3);
    RCP<const Rational> q3_5 = rational(3,5);
    RCP<const Rational> res;

    REQUIRE(not q2_5->is_perfect_power());
    REQUIRE(qm1_27->is_perfect_power());
    REQUIRE(q9_25->is_perfect_power());
    REQUIRE(not q2_5->r_nth_root(outArg(res), 2));
    REQUIRE(qm1_27->r_nth_root(outArg(res), 3));
    REQUIRE(res->__eq__(*qm1_3));
    REQUIRE(q9_25->r_nth_root(outArg(res), 2));
    REQUIRE(res->__eq__(*q3_5));
}

