#include<bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> invalid(n);
        stack<int> stk;
        string ans;
        
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == '(') stk.push(i);
            else if(ch == ')'){
                if(stk.empty()) invalid[i] = true;
                else stk.pop();
            }
        }
        
        while(!stk.empty()){
            invalid[stk.top()] = true;
            stk.pop();
        }
        
        for(int i=0; i<n; i++){
            if(invalid[i] == true) continue;
            ans.push_back(s[i]);
        }
        return ans;
    }

int main(){
	string str;
	cin >> str;
	
	string valid_string = minRemoveToMakeValid(str);
	cout << valid_string << "\n";

	return 0;
}
