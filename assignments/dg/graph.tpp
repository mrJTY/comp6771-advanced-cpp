#include "vector"

template <typename N, typename E>
typename std::vector<N> gdwg::Graph<N, E>::GetNodes() {
  return nodes_;
}
