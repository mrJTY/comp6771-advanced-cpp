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
    g.InsertEdge("hello", "how", 10);
    g.InsertEdge("hello", "how", 10);

    g.DeleteNode("are");
    g.DeleteNode("are");
    std::vector<std::string> connectedNodes = g.GetConnected("hello");
    auto connIter = connectedNodes.cbegin();
    std::cout << *connIter << "\n";

    auto iter = g.begin();
    std::cout << *iter << "\n";
    ++iter;
    std::cout << *iter << "\n";


    auto done = "Done";
    std::cout << done;
}
