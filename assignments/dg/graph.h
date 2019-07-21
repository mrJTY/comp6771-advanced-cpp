#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include "vector"

namespace gdwg {

template <typename N, typename E>
class Graph {
 public:
  //class const_iterator {};

  // Constructors
  Graph(typename std::vector<N>::const_iterator begin,
        typename std::vector<N>::const_iterator end) {
    for(auto iter = begin; iter != end; ++iter){
      nodes_.push_back(*iter);
    }
  };

  // Methods
  std::vector<N> GetNodes();

 private:
  std::vector<N> nodes_;
};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
