#include "assignments/ev/euclidean_vector.h"

#include <algorithm>  // Look at these - they are helpful https://en.cppreference.com/w/cpp/algorithm

std::ostream& operator<<(std::ostream& os, const EuclideanVector& v) {
  os << std::to_string(v.numDimensions_);
  return os;
}

const int& EuclideanVector::GetNumDimensions() {
  return numDimensions_;
}

const std::vector<double>& EuclideanVector::GetVector(){
  return vector_;
}
