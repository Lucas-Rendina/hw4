// #ifndef AVLBST_H
// #define AVLBST_H

// #include <iostream>
// #include <exception>
// #include <cstdlib>
// #include <cstdint>
// #include <algorithm>
// #include "bst.h"

// struct KeyError { };

// /**
// * A special kind of node for an AVL tree, which adds the balance as a data member, plus
// * other additional helper functions. You do NOT need to implement any functionality or
// * add additional data members or helper functions.
// */
// template <typename Key, typename Value>
// class AVLNode : public Node<Key, Value>
// {
// public:
//     // Constructor/destructor.
//     AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
//     virtual ~AVLNode();

//     // Getter/setter for the node's height.
//     int8_t getBalance () const;
//     void setBalance (int8_t balance);
//     void updateBalance(int8_t diff);

//     // Getters for parent, left, and right. These need to be redefined since they
//     // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
//     // for more information.
//     virtual AVLNode<Key, Value>* getParent() const override;
//     virtual AVLNode<Key, Value>* getLeft() const override;
//     virtual AVLNode<Key, Value>* getRight() const override;

// protected:
//     int8_t balance_;    // effectively a signed char
// };

// /*
//   -------------------------------------------------
//   Begin implementations for the AVLNode class.
//   -------------------------------------------------
// */

// /**
// * An explicit constructor to initialize the elements by calling the base class constructor
// */
// template<class Key, class Value>
// AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
//     Node<Key, Value>(key, value, parent), balance_(0)
// {

// }

// /**
// * A destructor which does nothing.
// */
// template<class Key, class Value>
// AVLNode<Key, Value>::~AVLNode()
// {

// }

// /**
// * A getter for the balance of a AVLNode.
// */
// template<class Key, class Value>
// int8_t AVLNode<Key, Value>::getBalance() const
// {
//     return balance_;
// }

// /**
// * A setter for the balance of a AVLNode.
// */
// template<class Key, class Value>
// void AVLNode<Key, Value>::setBalance(int8_t balance)
// {
//     balance_ = balance;
// }

// /**
// * Adds diff to the balance of a AVLNode.
// */
// template<class Key, class Value>
// void AVLNode<Key, Value>::updateBalance(int8_t diff)
// {
//     balance_ += diff;
// }

// /**
// * An overridden function for getting the parent since a static_cast is necessary to make sure
// * that our node is a AVLNode.
// */
// template<class Key, class Value>
// AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
// {
//     return static_cast<AVLNode<Key, Value>*>(this->parent_);
// }

// /**
// * Overridden for the same reasons as above.
// */
// template<class Key, class Value>
// AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
// {
//     return static_cast<AVLNode<Key, Value>*>(this->left_);
// }

// /**
// * Overridden for the same reasons as above.
// */
// template<class Key, class Value>
// AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
// {
//     return static_cast<AVLNode<Key, Value>*>(this->right_);
// }


// /*
//   -----------------------------------------------
//   End implementations for the AVLNode class.
//   -----------------------------------------------
// */


// template <class Key, class Value>
// class AVLTree : public BinarySearchTree<Key, Value>
// {
// public:
//     virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
//     virtual void remove(const Key& key);  // TODO
// protected:
//     virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

//     // Add helper functions here


// };

// /*
//  * Recall: If key is already in the tree, you should 
//  * overwrite the current value with the updated value.
//  */
// template<class Key, class Value>
// void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
// {
//     // TODO
// }

// /*
//  * Recall: The writeup specifies that if a node has 2 children you
//  * should swap with the predecessor and then remove.
//  */
// template<class Key, class Value>
// void AVLTree<Key, Value>:: remove(const Key& key)
// {
//     // TODO
// }

// template<class Key, class Value>
// void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
// {
//     BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
//     int8_t tempB = n1->getBalance();
//     n1->setBalance(n2->getBalance());
//     n2->setBalance(tempB);
// }


// #endif



#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int8_t getBalance () const;
    void setBalance (int8_t balance);
    void updateBalance(int8_t diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int8_t balance_;    // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    void rotateLeft(AVLNode<Key,Value>* node);
    void rotateRight(AVLNode<Key,Value>* node);

    void insertBalance(AVLNode<Key,Value>* node);
    void removeBalance(AVLNode<Key,Value>* node);

    int height(AVLNode<Key,Value>* node) const;


};

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
    // TODO

    AVLNode<Key, Value>* parent = NULL;
    AVLNode<Key, Value>* node = static_cast<AVLNode<Key, Value>*>(this->root_);
    while (node != NULL) {
        parent = node;
        if (new_item.first < node->getKey()) {
            node = static_cast<AVLNode<Key, Value>*>(node->getLeft());
        } 
        else if (new_item.first > node->getKey()) {
            node = static_cast<AVLNode<Key, Value>*>(node->getRight());
        } 
        else {
            node->setValue(new_item.second);
            return; 
        }
    }

    AVLNode<Key, Value>* newItem = new AVLNode<Key, Value>(new_item.first, new_item.second, parent);
    if (parent == NULL) {
        this->root_ = newItem;
    } 
    else if (new_item.first < parent->getKey()) {
        parent->setLeft(newItem);
    } 
    else {
        parent->setRight(newItem);
    }

    while (parent != NULL) {
        if (newItem == parent->getLeft()) {
            parent->updateBalance(-1);
        } 
        else {
            parent->updateBalance(1);
        }

        if (parent->getBalance() == 0) {
            break; 
        } 
        else if (parent->getBalance() > 1 || parent->getBalance() < -1) {
            insertBalance(parent);
            break; 
        }

        newItem = parent;
        parent = static_cast<AVLNode<Key, Value>*>(parent->getParent());
    }
}


