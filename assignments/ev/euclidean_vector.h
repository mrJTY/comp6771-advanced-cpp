// TODO(you): Include header guards

#include <exception>
#include <string>
#include <memory>

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
  explicit EuclideanVector(int i) : i_{i} {};
  friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& v);

  private:
    int i_;
  //  std::unique_ptr<double[]> magnitudes_;
};
