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
    bool found = false;
    for(auto iter = nodes_.begin(); iter != nodes_.end(); ++iter){
        if(val == (*iter)->value_){
            found = true;
        }
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

    // If src dst, and weight exists, return false
    {
        bool srcExists = false;
        bool dstExists = false;
        // Check for existing nodes
        for(auto iter = nodes_.begin(); iter != nodes_.end(); ++iter){
            srcExists = (*iter)->value_ == src ? true : srcExists;
            dstExists = (*iter)->value_ == dst ? true : dstExists;
        }
        if(!srcExists || !dstExists) {
            throw std::runtime_error("Cannot call Graph::InsertEdge when either src or dst node does not exist");
        }
    }

    {
        // Check for existing edges
        for(auto iter = edges_.begin(); iter != edges_.end(); ++iter){
            bool srcExists = (*(*iter).src_).value_ == src;
            bool dstExists = (*(*iter).dst_).value_ == dst;
            bool weightExists = (*iter).weight_ == w;
            if(srcExists && dstExists && weightExists){
                return false;
            }
        }
    }
    // Else, add a new edge...
    // Create a weak pointer for the edges
    std::shared_ptr<Node<N>> srcWp;
    std::shared_ptr<Node<N>> dstWp;
    for(auto iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
        if((*iter)->value_ == src){
            srcWp = (*iter);
        } else if((*iter)->value_ == dst) {
            dstWp = (*iter);
        }
    }

    Edge<N, E> e{srcWp, dstWp, w};
    edges_.push_back(e);
    return true;
}

template<typename N, typename E>
bool gdwg::Graph<N, E>::DeleteNode(const N& val){
  for(auto iter = nodes_.begin(); iter != nodes_.end(); ++iter){
    std::shared_ptr<Node<N>> p = (*iter);
    if((*p).value_ == val){
      return true;
    }
  }
  return false;
}
