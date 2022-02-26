#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> v,int l,int h) {
    if (h<l)
        return -1;
    if (h==l)
        return l;
    int mid=(l+h)/2;
    if (v[mid]>v[mid+1])
        return mid;
    if (v[mid-1]>v[mid])
        return mid-1;
    if (v[l]>=v[mid])
        return findPivot(v,l,mid-1);
    return findPivot(v,mid+1,h);
}

bool find_Element_in_Rotated_and_Sorted(vector<int> v,int key) {
    int pivot=findPivot(v,0,v.size());
    if (pivot==-1)
        return binary_search(v.begin(),v.end(),key);
    if (v[pivot]==key)
        return true;
    if (v[0]<=key)
        return binary_search(v.begin(),v.begin()+pivot-1,key);
    return binary_search(v.begin()+pivot+1,v.end(),key);
}

int main() {
	int t,key;
	vector<int> v;
	while(cin>>t) 
	    v.push_back(t);
	cin>>key;
	cout<<find_Element_in_Rotated_and_Sorted(v,key);
	// limitation is time complexity should be O(log n) !!
	return 0;
}
