/*

  == Explanation and rational of testing ==

  Explain and justify how you approached testing, the degree
   to which you're certain you have covered all possibilities,
   and why you think your tests are that thorough.

*/

#include "catch.h"
#include "string"
#include "utility"

#include "assignments/dg/graph.h"

/**
 * Tests for constructors
 *
 **/
TEST_CASE("Default constructor") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("Hello");
  g.InsertNode("how");
  g.InsertNode("are");
  g.InsertNode("you?");

  REQUIRE(g.IsNode("Hello") == true);
  REQUIRE(g.IsNode("False") == false);
}

TEST_CASE("Vector constructor") {
  std::vector<std::string> v{"Hello", "how", "are", "you"};
  gdwg::Graph<std::string, double> g{v.begin(), v.end()};
  REQUIRE(g.IsNode("Hello") == true);
  REQUIRE(g.IsNode("False") == false);
}

TEST_CASE("Tuple constructor") {
  std::string s1{"Hello"};
  std::string s2{"how"};
  std::string s3{"are"};
  auto e1 = std::make_tuple(s1, s2, 5.4);
  auto e2 = std::make_tuple(s2, s3, 7.6);
  auto e = std::vector<std::tuple<std::string, std::string, double>>{e1, e2};
  gdwg::Graph<std::string, double> g{e.begin(), e.end()};
  REQUIRE(g.IsNode("Hello") == true);
  REQUIRE(g.IsNode("False") == false);
}

TEST_CASE("Init list constructor") {
  gdwg::Graph<std::string, int> g{"Hello", "how", "are"};
  REQUIRE(g.IsNode("Hello") == true);
  REQUIRE(g.IsNode("False") == false);
}

TEST_CASE("Copy constructor") {
  gdwg::Graph<std::string, int> g{"Hello", "how", "are"};
  gdwg::Graph<std::string, int> h{g};
  REQUIRE(g.IsNode("Hello") == true);
  REQUIRE(g.IsNode("False") == false);
  REQUIRE(h.IsNode("Hello") == true);
  REQUIRE(h.IsNode("False") == false);
}

TEST_CASE("Move constructor") {
  gdwg::Graph<std::string, int> g{"Hello", "how", "are"};
  gdwg::Graph<std::string, int> h{std::move(g)};
  REQUIRE(g.IsNode("Hello") == false);
  REQUIRE(g.IsNode("False") == false);
  REQUIRE(h.IsNode("Hello") == true);
  REQUIRE(h.IsNode("False") == false);
}

/**
 * Inserting nodes that doesn't exist before
 * should return true.
 * False otherwise.
 **/
TEST_CASE("Insert nodes") {
  std::string srcVal{"src"};
  std::string dstVal{"dst_"};
  gdwg::Graph<std::string, int> g;

  REQUIRE(g.InsertNode(srcVal) == true);
  REQUIRE(g.InsertNode(srcVal) == false);
  REQUIRE(g.InsertNode(dstVal) == true);
}

/**
 * Inserting edges that doesn't exist before
 * should return true.
 * False otherwise.
 **/
TEST_CASE("Insert edges") {
  std::vector<std::string> v{"a"};
  gdwg::Graph<std::string, int> g{v.cbegin(), v.cend()};
  g.InsertNode("hello");
  g.InsertNode("how");

  // First insert must be true
  REQUIRE(g.InsertEdge("hello", "how", 10) == true);

  // Second insert must be false
  REQUIRE(g.InsertEdge("hello", "how", 10) == false);

  // INserrt an edge to intself
  REQUIRE(g.InsertEdge("hello", "hello", 10) == true);
  REQUIRE(g.InsertEdge("hello", "hello", 10) == false);
}

/**
 * Deleting nodes should only be
 * true if it exists
 **/
TEST_CASE("Delete ptr") {
  gdwg::Graph<std::string, int> g;
  REQUIRE(g.DeleteNode("hello") == false);
  g.InsertNode("hello");
  REQUIRE(g.DeleteNode("hello") == true);
  REQUIRE(g.DeleteNode("hello") == false);
}

TEST_CASE("Delete nodes") {
  std::string a{"a"};
  gdwg::Graph<std::string, int> g;
  g.InsertNode(a);
  REQUIRE(g.DeleteNode(a) == true);
  REQUIRE(g.DeleteNode(a) == false);
  REQUIRE(g.GetNodes().empty());
}

