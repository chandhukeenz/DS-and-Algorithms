#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void preorder(struct Node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct Node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
struct Node* getnewnode(int data){
    Node* newnode =new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct Node* insert(struct Node* root,int data){
    if(root==NULL){
        root=getnewnode(data);
        return root;
    }else if(data<=root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);
    }
    return root;
}

bool search(struct Node* root,int data){
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data<=root->data) return search(root->left,data);
    else return search(root->right,data);
}

int main(){
    struct Node *root=NULL;
    root= insert(root,9); root= insert(root,1);
    root= insert(root,6);root= insert(root,78);
    root= insert(root,11);root= insert(root,3);
    cout<<"postorder:"<<endl;
    postorder(root);
    cout<<"\ninorder:"<<endl;
    inorder(root);
    cout<<"\npreorder:"<<endl;
    preorder(root);
    cout<<endl;
    int number;
    cout<<"Enter the number to be searched:";
    cin>>number;
    if(search(root,number)) cout<<"number found";
    else cout<<"not found";
    return 0;
}