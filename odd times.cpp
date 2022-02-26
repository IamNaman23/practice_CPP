#include <bits/stdc++.h>
using namespace std;

int oddTimes(vector<int> v) {
    int num=0;
    for (auto i:v)
        num=num^i;
    return num;
}

int main() {
	int t;
	vector<int> v;
	while(cin>>t) 
	    v.push_back(t);
	cout<<oddTimes(v);
	return 0;
}
