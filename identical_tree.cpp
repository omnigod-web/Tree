#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left , *right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

bool isIdentical(Node*root1 , Node*root2 ){
    Node*Temp1 = root1;
    Node*Temp2 = root2;
    if(Temp1==NULL && Temp2==NULL) return true;
    if(Temp1==NULL || Temp2==NULL) return false;
    return (Temp1->data == Temp2->data)&&
            isIdentical(Temp1->left , Temp2->left)&&
            isIdentical(Temp1->right, Temp2->right);
  }

// void postOrder(Node*root ){
//     Node*Temp = root;
//     if(Temp==NULL) return;
//     postOrder(Temp->left);
//     postOrder(Temp->right);
//     cout<<Temp->data <<" ";
//   }

Node * insert(int x ){
    if(x==-1) return NULL;

    Node *Temp = new Node(x);
    cout<<"enter left Child of "<<Temp->data <<": ";
    cin>>x;
    Temp->left = insert(x);
    cout<<"enter right Child of "<<Temp->data <<": ";
    cin>>x;
    Temp->right = insert(x);
    return Temp;
}

int main(){
    cout<<"enter root node of First and second tree";
     int x , y;
     cin>>x >>y;
    if(x==-1) return 0;
    Node*root1= insert(x);
    cout << "buld second tree";
    Node*root2= insert(y);

    bool ans= isIdentical(root1 , root2);
    cout<<ans<<endl;
    // postOrder(root1);
    cout<<"second tree" << endl;
    // postOrder(root2); 
    
    return 0;
}