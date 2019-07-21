#include "vector"

template <typename N, typename E>
typename std::vector<N> gdwg::Graph<N, E>::GetNodes() {
    std::vector<N> out;
    for(auto iter = nodes_.begin(); iter != nodes_.end(); ++iter){
        auto node = *iter;
       out.push_back(node.value_);
    }
    return out;
}
