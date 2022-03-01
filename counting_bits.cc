#include<bits/stdc++.h>
using namespace std;

/* Approach 1 :- Time: O(nlogn)

     int getSetBits(int num){
         int cnt = 0;
         while(num > 0){
             cnt += (num&1);
             num >>= 1;
         }
         return cnt;
     }
    
     vector<int> countBits(int n) {
         vector<int> bits(n+1);
         for(int i=0; i<=n; i++){
             bits[i] = getSetBits(i);
         }
         return bits;
     }
*/

/* Approach 2 :- Time: O(n)
	
	vector<int> countBits(int n){
		vector<int> bits(n+1);
		int flag = 0, k = 0;

		bits[0] = 0;
		for(int i=1; i<=n; i++){
			if(pow(2,k) == i){
				bits[i] = 1;
				flag = i;
				k++;
			} 
			else{
				bits[i] = bits[flag] + bits[i-flag];
			}
		}
		return bits;
	}
*/

// Approach 3 :- Time: O(n)
	
	vector<int> countBits(int n){
        vector<int> bits(n+1);
        bits[0] = 0;
        for(int i=1; i<=n; i++){  
            if(i%2 != 0){
                bits[i] = bits[i/2] + 1;
            }
            else{
                bits[i] = bits[i/2];
            }
        }
        return bits;
    }

int main(){	
	int n;
	cin >> n;
	
	vector<int> bits = countBits(n);
	for(int& i : bits) cout << i << " ";
	cout << "\n";
	
	return 0;
}
