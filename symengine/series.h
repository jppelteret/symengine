/**
 *  \file series.h
 *  Class for univariate series.
 *
 **/
#ifndef SYMENGINE_SERIES_H
#define SYMENGINE_SERIES_H

#include <list>

#include <symengine/polynomial.h>

namespace SymEngine {
//! UnivariateSeries Class
class UnivariateSeries : public Basic {
public:
    //! `var_` : Variable of the UnivariateSeries
    //! `poly_` : holds the UnivariatePolynomial of the series
    //! `prec_` : precision of the UnivariateSeries, i.e. self = poly + O(var^prec)
    // UnivariateSeries 1 + 2*x + x**2 + O(x**5) has dict_ = {{0, 1}, {1, 2}, {2, 1}} with var_ = "x" and prec_ = 5
    RCP<const Symbol> var_;
    RCP<const UnivariatePolynomial> poly_;
    unsigned int prec_;
public:
    IMPLEMENT_TYPEID(UNIVARIATESERIES)
    //! Constructor of UnivariateSeries class
    UnivariateSeries(const RCP<const Symbol> &var, const unsigned int &precision, const RCP<const UnivariatePolynomial> &poly);
    UnivariateSeries(const RCP<const Symbol> &var, const unsigned int& precision, const unsigned int& max_exp, map_uint_mpz&& dict);
    UnivariateSeries(const RCP<const Symbol> &var, const unsigned int &precision, const map_uint_mpz &dict);
    //! Constructor using a dense vector of mpz_class coefficients
    UnivariateSeries(const RCP<const Symbol> &var, const unsigned int &precision, const std::vector<mpz_class> &v);

    static RCP<const UnivariateSeries> create(const RCP<const Symbol> &var,
            const unsigned int &prec, const std::vector<mpz_class> &v) {
        return make_rcp<const UnivariateSeries>(var, prec, v);
    }

    //! \return true if canonical
    bool is_canonical(const UnivariatePolynomial&, const unsigned int &);
    //! \return size of the hash
    std::size_t __hash__() const;
    /*! Equality comparator
     * \param o - Object to be compared with
     * \return whether the 2 objects are equal
     * */

    bool operator==(const UnivariateSeries &o) const {
        return (eq(*var_, *o.var_) and poly_->__eq__(*o.poly_) and prec_ == o.prec_);
    }
    bool __eq__(const Basic &o) const;
    int compare(const Basic &o) const;

    std::string __str__() const;
    virtual vec_basic get_args() const { return {}; }
    virtual void accept(Visitor &v) const;

};


inline RCP<const UnivariateSeries> univariate_series(RCP<const Symbol> i,       unsigned int prec, const map_uint_mpz& dict)
{
    return make_rcp<const UnivariateSeries>(i, prec, dict);
}

RCP<const UnivariateSeries> add_uni_series (const UnivariateSeries& a, const UnivariateSeries &b);
RCP<const UnivariateSeries> neg_uni_series (const UnivariateSeries& a);
RCP<const UnivariateSeries> sub_uni_series (const UnivariateSeries& a, const UnivariateSeries &b);
RCP<const UnivariateSeries> mul_uni_series (const UnivariateSeries& a, const UnivariateSeries &b);

template <typename Poly, typename Coeff, typename SeriesClass, bool symbolic = false>
class Series : public Number {
private:
    Poly p_;
    std::string var_;
    long degree_;
public:
    virtual void accept(Visitor &v) const;

    virtual bool is_zero() const { return false; }

    virtual bool is_one() const { return false; }

    virtual bool is_minus_one() const { return false; }

    virtual bool is_negative() const { return false; }

    virtual bool is_positive() const { return false; }

    /*
     * int ldegree(Poly &s);
     * Coeff& find_cf(Poly &s, int n);
     * Poly pow(Poly &s, int n);
     * Poly mul(Poly &a, Poly &b, unsigned prec);
     * Poly diff(Poly &a, Poly &var);
     * Poly integrate(Poly &a, Poly &var);
     * Coeff root(Coeff &c, unsigned n);
     * Poly subs(Poly &s, Poly &var, Poly& new, unsigned prec);
     */

    RCP<const SeriesClass> static series(RCP<const Basic> &x, const Poly& var,
                                         const std::string &varname, const unsigned prec);
};

}  //SymEngine
#endif
