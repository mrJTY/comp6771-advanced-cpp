#include "vector"
#include "assignments/dg/graph.h"


template <typename N, typename E>
typename std::vector<N> gdwg::Graph<N, E>::GetNodes() {
    std::vector<N> out;
    for(auto iter = nodes_.cbegin(); iter != nodes_.cend(); ++iter){
        Node<N> node = *iter;
        out.push_back(node.GetValue());
    }
    return out;
}

template <typename N, typename E>
bool gdwg::Graph<N, E>::InsertNode(const N& val) {

    bool found = false;
    for(auto iter = nodes_.cbegin(); iter != nodes_.cend(); ++iter) {
        Node<N> node = *iter;
        if(node.GetValue() == val){
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
   Edge<N, E> newEdge = Edge<N, E>{src, dst, w};
   bool foundSrc = false;
   bool foundDest = false;
   for(auto eIter = edges_.cbegin(); eIter != edges_.cend(); ++eIter){
       foundSrc = (*eIter).src_.value_ == newEdge.src_.value_;
       foundDest = (*eIter).dest_.value_ == newEdge.dest_.value_;
   }
   if(foundSrc && foundDest){
       return false;
   }
   edges_.push_back(newEdge);
   return true;
}
