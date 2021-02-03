#include<iostream>
using namespace std;
class queue{
    int front,rear,size,capacity;
    public:
       int *a;
       queue(int n){front=0;capacity=n;size=0;rear=capacity-1;a=new int[capacity*sizeof(int)];}
       bool enqueue(int x);
       int dequeue();
       int peek();
       bool isempty();
};

bool queue::enqueue(int x){
    if(size>=capacity){
        cout<<"Queue Overflow"<<endl;
        return false;
    }else{
        rear=(rear+1)%capacity;
        a[rear]=x;
        size++;
        cout<<x<<" enqueued into queue\n";
        return true;
    }
}

int queue::dequeue(){
    if(size<=0){
        cout<<"queue Underflow\n";
        return 0;
    }else{
        int x=a[front];
        front=(front+1)%capacity;
        size--;
        return x;
    }
}

int queue::peek(){
    if(size==0){
        cout<<"stack is empty";
        return 0;
    }else{
        int x=a[front];
        return x;
    }
}

bool queue::isempty(){
    return (size==0);
}

int main(){
    class queue q(2);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.dequeue()<<" dequeued from the queue"<<endl;
    cout<<q.peek()<<endl;
    cout<<q.isempty()<<endl;
    return 0;
}