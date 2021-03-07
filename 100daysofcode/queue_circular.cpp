#include<iostream>
using namespace std;
struct circularQueue{
    int front,rear;
    int length;
    int *a;
    circularQueue(int l){
        front=rear=-1;
        length=l;
        a= new int[l];
    }
    void enqueue(int val){
        if((front==0 && rear==length-1)||(rear==(front-1)%(length-1)))
                cout<<"circular queue is full !!"<<endl;
        else if(front==-1) 
                front=rear=0;
        else if(rear==length-1 && front!=0) 
                rear=0;
        else rear++;

        a[rear]=val;
        return;
    }

    int dequeue(){
        if(front==-1)
           cout<<"circular queue is empty!!"<<endl;
        
    }
    void displayqueue();
};
