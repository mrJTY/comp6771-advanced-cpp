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
  explicit EuclideanVector(int numDimensions) : numDimensions_{numDimensions} {}
  EuclideanVector(int numDimensions, double magnitude)
    : numDimensions_{numDimensions} {

    magnitudes_ = std::make_unique<double[]>(numDimensions_);
    for (int i = 0; i < numDimensions_; i++) {
        magnitudes_[i] = magnitude;
    }

  };

  // TODO:
//  EuclideanVector(std::vector<double>::const_iterator begin,
//                  std::vector<double>::const_iterator end) {
//    for (auto iter = begin; iter != end; ++iter) {
//      vector_.push_back(*iter);
//    }
//
//    numDimensions_ = vector_.size();
//  }
//  EuclideanVector(EuclideanVector& v) : EuclideanVector(v.GetVector().cbegin(), v.GetVector().cend()){}

  // Getters
  const int& GetNumDimensions();

  // Operators
  friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& v);
  //EuclideanVector& operator+=(EuclideanVector& v);
  //double& operator[](int i); // Setting via []
  //double operator[](int i) const; // getting via []

 private:
  int numDimensions_;
  std::unique_ptr<double[]> magnitudes_;
};
