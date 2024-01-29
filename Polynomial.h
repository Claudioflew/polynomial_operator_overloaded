#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <vector>

class Polynomial {
public:
  Polynomial();
  Polynomial(std::vector<int>);
  ~Polynomial();

  void enterTerms(); 
  void setTermsVec(std::vector<int>);

  std::vector<int> getTermsVec() const;
  void printPolynomial() const;

  // Comment 1: We have to pay attention to three points when we define overloaded operator (member func); (1) pass by value or reference, (2) constness, (3) return by value or reference.
  Polynomial operator+(const Polynomial&) const;
  Polynomial operator-(const Polynomial&) const;
  Polynomial& operator=(const Polynomial&);
  Polynomial& operator+=(const Polynomial&);
  Polynomial& operator-=(const Polynomial&);

private:
 std::vector<int> termsVec;
};

#endif