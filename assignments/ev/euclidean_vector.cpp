#include "assignments/ev/euclidean_vector.h"
#include <algorithm>  // Look at these - they are helpful https://en.cppreference.com/w/cpp/algorithm
#include <cassert>
#include <stdexcept>
#include <string>

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
  for (int i = 0; i < v.numDimensions_; ++i) {
    os << std::to_string(v.magnitudes_[i]);
    if (i <= v.numDimensions_ - 2) {
      os << comma;
    }
  }
  os << ending;
  return os;
}

int EuclideanVector::GetNumDimensions() {
  return numDimensions_;
}

// Setter subscript
double& EuclideanVector::operator[](int i) {
  assert(i < this->numDimensions_);
  return this->magnitudes_[i];
}

// Getter subscript
double EuclideanVector::operator[](int i) const {
  assert(i < this->numDimensions_);
  return this->magnitudes_[i];
}

// Copy assignment
EuclideanVector& EuclideanVector::operator=(const EuclideanVector& rhs) {
  this->magnitudes_ = std::make_unique<double[]>(rhs.numDimensions_);

  for (int i = 0; i < rhs.numDimensions_; ++i) {
    this->magnitudes_[i] = rhs.magnitudes_[i];
  }
  this->numDimensions_ = rhs.numDimensions_;
  return *this;
}

// Additions
EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& v) {
  if (this->numDimensions_ != v.numDimensions_) {
    std::string x = std::to_string(this->numDimensions_);
    std::string y = std::to_string(v.numDimensions_);
    throw EuclideanVectorError("Dimensions of LHS(" + x + ") and RHS(" + y + ") do not match");
  }

  // assert(this->numDimensions_ == v.numDimensions_);
  for (int i = 0; i < this->numDimensions_; ++i) {
    this->magnitudes_[i] += v.magnitudes_[i];
  }
  return *this;
}

EuclideanVector operator+(const EuclideanVector& lhs, const EuclideanVector& rhs) {
  if (lhs.numDimensions_ != rhs.numDimensions_) {
    std::string x = std::to_string(lhs.numDimensions_);
    std::string y = std::to_string(rhs.numDimensions_);
    throw EuclideanVectorError("Dimensions of LHS(" + x + ") and RHS(" + y + ") do not match");
  }
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for (int i = 0; i < lhs.numDimensions_; ++i) {
    v.magnitudes_[i] = lhs.magnitudes_[i] + rhs.magnitudes_[i];
  }
  return v;
}

// Subtractions
EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& v) {
  if (this->numDimensions_ != v.numDimensions_) {
    std::string x = std::to_string(this->numDimensions_);
    std::string y = std::to_string(v.numDimensions_);
    throw EuclideanVectorError("Dimensions of LHS(" + x + ") and RHS(" + y + ") do not match");
  }
  assert(this->numDimensions_ == v.numDimensions_);
  for (int i = 0; i < this->numDimensions_; ++i) {
    this->magnitudes_[i] -= v.magnitudes_[i];
  }
  return *this;
}

EuclideanVector operator-(const EuclideanVector& lhs, const EuclideanVector& rhs) {
  if (lhs.numDimensions_ != rhs.numDimensions_) {
    std::string x = std::to_string(lhs.numDimensions_);
    std::string y = std::to_string(rhs.numDimensions_);
    throw EuclideanVectorError("Dimensions of LHS(" + x + ") and RHS(" + y + ") do not match");
  }
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for (int i = 0; i < lhs.numDimensions_; ++i) {
    v.magnitudes_[i] = lhs.magnitudes_[i] - rhs.magnitudes_[i];
  }
  return v;
}

// Multiplications
EuclideanVector& EuclideanVector::operator*=(const int d) {
  for (int i = 0; i < this->numDimensions_; ++i) {
    this->magnitudes_[i] = this->magnitudes_[i] * d;
  }
  return *this;
}

EuclideanVector& EuclideanVector::operator*=(const double d) {
  for (int i = 0; i < this->numDimensions_; ++i) {
    this->magnitudes_[i] = this->magnitudes_[i] * d;
  }
  return *this;
}

