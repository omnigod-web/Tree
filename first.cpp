#include <iostream>
#include<vector>
using namespace std;

class Node{
    public: 
     int val;
     Node* left;
     Node* right;
    
    Node( int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node * binaryTree(){
       int x;
       cout<<"enter First value ";
       cin >>x;
       if(x==-1) return NULL;
       Node *Temp = new Node(x);
       
       cout << "enter left child of " << Temp->val <<" ";
       Temp->left = binaryTree();

       cout << "enter Right child of " << Temp->val <<" ";
       Temp->right = binaryTree();

       return Temp ;

}
  void PreOrder(Node*root , vector<int>&pre){
    Node*Temp = root;
    if(Temp==NULL) return;
    pre.push_back(Temp->val);
    PreOrder(Temp->left , pre);
    PreOrder(Temp->right , pre);
  }

    void inOrder(Node*root , vector<int>&in){
    Node*Temp = root;
    if(Temp==NULL) return;
    inOrder(Temp->left , in);
    in.push_back(Temp->val);
    inOrder(Temp->right , in);
  }

  void postOrder(Node*root ){
    Node*Temp = root;
    if(Temp==NULL) return;
    postOrder(Temp->left);
    postOrder(Temp->right);
    cout<<Temp->val <<" ";
  }



int main(){
     cout<< "enter root node";
     Node *root = binaryTree();
     vector<int>pre;
     vector<int>in;
     PreOrder(root , pre);
     for(auto it: pre){
     cout<<it<<" ";
     }
     cout<<endl;
     inOrder(root , in);
     for(auto it: in){
     cout<<it<<" ";
     }

     postOrder(root);
     return 0;
}