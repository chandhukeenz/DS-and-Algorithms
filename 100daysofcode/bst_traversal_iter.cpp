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

//LEFT - RIGHT - ROOT
void postorder(struct Node*root,stack<struct Node*>s){
    while(1){
        if(root){
            s.push(root);
            root=root->left;
        }else{
            if(s.empty()) break;
            else{
                if(s.top()->right==NULL){
                    root=s.top();
                    s.pop();
                    cout<<root->data<<" ";
                    while(root==s.top()->right){
                        cout<<s.top()->data<<" ";
                        root=s.top();
                        s.pop();
                        if(s.empty()) break;
                    }
                }
                if(!s.empty()) root=s.top()->right;
                else root=NULL;
            }
        }
    }
}

//LEFT - ROOT - RIGHT
void inorder(struct Node*root,stack<struct Node*>s){
    while(1){
        while(root){
            s.push(root);
            root=root->left;
        }
        if(s.empty()) break;
        root=s.top();
        s.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
}

//ROOT - LEFT - RIGHT
void preorder(struct Node*root,stack<struct Node*>s){
    while(1){
        while(root){
            cout<<root->data<<" ";
            s.push(root);
            root=root->left;
        }
        if(s.empty()) break;
        root=s.top();
        s.pop();
        root=root->right;
    }
}
struct Node* findmin(struct Node* root){
    while(root->left!=NULL) root=root->left;
    return root;
}

struct Node* deleteNode(struct Node* root,int val){
    if(root==NULL)return root;
    else if(val<root->data) root->left=deleteNode(root->left,val);
    else if(val>root->data) root->right=deleteNode(root->right,val);
    else{
        //no child
        if(root->left==NULL && root->right==NULL){
             delete root;
             root=NULL;
        }else if(root->left==NULL){
            struct Node *temp=root;
            root=root->right;
            delete temp;
        }else if(root->right==NULL){
            struct Node *temp=root;
            root=root->left;
            delete temp;
        }else{
            struct Node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}

int main(){
    struct Node *root=NULL;
    stack<struct Node*>s1;
    int n;
    root= insert(root,9); root= insert(root,1);
    root= insert(root,6);root= insert(root,78);
    root= insert(root,11);root= insert(root,3);
    cout<<"\nPostorder:"<<endl;
    postorder(root,s1);
    cout<<"\ninorder:"<<endl;
    inorder(root,s1);
    cout<<"\npreorder:"<<endl;
    preorder(root,s1);
    cout<<"\nenter the value to be deleted:"<<endl;
    cin>>n;
    root=deleteNode(root,n);
    cout<<"After deleting..inorder traversal:"<<endl;
    inorder(root,s1);
    return 0;
}