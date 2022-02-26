#include <bits/stdc++.h>
using namespace std;

bool different(pair<int,int> p1,pair<int,int> p2) {
    if ( (p1.first!=p2.first) && (p1.first!=p2.second) && (p1.second!=p2.first) && (p1.second!=p2.second) ) {
        return true;
    } else {
        return false;
    }
}

int findNumsWithSum(vector<int> v,int sum) {
    // mapping sum --> {index1,index2}
    map<int,pair<int,int>> m;
    
    for (int i=0;i<v.size();i++)
        for (int j=i+1;j<v.size();j++)
            m[v[i]+v[j]]={i,j};

    for (auto it=m.begin();it!=m.end();it++) {
        for (auto jt=m.begin();jt!=m.end();jt++) {
            // if sum found with four different nums
            if ((it->first + jt->first)==sum && different(it->second,jt->second)) {      
                cout<<"Sum found..."<<endl<<"nums are : ";
                cout<<it->second.first<<" "<<it->second.second<<" ";
                cout<<jt->second.first<<" "<<jt->second.second<<" ";
                return 0;
            }
        }
    }
    cout<<"No combination found";
    return 0;
}

int main() {
	vector<int> v{ 15, 2, 4, 8, 9, 5, 10, 23 };
	int sum=30;    // 15 + 5 + 8 + 2 = 30
	findNumsWithSum(v,sum);
	return 0;
}