// Dot multiplication
double operator*(const EuclideanVector& lhs, const EuclideanVector& rhs) {
  if (lhs.numDimensions_ != rhs.numDimensions_) {
    std::string x = std::to_string(lhs.numDimensions_);
    std::string y = std::to_string(rhs.numDimensions_);
    throw EuclideanVectorError("Dimensions of LHS(" + x + ") and RHS(" + y + ") do not match");
  }
  double dotProduct = 0;
  for (int i = 0; i < lhs.numDimensions_; ++i) {
    dotProduct += (lhs.magnitudes_[i] * rhs.magnitudes_[i]);
  }
  return dotProduct;
}

EuclideanVector operator*(const EuclideanVector& lhs, const double d) {
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for (int i = 0; i < lhs.numDimensions_; ++i) {
    v.magnitudes_[i] = lhs.magnitudes_[i] * d;
  }
  return v;
}

EuclideanVector operator*(const EuclideanVector& lhs, const int d) {
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for (int i = 0; i < lhs.numDimensions_; ++i) {
    v.magnitudes_[i] = lhs.magnitudes_[i] * d;
  }
  return v;
}

EuclideanVector operator*(const double d, const EuclideanVector& rhs) {
  EuclideanVector v = EuclideanVector{rhs.numDimensions_};
  for (int i = 0; i < rhs.numDimensions_; ++i) {
    v.magnitudes_[i] = rhs.magnitudes_[i] * d;
  }
  return v;
}

EuclideanVector operator*(const int d, const EuclideanVector& rhs) {
  EuclideanVector v = EuclideanVector{rhs.numDimensions_};
  for (int i = 0; i < rhs.numDimensions_; ++i) {
    v.magnitudes_[i] = rhs.magnitudes_[i] * d;
  }
  return v;
}

// Divisions
EuclideanVector& EuclideanVector::operator/=(const int d) {
  if (d == 0) {
    throw EuclideanVectorError("Invalid vector division by 0");
  }
  for (int i = 0; i < this->numDimensions_; ++i) {
    this->magnitudes_[i] = this->magnitudes_[i] / d;
  }
  return *this;
}

EuclideanVector& EuclideanVector::operator/=(const double d) {
  if (d == 0.0) {
    throw EuclideanVectorError("Invalid vector division by 0");
  }
  for (int i = 0; i < this->numDimensions_; ++i) {
    this->magnitudes_[i] = this->magnitudes_[i] / d;
  }
  return *this;
}

EuclideanVector operator/(const EuclideanVector& lhs, const double d) {
  if (d == 0.0) {
    throw EuclideanVectorError("Invalid vector division by 0");
  }
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for (int i = 0; i < lhs.numDimensions_; ++i) {
    v.magnitudes_[i] = lhs.magnitudes_[i] / d;
  }
  return v;
}
EuclideanVector operator/(const EuclideanVector& lhs, const int d) {
  if (d == 0.0) {
    throw EuclideanVectorError("Invalid vector division by 0");
  }
  EuclideanVector v = EuclideanVector{lhs.numDimensions_};
  for (int i = 0; i < lhs.numDimensions_; ++i) {
    v.magnitudes_[i] = lhs.magnitudes_[i] / d;
  }
  return v;
}

// Equal comparisons
bool operator==(const EuclideanVector& lhs, const EuclideanVector& rhs) {
  if (lhs.numDimensions_ != rhs.numDimensions_) {
    return false;
  }
  for (auto i = 0; i < lhs.numDimensions_; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const EuclideanVector& lhs, const EuclideanVector& rhs) {
  if (lhs.numDimensions_ != rhs.numDimensions_) {
    return true;
  }
  for (auto i = 0; i < lhs.numDimensions_; ++i) {
    if (lhs[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}

// Vector conversion
EuclideanVector::operator std::vector<double>() {
  std::vector<double> v;
  for (int i = 0; i < numDimensions_; ++i) {
    v.push_back(magnitudes_[i]);
  }
  return v;
}

// List conversion
EuclideanVector::operator std::list<double>() {
  std::list<double> l;
  for (int i = 0; i < numDimensions_; ++i) {
    l.push_back(magnitudes_[i]);
  }
  return l;
}
