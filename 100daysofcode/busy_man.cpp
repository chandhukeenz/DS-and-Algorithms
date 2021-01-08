#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1 , pair<int,int> p2){
    return p1.second<p2.second;
}

int main(){
    int n,s,e;
    vector<pair<int,int>> v;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }
        sort(v.begin(),v.end(),compare);

        int res =1;
        int fin =v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>=fin){
                fin=v[i].second;
                res++;
            }
        }
        cout<<"the result :"<<res<<endl;
        v.clear();
}