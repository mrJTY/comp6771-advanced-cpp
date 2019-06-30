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
  /**
   * Constructors
   **/

  // Constructor with number of dimensions
  explicit EuclideanVector(int numDimensions) : numDimensions_{numDimensions} {};

  // A constructor that takes the number of dimensions (as a int) and initialises the magnitude in
  // each dimension as the second argument (a double). You can assume the integer input will always
  // be non-negative.
  EuclideanVector(int numDimensions, double magnitude)
    : numDimensions_{numDimensions}, magnitude_{magnitude} {
    for (int i = 0; i < numDimensions_; i++) {
      vector_.push_back(magnitude_);
    }
  };

  // Iterator constructor
  EuclideanVector(std::vector<double>::const_iterator begin,
                  std::vector<double>::const_iterator end) {
    for (auto iter = begin; iter != end; ++iter) {
      vector_.push_back(*iter);
    }

    numDimensions_ = vector_.size();
  }

  // Copy constructor using the iterator constructor
  // TODO: this disqualifies const
 EuclideanVector(EuclideanVector& v) : EuclideanVector(v.GetVector().cbegin(), v.GetVector().cend()){}

  /**
   * Getters
   **/
  const int& GetNumDimensions() { return this->numDimensions_; }
  const std::vector<double> GetVector() { return this->vector_;}
  //const std::vector<double>::const_iterator& cbegin() { return vector_.cbegin();}
  //const std::vector<double>::const_iterator& cend() { return vector_.cend();}
  // TODO: const double& at(int index){ return static_cast<double> this->vector_.at(index); }

  friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& v);

 private:
  int numDimensions_;
  double magnitude_;
  std::vector<double> vector_;
  //  std::unique_ptr<double[]> magnitudes_;
};
