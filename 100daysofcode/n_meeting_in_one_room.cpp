/*N meetings in one room
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example 1:

Input:
N = 6
S[] = {1,3,0,5,8,5}
F[] = {2,4,6,7,9,9}
Output: 
4
Explanation: Four meetings can be held with
given start and end timings.
*/
// { Driver Code Starts
#include<iostream>
#include<algorithm>
using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}// } Driver Code Ends

struct meeting {
    int start;
    int end;
    int pos; 
}; 

bool comparator(struct meeting m1, meeting m2) 
{ 
    if (m1.end < m2.end) return true; 
    else if(m1.end > m2.end) return false; 
    else if(m1.pos < m2.pos) return true; 
    return false; 
} 

int maxMeetings(int start[], int end[], int n) {
    // Your code here
    struct meeting meet[n]; 
    for(int i = 0;i<n;i++) {
        meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i+1; 
    }
    sort(meet, meet+n, comparator); 
    int answer=1;
    int limit = meet[0].end; 
    for(int i = 1;i<n;i++) {
        if(meet[i].start > limit) {
            limit = meet[i].end; 
            answer++; 
        }
    }
    return answer;
}