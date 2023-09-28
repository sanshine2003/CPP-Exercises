#include <iostream>
#include <stdexcept>
#include <queue>

using namespace std;
#define COUNT 10  

class BSTException : public std::runtime_error {
 public:
   BSTException(const char* m) : std::runtime_error(m) { }
 };


template <class T>
class BST 
{
  struct node {
    T data;
    struct node *left;
    struct node *right;
  };

  struct node *root;
  
  void delete_tree(struct node * root);
  struct node * insert_data(struct node * r, const T& d);
  struct node * delete_data(struct node * r, const T& d);
  struct node * search_data(struct node * r, const T& d);
  void Inorder(struct node *r);
  struct node * find_min(struct node * r);
  struct node * find_max(struct node * r);
  int find_height(struct node * r);

  void print2DUtil(struct node *root, int space);
  void print2D(struct node *root);
  void convertBSTToSortedDDL(struct node *root, struct node* &headRef, int &n);
  struct node * convertSortedDDLToBST(struct node * &headRef, int n);

public:
  BST(); //Default CTOR
  BST(const T& data); //CTOR
 // BST(BST& bst_obj); //Copy CTOR
  ~BST();  //DTOR

  bool Insert(const T& d);
  bool Delete(const T& d);
  bool Search(const T& d);
  bool BreadthFirstSearch(const T& d);
  void Print();
  void Print2D();
  bool Reset();
  T& FindMin();
  T& FindMax();
  int FindHeight();
  void Balance();
};