/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::remove(const Key& key) {
    //TODO

    AVLNode<Key, Value>* node = static_cast<AVLNode<Key, Value>*>(this->internalFind(key));
    if (node == NULL) {
        return; 
    }

    if (node->getLeft() != NULL && node->getRight() != NULL) {
        AVLNode<Key, Value>* pred = static_cast<AVLNode<Key, Value>*>(this->predecessor(node));
        nodeSwap(node, pred);
    }


   AVLNode<Key, Value>* child = NULL;
    if (node->getLeft() != NULL) {
        child = static_cast<AVLNode<Key, Value>*>(node->getLeft());
    } 
    else if (node->getRight() != NULL){
        child = static_cast<AVLNode<Key, Value>*>(node->getRight());
    }


    AVLNode<Key, Value>* parent = node->getParent();

    if (parent != NULL) {
        if (parent->getLeft() == node) {
            parent->setLeft(child);
        } 
        else {
            parent->setRight(child);
        }
    } 
    else {
        this->root_ = child;
    }

    if (child != NULL) {
         child->setParent(node->getParent());
    }
    delete node; 

    AVLNode<Key, Value>* toBalance = parent;
    removeBalance(toBalance);

}



template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int8_t tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}





template<class Key, class Value>
int AVLTree<Key, Value>::height(AVLNode<Key, Value>* node) const {
    if (node ==NULL) {
        return -1;
    }
    int lheight = -1;
    if (node->getLeft() != NULL) {
        lheight = height(node->getLeft());
    }
    int rheight = -1;
    if (node->getRight() != NULL) {
        rheight = height(node->getRight());
    }
    if (lheight > rheight) {
        return lheight + 1;
    } 
    else {
        return rheight + 1;
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::removeBalance(AVLNode<Key, Value>* node) {
    while (node != NULL) {
        int lheight = -1;
        if (node->getLeft() != NULL) {
            lheight = height(node->getLeft());
        }
        int rightHeight = -1;
        if (node->getRight() != NULL) {
            rightHeight = height(node->getRight());
        }
        int balance = lheight - rightHeight;

        node->setBalance(balance); 

        if (balance > 1) {
            int llheight = -1;
            if (node->getLeft() != NULL && node->getLeft()->getLeft() != NULL) {
                llheight = height(node->getLeft()->getLeft());
            }
            int lrheight = -1;
            if (node->getLeft() !=NULL && node->getLeft()->getRight() != NULL) {
                lrheight = height(node->getLeft()->getRight());
            }
            if (llheight >= lrheight) {
                rotateRight(node);
            } 
            else {
                rotateLeft(node->getLeft()); 
                rotateRight(node);
            }
        } 
        else if (balance < -1) {
            int rrheight = -1;
            if (node->getRight() != NULL && node->getRight()->getRight() != NULL) {
                rrheight = height(node->getRight()->getRight());
            }
            int rlheight = -1;
            if (node->getRight() != NULL && node->getRight()->getLeft() != NULL) {
                rlheight = height(node->getRight()->getLeft());
            }
            if (rrheight >= rlheight) {
                rotateLeft(node); 
            } 
            else {
                rotateRight(node->getRight()); 
                rotateLeft(node);
            }
        }

        node = node->getParent(); 
    }
}


template<class Key, class Value>
void AVLTree<Key, Value>::insertBalance(AVLNode<Key, Value>* node) {
    if (node->getBalance() < 0) {
        AVLNode<Key, Value>* lchild = static_cast<AVLNode<Key, Value>*>(node->getLeft());
        if (lchild->getBalance() > 0) {
            rotateLeft(lchild);
        }
        rotateRight(node);
    } 
    else {
        AVLNode<Key, Value>* rchild = static_cast<AVLNode<Key, Value>*>(node->getRight());
        if (rchild->getBalance() < 0) {
            rotateRight(rchild);
        }
        rotateLeft(node);
    }
}


template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeft(AVLNode<Key, Value>* node) {
    AVLNode<Key, Value>* rchild = node->getRight();
    
    node->setRight(rchild->getLeft());
    if (rchild->getLeft() != NULL) {
        rchild->getLeft()->setParent(node);
    }
    rchild->setParent(node->getParent());
    if (node->getParent() == NULL) {
        this->root_ = rchild;
    } 
    else if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(rchild);
    } 
    else {
        node->getParent()->setRight(rchild);
    }
    rchild->setLeft(node);
    node->setParent(rchild);

    int bal = 0;
    if (rchild->getBalance() > 0) {
        bal = rchild->getBalance();
    }
    node->setBalance(node->getBalance()-1- bal);

    bal = 0;
    if (node->getBalance() < 0) {
        bal = node->getBalance();
    }
    rchild->setBalance(rchild->getBalance()-1+ bal);
}


template<class Key, class Value>
void AVLTree<Key, Value>::rotateRight(AVLNode<Key, Value>* node) {
    AVLNode<Key, Value>* lchild = node->getLeft();
    
    node->setLeft(lchild->getRight());
    if (lchild->getRight() != NULL) {
        lchild->getRight()->setParent(node);
    }

    lchild->setParent(node->getParent());
    if (node->getParent() == NULL) {
        this->root_ = lchild;
    } 
    else if (node == node->getParent()->getRight()) {
        node->getParent()->setRight(lchild);
    } 
    else {
        node->getParent()->setLeft(lchild);
    }

    lchild->setRight(node);
    node->setParent(lchild);

    int bal = 0;
    if (lchild->getBalance() < 0) {
        bal = lchild->getBalance();
    }
    node->setBalance(node->getBalance()+1-bal);

    bal = 0;
    if (node->getBalance() > 0) {
        bal = node->getBalance();
    }
    lchild->setBalance(lchild->getBalance()+1+bal);
}


#endif
