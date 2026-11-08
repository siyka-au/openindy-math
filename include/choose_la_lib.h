#ifndef OI_MATH_CHOOSE_LA_LIB_H_
#define OI_MATH_CHOOSE_LA_LIB_H_

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

#endif  // OI_MATH_CHOOSE_LA_LIB_H_
