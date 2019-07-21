#include "vector"

template <typename N, typename E>
typename std::vector<N> gdwg::Graph<N, E>::GetNodes() {
    std::vector<N> out;
    for(auto iter = nodes_.cbegin(); iter != nodes_.cend(); ++iter){
        Node<N> node = *iter;
       out.push_back(node.value_);
    }
    return out;
}
