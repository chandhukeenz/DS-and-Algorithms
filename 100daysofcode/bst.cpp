#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
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

//search the element in the tree
bool search(struct Node* root,int data){
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data<=root->data) return search(root->left,data);
    else return search(root->right,data);
}

//ROOT - LEFT - RIGHT
void preorder(struct Node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//LEFT - ROOT - RIGHT
void inorder(struct Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//LEFT - RIGHT - ROOT
void postorder(struct Node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//Print the tree in the level order in a single line
void levelorderInaLine(struct Node *root,queue<struct Node*>q){
    if(q.empty() || root==NULL) return;
    cout<<root->data<<" ";
    if(root->left)q.push(root->left);
    if(root->right)q.push(root->right);
    q.pop();
    levelorderInaLine(q.front(),q);
}

//Print the tree in the level order in level by level format
void levelorderLbyL(struct Node *root,queue<struct Node*>q,int c){
    if(q.empty()||c==2) return;
    if(root==NULL){
        c++;
        if(c!=2) cout<<'\n';
        q.push(NULL);
    }else{
        c=0;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        cout<<root->data<<" ";
    }
    q.pop();
    levelorderLbyL(q.front(),q,c);
}

//Print the tree in the vertical order
int cmp(pair<int,vector<int>> a,pair<int,vector<int>>b){
    return a.first<b.first;
}

void verticalorder(struct Node *root, queue<pair<struct Node*,int>>q, int v, unordered_map<int,vector<int>>m){
    if(q.empty()){
        vector<pair<int,vector<int>>>x(m.begin(),m.end());
        sort(x.begin(),x.end(),cmp);
        for(int i=0;i<x.size();i++){
            for(int j=0;j<x[i].second.size();j++){
                cout<<x[i].second[j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    if(q.empty() || root==NULL)return;
    if(root->left){
        q.push(make_pair(root->left,v-1));
        m[v-1].push_back(root->left->data);
    }
    if(root->right){
        q.push(make_pair(root->right,v+1));
        m[v+1].push_back(root->right->data);
    }
    q.pop();
    verticalorder(q.front().first, q, q.front().second, m);
}

int main(){
    struct Node *root=NULL;
    queue<struct Node*>q1,q2;
    queue<pair<struct Node *,int>>q3;
    int countNull=0;
    root= insert(root,9); root= insert(root,1);
    root= insert(root,6);root= insert(root,78);
    root= insert(root,11);root= insert(root,3);
    cout<<"\npreorder:"<<endl;
    preorder(root);
    cout<<"\ninorder:"<<endl;
    inorder(root);
    cout<<"postorder:"<<endl;
    postorder(root);
    cout<<"\nlevelorder in a single Line:"<<endl;
    q1.push(root);
    levelorderInaLine(root,q1);
    cout<<"\nlevelorder printed level by level:"<<endl;
    q2.push(root);q2.push(NULL);
    levelorderLbyL(root,q2,countNull);
    cout<<"Vertical order:"<<endl;
    q3.push(make_pair(root,0));
    int vLevel=0;
    unordered_map<int,vector<int>>m;
    m[vLevel].push_back(root->data);
    verticalorder(root,q3,vLevel,m);
    int number;
    cout<<"Enter the number to be searched:";
    cin>>number;
    if(search(root,number)) cout<<"number found";
    else cout<<"not found";
    return 0;
}