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

      Node<N> lhsDst = (*lhs.dst_);
      Node<N> rhsDst = (*rhs.dst_);

      E lhsWeight = (lhs.weight_);
      E rhsWeight = (rhs.weight_);

      return  (lhsSrc < rhsSrc) ||
        ((lhsSrc == rhsSrc) && (lhsDst < rhsDst)) ||
        ((lhsSrc == rhsSrc) && (lhsDst == rhsDst) && (lhsWeight < rhsWeight)) ;
    }
};

template<typename N, typename E>
// Iterator stuff
class const_iterator{
public:
  const_iterator(std::set<Edge<N, E>, CompareEdges<N, E>> &edges, std::string iterType){
    if(iterType == "begin"){
      iter_ = edges.begin();
    } else if(iterType == "end"){
      iter_ = edges.end();
    } else if(iterType == "cbegin"){
      iter_ = edges.cbegin();
    } else if(iterType == "cend") {
        iter_ = edges.cend();
    }
  };

  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = Edge<N, E>;
  using reference = Edge<N, E>;
  using pointer = Edge<N, E>*;
  using difference_type = int;

  reference operator*() const{
      return *iter_;
  };

  const_iterator& operator++(){
    ++iter_;
    return *this;
  };

  friend bool operator!=(const const_iterator &lhs, const const_iterator &rhs){
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


  using iterator = const_iterator<N, E>;

  iterator begin() {
    // Pass the nodes to the constructor
      iterator i = iterator{edges_, "begin"};
      return i;
  }
    iterator cbegin() { return iterator{edges_, "cbegin"}; }
    iterator end() { return iterator{edges_, "end"}; }
    iterator cend() { return iterator{edges_, "cend"}; }

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
  friend std::ostream& operator<<(std::ostream& os, Graph<N, E> &g){
    // TODO
    for(auto iter = g.cbegin(); iter != g.cend(); ++iter){
        N src = (*(*iter).src_).value_;
        N dst = (*(*iter).dst_).value_;
        E weight = (*iter).weight_;

        os << src << " (\n";
        os << "  " << dst << " | " << weight << "\n";

    }

    return os;
  };




private:
    std::set<std::shared_ptr<Node<N>>, CustomCompare<Node<N>>> nodes_;
    std::set<Edge<N, E>, CompareEdges<N, E>> edges_;

};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
