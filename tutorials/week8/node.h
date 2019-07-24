//
// Created by jet on 24/07/19.
//

#ifndef COMP6771_ADVANCED_CPP_NODE_H
#define COMP6771_ADVANCED_CPP_NODE_H

#include "string"

class Node{
    public:
        explicit Node(std::string word) : word_(word){}

    private:
        std::string word_;
};

#endif //COMP6771_ADVANCED_CPP_NODE_H
