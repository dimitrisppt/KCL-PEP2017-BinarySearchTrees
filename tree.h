#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
class BinarySearchTree {

  //private:
public:
    unique_ptr<TreeNode<T>> root;

  //public:

    void  write(ostream & os) const {
      if(root){
        root->write(os);
      }
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
              if (current->parent->leftChild.get() == nullptr) {
                // -------------- Right-Left Rotation ---------------
                TreeNode<T>* node1 = new TreeNode<T>(current->parent->data);
                TreeNode<T>* node2 = new TreeNode<T>(current->data);
                TreeNode<T>* var1 = new TreeNode<T>(data);
                if (current->parent->parent == nullptr) {

                    root.reset(var1);
                    var1->setLeftChild(node1);
                    var1->setRightChild(node2);

                }else{
                  cout << "this part - rlRotate" << endl;
                  //TreeNode<T>* parent = new TreeNode<T>(current->parent->parent->data);
                  TreeNode<T>* parent = current->parent->parent;

                  if(parent->rightChild.get() == node1){
                    parent->setRightChild(var1);
                    var1->setLeftChild(node1);
                    var1->setRightChild(node2);

                  } else {
                    parent->setLeftChild(var1);
                    var1->setLeftChild(node1);
                    var1->setRightChild(node2);
                  }
               }
              }
            }
          }

        } else {
          current->setRightChild(new TreeNode<T>(data));

          if (current->parent) {
            if (balanceFactor(current->parent) == -2 && !(current->leftChild)) {
              leftRotation(current->parent);
            } else {
              if (current->parent->rightChild.get() == nullptr) {
                TreeNode<T>* node1 = new TreeNode<T>(current->parent->data);
                TreeNode<T>* node2 = new TreeNode<T>(current->data);
                TreeNode<T>* var1 = new TreeNode<T>(data);
                // ------------ Left-Right Rotation -------------
                if (current->parent->parent == nullptr) {

                    root.reset(var1);
                    var1->setLeftChild(node2);
                    var1->setRightChild(node1);

                } else{
                  cout << "this part - lrRotate" << endl;
                  //TreeNode<T>* parent = new TreeNode<T>(current->parent->parent->data);
                  TreeNode<T>* parent = current->parent->parent;

                  if(parent->rightChild.get() == node1){
                    parent->setRightChild(var1);
                    var1->setLeftChild(node1);
                    var1->setRightChild(node2);

                  } else {
                    parent->setLeftChild(var1);
                    var1->setLeftChild(node1);
                    var1->setRightChild(node2);
                  }

                }

              }
            }

          }
        }
      }
      return current;
  }

  TreeNode<T>* insert(T data) {
    //cout << "inserting:" << data << ". Tree is: ";
    // write(cout);
    // cout<<endl;

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


};




// do not edit below this line

#endif
