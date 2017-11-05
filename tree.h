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

          if (current->parent) {
            if (balanceFactor(current->parent) == 2 && !(current->rightChild)) {
              rightRotation(current->parent);
            } else {
              // left-right rotation
            }
          }

        } else {
          current->setRightChild(new TreeNode<T>(data));

          if (current->parent) {
            if (balanceFactor(current->parent) == -2 && !(current->leftChild)) {
              leftRotation(current->parent);
            } else {
              // right- left rotation
            }

          }
        }
      }
      return current;
  }

  TreeNode<T>* insert(T data) {

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




    //-------------- Advanced Part
    TreeNodeIterator<T> begin() {
      TreeNode<T> * current = root.get();
      if(current)
      while (current->leftChild != nullptr) {
        current = current->leftChild.get();
      }
      return TreeNodeIterator<T>(current);

    }


    TreeNodeIterator<T> end() {
      return nullptr;
    }

    int maxDepth() {
      return root->maxDepth();
    }


    int balanceFactor(TreeNode<T>* node) {
      if (node->leftChild && node->rightChild) {
        return ((node->leftChild.get())->maxDepth() - (node->rightChild.get())->maxDepth());
      } else if (node->leftChild) {
        return ((node->leftChild.get())->maxDepth());
      } else if (node->rightChild) {
        return (-1*(node->rightChild.get())->maxDepth());
      } else {
        return 0;
      }
    }

    void leftRotation(TreeNode<T>* subRoot){

      TreeNode<T>* temp = subRoot->rightChild.release();

      if (subRoot->parent) {
        TreeNode<T>* parent = subRoot->parent;
        if (parent->rightChild.get() == subRoot) {
          parent->rightChild.release();
          parent->rightChild.reset(temp);
        } else {
          parent->leftChild.release();
          parent->leftChild.reset(temp);
        }
      } else {
        root.release(); //
        root.reset(temp); //
      }
      temp->leftChild.reset(subRoot);
      subRoot->parent = temp;


    }

    void rightRotation(TreeNode<T>* subRoot){

      TreeNode<T>* temp = subRoot->leftChild.release();

      if (subRoot->parent) {
        TreeNode<T>* parent = subRoot->parent;
        if (parent->leftChild.get() == subRoot) {
          parent->leftChild.release();
          parent->leftChild.reset(temp);
        } else {
          parent->rightChild.release();
          parent->rightChild.reset(temp);
        }
      } else {
        root.release(); //
        root.reset(temp); //
      }
      temp->rightChild.reset(subRoot);
      subRoot->parent = temp;
    }

    void leftRightRotation(TreeNode<T>* subRoot) {


    }

    void rightLeftRotation(TreeNode<T>* subRoot) {


    }





};




// do not edit below this line

#endif
