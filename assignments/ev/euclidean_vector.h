#ifndef ASSIGNMENTS_EV_EUCLIDEAN_VECTOR_H_
#define ASSIGNMENTS_EV_EUCLIDEAN_VECTOR_H_
#include <algorithm>
#include <cassert>
#include <cmath>
#include <exception>
#include <list>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

class EuclideanVectorError : public std::exception {
 public:
  explicit EuclideanVectorError(const std::string& what) : what_(what) {}
  const char* what() const noexcept { return what_.c_str(); }

 private:
  std::string what_;
};

class EuclideanVector {
 public:
  // Construct by providing number of dimensions
  explicit EuclideanVector(const int numDimensions) : numDimensions_{numDimensions} {
    magnitudes_ = std::make_unique<double[]>(numDimensions_);
  }

  // Construct by providing number of dimensions
  // and default magnitude value
  EuclideanVector(const int numDimensions, const double magnitudeForAll)
    : numDimensions_{numDimensions} {
    magnitudes_ = std::make_unique<double[]>(numDimensions_);
    for (int i = 0; i < numDimensions_; i++) {
      magnitudes_[i] = magnitudeForAll;
    }
  };

  // Construct by passing iterators
  EuclideanVector(const std::vector<double>::const_iterator begin,
                  const std::vector<double>::const_iterator end) {
    // Check how any dimensions
    int i = 0;
    for (auto iter = begin; iter != end; ++iter) {
      ++i;
    }
    numDimensions_ = i;

    // Copy over
    magnitudes_ = std::make_unique<double[]>(numDimensions_);
    i = 0;
    for (auto iter = begin; iter != end; ++iter) {
      magnitudes_[i] = *iter;
      ++i;
    }
  }

  // Copy constructor
  EuclideanVector(const EuclideanVector& v) : numDimensions_{v.numDimensions_} {
    magnitudes_ = std::make_unique<double[]>(v.numDimensions_);
    for (int i = 0; i < v.numDimensions_; ++i) {
      magnitudes_[i] = v.magnitudes_[i];
    }
  }

  // Copy assignment
  EuclideanVector& operator=(const EuclideanVector& rhs);

  // Move constructor
  EuclideanVector(EuclideanVector&& sourceVector) noexcept
    : numDimensions_{sourceVector.numDimensions_}, magnitudes_{
                                                       std::move(sourceVector.magnitudes_)} {
    // Clear out the the other source vector
    sourceVector.numDimensions_ = 0;
  }

  // Move assignment
  void operator=(EuclideanVector&& o) noexcept {
    magnitudes_ = std::move(o.magnitudes_);
    numDimensions_ = o.numDimensions_;
    o.numDimensions_ = 0;
  }

  // Destructor
  ~EuclideanVector() { magnitudes_.reset(); }

  // Methods
  int GetNumDimensions() const noexcept;
  double& at(const int i);
  double at(const int) const;
  double GetEuclideanNorm();
  EuclideanVector CreateUnitVector();

  // Operators
  EuclideanVector& operator+=(const EuclideanVector& v);
  EuclideanVector& operator-=(const EuclideanVector& v);
  EuclideanVector& operator*=(const int d);
  EuclideanVector& operator*=(const double d);
  EuclideanVector& operator/=(const int d);
  EuclideanVector& operator/=(const double d);
  double& operator[](int i);       // Setting via []
  double operator[](int i) const;  // getting via []

  explicit operator std::vector<double>();
  explicit operator std::list<double>();

  // Friends
  friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& v);
  friend EuclideanVector operator+(const EuclideanVector& lhs, const EuclideanVector& rhs);
  friend EuclideanVector operator-(const EuclideanVector& lhs, const EuclideanVector& rhs);
  friend double operator*(const EuclideanVector& lhs, const EuclideanVector& rhs);
  friend EuclideanVector operator*(const EuclideanVector& lhs, const double d);
  friend EuclideanVector operator*(const EuclideanVector& lhs, const int d);
  friend EuclideanVector operator*(const double d, const EuclideanVector& rhs);
  friend EuclideanVector operator*(const int d, const EuclideanVector& rhs);
  friend EuclideanVector operator/(const EuclideanVector& lhs, const double d);
  friend EuclideanVector operator/(const EuclideanVector& lhs, const int d);
  friend bool operator==(const EuclideanVector& lhs, const EuclideanVector& rhs);
  friend bool operator!=(const EuclideanVector& lhs, const EuclideanVector& rhs);

 private:
  int numDimensions_;
  std::unique_ptr<double[]> magnitudes_;
};

#endif  // ASSIGNMENTS_EV_EUCLIDEAN_VECTOR_H_
