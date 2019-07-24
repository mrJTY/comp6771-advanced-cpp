#ifndef TUTORIALS_WEEK8_ROPE_H_
#define TUTORIALS_WEEK8_ROPE_H_

#include <string>
#include <utility>
#include <vector>

class Rope {
 public:
  explicit Rope(std::vector<std::string> rope): rope_{std::move(rope)} {}

  class iterator {
   public:
    // TODO(tutorial): fill this in.
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::string;
    using reference = std::string;
    using pointer = const std::string*;
    using difference_type = int;

    reference operator*() const;
    iterator& operator++();
    iterator operator++(int) {
        letter_ ;
      auto copy{*this};
      ++(*this);
      return copy;
    }
    // This one isn't strictly required, but it's nice to have.
    //pointer operator->() const { return &(operator*()); }

    friend bool operator==(const iterator& lhs, const iterator& rhs) { return *lhs == *rhs; };
    friend bool operator!=(const iterator& lhs, const iterator& rhs) { return !(lhs == rhs); }

   private:
    // TODO(tutorial): What data members should we put here?
    std::string letter_;
  };

 private:
  std::vector<std::string> rope_;
};


#endif  // TUTORIALS_WEEK8_ROPE_H_
