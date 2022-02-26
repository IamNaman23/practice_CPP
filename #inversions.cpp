#include <bits/stdc++.h>
using namespace std;

int countInversions(vector<int> v) {
    int count=0;
    for (int i=0;i<v.size()-1;i++)
        for (int j=i+1;j<v.size();j++) 
            if (v[i]>v[j])
                count++;
                
    return count;
}

int main() {
	int t;
	vector<int> v;
	while(cin>>t)
	    v.push_back(t);
	cout<<countInversions(v);
	return 0;
}
