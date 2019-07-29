#include "assignments/dg/graph.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

template <typename N, typename E>
bool gdwg::Graph<N, E>::InsertNode(const N& val) {

  bool found = IsNode(val);
  if (!found) {
    std::shared_ptr<Node<N>> ptr = std::make_shared<Node<N>>(val);
    // Give ownership to the set
    nodes_.emplace(std::move(ptr));

    // Add an edge to a null node
    // TODO(jt): can we emplace something other than NULL?
    std::shared_ptr<Node<N>> srcPtr;
    for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
      if ((*iter)->value_ == val) {
        srcPtr = (*iter);
      }
    }

    // Give an edge to itself, flag as initializer = true
    E null = static_cast<E>(0);
    Edge<N, E> e{srcPtr, srcPtr, null, true};
    edges_.emplace(e);
  }

  // Return false if there is already a Node
  return !found;
}
template <typename N, typename E>
bool gdwg::Graph<N, E>::IsNode(const N& val) {
  bool found = false;
  for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
    if (val == (*iter)->value_) {
      found = true;
    }
  }
  return found;
}

template <typename N, typename E>
std::vector<N> gdwg::Graph<N, E>::GetNodes() {
  std::vector<N> v;
  // This is how you iterate through...
  for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
    v.push_back((*iter)->value_);
  }
  return v;
}

template <typename N, typename E>
bool gdwg::Graph<N, E>::InsertEdge(const N& src, const N& dst, const E& w) {

  // If src dst, and weight exists, return false
  {
    bool srcExists = IsNode(src);
    bool dstExists = IsNode(dst);
    if (!srcExists || !dstExists) {
      throw std::runtime_error(
          "Cannot call Graph::InsertEdge when either src or dst node does not exist");
    }
  }

  {
    // Check for existing edges
    for (auto iter = edges_.begin(); iter != edges_.end(); ++iter) {
      bool srcExists = (*(*iter).src_).value_ == src;
      bool dstExists = (*(*iter).dst_).value_ == dst;
      bool weightExists = (*iter).weight_ == w;
      if (srcExists && dstExists && weightExists) {
        return false;
      }
    }
  }
  // Else, add a new edge...
  std::shared_ptr<Node<N>> srcWp;
  std::shared_ptr<Node<N>> dstWp;
  for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
    if ((*iter)->value_ == src) {
      srcWp = (*iter);
    } else if ((*iter)->value_ == dst) {
      dstWp = (*iter);
    }
  }

  Edge<N, E> e{srcWp, dstWp, w};
  edges_.emplace(e);
  return true;
}

template <typename N, typename E>
bool gdwg::Graph<N, E>::DeleteNode(const N& val) {
  bool found = false;
  for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
    std::shared_ptr<Node<N>> p = (*iter);
    if ((*p).value_ == val) {
      nodes_.erase(iter);
      found = true;
    }
  }

  for (auto iter = edges_.begin(); iter != edges_.end(); ++iter) {
    auto edge = (*iter);
    auto srcVal = (*edge.src_).value_;
    auto dstVal = (*edge.dst_).value_;

    if (srcVal == val || dstVal == val) {
      edges_.erase(iter);
    }
  }
  return found;
}

template <typename N, typename E>
void gdwg::Graph<N, E>::Clear() {
  nodes_.erase(nodes_.begin(), nodes_.end());
  edges_.erase(edges_.begin(), edges_.end());
}

template <typename N, typename E>
bool gdwg::Graph<N, E>::IsConnected(const N& src, const N& dst) {
  // If src dst, and weight exists, return false
  {
    bool srcExists = IsNode(src);
    bool dstExists = IsNode(dst);
    if (!srcExists || !dstExists) {
      throw std::runtime_error(
          "Cannot call Graph::InsertEdge when either src or dst node does not exist");
    }
  }

  // Check for existing edges
  for (auto iter = edges_.cbegin(); iter != edges_.cend(); ++iter) {
    bool srcExists = (*(*iter).src_).value_ == src;
    bool dstExists = (*(*iter).dst_).value_ == dst;
    if (srcExists && dstExists) {
      return true;
    }
  }
  return false;
}

template <typename N, typename E>
std::vector<N> gdwg::Graph<N, E>::GetConnected(const N& src) {
  std::vector<N> v;

  if (!IsNode(src)) {
    throw std::runtime_error("Cannot call Graph::GetConnected if src doesn't exist in the graph");
  }

  for (auto iter = edges_.cbegin(); iter != edges_.cend(); ++iter) {
    auto edge = (*iter);
    auto srcNodeValue = (*(edge).src_).value_;

    if (srcNodeValue == src) {
      auto dstNodeValue = (*(edge).dst_).value_;
      E null = static_cast<E>(0);
      if ((edge).weight_ != null) {
        v.push_back(dstNodeValue);
      }
    }
  }
  std::sort(v.begin(), v.end());

  return v;
}

