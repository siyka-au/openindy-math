#include "chooselalib.h"

#include "laarmadillo.h"

using namespace oi::math;

/*!
 * \brief ChooseLALib::setLinearAlgebra
 * Decide which linear algebra library to use
 * \param lib
 */
void ChooseLALib::setLinearAlgebra(LinearAlgebraLibrary lib) {
  switch (lib) {
    case (LinearAlgebraLibrary::Armadillo): {
      // one backend object for the process, shared by OiVec and OiMat: the
      // two pointers are non-owning, and choosing again must not leak
      static LAArmadillo armadillo;
      OiVec::myLinearAlgebra = &armadillo;
      OiMat::myLinearAlgebra = &armadillo;
      break;
    }
    default:
      OiVec::myLinearAlgebra = nullptr;
      OiMat::myLinearAlgebra = nullptr;
      break;
  }
}
