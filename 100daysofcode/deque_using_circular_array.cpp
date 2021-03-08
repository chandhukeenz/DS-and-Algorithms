//double ended queue
#include<iostream>
using namespace std;
#define MAX 100
struct deque{
    int a[MAX];
    int front,rear,length;
    public:
    deque(int length){
        front=-1;
        rear=0;
        this->length=length;
    }
    bool isfull(){
        return (front==0&&rear==length-1)||
                front==rear+1;
    }
    bool isempty(){
        return front==-1;
    }
    void fInsert(int val){
        if(isfull()){
            cout<<"\nOverflow";
            return;
        }
        if(front==-1)
            front=rear=0;
        else if(front==0)
            front=length-1;
        else front--;
        a[front]=val;
    }
    void rInsert(int val){
        if(isfull()){
            cout<<"\nOverflow!!";
            return;
        }
        if(front==-1)
            front=rear=0;
        else if(rear==length-1)
            rear=0;
        else rear++;
        a[rear]=val;
    }
    void fDelete(){
        if(isempty()){
            cout<<"\nUnderflow!!";
            return;
        }
        if(front==rear)
           front=rear=-1;
        else if(front==length-1)
           front=0;
        else front++;
    }
    void rDelete(){
        if(isempty()){
            cout<<"\nUnderflow!!";
            return;
        }
        if(front==rear)
           front=rear=-1;
        else if(rear==0)
           rear=length-1;
        else rear--;
    }
    int fGet(){
        if(isempty()){
            cout<<"\nUnderflow!!";
            return -1;
        }
        return a[front];
    }
    int rGet(){
        if(isempty()||rear<0){
            cout<<"\nUnderflow!!";
            return -1;
        }
        return a[rear];
    }
};

int main(){
    deque d(5);
    d.rInsert(1);d.rInsert(2);
    cout<<d.rGet()<<endl;
    d.rDelete();
    cout<<d.rGet()<<endl;
    d.fInsert(3);
    cout<<d.fGet()<<endl;
    d.fDelete();
    cout<<d.fGet()<<endl;
    return 0;
}