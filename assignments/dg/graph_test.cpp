/*

  == Explanation and rational of testing ==

  Explain and justify how you approached testing, the degree
   to which you're certain you have covered all possibilities,
   and why you think your tests are that thorough.

*/

#include "assignments/dg/graph.h"
#include "catch.h"
#include "string"

TEST_CASE("Constructors") {
  std::vector<std::string> v{"Hello", "how", "are", "you"};
  auto a = gdwg::Graph<std::string, double> b{v.begin(),v.end()};
  auto nodes = a.GetNodes();
}
