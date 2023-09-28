/**

Given 2 sorted Doubly linked lists, Merge them into one in sorted order.

**/


struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node (int data) //Constructor
  {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

struct Node* merge_DLLs(struct Node* a, struct Node* b)
{
  if (a == nullptr)
    return b;

  if (b == nullptr)
    return a;

  if(a->data < b->data)
  {
    a->right = merge_DLLs(a->right, b);
    a->right->left = a;
    return a;
  }
  else
  {
    b->right = merge_DLLs(a,b->right);
    b->right->left = b;
    return b;
  }
}

int main ()
{
  
}
