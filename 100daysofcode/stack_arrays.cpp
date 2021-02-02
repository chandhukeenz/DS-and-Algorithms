#include<iostream>
using namespace std;
#define MAX 1000
class stack{
    int top;
    public:
       int a[MAX];
       stack(){top=-1;}
       bool push(int x);
       int pop();
       int peek();
       bool isempty();
};

bool stack::push(int x){
    if(top>=(MAX-1)){
        cout<<"Stack Overflow";
        return false;
    }else{
        a[++top]=x;
        cout<<x<<" pushed into stack\n";
        return true;
    }
}

int stack::pop(){
    if(top<0){
        cout<<"Stack Underflow\n";
        return 0;
    }else{
        int x=a[top--];
        return x;
    }
}

int stack::peek(){
    if(top<0){
        cout<<"stack is empty";
        return 0;
    }else{
        int x=a[top];
        return x;
    }
}

bool stack::isempty(){
    return (top<0);
}

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