template <typename N, typename E>
std::vector<E> gdwg::Graph<N, E>::GetWeights(const N& src, const N& dst) {
  std::vector<E> v;

  if (!IsNode(src) || !IsNode(dst)) {
    throw std::runtime_error(
        "Cannot call Graph::GetWeights if src or dst node don't exist in the graph");
  }

  for (auto iter = edges_.cbegin(); iter != edges_.cend(); ++iter) {
    auto edge = (*iter);
    auto srcNodeValue = (*(edge).src_).value_;
    auto dstNodeValue = (*(edge).dst_).value_;

    if (srcNodeValue == src && dstNodeValue == dst) {
      auto weight = edge.weight_;
      E null = static_cast<E>(0);
      if (weight != null) {
        v.push_back(weight);
      }
    }
  }

  // Return based on increasing order of Edge
  std::sort(v.begin(), v.end());

  return v;
}

template <typename N, typename E>
bool gdwg::Graph<N, E>::Replace(const N& oldData, const N& newData) {
  bool found = false;
  if (!IsNode(oldData)) {
    throw std::runtime_error("Cannot call Graph::Replace on a node that doesn't exist");
  }

  for (auto iter = this->begin(); iter != this->end(); ++iter) {
    auto edge = *iter;
    N srcVal = (*edge.src_).value_;
    N dstVal = (*edge.dst_).value_;
    if (srcVal == oldData){
      (*edge.src_).value_ = newData;
      found = true;
    }

    if(dstVal == oldData){
      (*edge.dst_).value_ = newData;
      found = true;
    }
  }
  return found;
}


template <typename N, typename E>
void gdwg::Graph<N, E>::MergeReplace(const N& oldData, const N& newData){

  // Checks
  if(!IsNode(oldData) || !IsNode(newData)){
    throw std::runtime_error("Cannot call Graph::MergeReplace on old or new data if they don't exist in the graph");
  }

//  std::vector<std::tuple<N, E>> incomingEdges {};
  std::vector<std::tuple<N, N, E>> outgoingEdges {};

  N newDataCopy = newData;


  // From the old node, record its incoming / outgoing edges
  for (auto iter = this->begin(); iter != this->end(); ++iter) {
    auto edge = *iter;
    N srcVal = (*edge.src_).value_;
    N dstVal = (*edge.dst_).value_;
    bool isInitializer = edge.initializer_;

    // Outgoing edges are is where the old node was the src
    if (srcVal == oldData && !isInitializer) {
        std::tuple<N,N, E> tup = std::make_tuple(newDataCopy, (*edge.dst_).value_, edge.weight_);
        outgoingEdges.push_back(tup);
    }

    // INcoming are were the old node was the dst
//    if (dstVal == oldData && !isInitializer) {
//        std::tuple<N, E> tup = {(*edge.dst_).value_, edge.weight_};
//        incomingEdges.push_back(tup);
//    }
  }
//
//  bool foo = true;
//  std::cout << foo;

  // Add the incoming / outgoing edges to the new node
//  for(auto iter = incomingEdges.begin(); iter != incomingEdges.end(); ++iter){
//      N oldSrc = std::get<0>(*iter);
//      E weight = std::get<1>(*iter);
//      // Add an edge from the old source to the new data
//      InsertEdge(oldSrc, newData, weight);
//  }
  for(auto iter = outgoingEdges.begin(); iter != outgoingEdges.end(); ++iter){
        N src = std::get<0>(*iter);
        N dst = std::get<1>(*iter);
        E weight = std::get<2>(*iter);
        // Add an edge from the old source to the new data
//        InsertEdge(newSrc, oldDst, weight);
        InsertEdge(src, dst, weight);
  }

  DeleteNode(oldData);


//  for(auto iter = outgoingEdges.begin(); iter != outgoingEdges.end(); ++iter){
//      N replacement = (*replacementNode).value_;
//      N old = (*(*iter).dst_).value_;
//      this->InsertEdge(replacement, old, (*iter).weight_);
//  }


    // Remove the old node
//    DeleteNode(oldData);

//  // Search for new data
//  for (auto iter = this->begin(); iter != this->end(); ++iter) {
//    auto edge = *iter;
//    N srcVal = (*edge.src_).value_;
//    N dstVal = (*edge.dst_).value_;
//    if (srcVal == newData) {
//        (*edge.src_).value_ = oldData;
//    } else if(dstVal == newData){
//        (*edge.dst_).value_ = oldData;
//    }
//  }

  // Swap the two by creating a new object
//  newPtr.reset(new Node<N>{oldData});
//  oldPtr.reset(new Node<N>{newData});

}
