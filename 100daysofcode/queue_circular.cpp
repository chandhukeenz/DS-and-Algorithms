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
        if(front==(rear+1)%length){
                cout<<"circular queue is full !!"<<endl;
                return;
        }
        else if(front==-1) 
                front=rear=0;
        else if(rear==(length-1) && front!=0) 
                rear=0;
        else rear++;

        a[rear]=val;
        return;
    }

    int dequeue(){
        if(front==-1){
           cout<<"circular queue is empty!!"<<endl;
           return INT32_MIN;
        }
        int data = a[front];
        a[front]=-1;
        if(front==rear)
            front=rear=-1;
        else if(front==(length-1))
            front=0;
        else front++;
        return data;
    }
    void displayqueue(){
        if(front==-1){
            cout<<"\nQueue is empty";
            return;
        }
        if(rear>=front){
            for(int i=front;i<=rear;i++)
                cout<<a[i]<<" ";
        }else{
            for(int i=front;i<length;i++)
                cout<<a[i]<<" ";
            for(int i=0;i<=rear;i++)
                cout<<a[i]<<" ";
        }
    }
};

int main(){
    struct circularQueue c(5);
    c.enqueue(1);c.enqueue(-1);
    c.enqueue(2);c.enqueue(-2);
    c.enqueue(3);c.enqueue(-3);

    c.displayqueue();
    cout<<endl;
    cout<<c.dequeue()<<endl;
    cout<<c.dequeue()<<endl;
    cout<<c.dequeue()<<endl;
    cout<<c.dequeue()<<endl;
    cout<<c.dequeue()<<endl;
    cout<<c.dequeue()<<endl;
    c.displayqueue();
    return 0;
}
