#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <memory>

namespace gdwg {

template <typename N, typename E>
struct Node {
    Node();
    Node(N value): value_{value} {};
    //Node(N value, std::unique_ptr<Node>&& next): value_{value}, next{std::move(next)} {}

    friend bool operator< (const Node<N, E>& lhs, const Node<N, E>& rhs) {
        return lhs.value_ < rhs.value_;
    };

    friend bool operator== (const Node<N, E>& lhs, const Node<N, E>& rhs) {
        return lhs.value_ == rhs.value_;
    };

    N value_;
    std::vector<std::tuple<std::unique_ptr<Node>, E>> neighbours_;

};


template<typename T, typename E>
class MyIter{
public:
    MyIter(std::set<Node<T,E>> &nodes):iter_{nodes.begin()} {};

    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using reference = T;
    using pointer = T*;
    using difference_type = int;

    reference operator*() const{
        return (*iter_).value_;
    };
    MyIter& operator++(){
        ++iter_;
        return *this;
    };

    MyIter operator++(int){
        auto copy{*this};
        ++(*this);
        return copy;
    }

    friend bool operator==(const MyIter& lhs, const MyIter& rhs){
        return *(lhs.iter_) == *(rhs.iter_);
    }

    friend bool operator!=(const MyIter& lhs, const MyIter& rhs){ return !(lhs == rhs);}

private:
    typename std::set<Node<T, E>>::iterator iter_;
};

template <typename N, typename E>
class Graph {
public:
    // Iterator stuff
    using iterator = MyIter<N,E>;
    // TODO my own const iterator

    iterator begin() {
        iterator i = iterator{nodes_};
        return i;
    }
    iterator end() { return nullptr; }

  // Constructors

  Graph() = default;
  Graph(typename std::vector<N>::const_iterator begin,
        typename std::vector<N>::const_iterator end) {
    for (auto iter = begin; iter != end; ++iter) {
        nodes_.emplace(*iter);
    }
  };

  // Copy constructor
  Graph(const Graph& other) : nodes_{other.nodes_}{}; //, edges_{other.edges} {};
  // Copy assignment
  Graph& operator=(const Graph& rhs);

  // Move constructor
  Graph(Graph&& other) noexcept: nodes_{std::move(other.nodes_)}{} //, edges_{std::move(other.edges_)} {};

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
  void Clear();
  bool IsNode(const N& val);

  friend std::ostream& operator<<(std::ostream& os, Graph<N, E> g){
//      for(auto iter = g.nodes_.begin(); iter != g.nodes_.end(); ++iter){
//          os << "asdf";
//      }
if(g.foo){

    os << "asdf";
}
      return os;
  };

    std::set<Node<N, E>> nodes_;
    bool foo = true;
private:
  std::unique_ptr<Node<N, E>> head_;

};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
