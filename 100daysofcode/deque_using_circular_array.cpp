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
            cout<<"\nOverflow!!"<<endl;
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
            cout<<"\nUnderflow!!"<<endl;
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
            cout<<"\nUnderflow!!"<<endl;
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
            cout<<"\nUnderflow!!"<<endl;
            return -1;
        }
        return a[front];
    }
    int rGet(){
        if(isempty()||rear<0){
            cout<<"\nUnderflow!!"<<endl;
            return -1;
        }
        return a[rear];
    }
};

int main(){
    deque d(5);
    d.rInsert(1);d.rInsert(2);
    d.rInsert(3);d.rInsert(4);
    d.rInsert(5);d.rInsert(6);
    cout<<"Element in rear:"<<d.rGet()<<endl;
    d.rDelete();
    cout<<"Element in rear after rear deletion:"<<d.rGet()<<endl;
    d.fInsert(3);
    cout<<"Element in front after insertion at front:"<<d.fGet()<<endl;
    d.fDelete();
    cout<<"Element in front after front deletion:"<<d.fGet()<<endl;
    return 0;
}