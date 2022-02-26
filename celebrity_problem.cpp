#include <bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int>> v) {
    stack<int> s;
    int k1,k2,k;
    for (int i=0;i<v.size();i++) 
        s.push(i);
    while(s.size()>1) {
        k1=s.top();
        s.pop();
        k2=s.top();
        s.pop();
        if (v[k1][k2]==0) {     // k1 do not know k2 --> k1 may be the celeb
            s.push(k1);
        } else {                // k1 knows k2 --> k2 may be the celeb
            s.push(k2);
        }
    }
    k=s.top();      // capture the only element left in stack
                    // potential value of celeb
    s.pop();        // empty stack
    int flag=-1;
    for (int i=0;i<v[k].size();i++) {
        if (v[k][i]==0) {
            if (i!=k) {
                if (v[i][k]==1) 
                    flag=k;
            } else {
                if (v[i][k]==0)
                    flag=k;
            }
        } else {
            return -1;
        }
    }
    return k;
}

int main() {
	vector<vector<int>> v{{0,0,1,0},{0,0,1,0},{0,0,0,0},{0,0,1,0}};
	cout<<"Celebrity is "<<findCelebrity(v);
	return 0;
}
