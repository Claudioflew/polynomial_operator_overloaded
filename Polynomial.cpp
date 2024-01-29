#include "Polynomial.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Polynomial::Polynomial() {}

// Comment 2: We need this overloaded constructor for overloaded operator definition.
Polynomial::Polynomial(vector<int> teVec) { setTermsVec(teVec); }

Polynomial::~Polynomial() {}

void Polynomial::enterTerms() {
  unsigned int numTe;
  cout << "\nEnter number of polynomial terms: ";
  cin >> numTe;

  vector<int> teVec(numTe, 0);
  for (int i = 0; i < numTe; i++) {
    unsigned int coe, exp;
    cout << "Enter coefficient: ";
    cin >> coe;
    cout << "Enter exponent: ";
    cin >> exp;

    // Comment 3: We want to create an ordered vector containing coefficients from x^0.
    if (exp >= teVec.size()) {
      int ind = teVec.size();
      while (ind < exp) {
        teVec.push_back(0);
        ind++;
      }
      teVec.push_back(coe);
    } else { teVec[exp] += coe; }
  }
  // Comment 4: We could directly edit termsVec member data, but we are supposed to make set function as well. So, setTermsVec() should be responsible for this.
  setTermsVec(teVec);
}

void Polynomial::setTermsVec(std::vector<int> teVec) {
  termsVec.clear();
  for (int coe : teVec)
    termsVec.push_back(coe);
}

vector<int> Polynomial::getTermsVec() const { return termsVec; }

void Polynomial::printPolynomial() const {
  vector<int> temp{getTermsVec()};
  string s = "";
  bool empty = true;

  for (int i = 0; i < temp.size(); i++) {
    // Comment 5: If the coefficient is 0, we don't need to print that term.
    if (temp[i] == 0) { continue; } 
    else {
      // Comment 6: Flag variable here to determine the vector is empty or not.
      empty = false;
      // Comment 7: We have to be careful if we need "+" to be printed.
      if (i == 0) { s += to_string(temp[i]); } 
      else if (i == 1) {
        if (temp[i] > 0 && s != "") {
          s += "+" + to_string(temp[i]) + "x";
        } else { s += to_string(temp[i]) + "x"; }
      } else if (temp[i] > 0 && s != "") {
        s += "+" + to_string(temp[i]) + "x^" + to_string(i);
      } else { s += to_string(temp[i]) + "x^" + to_string(i); }
    }
  }
  empty? cout << "0" << endl: cout << s << endl;
}

Polynomial Polynomial::operator+(const Polynomial& mou) const {
  // Comment 8: We want to return a temporary unnamed object here.
  vector<int> temp{termsVec};
  for (int i = 0; i < mou.termsVec.size(); i++) {
    if (i >= temp.size()) {
      temp.push_back(mou.termsVec[i]);
    } else {
      temp[i] += mou.termsVec[i];
    }
  }
  return Polynomial(temp);
}

Polynomial Polynomial::operator-(const Polynomial& mou) const {
  vector<int> temp{termsVec};
  for (int i = 0; i < mou.termsVec.size(); i++) {
    if (i >= temp.size()) {
      // Comment 9: We need to use negation here.
      temp.push_back(-(mou.termsVec[i]));
    } else {
      temp[i] -= mou.termsVec[i];
    }
  }
  return Polynomial(temp);
}

Polynomial& Polynomial::operator=(const Polynomial& mou) {
  // Comment 10: Don't forget to reset the vector, otherwise larger index terms would remain.
  termsVec.clear();
  for (int coe: mou.termsVec) {
    termsVec.push_back(coe);
  }
  return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& mou) {
  for (int i = 0; i < mou.termsVec.size(); i++) {
    if (i >= termsVec.size()) {
      termsVec.push_back(mou.termsVec[i]);
    } else {
      termsVec[i] += mou.termsVec[i];
    }
  }
  return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& mou) {
  for (int i = 0; i < mou.termsVec.size(); i++) {
    if (i >= termsVec.size()) {
      termsVec.push_back(-(mou.termsVec[i]));
    } else {
      termsVec[i] -= mou.termsVec[i];
    }
  }
  return *this;
}