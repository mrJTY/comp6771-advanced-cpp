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

using namespace gdwg;

TEST_CASE("Constructors") {
  std::vector<std::string> v{"Hello", "how", "are", "you"};
  Graph<std::string, double> b{v.begin(), v.end()};
  auto nodes = b.GetNodes();
}

TEST_CASE("Hello how are you"){
    Graph<std::string, int> g;
    g.InsertNode("hello");
    g.InsertNode("how");
    g.InsertNode("are");
    g.InsertNode("you?");

    //std::vector<std::string> nodes = g.GetNodes();

}

TEST_CASE("Tuple constructor") {
  std::string s1{"Hello"};
  std::string s2{"how"};
  std::string s3{"are"};
  auto e1 = std::make_tuple(s1, s2, 5.4);
  auto e2 = std::make_tuple(s2, s3, 7.6);
  auto e = std::vector<std::tuple<std::string, std::string, double>>{e1, e2};
  Graph<std::string, double> b{e.begin(), e.end()};
}

TEST_CASE("Insert nodes"){
    std::string srcVal{"src"};
    std::string dstVal{"dst_"};
    Graph<std::string, int> g;

    REQUIRE(g.InsertNode(srcVal) == true);
    REQUIRE(g.InsertNode(srcVal) == false);
    REQUIRE(g.InsertNode(dstVal) == true);
}

TEST_CASE("Insert edges"){
    std::string srcVal{"src"};
    std::string dstVal{"dst_"};
    Graph<std::string, int> g;
    REQUIRE(g.InsertEdge(srcVal, dstVal, 10) == true );
    REQUIRE(g.InsertEdge(srcVal, dstVal, 10) == false );
    REQUIRE(g.InsertEdge(srcVal, dstVal, 20) == true );
}

TEST_CASE("Erase"){
    std::string a{"a"};
    Graph<std::string, int> g;
    g.InsertNode(a);
    REQUIRE(g.DeleteNode(a) == true);
    REQUIRE(g.DeleteNode(a) == false);


}