#include "vector"

template <typename N, typename E>
std::vector<N> gdwg::Graph<N, E>::GetNodes() {
  return nodes_;
}
