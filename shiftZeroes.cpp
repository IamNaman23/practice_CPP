#include <bits/stdc++.h>
using namespace std;

int shiftZeroes(vector<int> v) {
    int n=v.size(),count=0;
    for (int i=0;i<n;i++)
        if (v[i]!=0) 
            v[count++]=v[i];
    while(count<n)
        v[count++]=0;
    for (auto i:v) 
        cout<<i<<" ";
}

int main() {
	int t;
	vector<int> v;
	while(cin>>t) 
	    v.push_back(t);
	shiftZeroes(v);
	return 0;
}
