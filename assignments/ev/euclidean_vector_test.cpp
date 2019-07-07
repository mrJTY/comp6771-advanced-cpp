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

TEST_CASE("Plus operator"){
  EuclideanVector a{2, 5.0};
  EuclideanVector b{2, 5.0};

  // Operator
  auto c = a + b;
  REQUIRE(c.GetNumDimensions() == 2);
  REQUIRE(c[0] == 10.0);
  REQUIRE(c[1] == 10.0);

  // Compound assignment
  a += b;
  REQUIRE(a.GetNumDimensions() == 2);
  REQUIRE(a[0] == 10.0);
  REQUIRE(a[1] == 10.0);

}

TEST_CASE("Minus operator"){
  EuclideanVector a{2, 5.0};
  EuclideanVector b{2, 5.0};

  // Operator
  auto c = a - b;
  REQUIRE(c.GetNumDimensions() == 2);
  REQUIRE(c[0] == 0.0);
  REQUIRE(c[1] == 0.0);

  // Compund assignment
  a -= b;
  REQUIRE(a.GetNumDimensions() == 2);
  REQUIRE(a[0] == 0.0);
  REQUIRE(a[1] == 0.0);
}

TEST_CASE("Multiplication operator"){
  EuclideanVector a{2, 5.0};

  // Dot product
  double b = a * a;
  REQUIRE(b == 50.0);
  REQUIRE(b == 50.0);

  // Scalar
  auto c = a * 2.0;
  REQUIRE(c.GetNumDimensions() == 2);
  REQUIRE(c[0] == 10.0);
  REQUIRE(c[1] == 10.0);

  auto d = 2.0 * a;
  REQUIRE(d.GetNumDimensions() == 2);
  REQUIRE(d[0] == 10.0);
  REQUIRE(d[1] == 10.0);


  // Compound assignment
  a *= 2;
  REQUIRE(a.GetNumDimensions() == 2);
  REQUIRE(a[0] == 10.0);
  REQUIRE(a[1] == 10.0);
}

TEST_CASE("Dot product"){
  EuclideanVector a{2, 5.0};
  EuclideanVector b{2, 5.0};

  auto c = a * b;

  REQUIRE(c == 50.0);
}

TEST_CASE("Division operator"){
  EuclideanVector a{2, 5.0};

  a /= 2;
  REQUIRE(a.GetNumDimensions() == 2);
  REQUIRE(a[0] == 2.5);
  REQUIRE(a[1] == 2.5);
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
