#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:
template<typename T>
class TreeNode {

  public:
    T data;
    unique_ptr<TreeNode<T>> leftChild;
    unique_ptr<TreeNode<T>> rightChild;
    TreeNode<T> * parent;

  public:
    TreeNode(const T & dataIn)
        : data(dataIn), parent(nullptr) {

    }



  void setLeftChild(TreeNode<T>* child) {
    leftChild.reset(child);
    child->parent = this;
  }

  void setRightChild(TreeNode<T>* child) {
    rightChild.reset(child);
    child->parent = this;

  }

  ostream& write(ostream & os) const {

      if (leftChild != nullptr) {
        cout << "Check if it goes to leftChild" << endl;

        leftChild->write(os);
        //os << " " << this->leftChild->leftChild->data << " " << " " << leftChild->data << " " << " " << leftChild->parent->data << " ";

      }

      os << " " << data << " ";

      if (rightChild != nullptr) {
        cout << "Check if it goes to rightChild" << endl;

        rightChild->write(os);
      }

      cout << "Check treenode's write function" << endl;

    return os;
  }


};


// do not edit below this line

#endif
