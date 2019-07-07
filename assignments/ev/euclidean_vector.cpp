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

double& EuclideanVector::operator[](int i) {
  assert(i <= this->numDimensions_);
  return this->magnitudes_[i];
};

double EuclideanVector::operator[](int i) const {
  assert(i <= this->numDimensions_);
  return this->magnitudes_[i];
};

EuclideanVector& EuclideanVector::operator+=(EuclideanVector& v) {
  assert(this->numDimensions_ == v.numDimensions_);
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] += v.magnitudes_[i];
  }
  return *this;
}

EuclideanVector& EuclideanVector::operator-=(EuclideanVector& v) {
  assert(this->numDimensions_ == v.numDimensions_);
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] -= v.magnitudes_[i];
  }
  return *this;
}

