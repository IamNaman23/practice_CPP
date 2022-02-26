#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1,string s2) {
    int ed[s1.size()+1][s2.size()+1];
    for (int i=0;i<=s1.size();i++) {
        for (int j=0;j<=s2.size();j++) {
            if (s1[i]==s2[j]) { // its a match :)
                ed[i][j]=min(min(ed[i-1][j-1],ed[i-1][j]),ed[i][j-1]);
            } else { // its a mis-match ;(
                ed[i][j]=ed[i-1][j-1]+1;
            }
        }
    }
    return ed[s1.size()][s2.size()];
}

int main() {
	string s1,s2;
	cin>>s1;
	cin>>s2;
	cout<<editDistance(s1,s2);
	return 0;
}
