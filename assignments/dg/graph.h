#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace gdwg {

template <typename N>
struct Node {
  Node();
  explicit Node(N value) : value_{value} {};

  friend bool operator<(const Node<N>& lhs, const Node<N>& rhs) { return lhs.value_ < rhs.value_; }

  friend bool operator==(const Node<N>& lhs, const Node<N>& rhs) {
    return lhs.value_ == rhs.value_;
  }

  N value_;
};

template <typename N>
struct CustomCompare {
  bool operator()(const std::shared_ptr<N>& lhs, const std::shared_ptr<N>& rhs) {
    return (*lhs) < (*rhs);
  }
};

template <typename N, typename E>
struct Edge {
  std::shared_ptr<Node<N>> src_;
  std::shared_ptr<Node<N>> dst_;
  E weight_;
  bool initializer_ = false;
};

template <typename N, typename E>
struct CompareEdges {
  bool operator()(const Edge<N, E>& lhs, const Edge<N, E>& rhs) {
    Node<N> lhsSrc = (*lhs.src_);
    Node<N> rhsSrc = (*rhs.src_);

    Node<N> lhsDst = (*lhs.dst_);
    Node<N> rhsDst = (*rhs.dst_);

    E lhsWeight = (lhs.weight_);
    E rhsWeight = (rhs.weight_);

    return (lhsSrc < rhsSrc) || ((lhsSrc == rhsSrc) && (lhsDst < rhsDst)) ||
           ((lhsSrc == rhsSrc) && (lhsDst == rhsDst) && (lhsWeight < rhsWeight));
  }
};

template <typename N, typename E>
// Iterator stuff
class const_iterator {
 public:
  const_iterator(std::set<Edge<N, E>, CompareEdges<N, E>>& edges, std::string iterType) {
    if (iterType == "begin") {
      iter_ = edges.begin();
      // Ignore edges that were initialized (edges on to itself)
      while((*iter_).initializer_ && iter_ != edges.end()){
        ++iter_;
      }
    } else if (iterType == "end") {
      iter_ = edges.end();
    } else if (iterType == "cbegin") {
      iter_ = edges.cbegin();
    } else if (iterType == "cend") {
      iter_ = edges.cend();
    }
  }

  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = std::tuple<N, N, E>;
  using reference = std::tuple<const N, const N, const E>;
  using pointer = std::tuple<N, N, E>*;
  using difference_type = int;

  reference operator*() const {
    auto edge = *iter_;
    N src = (*edge.src_).value_;
    N dst = (*edge.dst_).value_;
    E weight = edge.weight_;
    std::tuple<N, N, E> tup = {src, dst, weight};
    return tup;
  }

  pointer operator->() const { return &(operator*()); }

  const_iterator& operator++() {
    ++iter_;
    auto edge = *iter_;
    if(edge.initializer_){
      ++iter_;
    }
    return *this;
  }

  const_iterator operator++(int) {
    auto copy{*this};
    ++(*this);
    auto edge = *iter_;
    // Skip the edge on itself
    if(edge.initializer_){
       ++(*this);
    }
    return copy;
  }

  const_iterator& operator--() {
    --iter_;
    return *this;
  }

  const_iterator operator--(int) {
    auto copy{*this};
    --(*this);
    return copy;
  }

  friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {
    return lhs.iter_ != rhs.iter_;
  }

