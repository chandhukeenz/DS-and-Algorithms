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
    return 0;
}