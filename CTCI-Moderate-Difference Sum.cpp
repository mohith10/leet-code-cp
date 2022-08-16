#include <bits/stdc++.h>
using namespace std;

pair<int, int> swapToEquateSum(vector<int> arr1, vector<int> arr2, int size1, int size2, int targetDiff){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int iter1 = 0, iter2 = size2 - 1;
    while(iter1 < size1 && iter2 < size2){
        int diff = arr1[iter1] - arr2[iter2];
        if(diff == targetDiff){
            return {arr1[iter1] , arr2[iter2]};
        }
        else if(diff < targetDiff){
            iter2--;
        }else{
            iter1++;
        }
    }
    return {-1, -1};
}

int main() {
	int size1, size2, sum1=0, sum2=0;
	cin>>size1>>size2;
	vector<int> arr1, arr2;
	for(int i=0;i<size1;i++){
	    int ele;
	    cin>>ele;
	    arr1.push_back(ele);
	    sum1+=ele;
	}
	for(int i=0;i<size2;i++){
	    int ele;
	    cin>>ele;
	    arr2.push_back(ele);
	    sum2+=ele;
	}
	if((sum1-sum2)%2!=0){
	    cout<<"Not possible";
	}
	else{
	    pair<int, int> res = swapToEquateSum(arr1, arr2, size1, size2, (sum1-sum2)/2);
	    cout<<res.first<<" "<<res.second;
	}
	return 0;
}
