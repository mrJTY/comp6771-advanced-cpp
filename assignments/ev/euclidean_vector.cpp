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

EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& v) {
  assert(this->numDimensions_ == v.numDimensions_);
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] += v.magnitudes_[i];
  }
  return *this;
}

EuclideanVector operator+(const EuclideanVector& lhs, const EuclideanVector& rhs){
  assert(lhs.numDimensions_ == rhs.numDimensions_);
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for(int i = 0; i < lhs.numDimensions_; ++i){
    v.magnitudes_[i] = lhs.magnitudes_[i] + rhs.magnitudes_[i];
  }
  return v;
}

EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& v) {
  assert(this->numDimensions_ == v.numDimensions_);
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] -= v.magnitudes_[i];
  }
  return *this;
}

EuclideanVector& EuclideanVector::operator*=(const int d) {
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] = this->magnitudes_[i] * d;
  }
  return *this;
}

EuclideanVector& EuclideanVector::operator*=(const double d) {
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] = this->magnitudes_[i] * d;
  }
  return *this;
}

EuclideanVector& EuclideanVector::operator/=(const int d) {
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] = this->magnitudes_[i] / d;
  }
  return *this;
}

EuclideanVector& EuclideanVector::operator/=(const double d) {
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] = this->magnitudes_[i] / d;
  }
  return *this;
}


