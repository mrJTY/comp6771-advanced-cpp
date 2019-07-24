//
// Created by jet on 24/07/19.
//
#include <iostream>
#include <string>

#include "assignments/dg/graph.h"

// Note: At the moment, there is no client.sampleout. Please do your own testing

int main() {
    gdwg::Graph<std::string, int> g;
    g.InsertNode("hello");
    g.InsertNode("how");
    g.InsertNode("are");
    g.InsertNode("you?");

    g.InsertEdge("hello", "how", 5);
    g.InsertEdge("hello", "are", 8);
    g.InsertEdge("hello", "are", 2);
    auto i = g.begin();

    std::cout << (*i);
    i++;
    std::cout << (*i);

    std::cout << "---\n";

    std::cout << g;

}
