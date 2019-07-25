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
    bool operator()(const std::unique_ptr<N>& lhs, const std::unique_ptr<N>& rhs)
    {
        return (*lhs)< (*rhs);
    }

};

template <typename N, typename E>
class Graph {
public:
  Graph() = default;
  Graph(typename std::vector<N>::const_iterator begin,
        typename std::vector<N>::const_iterator end) {
    for (auto iter = begin; iter != end; ++iter) {
        std::unique_ptr<Node<N>> ptr = std::make_unique<Node<N>>(*iter);
        // Give ownership to the set
        nodes_.emplace(std::move(ptr));
    }
  };

  // Methods:
  bool InsertNode(const N& val);
  bool IsNode(const N& val);

private:
    std::set<std::unique_ptr<Node<N>>, CustomCompare<Node<N>>> nodes_;
};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
