/*

  == Explanation and rational of testing ==

  Explain and justify how you approached testing, the degree
   to which you're certain you have covered all possibilities,
   and why you think your tests are that thorough.

*/

#include "assignments/dg/graph.h"
#include "catch.h"
#include "iostream"
#include "string"

//TEST_CASE("Hello"){
//  gdwg::Graph<std::string, int> a;
//  auto nodes = a.GetNodes();
//  for(auto it = nodes.begin(); it!=nodes.end(); ++it){
//    std::cout << *it;
//  }
//}

TEST_CASE("Constructors") {
  std::vector<std::string> v{"Hello", "how", "are", "you"};
  gdwg::Graph<std::string, double> b{v.begin(),v.end()};
  auto nodes = b.GetNodes();
}
