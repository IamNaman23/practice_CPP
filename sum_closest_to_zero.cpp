#include <bits/stdc++.h>
using namespace std;

int sumClosestToZero(vector<int> v) {
    sort(v.begin(),v.end());
    int min_sum=INT_MAX,nL,nH;
    for (int i=1;i<v.size();i++) {
        if (abs(v[i-1]+v[i])<=min_sum) {
            min_sum=v[i-1]+v[i];
            nL=v[i-1];
            nH=v[i];
        }
    }
    cout<<nL<<" "<<nH;
    return 0;
}

int main() {
	int t;
	vector<int> v;
	while(cin>>t)
	    v.push_back(t);
	sumClosestToZero(v);
	return 0;
}
