#include "assignments/dg/graph.h"
#include <vector>
#include <iostream>


template <typename N, typename E>
typename std::vector<N> gdwg::Graph<N, E>::GetNodes() {
    std::vector<N> out;
    for(auto iter = nodes_.cbegin(); iter != nodes_.cend(); ++iter){
        out.push_back((*iter).value_);
    }
    return out;
}

template <typename N, typename E>
bool gdwg::Graph<N, E>::InsertNode(const N& val) {

    bool found = IsNode(val);
    // Add only if its not found
    if(!found){
        nodes_.emplace(val);
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
       foundSrc = (*eIter).src_ == newEdge.src_;
       foundDest = (*eIter).dst_ == newEdge.dst_;
       foundWeight = (*eIter).weight_ == newEdge.weight_;
       if(foundSrc && foundDest && foundWeight){
           return false;
       }
   }
   edges_.push_back(newEdge);
   return true;
}

template<typename N, typename E>
bool gdwg::Graph<N, E>::DeleteNode(const N &val) {
    bool found = false;
    auto search = nodes_.find(val);
    if(search != nodes_.end()){
        found = true;
        nodes_.erase(val);
    }

    return found;
}

template<typename N, typename E>
void gdwg::Graph<N, E>::Clear(){
    nodes_.erase(nodes_.cbegin(), nodes_.cend());
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
template<typename N, typename E>
std::ostream& operator<<(std::ostream& os, const gdwg::Graph<N,E> g) {
    for(auto iter = g.begin(); iter != g.end(); ++iter){
        auto node =  *iter;
       os <<  node.value_;
       os << " (\n";

       /**
       // Edges TODO:
       for(auto edge : node.edges_){
           os << "    ";
           os << edge.dst_.value_;
           os << " | ";
           os << edge.weight_;
           os << "\n";
       }

        **/
       os << ")\n";
    }

    //1 (
    //    5 | -1
    //)
    return os;
}
