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


template<typename N, typename E>
bool gdwg::Graph<N, E>::InsertEdge(const N &src, const N &dst, const E &w) {
//   Edge<N, E> newEdge{src, dst, w};
//   bool foundSrc = false;
//   bool foundDest = false;
//   bool foundWeight = false;
//   for(auto eIter = edges_.cbegin(); eIter != edges_.cend(); ++eIter){
//       foundSrc = (*eIter).src_ == newEdge.src_;
//       foundDest = (*eIter).dst_ == newEdge.dst_;
//       foundWeight = (*eIter).weight_ == newEdge.weight_;
//       if(foundSrc && foundDest && foundWeight){
//           return false;
//       }
//   }

    auto srcNode = std::find(nodes_.begin(), nodes_.end(), src);
    auto dstNode = std::find(nodes_.begin(), nodes_.end(), dst);

    // If the edge already exists, return false
    if(srcNode != nodes_.end() || dstNode != nodes_.end()){
        // TODO: add a check for the weight
        return false;
    }

    // Else create it
    InsertNode(src);
    InsertNode(dst);

    if(w==1){

    }
//   srcNode = std::find(nodes_.begin(), nodes_.end(), src);
//   dstNode = std::find(nodes_.begin(), nodes_.end(), dst);
//    (*srcNode).neighbours_.push((dstNode,w));

    //TODO:
    //(*srcNode).neighbours_.push_back(dst, w);

    // Return true for creating a new edge
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

//    for(auto iter = g.begin(); iter != g.end(); ++iter){
//        auto node =  *iter;
//       os <<  node;
//       os << " (\n";
//
//       /**
//       // Edges TODO:
//       for(auto edge : node.edges_){
//           os << "    ";
//           os << edge.dst_.value_;
//           os << " | ";
//           os << edge.weight_;
//           os << "\n";
//       }
//
//        **/
//       os << ")\n";
//    }

//1 (
//    5 | -1
//)




//template<typename T, typename E>
//class MyIter{
//public:
//    MyIter(std::set<Node<T,E>> &nodes):iter_{nodes.begin()} {};
//
//    using iterator_category = std::forward_iterator_tag;
//    using value_type = T;
//    using reference = T;
//    using pointer = T*;
//    using difference_type = int;
//
//    reference operator*() const{
//        return (*iter_).value_;
//    };
//    MyIter& operator++(){
//        ++iter_;
//        return *this;
//    };
//
//    MyIter operator++(int){
//        auto copy{*this};
//        ++(*this);
//        return copy;
//    }
//
//    friend bool operator==(const MyIter& lhs, const MyIter& rhs){
//        return *(lhs.iter_) == *(rhs.iter_);
//    }
//
//    friend bool operator!=(const MyIter& lhs, const MyIter& rhs){ return !(lhs == rhs);}
//
//private:
//    typename std::set<Node<T, E>>::iterator iter_;
//};
// Iterator stuff
//    using iterator = MyIter<N>;
//    // TODO my own const iterator
//
//    iterator begin() {
//        iterator i = iterator{nodes_};
//        return i;
//    }
//    iterator end() { return nullptr; }

// Constructors

// Copy constructor
//  Graph(const Graph& other) : nodes_{other.nodes_}{}; //, edges_{other.edges} {};
// Copy assignment
//  Graph& operator=(const Graph& rhs);

// Move constructor
//  Graph(Graph&& other) noexcept: nodes_{std::move(other.nodes_)}{} //, edges_{std::move(other.edges_)} {};

//   Graph(typename std::vector<std::tuple<N, N, E>>::const_iterator begin,
//      typename std::vector<std::tuple<N, N, E>>::const_iterator end){
//       for (auto iter = begin; iter != end; ++iter) {
//           N srcVal = std::get<0>(*iter);
//           N destVal = std::get<1>(*iter);
//           E weight = std::get<2>(*iter);
//
//           std::vector<N> nodeValues = GetNodes();
//
//           // Only add to the nodes, if it hasn't been added before
//           InsertNode(srcVal);
//           InsertNode(destVal);
////           InsertEdge(srcVal, destVal, weight);
//
//       }
//   };


// Methods
//  std::vector<N> GetNodes();
//  bool InsertNode(const N& val);
//  bool InsertEdge(const N& src, const N& dst, const E& w);
//  bool DeleteNode(const N&);
//  void Clear();
//  bool IsNode(const N& val);

//  friend std::ostream& operator<<(std::ostream& os, const Graph<N, E> &g){
//      for(auto iter = g.nodes_.begin(); iter != g.nodes_.end(); ++iter){
//          os << (*iter).value_;
//      }
//      return os;
//  };

