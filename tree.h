#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
class BinarySearchTree {

  private:
    unique_ptr<TreeNode<T>> root;

  public:

    void  write(ostream & os) const {
      root->write(os);
    }

    TreeNode<T>* insertIteration(TreeNode<T>* current, T data) {

      if(data < current->data && current->leftChild != NULL) {
          insertIteration(current->leftChild.get(), data);

      } else if (current->data < data && current->rightChild != NULL) {
          insertIteration(current->rightChild.get(), data);
      } else {
        if (data < current->data){
          current->setLeftChild(new TreeNode<T>(data));
        } else {
          current->setRightChild(new TreeNode<T>(data));
        }
      }
      return current;
  }

  TreeNode<T>* insert(const T & data) {

    if (root == nullptr) {

      TreeNode<T>* newNode = new TreeNode<T>(data);
      root.reset(newNode);

      return root.get();

    } else {

      return insertIteration(root.get(),data);
    }


  }


    TreeNode<T>* find(const T & data) {

        return findRec(root.get(), data);

    }


    TreeNode<T>* findRec(TreeNode<T>* current, T data) {

      if (current != nullptr) {

        if (data < current->data) {
          return findRec(current->leftChild.get(), data);
        } else if (current->data < data){
          return findRec(current->rightChild.get(), data);
        } else {
          return current;
        }
      } else {
        return nullptr;
      }
    }


};




// do not edit below this line

#endif
