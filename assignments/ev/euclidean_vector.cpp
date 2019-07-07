#include "assignments/ev/euclidean_vector.h"
#include <cassert>
#include <stdexcept>
#include <string>
#include <algorithm>  // Look at these - they are helpful https://en.cppreference.com/w/cpp/algorithm

// Methods
double EuclideanVector::at(const int i) {
  assert(i <= this->numDimensions_);
  return this->magnitudes_[i];
}

std::ostream& operator<<(std::ostream& os, const EuclideanVector& v) {
  std::string opening = "[";
  std::string comma = ", ";
  std::string ending = "]";

  os << opening;
  for(int i = 0; i < v.numDimensions_; ++i){
    os << std::to_string(v.magnitudes_[i]);
    if(i <= v.numDimensions_ - 2){
      os << comma;
    }
  }
  os << ending;
  return os;
}

const int& EuclideanVector::GetNumDimensions() {
  return numDimensions_;
}

// Setter subscript
double& EuclideanVector::operator[](int i) {
  // TODO: add exception
  assert(i <= this->numDimensions_);
  return this->magnitudes_[i];
}

// Getter subscript
double EuclideanVector::operator[](int i) const {
  // TODO: add exception
  assert(i <= this->numDimensions_);
  return this->magnitudes_[i];
}

// Additions
EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& v) {
  if(this->numDimensions_ != v.numDimensions_){
    throw "Dimensions of LHS(X) and RHS(Y) do not match";
  }

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

// Subtractions
EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& v) {
  assert(this->numDimensions_ == v.numDimensions_);
  for(int i = 0; i < this->numDimensions_; ++i){
    this->magnitudes_[i] -= v.magnitudes_[i];
  }
  return *this;
}

EuclideanVector operator-(const EuclideanVector& lhs, const EuclideanVector& rhs){
  assert(lhs.numDimensions_ == rhs.numDimensions_);
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for(int i = 0; i < lhs.numDimensions_; ++i){
    v.magnitudes_[i] = lhs.magnitudes_[i] - rhs.magnitudes_[i];
  }
  return v;
}

// Multiplications
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

// Dot multiplication
double operator*(const EuclideanVector& lhs, const EuclideanVector& rhs){
  // TODO: Exception
  assert(lhs.numDimensions_ == rhs.numDimensions_);
  double dotProduct = 0;
  for(int i = 0; i < lhs.numDimensions_; ++i){
    dotProduct += (lhs.magnitudes_[i] * rhs.magnitudes_[i]);
  }
  return dotProduct;
}

EuclideanVector operator*(const EuclideanVector& lhs, const double d){
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for(int i = 0; i < lhs.numDimensions_; ++i){
    v.magnitudes_[i] = lhs.magnitudes_[i] * d;
  }
  return v;
}

EuclideanVector operator*(const EuclideanVector& lhs, const int d){
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for(int i = 0; i < lhs.numDimensions_; ++i){
    v.magnitudes_[i] = lhs.magnitudes_[i] * d;
  }
  return v;
}

EuclideanVector operator*(const double d, const EuclideanVector& rhs){
  EuclideanVector v = EuclideanVector{rhs.numDimensions_};
  for(int i = 0; i < rhs.numDimensions_; ++i){
    v.magnitudes_[i] = rhs.magnitudes_[i] * d;
  }
  return v;
}

EuclideanVector operator*(const int d, const EuclideanVector& rhs){
  EuclideanVector v = EuclideanVector{rhs.numDimensions_};
  for(int i = 0; i < rhs.numDimensions_; ++i){
    v.magnitudes_[i] = rhs.magnitudes_[i] * d;
  }
  return v;
}

// Divisions
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

// Vector conversion
EuclideanVector::operator std::vector<double>(){
  std::vector<double> v;
  for(int i = 0; i < numDimensions_; ++i){
    v.push_back(magnitudes_[i]);
  }
  return v;
}
