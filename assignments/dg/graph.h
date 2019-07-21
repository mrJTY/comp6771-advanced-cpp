#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include "vector"

namespace gdwg {

template <typename N, typename E>
class Graph {
 public: bb
  class const_iterator {};
  // Constructors
  Graph<N, E>(std::vector<N>::const_iterator begin, std::vector<N>::const_iterator end){
    
  }

  // Methods
  std::vector<N> GetNodes();

 private:
  std::vector<N> nodes_;
};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
