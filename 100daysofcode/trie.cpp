#include<iostream>
using namespace std;

struct trienode{
    char data;
    trienode *child[26];
    int wc;//word count
    int we; //word end
};

trienode nodepool[100000];
trienode *root;
int poolcount;

//initial node
void init(){
    poolcount=0;
    root=&nodepool[poolcount++];
    root->data='/';
    for(int i=0;i<26;i++){
        root->child[i]=NULL;
    }
}

struct trienode* getnewnode(char data){
    trienode* newnode = &nodepool[poolcount++];
    newnode->data=data;
    for(int i=0;i<26;i++){
        newnode->child[i]=NULL;
    }
    newnode->wc=0;
    newnode->we=0;
    return newnode;
}

void insert(char *str){
    trienode *curr=root;
    int index;
    for(int i=0;str[i]!='\0';i++){
        index=str[i]-'a';
        if(curr->child[index]==NULL)
           curr->child[index]=getnewnode(str[i]);
        curr->child[index]->wc ++;
        curr=curr->child[index];
    }
    curr->we++;
}

bool search(char *str){
    trienode *curr=root;
    int index;
    for(int i=0;str[i]!='\0';i++){
        index=str[i]-'a';
        if(curr->child[index]==NULL)
           return false;
        else if(curr->child[index]->we==1)
           return true;
        curr=curr->child[index];
    }
    return false;
}

int main(){
    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};
    char g[5] ={'a','r'};
    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    cout<<search(b)<<endl;
    cout<<search(d)<<endl;
    cout<<search(f)<<endl;
    cout<<search(g)<<endl;
    return 0;
}