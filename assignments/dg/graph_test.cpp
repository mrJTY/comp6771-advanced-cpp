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

// TEST_CASE("Hello"){
//  gdwg::Graph<std::string, int> a;
//  auto nodes = a.GetNodes();
//  for(auto it = nodes.begin(); it!=nodes.end(); ++it){
//    std::cout << *it;
//  }
//}

TEST_CASE("Constructors") {
  std::vector<std::string> v{"Hello", "how", "are", "you"};
  gdwg::Graph<std::string, double> b{v.begin(), v.end()};
  auto nodes = b.GetNodes();
}
//
//TEST_CASE("Tuple constructor") {
//  std::string s1{"Hello"};
//  std::string s2{"how"};
//  std::string s3{"are"};
//  auto e1 = std::make_tuple(s1, s2, 5.4);
//  auto e2 = std::make_tuple(s2, s3, 7.6);
//  auto e = std::vector<std::tuple<std::string, std::string, double>>{e1, e2};
//  gdwg::Graph<std::string, double> b{e.begin(), e.end()};
//}