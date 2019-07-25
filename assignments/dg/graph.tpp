#include "assignments/dg/graph.h"
#include <vector>
#include <iostream>

template <typename N, typename E>
bool gdwg::Graph<N, E>::InsertNode(const N& val) {

    bool found = IsNode(val);
    if(!found){
        std::unique_ptr<Node<N>> ptr = std::make_unique<Node<N>>(val);
        // Give ownership to the set
        nodes_.emplace(std::move(ptr));
    }

    // Return false if there is already a Node
    return !found;
}
template<typename N, typename E>
bool gdwg::Graph<N, E>::IsNode(const N& val){
    auto search = nodes_.find(val);
    bool found = false;
    if(search != nodes_.end()){
        found = true;
    }
    return found;
}
