#include "assignments/dg/graph.h"
#include <vector>
#include <iostream>
#include <algorithm>

template <typename N, typename E>
bool gdwg::Graph<N, E>::InsertNode(const N& val) {

    bool found = IsNode(val);
    if(!found){
        std::shared_ptr<Node<N>> ptr = std::make_shared<Node<N>>(val);
        // Give ownership to the set
        nodes_.emplace(std::move(ptr));
    }

    // Return false if there is already a Node
    return !found;
}
template<typename N, typename E>
bool gdwg::Graph<N, E>::IsNode(const N& val){
    std::shared_ptr<Node<N>> ptr = std::make_shared<Node<N>>(val);
    auto search = std::find(nodes_.begin(), nodes_.end(), ptr);
    bool found = false;
    if(search != nodes_.end()){
        found = true;
    }
    return found;
}
