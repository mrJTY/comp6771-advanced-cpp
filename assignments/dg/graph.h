#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <iostream>
#include <memory>

namespace gdwg {

template <typename N>
struct Node {
    Node();
    Node(N value): value_{value} {};

    friend bool operator< (const Node<N>& lhs, const Node<N>& rhs) {
        return lhs.value_ < rhs.value_;
    };

    friend bool operator== (const Node<N>& lhs, const Node<N>& rhs) {
        return lhs.value_ == rhs.value_;
    };

    N value_;
};

template<typename N>
struct CustomCompare {
    bool operator()(const std::shared_ptr<N>& lhs, const std::shared_ptr<N>& rhs)
    {
        return (*lhs) < (*rhs);
    }

    bool operator()(const std::shared_ptr<N>& lhs, const N& rhs)
    {
        return (*lhs) < (rhs);
    }

};

template<typename N, typename E>
struct Edge{
  std::shared_ptr<Node<N>> src_;
  std::shared_ptr<Node<N>> dst_;
  E weight_;
};

template <typename N, typename E>
class Graph {
public:
  Graph() = default;
  Graph(typename std::vector<N>::const_iterator begin,
        typename std::vector<N>::const_iterator end) {
    for (auto iter = begin; iter != end; ++iter) {
        std::shared_ptr<Node<N>> ptr = std::make_unique<Node<N>>(*iter);
        // Give ownership to the set
        nodes_.emplace(std::move(ptr));
    }
  };

  Graph(typename std::vector<std::tuple<N, N, E>>::const_iterator begin,
        typename std::vector<std::tuple<N, N, E>>::const_iterator end){
      for (auto iter = begin; iter != end; ++iter) {
          N srcVal = std::get<0>(*iter);
          N destVal = std::get<1>(*iter);
          E weight = std::get<2>(*iter);
          InsertNode(srcVal);
          InsertNode(destVal);

          InsertEdge(srcVal, destVal, weight);
      }
  }

  // Methods:
  bool InsertNode(const N& val);
  bool InsertEdge(const N& src, const N& dst, const E& w);
  bool IsNode(const N& val);
  std::vector<N> GetNodes();
  bool DeleteNode(const N& val);

private:
    std::set<std::shared_ptr<Node<N>>, CustomCompare<Node<N>>> nodes_;
    std::vector<Edge<N, E>> edges_;
};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
