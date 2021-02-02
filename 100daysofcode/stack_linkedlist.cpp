#include<iostream>
using namespace std;

class stacknode{
    public:
      int data;
      stacknode *next;
      stacknode(int value){
          this->data=value;
          this->next=NULL;
      }
};
class stack{
  public:
    stacknode* first = new stacknode(0);
    stacknode* last = new stacknode(0);
    int size;
    stack(){
        this->first=NULL;
        this->last=NULL;
        this->size=0;
    }
    int push(int data){
        stacknode* newNode =new stacknode(data);
        if(!this->first){
            this->first=newNode;
            this->last=newNode;
        }else{
            stacknode* temp=this->first;
            this->first=newNode;
            this->first->next=temp;
        }
        return ++this->size; 
    }
    int pop(){
        if(!this->first) cout<<"stack is empty"<<endl;
        stacknode* temp = this->first;
        if(this->first ==this->last){
            this->last=NULL;
        }
        this->first=this->first->next;
        this->size--;
        return temp->data;
    }
    int peek(){
        return this->first->data;
    }
    bool isfull(int maxsize){
        if(this->size==maxsize)return true;
        else return false;
    }
    bool isempty(){
        if(!this->first) return true;
        else return false;
    }

};

int main(){
    class stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.pop()<<" popped from the stack"<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isempty()<<endl;
    return 0;
}

