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
  REQUIRE(a[0] == 4.0);
  REQUIRE(a[1] == 4.0);

  int x{3};
  double y{3.24};
  EuclideanVector b{x, y};
  REQUIRE(b.GetNumDimensions() == 3);
  REQUIRE(b[0] == y);
  REQUIRE(b[1] == y);
  REQUIRE(b[2] == y);
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

TEST_CASE("Plus equals operator"){
  EuclideanVector a{2, 5.0};
  EuclideanVector b{2, 5.0};

  a += b;

  REQUIRE(a.GetNumDimensions() == 2);
  REQUIRE(a[0] == 10.0);
  REQUIRE(a[1] == 10.0);
}


/**
TEST_CASE("Copy constructor") {
  EuclideanVector a{2, 4.0};
  EuclideanVector b{a};

  REQUIRE(b.GetNumDimensions() == 2);

}

TEST_CASE("Compound constructor") {
  EuclideanVector a{2, 4.0};

}
**/
