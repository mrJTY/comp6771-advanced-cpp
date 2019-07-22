#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include <vector>
#include <tuple>
#include <algorithm>
#include <set>

namespace gdwg {

    template <typename N, typename E>
    class Edge{
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

   Graph(typename std::vector<std::tuple<N, N, E>>::const_iterator begin,
      typename std::vector<std::tuple<N, N, E>>::const_iterator end){
       for (auto iter = begin; iter != end; ++iter) {
           N srcVal = std::get<0>(*iter);
           N destVal = std::get<1>(*iter);

           std::vector<N> nodeValues = GetNodes();

           // Only add to the nodes, if it hasn't been added before
           nodes_.emplace(srcVal);
           nodes_.emplace(destVal);
       }

   };

  // Methods
  std::vector<N> GetNodes();
  bool InsertNode(const N& val);
  bool InsertEdge(const N& src, const N& dst, const E& w);

private:
  std::set<N> nodes_;
  std::vector<Edge<N,E>> edges_;

};

}  // namespace gdwg

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
