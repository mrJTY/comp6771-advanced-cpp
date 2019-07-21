#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include <vector>
#include <tuple>
#include <algorithm>

namespace gdwg {

template <typename N>
class Node {
 public:
  Node(N val) { value_ = val; };
  N value_;
};

template <typename N, typename E>
class Edge {
public:
    Edge(typename Node<N> src, Node<N> dest, E weight){
        src_ = src;
        dest_ = dest;
        weight_ = weight;
    }
private:
    Node<N> src_;
    Node<N> dest_;
    E weight_;
};

template <typename N, typename E>
class Graph {
 public:
  // class const_iterator {};

  // Constructors
  Graph(typename std::vector<N>::const_iterator begin,
        typename std::vector<N>::const_iterator end) {
    for (auto iter = begin; iter != end; ++iter) {
      // Create a new node
      auto node = Node(*iter);
      nodes_.push_back(node);
    }
  };

   Graph(typename std::vector<std::tuple<N, N, E>>::const_iterator begin,
      typename std::vector<std::tuple<N, N, E>>::const_iterator end){
       for (auto iter = begin; iter != end; ++iter) {
           N srcVal = std::get<0>(*iter);
           N destVal = std::get<1>(*iter);

           Node<N> srcNode = Node<N>{srcVal};
           Node<N> destNode = Node<N>{srcVal};

           std::vector<N> nodeValues = GetNodes();

           // Only add to the nodes, if it hasn't been added before
           auto searchSrc = std::find(nodeValues.cbegin(), nodeValues.cend(), srcVal);
           if(searchSrc != nodeValues.end()){
           } else{
               nodes_.push_back(srcNode);
           }

           auto searchDest = std::find(nodeValues.cbegin(), nodeValues.cend(), destVal);
           if(searchDest != nodeValues.end()){
           } else{
               nodes_.push_back(destNode);
           }


           // Check if src and dest are in edges
           //E weight = std::get<2>(*iter);
           //auto newEdge = Edge<N, E>{srcNode, destNode, weight};
//           bool foundSrc = false;
//           bool foundDest = false;
//           for(auto eIter = edges_.cbegin(); eIter != edges_.cend(); ++eIter){
//               foundSrc = (*eIter).src_.value_ == newEdge.src_.value_;
//               foundDest = (*eIter).dest_.value_ == newEdge.dest_.value_;
//           }
//           if(foundSrc && foundDest){
//           } else{
//               edges_.push_back(newEdge);
//           }

       }

   };

  // Methods
  std::vector<N> GetNodes();

 private:
    // TODO(JT): make this a set
  std::vector<Node<N>> nodes_;
  std::vector<Edge<N, E>> edges_;

};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
