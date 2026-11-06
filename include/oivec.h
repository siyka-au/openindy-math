#ifndef OIVEC_H
#define OIVEC_H

#include <stdexcept>
#include <string>
#include <vector>

#include "global.h"

namespace oi {
namespace math {

class LinearAlgebra;
class OiMat;

using namespace std;

/*!
 * \brief The OiVec class
 */
class OI_MATH_EXPORT OiVec {
 public:
  OiVec();
  explicit OiVec(const int& size);
  OiVec(const OiVec&) = default;
  // A moved-from OiVec is an empty (size 0) vector, which is a valid state.
  // There is deliberately no move assignment: operator= only accepts a vector
  // of equal size (or into an empty one) and throws otherwise, so assignment
  // has to keep going through it.
  OiVec(OiVec&&) noexcept = default;
  ~OiVec();

  static LinearAlgebra* myLinearAlgebra;

 private:
  vector<double> values;

 public:
  [[nodiscard]] double getAt(int pos) const;
  [[nodiscard]] int getSize() const;

  void set(vector<double> v);
  void setAt(const int& pos, const double& value);

  void add(const double& value);
  void removeLast();

  void replace(const OiVec&);

  OiVec& operator=(const OiVec&);
  OiVec operator+(const OiVec&) const;
  OiVec operator-(const OiVec&) const;
  OiVec& operator+=(const OiVec&);
  OiVec& operator-=(const OiVec&);
  friend OiVec operator*(const OiVec& v, const double value) {
    return OiVec::mult(value, v);
  }
  friend OiVec operator*(const double value, const OiVec& v) {
    return OiVec::mult(value, v);
  }
  friend OiVec operator/(const OiVec& v, const double value) {
    return OiVec::mult((1.0 / value), v);
  }
  friend bool operator==(const OiVec& v1, const OiVec& v2) {
    if (v1.getSize() != v2.getSize()) {
      return false;
    }

    for (int i = 0; i < v1.getSize(); i++) {
      if (v1.getAt(i) != v2.getAt(i)) {
        return false;
      }
    }

    return true;
  }

  void normalize();

  [[nodiscard]] OiMat t() const;

  static void cross(OiVec& result, const OiVec& a, const OiVec& b);
  static void dot(double& result, const OiVec& a, const OiVec& b);

  static void concatenateRotations(OiVec& q, const OiVec& q1, const OiVec& q2);

  void writeTo(const std::string& filename) const;

  double length();

 private:
  static OiVec mult(const double& value, const OiVec& v);
};

}  // namespace math
}  // namespace oi

#endif  // OIVEC_H
