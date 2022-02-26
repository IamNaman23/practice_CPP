#include <bits/stdc++.h>
using namespace std;

int decimalOf(vector<int> d) {
    int sum=0;
    for (int i=d.size()-1;i>=0;i--)
        sum+=pow(2,d[i]);
    return sum;
}

int printUniqueRows(vector<vector<int>> v) {
    map<int,int> m;
    int val;
    for (int i=0;i<v.size();i++) {
        val=decimalOf(v[i]);
        m[val]=i;
    }
    for (auto it=m.begin();it!=m.end();it++)
        cout<<it->second<<" ";
    return 0;
}

int main() {
	vector<vector<int>> v;
	vector<int> r1{0,1,0,0,1};
    vector<int> r2{1,1,0,0,1};
    vector<int> r3{1,1,1,1,1};
    vector<int> r4{0,1,0,0,1};
	v.push_back(r1);
	v.push_back(r2);
	v.push_back(r3);
	v.push_back(r4);
	printUniqueRows(v);
	return 0;
}
