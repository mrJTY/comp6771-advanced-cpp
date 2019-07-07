/*

  == Explanation and rational of testing ==

  Explain and justify how you approached testing, the degree
   to which you're certain you have covered all possibilities,
   and why you think your tests are that thorough.

*/

#include "assignments/ev/euclidean_vector.h"
#include "catch.h"

/**
 * Construct using the int constructor.
 * This should initialise an empty vector with the given number
 * of dimensions.
 **/
TEST_CASE("Constructor with int") {
  EuclideanVector a(2);
  REQUIRE(a.GetNumDimensions() == 2);

}

/**
 * Construct by giving a number of dimensions
 * and a default double magnitude.
 **/
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

/**
 * Construct by passing an iterator from
 * a vector.
 **/
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

/**
 * Test the at method which should
 * return a double from the EV.
 **/
TEST_CASE("At and subscripts"){
  // Initialise an empty vector with 3 slots
  EuclideanVector a{3};

  // Set using the [] operator
  a[0] = 10.0;
  a[1] = 20.0;
  a[2] = 30.0;

  // Get using []
  REQUIRE(a[0] == 10.0);
  // Get using at
  REQUIRE(a.at(1) == 20.0);
  REQUIRE(a.at(2) == 30.0);
  // TODO: Force an exception

}

/**
 * Test the addition
 * operators and compound assignments.
 **/
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

TEST_CASE("Vector type conversion") {
  EuclideanVector a{1, 100.0};
  std::vector<double> vf = std::vector<double>{a};
  REQUIRE(vf.at(0) == 100.0);
  // TODO: require this to fail
  //REQUIRE(vf.at(1));
}
