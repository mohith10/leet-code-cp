#include <bits/stdc++.h>
using namespace std;


string f(int n, int k){
    int fact_val = 1;
    vector<int> nums;
    for(int i=1;i<n;i++){
        fact_val = fact_val * i;
        nums.push_back(i);
    }
    nums.push_back(n);
    string ans = "";
    k--;
    while(true){
        ans = ans+to_string(nums[k/fact_val]);
        nums.erase(nums.begin() + k/fact_val);
        if(nums.size() == 0 )
            break;
        k = k%fact_val;
        fact_val = fact_val/nums.size();
    }
    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    cout<<f(n,k);
	return 0;
}
