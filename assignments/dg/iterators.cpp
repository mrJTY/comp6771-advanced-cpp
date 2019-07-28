

template <typename T>
class const_iterator {
 public:
  //    const_iterator(typename std::set<std::shared_ptr<Node<T>>, CustomCompare<Node<T>>> &nodes,
  //    const std::string iterType) :
  //      iterType_(iterType) {
  //
  //        if(iterType == "begin"){
  //            iter_ = nodes.begin();
  //        } else if(iterType == "end"){
  //            iter_ = nodes.end();
  //        }
  //    };
  // const_iterator(typename std::set<std::shared_ptr<Node<T>>, CustomCompare<Node<T>>> &nodes) {
  //        iter_ = nodes.begin();
  //    };

  explicit const_iterator(
      typename std::set<std::shared_ptr<Node<T>>, CustomCompare<Node<T>>>& nodes)
    : iter_{nodes.begin()} {};

  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using reference = T;
  using pointer = T*;
  using difference_type = int;

  reference operator*() const { return (*iter_)->value_; };

  const_iterator& operator++() {
    ++iter_;
    return *this;
  };

  const_iterator operator++(int) {
    auto copy{*this};
    ++(*this);
    return copy;
  }

 private:
  typename std::set<std::shared_ptr<Node<T>>, CustomCompare<Node<T>>>::iterator iter_;
  std::string iterType_;
};

// Iterator stuff
// using iterator = typename std::set<std::shared_ptr<Node<N>>, CustomCompare<Node<N>>>::iterator;
using iterator = const_iterator<N>;

iterator begin() {
  iter_ = iterator{nodes_};  //, "begin"};
  return iter_;
}

// iterator end() {
//    iter_ = iterator{nodes_, "end"};
//    return iter_;
//}

//    iterator end() { return nullptr; }
