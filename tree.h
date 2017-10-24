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
        cout << "Test if null" << endl;
        cout << root.get()->data << endl;
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

        if (current->data == data) {
          return current;
        }
        if (data < current->data) {
          return findRec(current->leftChild.get(), data);
        } else {
          return findRec(current->rightChild.get(), data);
        }
      } else {
        return nullptr;
      }
    }



    // TreeNode<T>* insert(const T & data) {
    //
    //   if () {
    //     TreeNode<T>* newNode = new TreeNode<T>(data);
    //     root.reset(newNode);
    //     return newNode;
    //
    //   }
    //
    //   TreeNode<T>* parent = insertIteration(root, data);
    //
    //   if (data < parent.getData()) {
    //     parent->setLeftChild(new TreeNode<T>(data));
    //
    //   } else {
    //     parent->setRightChild(new TreeNode<T>(data));
    //   }
    //
    //   return parent;
    //
    //
    // }



    //
    // TreeNode<T>* insert(const T & data) {
    //
    //   if (!root == nullptr) {
    //
    //     TreeNode<T>* newNode = new TreeNode<T>(data);
    //     root.reset(newNode);
    //     return newNode;
    //
    //   } else {
    //
    //     while(root != nullptr) {
    //
    //       if (data < root->data) {
    //         root->leftChild.get() = insert(data);
    //         root.get()->setLeftChild(root->leftChild.get());
    //
    //       } else if (root->data < data){
    //         root->rightChild.get() = insert(data);
    //         root.get()->setRightChild(root->rightChild.get());
    //
    //       } else {
    //         return root.get();
    //       }
    //
    //     }
    //   }
    //   return root.get();
    //
    //
    // }


};




// do not edit below this line

#endif
