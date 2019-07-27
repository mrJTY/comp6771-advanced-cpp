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


};



template<typename N, typename E>
struct Edge{
  std::shared_ptr<Node<N>> src_;
  std::shared_ptr<Node<N>> dst_;
  E weight_;
};

template<typename N, typename E>
  struct CompareEdges {
    bool operator()(const Edge<N, E>& lhs, const Edge<N, E>& rhs)
    {
      Node<N> lhsSrc = (*lhs.src_);
      Node<N> rhsSrc = (*rhs.src_);

      return  lhsSrc < rhsSrc;
    }
};


template<typename T>
class const_iterator{
 public:
  const_iterator(typename std::set<std::shared_ptr<Node<T>>, CustomCompare<Node<T>>> &nodes, std::string iterType) {
      if(iterType == "begin"){
          iter_ = nodes.begin();
      } else if(iterType == "end"){
          iter_ = nodes.end();
      }
  };

    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using reference = T;
    using pointer = T*;
    using difference_type = int;

    reference operator*() const{
        return (*iter_)->value_;
    };

    const_iterator& operator++(){
        ++iter_;
        return *this;
    };

    private:
      typename std::set<std::shared_ptr<Node<T>>, CustomCompare<Node<T>>>::iterator iter_;
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

  // Tuple constructor
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

  // Initialiser list
  Graph(std::initializer_list<N> init_list){
    for(auto i : init_list){
      InsertNode(i);
    }
  }

  // Copy constructor
  Graph(const Graph& other)  : nodes_{other.nodes_}, edges_{other.edges_} {};

  // Move constructor
  Graph(Graph&& source) noexcept : nodes_{std::move(source.nodes_)}, edges_{source.edges_}{};


    // Iterator stuff
  using iterator = const_iterator<N>;

  iterator begin() {
    // Pass the nodes to the constructor
      iterator i = iterator{nodes_, "begin"};
      return i;
  }
    iterator end() { return iterator{nodes_, "end"}; }

  //    iterator end() { return nullptr; }

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


private:
    std::set<std::shared_ptr<Node<N>>, CustomCompare<Node<N>>> nodes_;
    std::set<Edge<N, E>, CompareEdges<N, E>> edges_;

};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
