#include <bits/stdc++.h>
using namespace std;

int findSubArray(int sum,vector<int> v) {
    int l=0,s=0;
    for (int i=0;i<v.size();i++) {
        s+=v[i];
        if (s==sum) {
            cout<<"Array Found between "<<l<<" and "<<i;
            return 0;
        } else if (s>sum) {
            s-=v[l++];
        }
    }
    cout<<"No sub array found";
    return 0;
}

int main() {
	int t,sum;
	vector<int> v{ 15, 2, 4, 8, 9, 5, 10, 23 };
	cin>>sum;
	findSubArray(sum,v);
	return 0;
}
