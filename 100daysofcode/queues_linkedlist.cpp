#include<iostream>
using namespace std;

class queuenode{
    public:
      int data;
      queuenode *next;
      queuenode(int value){
          this->data=value;
          this->next=NULL;
      }
};
class queue{
  public:
    queuenode* first = new queuenode(0);
    queuenode* last = new queuenode(0);
    int size;
    queue(){
        this->first=NULL;
        this->last=NULL;
        this->size=0;
    }
    int enqueue(int data){
        queuenode* newNode = new queuenode(data);
        if(!this->first){
            this->first=newNode;
            this->last=newNode;
        }else{
            this->last->next=newNode;
            this->last=newNode;
        }
        return ++this->size; 
    }
    int dequeue(){
        if(!this->first) cout<<"queue is empty"<<endl;
        queuenode* temp = this->first;
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
    class queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.dequeue()<<" dequeued from the queue"<<endl;
    cout<<q.peek()<<endl;
    cout<<q.isempty()<<endl;
    return 0;
}

