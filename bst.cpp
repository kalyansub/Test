/* Code to learn how to build Binary Search Tree and associated funtions.
   This topic seems to be a frequently occusrring theme in SW interviews;
   Points to note: A binary tree is made of nodes, where each node contains a
   "left" pointer, a "right" pointer, and a data element. The "root" pointer 
    points to the topmost node in the tree. The left and right pointers recursively 
    point to smaller "subtrees" on either side. A Binary Search Tree (BST) is a special
    case of a Binary Tree, where nodes are sorted in some order, e.g., the top most 
   (root) node is the largest, the next smaller or qeual (<=) node gets added to the 
   left and the next larger node (>) (compared ot the root), gets added to the right, 
   and so forth recursively, until there are no more nodes.
   BSTs are fast at insert and lookup, as they basically use a binary search to find
   a node in O(log(N)) time.Thereforem BSTs are good for dictionary problems.
   $Author$: Kalyan Subramanian
   $emai$: kalyan dot sub at gmail
   $Date$: Aug 21, 2014.
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/* Basic Binary Tree structure: the current node (parent) has a left child and 
   a right child node 
*/
typedef struct Node Node;
typedef struct Node* NodePtr;
struct Node
{
    int data;
    NodePtr left;
    NodePtr right;
};

//function prototypes:
NodePtr createNode(int data);
NodePtr insert(NodePtr node, int data);
NodePtr build123a();
int sizeOfTree( NodePtr node);
NodePtr build123b();
NodePtr build123c();

// Helper function that alloates and inserts a node in the BST
NodePtr createNode(int data)
{
 NodePtr node = new(Node); 
 node->data = data;
 node->left = NULL;
 node->right = NULL;

 return(node);
}

/*
 Given a BST tree and a datum, inserts a new node
 with the given datum in the correct place in the tree.
 Returns the new root pointer which the caller should
 then use...
*/
NodePtr insert(NodePtr node, int data)
{
    if (node == NULL)
    {
        return (createNode(data));
    }
    else
    {
       if (data <= node->data) // lte case, go left
       {
           node->left =  insert(node->left, data);
       }
       else// gt case, go right
       {
           node->right= insert(node->right, data);
       }
    }
    return node;
}

NodePtr build123a()
{
    NodePtr root = createNode(2);
    NodePtr lChild = createNode(1);
    NodePtr rChild = createNode(3);
    
    root->left = lChild;
    root->right = rChild;

    return root;
}

NodePtr build123b()
{
    NodePtr root = NULL;

    root = createNode(2);
    root->left = createNode(1); 
    root->right = createNode(3); 

    return root;
}

NodePtr build123c()
{
     NodePtr root = NULL;
     root = insert(root, 2);
     root = insert(root, 1);
     root = insert(root, 3);

     return root;
}

/* Calculate the number of nodes in the tree */
int sizeOfTree( NodePtr node)
{
    int numNodes;
    
    if ( node == NULL )
    {
        numNodes = 0;
    }
    else
    {
        numNodes = sizeOfTree( node->left) + 1 + sizeOfTree( node-> right);
    }
    return numNodes;
}

/* Given a binary tree, find a datum: return true if the datum is foound in one of the
   nodes of the tree; recusively traverse the nodes, choosing left or right by comparing the
   sought for value to the current node: 
*/
static int lookup(NodePtr startNode, int target)
{
    cout << "lookup(): startNode->data = " << startNode->data << "\n";
    // 1. base case: empty tree, so retrun false right away:
    if (startNode == NULL)
    {
        return false;
    } 
    else
    {
        if ( target == startNode->data ) // if we found it here, great !
        {
            cout << "lookup(): got it !\n";
            return true;
        }
        if (target < startNode->data) // lte case, recurse left
        {
            cout << "lookup(): going left: target =" << target << "data = " << startNode->data << "\n";
            return (lookup(startNode->left, target));
        }
        else  // gt case, recurse right
        {
            cout << "lookup(): going right: target =" << target << "data = " << startNode->data << "\n";
            return (lookup(startNode->right, target));
        }
    }
}



int main(int argc, char* argv[])
{
   NodePtr aNode = build123a(); 
   int target = 3;
   int size = sizeOfTree(aNode);

   cout << "size of tree so far is " << size << "\n";
   if (lookup(aNode, 3))
   {
       cout << "Found " << target << "\n";
   }
   else
   {
       cout << "Could not find " << target << "\n";
   }

   return 0;
}
