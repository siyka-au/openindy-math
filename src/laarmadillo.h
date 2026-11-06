#ifndef LAARMADILLO_H
#define LAARMADILLO_H

#include "armadillo"
#include "global.h"
#include "linearalgebra.h"
#include "oimat.h"
#include "oivec.h"

namespace oi {
namespace math {

/*!
 * \brief The LAArmadillo class
 * LinearAlgebra implementation using the armadillo library
 */
class OI_MATH_EXPORT LAArmadillo : public LinearAlgebra {
 public:
  LAArmadillo();
  ~LAArmadillo() override;

  void addIn(OiVec& result, const OiVec& v1, const OiVec& v2) override;
  void addIn(OiMat& result, const OiMat& m1, const OiMat& m2) override;
  void substract(OiVec& result, const OiVec& v1, const OiVec& v2) override;
  void substract(OiMat& result, const OiMat& m1, const OiMat& m2) override;
  void multiply(OiMat& result, const OiMat& m1, const OiMat& m2) override;
  void multiply(OiVec& result, const OiMat& m, const OiVec& v) override;
  void multiply(OiMat& result, const double& s, const OiMat& m) override;
  void multiply(OiVec& result, const double& s, const OiVec& v) override;
  bool invert(OiMat& result, const OiMat& m) override;
  void transpose(OiMat& result, const OiMat& m) override;
  bool svd(OiMat& u, OiVec& d, OiMat& v, const OiMat& x) override;
  void cross(OiVec& result, const OiVec& a, const OiVec& b) override;
  void dot(double& result, const OiVec& a, const OiVec& b) override;
  void det(double& result, const OiMat& a) override;
  bool solve(OiVec& x, const OiMat& A, const OiVec& b) override;
  bool solve(OiMat& X, const OiMat& A, const OiMat& B) override;

 private:
  void oiVec2Arma(arma::vec& result, const OiVec& v);
  void oiMat2Arma(arma::mat& result, const OiMat& m);
  void arma2OiVec(OiVec& result, const arma::vec& v);
  void arma2OiMat(OiMat& result, const arma::mat& m);
};

}  // namespace math
}  // namespace oi

#endif  // LAARMADILLO_H
