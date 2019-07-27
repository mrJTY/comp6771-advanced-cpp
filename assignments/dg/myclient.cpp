//
// Created by jet on 24/07/19.
//
#include <iostream>
#include <string>

#include "assignments/dg/graph.h"

// Note: At the moment, there is no client.sampleout. Please do your own testing

int main() {

    std::vector<std::string> v {"a"};
    gdwg::Graph<std::string, int> g{v.cbegin(), v.cend()};
    g.InsertNode("hello");
    g.InsertNode("hello");
    g.InsertNode("how");
    g.InsertNode("are");
    std::cout << g.InsertEdge("hello", "how", 10);
    std::cout << g.InsertEdge("hello", "how", 10);

    std::cout << g.DeleteNode("are");
    std::cout << g.DeleteNode("are");
    std::vector<std::string> connectedNodes = g.GetConnected("hello");
    auto iter = connectedNodes.cbegin();
    std::cout << *iter;
    auto done = "Done";
    std::cout << done;

    /**
    auto iter = g.begin();
    std::cout << *iter;
    ++iter;
    std::cout << *iter;
**/
}
