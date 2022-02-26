#include <bits/stdc++.h>
using namespace std;

int nextGreater(vector<int> v) {
    stack<int> s;
    s.push(v[0]);
    for (int i=1;i<v.size();i++) {
        if (s.empty()) {
            s.push(v[i]);
            continue;
        }
        while(!s.empty() && s.top()<v[i]) {
                cout<<s.top()<<" --> "<<v[i]<<endl;
                s.pop();
        }
        s.push(v[i]);
    }
    while(!s.empty()) {
            cout<<s.top()<<" --> "<<-1<<endl;
            s.pop();
    }
    return 0;
}

int main() {
	int t;
	vector<int> v;
	while(cin>>t)
	    v.push_back(t);
	nextGreater(v);
	return 0;
}