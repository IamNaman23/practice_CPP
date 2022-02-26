#include <bits/stdc++.h>
using namespace std;

// using only {} , [] , () 

bool checkBalancedParanthesis(string s) {
    stack<char> stk;
    map<char,char> m;
    m['(']=')';
    m['{']='}';
    m['[']=']';
    for (int i=0;i<s.length();i++) {
        if ( (s[i]=='{') || (s[i]=='[') || (s[i]=='(') ) { // push opening paranthesis onto the stack
            stk.push(s[i]);
        } else if (m[stk.top()]==s[i]) { // stack top and current char match paranthesis --> pop
            stk.pop();
        } else {
            return 0;
        }
    }
    return stk.empty();
}

int main() {
	string s;
	cin>>s;
	cout<<checkBalancedParanthesis(s);
	return 0;
}
