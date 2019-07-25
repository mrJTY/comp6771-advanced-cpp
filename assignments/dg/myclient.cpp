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

    auto i = "Done";
    std::cout << i;


}
