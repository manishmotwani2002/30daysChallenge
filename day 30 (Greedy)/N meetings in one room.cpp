#include <bits/stdc++.h>

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
bool comparator(meeting m1, meeting m2) 
{ 
    if (m1.end < m2.end) return true; 
    else if(m1.end > m2.end) return false; 
    else if(m1.pos < m2.pos) return true; 
    return false; 
} 
int maxMeetings(int start[], int end[], int n) {
    meeting storeMeet[n];
    int i;
    for(i=0;i<n;i++)
    {
        storeMeet[i].start=start[i];
        storeMeet[i].end=end[i];
        storeMeet[i].pos=i+1;
    }
    sort(storeMeet,storeMeet+n,comparator);
    int endT,count=0;
    
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            endT=storeMeet[i].end;
            count++;
        }
        else
        {
            if(storeMeet[i].start > endT)
            {
                endT=storeMeet[i].end;
                count++;
            }
        }
    }
    return count;
    
}
