#include<iostream>
#include<algorithm>
using namespace std;

struct work {
    int start;
    int end;
    int pos; 
}; 

bool comparator(struct work w1, work w2) 
{ 
    if (w1.end < w2.end) return true; 
    else if(w1.end > w2.end) return false; 
    else if(w1.pos < w2.pos) return true; 
    return false; 
} 
int maxwork(int start[], int end[], int n) {
    struct work w[n]; 
    for(int i = 0;i<n;i++) {
        w[i].start = start[i], w[i].end = end[i], w[i].pos = i+1; 
    }
    sort(w, w+n, comparator); 
    int answer=1;
    int limit = w[0].end; 
    for(int i = 1;i<n;i++) {
        if(w[i].start > limit) {
            limit = w[i].end; 
            answer++; 
        }
    }
    return answer;
}
int main() {    
    int n;
     cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++) cin >> start[i];
    for (int i = 0; i < n; i++) cin >> end[i];
    int ans = maxwork(start, end, n);
    cout << ans << endl;
    return 0;
}