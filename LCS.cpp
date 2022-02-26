#include <bits/stdc++.h>
using namespace std;

int LCS(string l1,string l2) {
    int sl1=l1.size();
    int sl2=l2.size();
    int L[sl1+1][sl2+1];
    for (int i=0;i<=sl1;i++) {
        for (int j=0;j<=sl2;j++) {
            if (i==0 || j==0) {
                L[i][j]=0;
            } else if (l1[i-1]==l2[j-1]) {
                L[i][j]=L[i-1][j-1]+1;
            } else {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    return L[sl1][sl2];
}

int main() {
    string l1,l2;
    cin>>l1;
    cin>>l2;
    cout<<LCS(l1,l2);
	return 0;
}
