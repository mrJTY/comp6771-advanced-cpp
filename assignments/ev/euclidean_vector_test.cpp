/*

  == Explanation and rational of testing ==

  Explain and justify how you approached testing, the degree
   to which you're certain you have covered all possibilities,
   and why you think your tests are that thorough.

*/

#include "assignments/ev/euclidean_vector.h"
#include "catch.h"

TEST_CASE("Constructor with int") {
  EuclideanVector a(2);
  REQUIRE(a.GetNumDimensions() == 2);
}

TEST_CASE("Constructor with num dimensions and float") {
  EuclideanVector a{2, 4.0};
  REQUIRE(a.GetNumDimensions() == 2);

  int x{3};
  double y{3.24};
  EuclideanVector b{x, y};
  REQUIRE(b.GetNumDimensions() == 3);
}

TEST_CASE("Iterator constructor") {
  std::vector<double> l;
  l.push_back(5.0);
  l.push_back(6.5);
  l.push_back(7.0);
  // a Euclidean Vector in 3 dimensions constructed from a vector of magnitudes
  EuclideanVector c{
      l.begin(),
      l.end()};
  REQUIRE(c.GetNumDimensions() == 3);
}

TEST_CASE("Copy constructor") {
  EuclideanVector a{2, 4.0};
  EuclideanVector b{a};

  REQUIRE(b.GetNumDimensions() == 2);

}

TEST_CASE("Compound constructor") {
  EuclideanVector a{2, 4.0};

}
