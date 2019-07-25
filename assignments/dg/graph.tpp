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

template<typename N, typename E>
std::vector<N> gdwg::Graph<N, E>::GetNodes(){
    std::vector<N> v;
    // This is how you iterate through...
    for(auto iter = nodes_.begin(); iter != nodes_.end(); ++iter){
        v.push_back((*iter)->value_);
    }
    return v;
}

template<typename N, typename E>
bool gdwg::Graph<N, E>::InsertEdge(const N& src, const N& dst, const E& w){

//    auto searchSrc = std::find(nodes_.begin(), nodes_.end(), src);
//    auto searchDst = std::find(nodes_.begin(), nodes_.end(), dst);
//    bool foundSrc = searchSrc !=nodes_.end();
//    bool foundDst = searchDst !=nodes_.end();



    std::cout << src;
    std::cout << dst;
    std::cout << w;

    return true;
}