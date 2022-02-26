#include <bits/stdc++.h>
using namespace std;

int zigZag(vector<int> v) {
    bool flag=true; // flag=true --> '<'
    for (int i=0;i<v.size()-2;i++) {
        if (flag) {
            if (v[i]>v[i+1])
                swap(v[i],v[i+1]);
        } else {
            if (v[i]<v[i+1])
                swap(v[i],v[i+1]);
        }
        flag=!flag;
    }
    for (auto i:v)
        cout<<i<<" ";
    return 0;
}

int main() {
	int t;
	vector<int> v;
	while(cin>>t)
	    v.push_back(t);
	zigZag(v);
	return 0;
}
