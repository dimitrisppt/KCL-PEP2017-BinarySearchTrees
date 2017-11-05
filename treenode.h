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

  // ----------- Advanced Part

  int maxDepth() {

    int L = -1;
    int R = -1;
    if (leftChild == nullptr && rightChild == nullptr) {
      return 1;
    } else {

    	if(leftChild){
    		L = leftChild->maxDepth();
    	}
    	if(rightChild){
    		R = rightChild->maxDepth();
    	}
      //<<"Left: " <<L<< " Right: "<< R<<endl;
    	if(L>R){
    		return L+1;
    	}
    	else{
    		return R+1;
    	}
    }

  }


};


template<typename T>
class TreeNodeIterator {

private:

    TreeNode<T>* current;

public:

    TreeNodeIterator(TreeNode<T>* currentIn)
        : current(currentIn) {
    }

    T & operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here
    TreeNodeIterator<T> operator++() {
      if(current->rightChild) {
        current = current->rightChild.get();
        //cout << " before first While" <<endl;
        while (current->leftChild) {
          current = current->leftChild.get();
        }
      //  cout << current->data  << " first return" << endl;
        return TreeNodeIterator<T>(current);
      } else {
        T currentData = current->data;
        //cout << "Before second while"<< endl;
        while (current->parent && (currentData >= current->data)) {
          current = current->parent;
        }
        if (current->data > currentData) {
        //  cout << current->data << " second return" <<  endl;
          return TreeNodeIterator<T>(current);
        } else {
          //cout << "We have reached the end" << endl;
          current = nullptr;
          return current;
        }
      }


    }

    bool operator==(const TreeNodeIterator<T>& itr) {
      return current==itr.current;
    }

    bool operator!=(const TreeNodeIterator<T>& itr) {
      return current!=itr.current;
    }



};


// do not edit below this line

#endif
