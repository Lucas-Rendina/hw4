// #ifndef RECCHECK
// //if you want to add any #includes like <iostream> you must do them here (before the next endif)

// #endif

// #include "equal-paths.h"
// using namespace std;


// // You may add any prototypes of helper functions here


// bool equalPaths(Node * root)
// {
//     // Add your code below

// }


#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

int findPath(Node* node, bool& isEqual, int depth);

bool equalPaths(Node * root)
{
    // Add your code below
    if (!root) return true;
    
    bool isEqual = true;
    int initialDepth = findPath(root, isEqual, 0);
    initialDepth++;
    
    return isEqual;
}

int findPath(Node* node, bool& isEqual, int depth) {

    if (!node->left && !node->right) {
        return depth;
    }
    
    int lDepth = -1;
    int rDepth = -1;
    
    if (node->left) {
        lDepth = findPath(node->left, isEqual, depth + 1);
    }
    
    if (node->right) {
        rDepth = findPath(node->right, isEqual, depth + 1);
    }
    
    if (node->left && node->right && lDepth != rDepth) {
        isEqual = false;
    }
    

    if( lDepth > rDepth){
        return lDepth;
    }
    return rDepth;
}

