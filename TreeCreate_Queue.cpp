#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node *left , *right; 
    
    Node(int val){
        data = val;
        left=NULL ;
        right=NULL;
    }
};

void Traversetree(Node * root , vector<int>&result ){
    queue<Node*> q;
    // vector<int> tree;
    q.push(root);

    while(!q.empty()){
        Node *Temp = q.front();
        q.pop();
        if(Temp==NULL) continue;
        if(Temp->left==NULL && Temp->right==NULL){
        result.push_back(Temp->data);
        }
        q.push(Temp->left);
        q.push(Temp->right);
        // if(Temp->left !=NULL)
    }
    // return tree;
}
int main(){
    int x;
    cout<<"enter root of tree";
    cin>>x;
    Node *root= new Node(x);
    queue<Node*>q;
    q.push(root);
    int leftChild , rightChild;
    while (!q.empty())
    {   
        Node* Temp=q.front();
        q.pop();
        cout<<"enter left and right Child of"<<Temp->data<<endl;
        cin>>leftChild>>rightChild;

        if(leftChild !=-1){
           Temp->left= new Node(leftChild);
           q.push(Temp->left);
        }

        if(rightChild !=-1){
           Temp->right= new Node(rightChild);
           q.push(Temp->right);
        }
    }

     vector<int> result;
     Traversetree(root,result);
     for(auto it:result) cout<<it<<" ";
    return 0;
    
}