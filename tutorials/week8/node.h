//
// Created by jet on 24/07/19.
//

#ifndef COMP6771_ADVANCED_CPP_NODE_H
#define COMP6771_ADVANCED_CPP_NODE_H
#include <iterator>
#include <memory>
#include "string"
#include <utility>
#include <algorithm>

template<typename T>
struct Node{
public:
    //Node(T value) : value_(value) {}
    Node(T value, std::unique_ptr<Node<T>>&& next) : value_(value), next_(std::move(next)){}

    T value_;
    std::unique_ptr<Node> next_;
};

template<typename T>
class MyIter{
public:
    MyIter(Node<T>* node): node_{node}{};
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = int;

    reference operator*() const{
        return node_->value_;
    };
    MyIter& operator++(){
        node_ = node_->next_.get();
        return *this;
    };
    MyIter operator++(int){
        auto copy{*this};
        ++(*this);
        return copy;
    }

    friend bool operator==(const MyIter& lhs, const MyIter& rhs){
        return lhs.node_ == rhs.node_;
    }

    friend bool operator!=(const MyIter& lhs, const MyIter& rhs){ return !(lhs == rhs);}

    private:
        Node<T>* node_;
};

template<typename T>
class Stack{
public:
    // TODO(lecture): show how make const and non-const iterators during lecture.
    using iterator = MyIter<T>;
    using const_iterator = MyIter<T>;

    iterator begin() { return iterator{head_.get()}; }
    //const_iterator begin() const { return cbegin(); }
    //const_iterator cbegin() const { return const_iterator{head_.get()}; }
    iterator end() { return iterator{nullptr}; }
    //const_iterator end() const { return cend(); }
    //const_iterator cend() const { return const_iterator{nullptr}; }

    void push(T value) { head_ = std::make_unique<Node<T>>(value, std::move(head_)); }

    // TODO(students): Why doesn't std::stack::pop return the value you pop?
    void pop() { head_ = std::move(head_->next); }

    //const int& top() const { return *cbegin(); }
    T& top() { return *begin(); }

private:
    std::unique_ptr<Node<T>> head_;
};

#endif //COMP6771_ADVANCED_CPP_NODE_H
