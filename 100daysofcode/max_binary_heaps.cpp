#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct maxbinaryheap{
    vector<int> values;
    void insert(int element){
        values.push_back(element);
        bubbleup();
    }
    void bubbleup(){
        int idx = values.size()-1;
        int element=values[idx];
        while(idx>0){
            int parentidx = floor((idx-1)/2);
            int parent =values[parentidx];
            if(parent>element) break;
            values[parentidx]=element;
            values[idx]=parent;
            idx=parentidx;
        }
    }
    int extractMax(){
		int max =values[0];
		int end =values.back();
        values.pop_back();
		if(values.size()>0){
			values[0]=end;
		    sinkDown();	
		}
		return max;
	}
	void sinkDown(){
		int idx=0;
		int length =values.size();
		int element = values[0];
		while(true){
			int leftChildIdx =2*idx+1;
			int rightChildIdx =2*idx+2;
			int leftChild,rightChild;
			bool swap=false;
            int s;
			if(leftChildIdx<length){
				leftChild=values[leftChildIdx];
				if(leftChild>element){
					s=leftChildIdx;
                    swap=true;
				}
			}
			if(rightChildIdx<length){
				rightChild=values[rightChildIdx];
				if((swap==false && rightChild>element)||
				(swap!=false &&rightChild>leftChild)){
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
        cout<<"The max binary heap:\n";
        for(int i=0;i<values.size();i++){
            cout<<values[i]<<" ";
        }
    }
};
int main(){
    struct maxbinaryheap h;
    h.insert(5);h.insert(2);
    h.insert(1);h.insert(6);
    h.insert(8);h.insert(3);
    h.insert(15);
    h.insert(100);
    h.display();
    cout<<"\nmax val:"<<h.extractMax()<<endl;
    h.display();
    cout<<"\nmax val:"<<h.extractMax()<<endl;
    h.display();
    cout<<"\nmax val:"<<h.extractMax()<<endl;
    h.display();
    cout<<"\nmax val:"<<h.extractMax()<<endl;
    h.display();
    cout<<"\nmax val:"<<h.extractMax()<<endl;
    h.display();
    return 0;
}