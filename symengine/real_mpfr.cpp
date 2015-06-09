/**
 *  \file RealMPFR.h
 *  Class for RealMPFR built on top of Number class
 *
 **/
#include <cmath>
#include "basic.h"
#include "real_double.h"
#include "complex_double.h"
#include "real_mpfr.h"

#ifdef HAVE_SYMENGINE_MPFR
namespace SymEngine {

RealMPFR::RealMPFR(mpfr_class i, mpfr_rnd_t rnd) : i{std::move(i)}, rnd_(rnd)  {

}

std::size_t RealMPFR::__hash__() const
{
    std::hash<mpfr_srcptr> hash_fn;
    return hash_fn(i.get_mpfr_t());
}

bool RealMPFR::__eq__(const Basic &o) const
{
    if (is_a<RealMPFR>(o)) {
        const RealMPFR &s = static_cast<const RealMPFR &>(o);
        return mpfr_cmp(this->i.get_mpfr_t(), s.i.get_mpfr_t()) == 0;
    }
    return false;
}

int RealMPFR::compare(const Basic &o) const
{
    SYMENGINE_ASSERT(is_a<RealMPFR>(o))
    const RealMPFR &s = static_cast<const RealMPFR &>(o);
    int cmp = mpfr_cmp(this->i.get_mpfr_t(), s.i.get_mpfr_t());
    if (cmp == 0) return 0;
    return cmp > 0 ? 1 : -1;
}

/*! Add RealMPFRs
 * \param other of type Integer
 * */
RCP<const Number> RealMPFR::addreal(const Integer &other) const {
    mpfr_class t(get_prec());
    mpfr_add_z(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpz_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Add RealMPFRs
 * \param other of type Rational
 * */
RCP<const Number> RealMPFR::addreal(const Rational &other) const {
    mpfr_class t(get_prec());
    mpfr_add_q(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpq_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Add RealMPFRs
 * \param other of type Complex
 * */
RCP<const Number> RealMPFR::addreal(const Complex &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Add RealMPFRs
 * \param other of type RealDouble
 * */
RCP<const Number> RealMPFR::addreal(const RealDouble &other) const {
    mpfr_class t(get_prec());
    mpfr_add_d(t.get_mpfr_t(), i.get_mpfr_t(), other.i, rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Add RealMPFRs
 * \param other of type ComplexDouble
 * */
RCP<const Number> RealMPFR::addreal(const ComplexDouble &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Add RealMPFRs
 * \param other of type RealMPFR
 * */
RCP<const Number> RealMPFR::addreal(const RealMPFR &other) const {
    mpfr_class t(std::max(get_prec(), other.get_prec()));
    mpfr_add(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Subtract RealMPFRs
 * \param other of type Integer
 * */
RCP<const Number> RealMPFR::subreal(const Integer &other) const {
    mpfr_class t(get_prec());
    mpfr_sub_z(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpz_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Subtract RealMPFRs
 * \param other of type Rational
 * */
RCP<const Number> RealMPFR::subreal(const Rational &other) const {
    mpfr_class t(get_prec());
    mpfr_sub_q(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpq_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Subtract RealMPFRs
 * \param other of type Complex
 * */
RCP<const Number> RealMPFR::subreal(const Complex &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Subtract RealMPFRs
 * \param other of type RealDouble
 * */
RCP<const Number> RealMPFR::subreal(const RealDouble &other) const {
    mpfr_class t(get_prec());
    mpfr_sub_d(t.get_mpfr_t(), i.get_mpfr_t(), other.i, rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Subtract RealMPFRs
 * \param other of type ComplexDouble
 * */
RCP<const Number> RealMPFR::subreal(const ComplexDouble &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Subtract RealMPFRs
 * \param other of type RealMPFR
 * */
RCP<const Number> RealMPFR::subreal(const RealMPFR &other) const {
    mpfr_class t(std::max(get_prec(), other.get_prec()));
    mpfr_sub(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Subtract RealMPFRs
 * \param other of type Integer
 * */
RCP<const Number> RealMPFR::rsubreal(const Integer &other) const {
    mpfr_class t(get_prec());
    mpfr_z_sub(t.get_mpfr_t(), other.i.get_mpz_t(), i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Subtract RealMPFRs
 * \param other of type Rational
 * */
RCP<const Number> RealMPFR::rsubreal(const Rational &other) const {
    mpfr_class t(get_prec());
    mpfr_sub_q(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpq_t(), rnd_);
    mpfr_neg(t.get_mpfr_t(), t.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Subtract RealMPFRs
 * \param other of type Complex
 * */
RCP<const Number> RealMPFR::rsubreal(const Complex &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Subtract RealMPFRs
 * \param other of type RealDouble
 * */
RCP<const Number> RealMPFR::rsubreal(const RealDouble &other) const {
    mpfr_class t(get_prec());
    mpfr_d_sub(t.get_mpfr_t(), other.i, i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Subtract RealMPFRs
 * \param other of type ComplexDouble
 * */
RCP<const Number> RealMPFR::rsubreal(const ComplexDouble &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Multiply RealMPFRs
 * \param other of type Integer
 * */
RCP<const Number> RealMPFR::mulreal(const Integer &other) const {
    mpfr_class t(get_prec());
    mpfr_mul_z(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpz_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Multiply RealMPFRs
 * \param other of type Rational
 * */
RCP<const Number> RealMPFR::mulreal(const Rational &other) const {
    mpfr_class t(get_prec());
    mpfr_mul_q(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpq_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Multiply RealMPFRs
 * \param other of type Complex
 * */
RCP<const Number> RealMPFR::mulreal(const Complex &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Multiply RealMPFRs
 * \param other of type RealMPFR
 * */
RCP<const Number> RealMPFR::mulreal(const RealDouble &other) const {
    mpfr_class t(get_prec());
    mpfr_mul_d(t.get_mpfr_t(), i.get_mpfr_t(), other.i, rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Multiply RealMPFRs
 * \param other of type ComplexDouble
 * */
RCP<const Number> RealMPFR::mulreal(const ComplexDouble &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Multiply RealMPFRs
 * \param other of type RealMPFR
 * */
RCP<const Number> RealMPFR::mulreal(const RealMPFR &other) const {
    mpfr_class t(std::max(get_prec(), other.get_prec()));
    mpfr_mul(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Divide RealMPFRs
 * \param other of type Integer
 * */
RCP<const Number> RealMPFR::divreal(const Integer &other) const {
    mpfr_class t(get_prec());
    mpfr_div_z(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpz_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Divide RealMPFRs
 * \param other of type Rational
 * */
RCP<const Number> RealMPFR::divreal(const Rational &other) const {
    mpfr_class t(get_prec());
    mpfr_div_q(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpq_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Divide RealMPFRs
 * \param other of type Complex
 * */
RCP<const Number> RealMPFR::divreal(const Complex &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Divide RealMPFRs
 * \param other of type RealDouble
 * */
RCP<const Number> RealMPFR::divreal(const RealDouble &other) const {
    mpfr_class t(get_prec());
    mpfr_div_d(t.get_mpfr_t(), i.get_mpfr_t(), other.i, rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Divide RealMPFRs
 * \param other of type ComplexDouble
 * */
RCP<const Number> RealMPFR::divreal(const ComplexDouble &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Divide RealMPFRs
 * \param other of type RealMPFR
 * */
RCP<const Number> RealMPFR::divreal(const RealMPFR &other) const {
    mpfr_class t(std::max(get_prec(), other.get_prec()));
    mpfr_div(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Divide RealMPFRs
 * \param other of type Integer
 * */
RCP<const Number> RealMPFR::rdivreal(const Integer &other) const {
    mpfr_class t(get_prec());
    mpfr_div_z(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpz_t(), rnd_);
    mpfr_pow_si(t.get_mpfr_t(), t.get_mpfr_t(), -1, rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Divide RealMPFRs
 * \param other of type Rational
 * */
RCP<const Number> RealMPFR::rdivreal(const Rational &other) const {
    mpfr_class t(get_prec());
    mpfr_div_q(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpq_t(), rnd_);
    mpfr_pow_si(t.get_mpfr_t(), t.get_mpfr_t(), -1, rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Divide RealMPFRs
 * \param other of type Complex
 * */
RCP<const Number> RealMPFR::rdivreal(const Complex &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Divide RealMPFRs
 * \param other of type RealDouble
 * */
RCP<const Number> RealMPFR::rdivreal(const RealDouble &other) const {
    mpfr_class t(get_prec());
    mpfr_d_div(t.get_mpfr_t(), other.i, i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Divide RealMPFRs
 * \param other of type ComplexDouble
 * */
RCP<const Number> RealMPFR::rdivreal(const ComplexDouble &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Raise RealMPFR to power `other`
 * \param other of type Integer
 * */
RCP<const Number> RealMPFR::powreal(const Integer &other) const {
    mpfr_class t(get_prec());
    mpfr_pow_z(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpz_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Raise RealMPFR to power `other`
 * \param other of type Rational
 * */
RCP<const Number> RealMPFR::powreal(const Rational &other) const {
    if (mpfr_cmp_si(i.get_mpfr_t(), 0) < 0) {
#ifdef HAVE_SYMENGINE_MPC
        throw std::runtime_error("Not Implemented.");
#else
        throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
    }
    mpfr_class t(get_prec());
    mpfr_set_q(t.get_mpfr_t(), other.i.get_mpq_t(), rnd_);
    mpfr_pow(t.get_mpfr_t(), i.get_mpfr_t(), t.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Raise RealMPFR to power `other`
 * \param other of type Complex
 * */
RCP<const Number> RealMPFR::powreal(const Complex &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Raise RealMPFR to power `other`
 * \param other of type RealDouble
 * */
RCP<const Number> RealMPFR::powreal(const RealDouble &other) const {
    if (mpfr_cmp_si(i.get_mpfr_t(), 0) < 0) {
#ifdef HAVE_SYMENGINE_MPC
        throw std::runtime_error("Not Implemented.");
#else
        throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
    }
    mpfr_class t(get_prec());
    mpfr_set_d(t.get_mpfr_t(), other.i, rnd_);
    mpfr_pow(t.get_mpfr_t(), i.get_mpfr_t(), t.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Raise RealMPFR to power `other`
 * \param other of type ComplexDouble
 * */
RCP<const Number> RealMPFR::powreal(const ComplexDouble &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

/*! Raise RealMPFR to power `other`
 * \param other of type RealMPFR
 * */
RCP<const Number> RealMPFR::powreal(const RealMPFR &other) const {
    if (mpfr_cmp_si(i.get_mpfr_t(), 0) < 0) {
#ifdef HAVE_SYMENGINE_MPC
        throw std::runtime_error("Not Implemented.");
#else
        throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
    }
    mpfr_class t(std::max(get_prec(), other.get_prec()));
    mpfr_pow(t.get_mpfr_t(), i.get_mpfr_t(), other.i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Raise `other` to power RealMPFR
 * \param other of type Integer
 * */
RCP<const Number> RealMPFR::rpowreal(const Integer &other) const {
    if (other.is_negative()) {
#ifdef HAVE_SYMENGINE_MPC
        throw std::runtime_error("Not Implemented.");
#else
        throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
    }
    mpfr_class t(get_prec());
    mpfr_set_z(t.get_mpfr_t(), other.i.get_mpz_t(), rnd_);
    mpfr_pow(t.get_mpfr_t(), t.get_mpfr_t(), i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Raise `other` to power RealMPFR
 * \param other of type Rational
 * */
RCP<const Number> RealMPFR::rpowreal(const Rational &other) const {
    if (other.is_negative()) {
#ifdef HAVE_SYMENGINE_MPC
        throw std::runtime_error("Not Implemented.");
#else
        throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
    }
    mpfr_class t(get_prec());
    mpfr_set_q(t.get_mpfr_t(), other.i.get_mpq_t(), rnd_);
    mpfr_pow(t.get_mpfr_t(), t.get_mpfr_t(), i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Raise `other` to power RealMPFR
 * \param other of type Complex
 * */
RCP<const Number> RealMPFR::rpowreal(const Complex &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}


/*! Raise `other` to power RealMPFR
 * \param other of type RealDouble
 * */
RCP<const Number> RealMPFR::rpowreal(const RealDouble &other) const {
    if (mpfr_cmp_si(i.get_mpfr_t(), 0) < 0) {
#ifdef HAVE_SYMENGINE_MPC
        throw std::runtime_error("Not Implemented.");
#else
        throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
    }
    mpfr_class t(get_prec());
    mpfr_set_d(t.get_mpfr_t(), other.i, rnd_);
    mpfr_pow(t.get_mpfr_t(), t.get_mpfr_t(), i.get_mpfr_t(), rnd_);
    return rcp(new RealMPFR(std::move(t)));
}

/*! Raise `other` to power RealMPFR
* \param other of type ComplexDouble
* */
RCP<const Number> RealMPFR::rpowreal(const ComplexDouble &other) const {
#ifdef HAVE_SYMENGINE_MPC
    throw std::runtime_error("Not Implemented.");
#else
    throw std::runtime_error("Result is complex. Recompile with MPC support.");
#endif
}

} // SymEngine
#endif //HAVE_SYMENGINE_MPFR