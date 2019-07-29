//
// Created by jet on 24/07/19.
//
#include "assignments/dg/graph.h"
#include <iostream>
#include <string>
#include <vector>

// Note: At the moment, there is no client.sampleout. Please do your own testing

int main() {

//  {
//      std::vector<std::string> v{"a"};
//      gdwg::Graph<std::string, int> g{v.cbegin(), v.cend()};
//      g.InsertNode("hello");
//      //    g.InsertNode("hello");
//      g.InsertNode("how");
//      g.InsertNode("are");
//      g.InsertEdge("hello", "how", 10);
//      g.InsertEdge("hello", "how", 20);
//      g.InsertEdge("how", "are", 10);
//
//      std::cout << g;
//      std::cout << "\n\n";
//
//      g.DeleteNode("are");
//      std::cout << g;
//
//      gdwg::Graph<std::string, int> h{g};
//      auto same = g == h;
//      std::cout << same;
//
//      gdwg::Graph<std::string, int> k;
//      k.InsertNode("a");
//      k.InsertNode("b");
//      k.InsertNode("c");
//      k.InsertEdge("a", "c", 100);
//      k.InsertEdge("a", "b", 99);
//      // Copy construct
//      gdwg::Graph<std::string, int> f{k};
//      auto same2 = k == f;
//      std::cout << same2;
//  }

    {
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
        g.MergeReplace("a", "b");
        std::vector<std::string> aAfter = g.GetConnected("a");
        std::vector<std::string> bAfter = g.GetConnected("b");
        auto done = "Done";
        std::cout << done;
    }

}
