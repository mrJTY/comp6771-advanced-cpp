//
// Created by jet on 24/07/19.
//

#ifndef COMP6771_ADVANCED_CPP_NODE_H
#define COMP6771_ADVANCED_CPP_NODE_H
#include <iterator>
#include <memory>
#include "string"

template<typename T>
struct Node{
public:
    Node(T value, std::unique_ptr<Node>&& next) : value_(value), next_(std::move(next)){}

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
        // TODO: node_ = node_->next.get();
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

#endif //COMP6771_ADVANCED_CPP_NODE_H
