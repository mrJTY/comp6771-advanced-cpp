/*

  == Explanation and rational of testing ==

  Explain and justify how you approached testing, the degree
   to which you're certain you have covered all possibilities,
   and why you think your tests are that thorough.

*/

#include "assignments/ev/euclidean_vector.h"
#include "catch.h"
#include "utility"

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
  EuclideanVector c{l.begin(), l.end()};
  REQUIRE(c.GetNumDimensions() == 3);
}

/**
 * Test copy constructor
 * by passing an existing EV to a new EV.
 * The old OV should still retain the
 * existing magnitudes.
 **/
TEST_CASE("Copy constructor") {
  EuclideanVector oldEV{2, 4.0};
  EuclideanVector newEV{oldEV};

  REQUIRE(newEV[0] == 4.0);
  REQUIRE(newEV[1] == 4.0);

  REQUIRE(oldEV[0] == 4.0);
  REQUIRE(oldEV[1] == 4.0);

  REQUIRE(newEV.GetNumDimensions() == oldEV.GetNumDimensions());
}

/**
 * Test copy assignment
 * by passing an existing EV to
 * another EV
 **/
TEST_CASE("Copy assignment") {
  EuclideanVector oldEV{2, 4.0};
  EuclideanVector newEV{20, 4.0};

  newEV = oldEV;
  REQUIRE(newEV[0] == 4.0);
  REQUIRE(newEV[1] == 4.0);

  REQUIRE(oldEV[0] == 4.0);
  REQUIRE(oldEV[1] == 4.0);

  REQUIRE(newEV.GetNumDimensions() == oldEV.GetNumDimensions());
}

/**
 * Test move constructor
 * by passing an existing EV to a new EV.
 * The old OV should NOT retain the
 * it's magnitudes.
 **/
TEST_CASE("Move constructor") {
  EuclideanVector oldEV{2, 4.0};
  EuclideanVector newEV = std::move(oldEV);

  REQUIRE(newEV[0] == 4.0);
  REQUIRE(newEV[1] == 4.0);

  REQUIRE(newEV.GetNumDimensions() == 2);
  REQUIRE(oldEV.GetNumDimensions() == 0);
}

/**
 * Test the at method which should
 * return a double from the EV.
 **/
TEST_CASE("At and subscripts") {
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
  // TODO(jt): Force an exception
}

/**
 * Test the addition
 * operators and compound assignments.
 **/
TEST_CASE("Plus operator") {
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

/**
 * Expect an exception
 * thrown when addition of two different
 * sized vectors
 **/
TEST_CASE("Plus exception"){
  EuclideanVector a{2, 5.0};
  EuclideanVector b{9, 5.0};

  try {
    // Expect to fail
    a + b;
    // Those code should not run
    // if it does, then the error wasn't thrown
    REQUIRE(false == true);
  } catch (const EuclideanVectorError& e) {
    std::string message = e.what();
    REQUIRE(message.compare("Dimensions of LHS(2) and RHS(9) do not match") == 0);
  }
}

TEST_CASE("Minus operator") {
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

TEST_CASE("Multiplication operator") {
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

/**
 * Dot product [5, 5] * [5, 5] = 50.00
 **/
TEST_CASE("Dot product") {
  EuclideanVector a{2, 5.0};
  EuclideanVector b{2, 5.0};

  auto c = a * b;

  REQUIRE(c == 50.0);
}

/**
 * Division test
 * [5, 5] / 2 = [2.5, 2.5]
 **/
TEST_CASE("Division compound assignment") {
  EuclideanVector a{2, 5.0};

  a /= 2;
  REQUIRE(a.GetNumDimensions() == 2);
  REQUIRE(a[0] == 2.5);
  REQUIRE(a[1] == 2.5);
}

TEST_CASE("Division operator") {
  EuclideanVector a{2, 5.0};
  double b{2};

  auto c = a / b;
  REQUIRE(c.GetNumDimensions() == 2);
  REQUIRE(c[0] == 2.5);
  REQUIRE(c[1] == 2.5);
}

/**
 * Test equality
 * by comparing values in magnitudes
 **/
TEST_CASE("Equality operator") {
  EuclideanVector a{2, 25.0};
  EuclideanVector b{2, 25.0};

  REQUIRE(a == b);
}
TEST_CASE("Inequality operator") {
  EuclideanVector a{3, 25.0};
  EuclideanVector b{2, 25.0};
  EuclideanVector c{2, 5.0};

  REQUIRE(a != b);
  REQUIRE(b != c);
}

/**
 * Cast a EV to a std::vector
 **/
TEST_CASE("Vector type conversion") {
  EuclideanVector a{1, 100.0};
  std::vector<double> vf = std::vector<double>{a};
  REQUIRE(vf.at(0) == 100.0);
  // TODO(jt): require this to fail
  // REQUIRE(vf.at(1));
}

/**
 * Cast a EV to a std::list
 **/
TEST_CASE("List type conversion") {
  EuclideanVector a{1, 100.0};
  std::list<double> l = std::list<double>{a};
  REQUIRE(l.front() == 100.0);
  REQUIRE(l.back() == 100.0);
}
