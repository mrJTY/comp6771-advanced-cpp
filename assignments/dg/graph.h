#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include "vector"
#include "tuple"

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
    Edge(Node<N> src, Node<N> dest, E weight){
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
           auto srcVal = std::get<0>(*iter);
           auto destVal = std::get<1>(*iter);

           auto srcNode = Node<N>{srcVal};
           auto destNode = Node<N>{srcVal};

           nodes_.push_back(srcNode);
           nodes_.push_back(destNode);
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
