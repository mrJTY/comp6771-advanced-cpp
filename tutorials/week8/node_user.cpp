//
// Created by jet on 24/07/19.
//

#include "string"
#include "iostream"
#include "tutorials/week8/node.h"

int main(){
    std::string hellostr = "hello";
    Node<std::string> node{hellostr, nullptr };
    std::cout << node.value_;
    return 0;
}