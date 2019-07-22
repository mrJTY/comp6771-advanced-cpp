#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <memory>

namespace gdwg {

template <typename N>
struct Node {
    Node();
    Node(N value): value_{value} {};
    Node(N value, std::unique_ptr<Node>&& next): value_{value}, next{std::move(next)} {}
    N value_;
    std::unique_ptr<Node> next;

    friend bool operator< (const Node<N>& lhs, const Node<N>& rhs) {
        return lhs.value_ < rhs.value_;
    };

    friend bool operator== (const Node<N>& lhs, const Node<N>& rhs) {
        return lhs.value_ == rhs.value_;
    };

};




template <typename N, typename E>
struct Edge{
public:
    Edge(N src, N dst, E weight): src_(src), dst_(dst), weight_(weight){};
    N src_;
    N dst_;
    E weight_;
};

template <typename N, typename E>
class Graph {
 public:
  // class const_iterator {};

  // Constructors
  Graph() = default;
  Graph(typename std::vector<N>::const_iterator begin,
        typename std::vector<N>::const_iterator end) {
    for (auto iter = begin; iter != end; ++iter) {
        nodes_.emplace(*iter);
    }
  };

  // Copy constructor
  Graph(const Graph& other) : nodes_{other.nodes_}, edges_{other.edges} {};
  // Copy assignment
  Graph& operator=(const Graph& rhs);

  // Move constructor
  Graph(Graph&& other) noexcept: nodes_{std::move(other.nodes_)}, edges_{std::move(other.edges_)} {};

   Graph(typename std::vector<std::tuple<N, N, E>>::const_iterator begin,
      typename std::vector<std::tuple<N, N, E>>::const_iterator end){
       for (auto iter = begin; iter != end; ++iter) {
           N srcVal = std::get<0>(*iter);
           N destVal = std::get<1>(*iter);
           E weight = std::get<2>(*iter);

           std::vector<N> nodeValues = GetNodes();

           // Only add to the nodes, if it hasn't been added before
           InsertNode(srcVal);
           InsertNode(destVal);
           InsertEdge(srcVal, destVal, weight);

       }

   };


  // Methods
  std::vector<N> GetNodes();
  bool InsertNode(const N& val);
  bool InsertEdge(const N& src, const N& dst, const E& w);
  bool DeleteNode(const N&);

private:
  std::set<Node<N>> nodes_;
  std::vector<Edge<N,E>> edges_;

};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
