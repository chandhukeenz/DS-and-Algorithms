#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct Node{
    int val,priority;
    Node(int val,int priority){
        this->val=val;
        this->priority=priority;
    }
};

struct priorityQueue{
    vector<struct Node*> values;
    void enqueue(int val,int priority){
        Node *newnode=new Node(val,priority);
        values.push_back(newnode);
        bubbleup();
    }
    void bubbleup(){
        int idx = values.size()-1;
        struct Node* element=values[idx];
        while(idx>0){
            int parentidx = floor((idx-1)/2);
            struct Node* parent =values[parentidx];
            if(parent->priority<=element->priority) break;
            values[parentidx]=element;
            values[idx]=parent;
            idx=parentidx;
        }
    }
    struct Node* dequeue(){
		struct Node* min =values[0];
		struct Node* end =values.back();
        values.pop_back();
		if(values.size()>0){
			values[0]=end;
		    sinkDown();	
		}
		return min;
	}
	void sinkDown(){
		int idx=0;
		int length =values.size();
		struct Node* element = values[0];
		while(true){
			int leftChildIdx =2*idx+1;
			int rightChildIdx =2*idx+2;
			struct Node *leftChild,*rightChild;
			bool swap=false;
            int s;
			if(leftChildIdx<length){
				leftChild=values[leftChildIdx];
				if(leftChild->priority < element->priority){
					s=leftChildIdx;
                    swap=true;
				}
			}
			if(rightChildIdx<length){
				rightChild=values[rightChildIdx];
				if((swap==false && rightChild->priority <element->priority)||
				(swap!=false &&rightChild->priority < leftChild->priority)){
					s=rightChildIdx;
                    swap=true;
				}
			}
			if(swap==false) break;
			values[idx]=values[s];
			values[s]=element;
			idx=s;
		}
	}
    void display(){
        cout<<"The priority min binary heap:\n";
        for(int i=0;i<values.size();i++){
            cout<<"priority: "<<values[i]->priority<<" "<<"value: "<<values[i]->val<<endl;
        }
    }
};

int main(){
    struct priorityQueue pq;
    pq.enqueue(10,4);pq.enqueue(100,5);
    pq.enqueue(200,1);pq.enqueue(25,3);
    pq.enqueue(46,0);pq.enqueue(150,2);
    pq.display();
    cout<<"\ndequeued: value: "<<pq.dequeue()->val<<endl;
    pq.display();
    cout<<"\ndequeued: value: "<<pq.dequeue()->val<<endl;
    pq.display();
    cout<<"\ndequeued: value: "<<pq.dequeue()->val<<endl;
    pq.display();
    cout<<"\ndequeued: value: "<<pq.dequeue()->val<<endl;
    pq.display();
    cout<<"\ndequeued: value: "<<pq.dequeue()->val<<endl;
    pq.display();
    return 0;
}