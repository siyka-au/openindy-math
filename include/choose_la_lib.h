#ifndef CHOOSELALIB_H
#define CHOOSELALIB_H

#include "global.h"
#include "oi_mat.h"
#include "oi_vec.h"

namespace oi {
namespace math {

/*!
 * \brief The ChooseLALib class
 */
class OI_MATH_EXPORT ChooseLALib {
 public:
  enum class LinearAlgebraLibrary { Armadillo };

  static void setLinearAlgebra(LinearAlgebraLibrary lib);
};

}  // namespace math
}  // namespace oi

#endif  // CHOOSELALIB_H