// Function to print binary tree in 2D  
// It does reverse inorder traversal  
template <class T>
void BST<T>::print2DUtil(struct node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()
template <class T>  
void BST<T>::print2D(struct node *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  

template <class T>
void BST<T>::delete_tree(struct node * root)
{
  if(root == nullptr)
    return;

  delete_tree(root->left);
  delete_tree(root->right);

  delete root;
}

template <class T>
bool BST<T>::Reset()
{
  //Delete all nodes
  delete_tree(root);
  root = nullptr;
  return true;
}

template <class T>
BST<T>::BST()
{
  root = nullptr;
}

template <class T>
BST<T>::BST(const T& data)
{
  root = nullptr;
  root = insert_data(root, data);
}

template <class T>
BST<T>::~BST()
{
  Reset();
}

template <class T>
struct BST<T>::node * BST<T>::insert_data(struct node * r, const T& d)
{
  if(r == nullptr)
  {
    r = new node();
    r->data = d;
    r->left = r->right = nullptr;
  }  
  else if(d <= r->data)
    r->left = insert_data(r->left, d);
  else if(d > r->data)
    r->right = insert_data(r->right, d);

  return r;
}

//All elements less than the incoming are in the left
//Find the leaf node in the left subtree
template <class T>
struct BST<T>::node * BST<T>::find_min(struct node * r)
{
  while (r->left != nullptr)
    r = r->left;
  
  return r;
}

//All elements greater than the incoming are in the right
//Find the leaf node in the right subtree
template <class T>
struct BST<T>::node * BST<T>::find_max(struct node * r)
{
  while (r->right != nullptr)
    r = r->right;
  
  return r;
}

template <class T>
int BST<T>::find_height(struct node * r)
{
  if(r == nullptr)
    return -1;

  int lh = find_height(r->left);
  int rh = find_height(r->right);
  int max = (lh < rh) ? rh : lh;
  return max + 1 ;
}

template <class T>
struct BST<T>::node * BST<T>::delete_data(struct node * r, const T& d)
{
  if (r == nullptr)
    return r;

  cout << "d - " << d << " r->d " << r->data << endl;

  if(d < r->data)
    r->left = delete_data(r->left, d);
  else if(d > r->data)
    r->right = delete_data(r->right, d);
  else //data found. Ready to delete
  {
    cout << "Data Found, Ready to delete" << endl;
    //This node may have both nodes or only one node or no nodes.
    //handle all the cases

    //Case 1: This node has no children. just delete the node
    if( r->left == nullptr && r->right == nullptr)
    {
      delete r;
      r = nullptr;
    }
    //Case2: One child, left or right
    else if(r->left == nullptr)
    {
      struct node *t = r;
      r  = r->right;
      delete t;
    }
    else if(r->right == nullptr)
    {
      struct node *t = r;
      r  = r->left;
      delete t;
    }
    //Case 3: Both Children
    //We are going to delete a node that has a subtree. After deletion,
    //one of the nodes in the subtree needs to be promoted to root.
    //That node can be either the minimum node in the right subtree or //the maximum in the left subtree. Here we will choose the minimum in the right subtree.
    else
    {
      struct node *t = find_min(r->right);
      r->data = t->data;
      r->right = delete_data(r->right, t->data);
    }
  }
  return r;
}

template <class T>
struct BST<T>::node * BST<T>::search_data(struct node * r, const T& d)
{
  if(r == nullptr)
    return r;
  else if(d == r->data)
    return r;
  if(d <= r->data)
    return search_data(r->left, d);
  else
    return search_data(r->right, d);
  
}


template <class T>
bool BST<T>::Insert(const T& d)
{
  root = insert_data(root,d);
  if(root)
    return true;
  return false;
}

template <class T>
bool BST<T>::Delete(const T& d)
{
  root = delete_data(root,d);
  if(root)
    return true;
  return false;
}

template <class T>
bool BST<T>::Search(const T& d)
{
  struct node *n = search_data(root,d);
  if(n)
  {
    cout << "Found data" << endl;
    return true;
  }
  cout << "Data Not found" << endl;
  return false;
}

//Function to print nodes in Inorder
//Inorder travesral of Binary will print items in sorted order
template <class T>
void BST<T>::Inorder(struct node *r) {
	if(r == nullptr) return;
 
	Inorder(r->left);       //Visit left subtree
	cout << r->data << " ";  //Print data in current root
	Inorder(r->right);      // Visit right subtree
}

//Function to visit nodes in Level Order
//Also Called Breadth first traversal
template <class T>
bool BST<T>::BreadthFirstSearch(const T& d) {
  if(root == nullptr) return false;

  queue<struct node *> Q;
  Q.push(root);

  while (!Q.empty())
  {
    struct node * t = Q.front();
    //cout << t->data << " " ; // Visit the element
    if(t->data == d)
    {
      cout << "BST::BFS - Found data " << endl;
      return true;
    }
    if(t->left != nullptr) Q.push(t->left); //Push left to Q
    if(t->right != nullptr) Q.push(t->right);//Push right to Q
    Q.pop(); //Remove the element that is already visited
  }
  return false;
  
}

template <class T>
void BST<T>::Print2D() {
  print2D(root);
}

template <class T>
void BST<T>::Print() {
  Inorder(root);
}

template <class T>
T& BST<T>::FindMin()
{
  struct node* n = find_min(root);
  if(n)
    return (n->data);
  throw BSTException("Couldnt find an element!!!");
}

template <class T>
T& BST<T>::FindMax()
{
  struct node* n = find_max(root);
  if(n)
    return (n->data);
  throw BSTException("Couldnt find an element!!!");
}

template <class T>
int BST<T>::FindHeight()
{
  return find_height(root);
}

/**
root : Root node of the BST
headRef : reference to the pointer holding the head of the resultant DDL.
n : number of nodes, returned
*/
template <class T>
void BST<T>::convertBSTToSortedDDL(struct node *head, struct node* &headRef, int &n)
{
  /*
  Idea is to perform a reverse inorder traversal of the BST and insert root in
  front of the DDL.
  */

  if(head == nullptr)//Base Case
     return;

  //Reverse inorder traversal, Right first. 
  //Visit in descending order. This will make sure that when the stack winds up from recursion, the DDL is formed in ascending order.
  convertBSTToSortedDDL(head->right, headRef, n);

  //Insert the given node at the front of the DDL.
  head->right = headRef;
  if(headRef != nullptr)
     headRef->left = head;
  
  headRef = head;

  n++; //We have pushed one node into the DDL. Increment.
  //Now travel to the left.
  convertBSTToSortedDDL(head->left, headRef, n);
}

/*
    Idea is to reduce the sorted DDL into self reducing smaller DDLs by using the node count n.

            2<->3<->4<->5<->6<->8<->9

                      5

          2<->3<->4       6<->8<->9

              3               8

          2       4       6       9


*/
template <class T>
struct BST<T>::node * BST<T>::convertSortedDDLToBST(struct node* &headRef, int n)
{
  //base case
 
  if(n <= 0)
  {
    cout << "returning from base with null" << endl;
    return nullptr;
  }
  cout << "Calling convert for left with n -" << n << " and n/2 - " << n/2 << endl;
  struct node *leftSubTree = convertSortedDDLToBST(headRef, n/2);
  cout << "leftsubtree - " << (leftSubTree ? leftSubTree->data : -1) << endl;
  struct node * head = headRef;
  cout << "Head and headRef at " << (head ? head->data : -1) << endl;
  

  head->left = leftSubTree;
  
  if(headRef != nullptr){
      headRef = headRef->right;
      cout << "headRef at " << headRef->data << endl;
  }

cout << "Calling convert for right with n -" << n << " and n-(n/2 + 1) - " << n-(n/2 + 1) << endl;
  head->right = convertSortedDDLToBST(headRef, n-(n/2 + 1));
  cout << "Head->right - " << (head->right ? head->right->data : -1) << endl;
  cout << "returning Head - " << (head ? head->data : -1) << endl;
  return head;

}

template <class T>
void BST<T>::Balance()
{
  struct node *head = nullptr;

  int n = 0;

  convertBSTToSortedDDL(root, head, n);

  cout << "number of nodes - " << n << endl;

  root = convertSortedDDLToBST(head,n);
}

int main()
{
  cout << "Binary Search Tree" << endl;

  BST<int> *bst = new BST<int>();
  bst->Insert(9);
  bst->Insert(8);
  bst->Insert(5);
  bst->Insert(10);
  bst->Insert(2);
  bst->Insert(4);
  bst->Insert(3);
  bst->Insert(6);

  try{
    cout << "Minimum Element in Tree - " << bst->FindMin() << endl;
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }

  try{
    cout << "Maximum Element in Tree - " << bst->FindMax() << endl;
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }

  cout << "Height of the tree - " << bst->FindHeight() << endl;

  bst->Print2D();

  bst->Search(10);

  bst->BreadthFirstSearch(9);

  bst->Delete(9);

  cout << "Height of the tree - " << bst->FindHeight() << endl;
  bst->Print();

  bst->Balance();

  cout << "Height of the tree - " << bst->FindHeight() << endl;
  bst->Print();
  bst->Print2D();

  delete bst;
  
  return 0;
}

