#include "assignments/ev/euclidean_vector.h"
#include <cassert>

#include <algorithm>  // Look at these - they are helpful https://en.cppreference.com/w/cpp/algorithm

std::ostream& operator<<(std::ostream& os, const EuclideanVector& v) {
  os << std::to_string(v.numDimensions_);
  return os;
}

const int& EuclideanVector::GetNumDimensions() {
  return numDimensions_;
}


/**
const std::vector<double>& EuclideanVector::GetVector(){
  return vector_;
}

EuclideanVector& EuclideanVector::operator+=(EuclideanVector& v) {
  // TODO: assert that the two vectors are the same

  auto thisIter = this->vector_.begin();
  auto otherIter = v.vector_.cbegin();
  while(thisIter != this->vector_.end()){
    thisIter += *otherIter;

    thisIter++;
    otherIter++;
  }
  return *this;
}

// Setter
double& EuclideanVector::operator[](int i) {
  assert(i <= this->GetNumDimensions());
  return this->vector_.at(i);
};
double EuclideanVector::operator[](int i) const {
  assert(i <= this->GetNumDimensions());
  return this->vector_.at(i);
};
**/