 private:
  typename std::set<Edge<N, E>, CompareEdges<N, E>>::iterator iter_;
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
  }

  // Tuple constructor
  Graph(typename std::vector<std::tuple<N, N, E>>::const_iterator begin,
        typename std::vector<std::tuple<N, N, E>>::const_iterator end) {
    for (auto iter = begin; iter != end; ++iter) {
      N srcVal = std::get<0>(*iter);
      N destVal = std::get<1>(*iter);
      E weight = std::get<2>(*iter);
      InsertNode(srcVal);
      InsertNode(destVal);

      InsertEdge(srcVal, destVal, weight);
    }
  }

  // Initialiser list
  Graph(std::initializer_list<N> init_list) {
    for (auto i : init_list) {
      InsertNode(i);
    }
  }

  // Copy constructor
  Graph(const Graph& other) : nodes_{other.nodes_}, edges_{other.edges_} {};

  // Move constructor
  Graph(Graph&& source) noexcept : nodes_{std::move(source.nodes_)}, edges_{source.edges_} {};

  using iterator = const_iterator<N, E>;

  iterator begin() {
    // Pass the nodes to the constructor
    iterator i = iterator{edges_, "begin"};
    return i;
  }
  iterator cbegin() { return iterator{edges_, "cbegin"}; }
  iterator end() { return iterator{edges_, "end"}; }
  iterator cend() { return iterator{edges_, "cend"}; }
  iterator find(const N& s, const N& d, const E& w) {
    int i = 0;
    bool found = false;
    auto iter = iterator{edges_, "begin"};
    while (i < edges_.size() && !found) {
      auto edge = *iter;
      if (((*edge.src_).value_ == s) && ((*edge.dst_).value_ == d) && (edge.weight_ == w)) {
        found = true;
        break;
      }
      ++i;
      ++iter;
    }
    return iter;
  }

  // Methods:
  bool InsertNode(const N& val);
  bool InsertEdge(const N& src, const N& dst, const E& w);
  bool IsNode(const N& val);
  std::vector<N> GetNodes();
  bool DeleteNode(const N& val);
  bool IsConnected(const N& src, const N& dst);
  void Clear();
  std::vector<N> GetConnected(const N& src);
  std::vector<E> GetWeights(const N& src, const N& dst);
  bool Replace(const N& oldData, const N& newData);
  void MergeReplace(const N& oldData, const N& newData);
  bool erase(const N& src, const N& dst, const E& w);

  friend std::ostream& operator<<(std::ostream& os, const gdwg::Graph<N, E>& g) {
    N currentSrc;
    bool firstPrint = true;

    for (auto iter = g.edges_.cbegin(); iter != g.edges_.cend(); ++iter) {
      Edge<N, E> edge = *iter;
      N src = (*(edge).src_).value_;
      N dst = (*(edge).dst_).value_;
      E weight = (edge).weight_;

      // Print out new source
      if (currentSrc != src) {
        if (firstPrint) {
          os << src << " (\n";
          firstPrint = false;
        } else {
          // Close it up
          os << ")\n";
          os << src << " (\n";
        }
        // Update the current src
        currentSrc = src;
      }

      if (!edge.initializer_) {
        os << "  " << dst << " | " << weight << "\n";
      }
    }

    os << ")\n";

    return os;
  }

  friend bool operator==(const gdwg::Graph<N, E>& lhs, const gdwg::Graph<N, E>& rhs) {
    auto j = rhs.edges_.cbegin();
    for (auto i = lhs.edges_.cbegin(); i != lhs.edges_.cend(); ++i) {
      try {
        N srcI = (*(*i).src_).value_;
        N srcJ = (*(*j).src_).value_;
        N dstI = (*(*i).dst_).value_;
        N dstJ = (*(*j).dst_).value_;
        E weightI = (*i).weight_;
        E weightJ = (*j).weight_;

        bool sameSrc = static_cast<bool>(srcI == srcJ);
        bool sameDst = static_cast<bool>(dstI == dstJ);
        bool sameWeight = static_cast<bool>(weightI == weightJ);

        if ((!sameSrc) || (!sameDst) || (!sameWeight)) {
          return false;
        }
        ++j;
      } catch (std::exception) {
        return false;
      }
    }
    return true;
  }

  friend bool operator!=(gdwg::Graph<N, E>& lhs, gdwg::Graph<N, E>& rhs) { return !(lhs == rhs); }

 private:
  std::set<std::shared_ptr<Node<N>>, CustomCompare<Node<N>>> nodes_;
  std::set<Edge<N, E>, CompareEdges<N, E>> edges_;
};

}  // namespace gdwg

#include "assignments/dg/graph.cpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
