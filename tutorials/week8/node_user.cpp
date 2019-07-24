//
// Created by jet on 24/07/19.
//

#include "string"
#include "iostream"
#include <memory>
#include "tutorials/week8/node.h"

int main(){
//    std::string hellostr = "hello";
//    std::string worldstr = "world";
//
//    std::unique_ptr<Node<std::string>> ptr1 = std::make_unique<Node<std::string>>(hellostr);
//    std::unique_ptr<Node<std::string>> ptr2 = std::make_unique<Node<std::string>>(worldstr);
//
//    Node<std::string> node1{hellostr, ptr2};
//    Node<std::string> node2{worldstr, ptr1};


    Stack<std::string> s;
    s.push("asdf");
    s.push("foo");
    std::cout << s.top();




    return 0;
}