// TODO(you): Include header guards

#include <exception>
#include <string>
#include <memory>
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
  // Constructor with number of dimensions
  explicit EuclideanVector(int numDimensions) : numDimensions_{numDimensions} {};

  // A constructor that takes the number of dimensions (as a int) and initialises the magnitude in each dimension as the second argument (a double).
  // You can assume the integer input will always be non-negative.
  EuclideanVector(int numDimensions, double magnitude) : numDimensions_{numDimensions}, magnitude_{magnitude} {
    for(int i = 0; i < numDimensions_; i++){
      vector_.push_back(magnitude_);
    }
  };


  /**
   * Getters
   **/
  const int& GetNumDimensions(){ return this->numDimensions_; }
  // TODO: const double& at(int index){ return static_cast<double> this->vector_.at(index); }

  friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& v);

  private:
    int numDimensions_;
    double magnitude_;
    std::vector<double> vector_;
  //  std::unique_ptr<double[]> magnitudes_;
};
