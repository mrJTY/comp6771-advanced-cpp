#include "vector"
#include "assignments/dg/graph.h"


template <typename N, typename E>
typename std::vector<N> gdwg::Graph<N, E>::GetNodes() {
    std::vector<N> out;
    for(auto iter = nodes_.cbegin(); iter != nodes_.cend(); ++iter){
        Node<N> node = *iter;
        out.push_back(node.value_);
    }
    return out;
}

template <typename N, typename E>
bool gdwg::Graph<N, E>::InsertNode(const N& val) {

    bool found = false;
    for(auto iter = nodes_.cbegin(); iter != nodes_.cend(); ++iter) {
        Node<N> node = *iter;
        if(node.value_ == val){
            found = true;
        }
    }

    // Add only if its not found
    if(!found){
        nodes_.push_back(Node{val});
    }

    // Return false if there is already a Node
    return !found;
}

template<typename N, typename E>
bool gdwg::Graph<N, E>::InsertEdge(const N &src, const N &dst, const E &w) {
   Edge<N, E> newEdge{src, dst, w};
   bool foundSrc = false;
   bool foundDest = false;
   bool foundWeight = false;
   for(auto eIter = edges_.cbegin(); eIter != edges_.cend(); ++eIter){
       foundSrc = (*eIter).src_.value_ == newEdge.src_.value_;
       foundDest = (*eIter).dst_.value_ == newEdge.dst_.value_;
       foundWeight = (*eIter).weight_ == newEdge.weight_;
       if(foundSrc && foundDest && foundWeight){
           return false;
       }
   }
   edges_.push_back(newEdge);
   return true;
}

