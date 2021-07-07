#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void selectActivities(vector<int>s,vector<int>f){
    vector<pair<int,int>>activities;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0; i<s.size();i++){
        //ascending order of finish times
        pq.push(make_pair(f[i],s[i]));
    }
    auto it=pq.top();
    int start = it.second;
    int end = it.first;
    activities.push_back(make_pair(start,end));
    pq.pop();
    while(pq.size()>0){
        auto itr = pq.top();
        pq.pop();
        if(itr.second >= end){
            start=itr.second;
            end=itr.first;
            activities.push_back(make_pair(start,end));
        }
    }
    for(auto itr= activities.begin();itr!=activities.end();itr++){
        cout<<"Activity started at "<<(*itr).first<<" and ended at "<<(*itr).second<<endl;
    }

}
int main(){
    vector<int>start={1, 3, 0, 5, 8, 5};
    vector<int>finish={2, 4, 6, 7, 9, 9};
    selectActivities(start,finish);
    return 0;
}