TEST_CASE("Clear") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("b");
  g.InsertEdge("a", "b", 99);
  REQUIRE(!g.GetNodes().empty());
  g.Clear();
  REQUIRE(g.GetNodes().empty());
}

TEST_CASE("Is connected") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("b");
  g.InsertNode("c");
  g.InsertEdge("a", "b", 99);

  REQUIRE(g.IsConnected("a", "b") == true);
  REQUIRE(g.IsConnected("a", "c") == false);
  REQUIRE(g.IsConnected("b", "a") == false);
}

TEST_CASE("Get connected") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("b");
  g.InsertNode("c");
  g.InsertEdge("a", "c", 100);
  g.InsertEdge("a", "b", 99);

  std::vector<std::string> connectedNodes = g.GetConnected("a");
  auto i = connectedNodes.cbegin();
  REQUIRE(*i == "b");
  ++i;
  REQUIRE(*i == "c");
}

TEST_CASE("Get weights") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("b");
  g.InsertNode("c");
  g.InsertEdge("a", "c", 100);
  g.InsertEdge("a", "c", 101);
  g.InsertEdge("a", "b", 99);

  std::vector<int> weights = g.GetWeights("a", "c");

  auto iter = weights.cbegin();
  REQUIRE(*iter == 100);
  ++iter;
  REQUIRE(*iter == 101);
}

/**
 * Copy construct should mean that
 * the two graphs are the same.
 * It is also a test for the == operator
 **/
TEST_CASE("Similarity") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("b");
  g.InsertNode("c");
  g.InsertEdge("a", "c", 100);
  g.InsertEdge("a", "b", 99);

  // Copy construct
  gdwg::Graph<std::string, int> h{g};
  bool same = g == h;
  REQUIRE(same == true);
}

/**
 * Test case when they are not the same
 **/
TEST_CASE("Disimilarity") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("b");
  g.InsertNode("c");
  g.InsertEdge("a", "c", 100);
  g.InsertEdge("a", "b", 99);

  gdwg::Graph<std::string, int> h{g};
  h.InsertEdge("c", "a", 100);
  h.InsertNode("foo");

  bool same = g == h;
  REQUIRE(same == false);

  bool disimilar = g != h;
  REQUIRE(disimilar == true);
}

/**
 * Replace the nodes from a to b
 **/
TEST_CASE("Replace") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("a");
  REQUIRE(g.IsNode("a") == true);

  g.Replace("a", "b");
  REQUIRE(g.IsNode("a") == false);
  REQUIRE(g.IsNode("b") == true);
}

/**
 * Test the the replaced nodes have the
 * incoming/outgoing edges are passed to the new node
 **/
TEST_CASE("Merge replace 1") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("b");
  g.InsertNode("c");
  g.InsertNode("d");

  g.InsertEdge("a", "b", 1);
  g.InsertEdge("a", "c", 2);
  g.InsertEdge("a", "d", 3);

  // Before
  std::vector<std::string> aBefore = g.GetConnected("a");
  std::vector<std::string> bBefore = g.GetConnected("b");
  REQUIRE(aBefore.empty() == false);

  // After
  g.MergeReplace("a", "b");
  std::vector<std::string> bAfter = g.GetConnected("b");

  // B's neighbours are now a's old neighbours
  REQUIRE(bAfter.size() == aBefore.size());
}

/**
 * Create a connection between a and b
 * then delete it
 **/
TEST_CASE("Erase") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("a");
  g.InsertNode("b");
  g.InsertNode("c");
  g.InsertNode("d");

  g.InsertEdge("a", "b", 1);
  g.InsertEdge("a", "c", 2);
  g.InsertEdge("a", "d", 3);

  REQUIRE(g.IsConnected("a", "b") == true);
  REQUIRE(g.erase("a", "b", 99) == false);
  REQUIRE(g.erase("a", "b", 1) == true);
  REQUIRE(g.IsConnected("a", "b") == false);
}

/**
 * Test iterators
 **/
TEST_CASE("Graph iterator") {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("hello");
  g.InsertNode("how");
  g.InsertNode("are");
  g.InsertNode("you?");

  g.InsertEdge("hello", "how", 5);
  g.InsertEdge("hello", "are", 8);
  g.InsertEdge("hello", "are", 2);

  g.InsertEdge("how", "you?", 1);
  g.InsertEdge("how", "hello", 4);

  g.InsertNode("c");
  for (const auto& [from, to, weight] : g) {
    std::cout << from << " -> " << to << " (weight " << weight << ")\n";
  }

  auto iter = g.begin();
  iter++;
  ++iter;
}
