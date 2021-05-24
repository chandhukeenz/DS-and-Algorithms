#include<iostream>
using namespace std;

struct trienode{
    char data; //trienode key 
    trienode *child[26]; //trienode pointer array
    int we; //wordend
    string wtype; //dictionary word type
    string meaning; //dictionary word meaning
};

trienode nodepool[100];
trienode *root;
int poolcount;

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
    newnode->we=0;
    return newnode;
}

void insert(string &str,
            const string &wtype,
            const string &meaning){
    trienode *curr=root;
    int index;
    for(int i=0;str[i]!='\0';i++){
        index=tolower(str[i])-'a';
        if(curr->child[index]==NULL)
           curr->child[index]=getnewnode(str[i]);
        curr=curr->child[index];
    }
    curr->we++;
    curr->wtype=wtype;
    curr->meaning=meaning;
}


bool search(string &str,int del=0){
    cout<<"word: "<<str<<endl;
    trienode *curr=root;
    int index;
    for(int i=0;i<str.length();i++){
        index=str[i]-'a';
        if(curr->child[index]==NULL){
            if(del==0){
                cout<<"word present: ";
            }
            return false;
        }
        else if(curr->child[index]->we ==1 && i==(str.length()-1)){
            if(del==1){
                curr->child[index]->we=0;
            }else{
                cout<<"type: ";
                cout<<curr->child[index]->wtype<<endl;
                cout<<"meaning: ";
                cout<<curr->child[index]->meaning<<endl;
                cout<<"word present: ";
            }
            return true;
        }
        curr=curr->child[index];
    }
    if(del==0){cout<<"word present: ";}
    return false;
}

void delword(string str){
    if(search(str,1)){
        cout<<str<<" is successfully deleted"<<endl;
    }else{
        cout<<"no such word as "<<str<<" is present"<<endl;
    }
}

int main(){
    init();
    string a = "abandon";
    string b = "abase";
    string c = "aberration";
    string d = "baulk";
    string e = "bawdy";
    string f = "beacon";
    string g = "bedlam";
    insert(a,"verb","To give up completely, leave permanently, lack of inhibition.");
    insert(b,"verb","To humiliate or degrade");
    insert(c,"noun","Deviation from what is normal or acceptable");
    insert(d,"verb","Hesitate to accept, thwart or hinder");
    insert(e,"adjective","Indecent, obscene");
    cout<<".................................."<<endl;
    cout<<search(a)<<endl;
    cout<<".................................."<<endl;
    cout<<search(b)<<endl;
    cout<<".................................."<<endl;
    cout<<search(g)<<endl;
    cout<<".................................."<<endl;
    cout<<search(c)<<endl;
    cout<<".................................."<<endl;
    delword(a);
    cout<<".................................."<<endl;
    delword(c);
    cout<<".................................."<<endl;
    cout<<search(a)<<endl;
    cout<<".................................."<<endl;
    cout<<search(c)<<endl;
    cout<<".................................."<<endl;
    cout<<search(b)<<endl;
    cout<<".................................."<<endl;
    return 0;
}
