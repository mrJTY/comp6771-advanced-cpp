// TODO(you): Include header guards

#include <exception>
#include <memory>
#include <string>
#include <vector>

/**
class EuclideanVectorError : public std::exception {
 public:
  explicit EuclideanVectorError(const std::string& what) : what_(what) {}
  const char* what() const noexcept{ return what_.c_str(); }
 private:
  std::string what_;
};
**/

class EuclideanVector {
 public:
  // Constructors
  explicit EuclideanVector(int numDimensions) : numDimensions_{numDimensions} {
    magnitudes_ = std::make_unique<double[]>(numDimensions_);
  }

  EuclideanVector(int numDimensions, double magnitudeForAll)
    : numDimensions_{numDimensions} {
    magnitudes_ = std::make_unique<double[]>(numDimensions_);
    for (int i = 0; i < numDimensions_; i++) {
        magnitudes_[i] = magnitudeForAll;
    }
  };

  EuclideanVector(std::vector<double>::const_iterator begin,
                  std::vector<double>::const_iterator end) {
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
//  EuclideanVector(EuclideanVector& v) : EuclideanVector(v.GetVector().cbegin(), v.GetVector().cend()){}

  const int& GetNumDimensions();

  // Operators
  EuclideanVector& operator+=(const EuclideanVector& v);
  EuclideanVector& operator-=(const EuclideanVector& v);
  EuclideanVector& operator*=(const int d);
  EuclideanVector& operator*=(const double d);
  EuclideanVector& operator/=(const int d);
  EuclideanVector& operator/=(const double d);
  double& operator[](int i); // Setting via []
  double operator[](int i) const; // getting via []

  // Friends
  friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& v);
  friend EuclideanVector operator+(const EuclideanVector& lhs, const EuclideanVector& rhs);

 private:
  int numDimensions_;
  std::unique_ptr<double[]> magnitudes_;
};
