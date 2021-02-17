#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

//create new node
struct Node* getnewnode(int data){
    Node* newnode =new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

//insert the newnode into the bst tree
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

void inorderPredecessor(struct Node* root,struct Node* find){
    struct Node *temp,*store;
    if(find->left!=NULL){
        temp=find->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        cout<<temp->data<<endl;
    }else{
        while(find->data!=root->data){
            if(find->data > root->data){
                store=root;
                root=root->right;
            }else root=root->left;
        }
        cout<<store->data<<endl;
    }
}

void inorderSuccessor(struct Node* root,struct Node* find){
    struct Node *temp,*store;
    if(find->right!=NULL){
        temp=find->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        cout<<temp->data<<endl;
    }else{
        while(find->data!=root->data){
            if(find->data < root->data){
                store=root;
                root=root->left;
            }else root=root->right;
        }
        cout<<store->data<<endl;
    }
}
int main(){
    struct Node *root=NULL;
    stack<struct Node*>s1;
    root= insert(root,9); root= insert(root,1);
    root= insert(root,6);root= insert(root,78);
    root= insert(root,11);root= insert(root,3);
    //passing node with data 6
    cout<<"inorder Predecessor of "<<root->left->right->data<<" is: ";
    inorderPredecessor(root,root->left->right);
    cout<<"inorder Successor of "<<root->left->right->data<<" is: ";
    inorderSuccessor(root,root->left->right);
    return 0;
}