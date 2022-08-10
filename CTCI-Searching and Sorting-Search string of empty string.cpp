#include <bits/stdc++.h>
using namespace std;

int findInEmptyStringArray(vector<string> arr, string key, int num){
    int low = 0, high = num-1;
    while(low < high){
        int mid = low + (high-low)/2;
        cout<<low<<" "<<mid<<" "<<high<<endl;
        if(arr[mid] == "-"){
            int left = mid, right = mid;
            while(true){
                if(left < low && right > high){
                    return -1;
                }
                else if(arr[right]!="-" && right<=high){
                    mid = right;
                    break;
                }else if(arr[left]!="-" && left>=low){
                    mid = left;
                    break;
                }
                left--;
                right++;
            }
        }
        cout<<"After change "<<low<<" "<<mid<<" "<<high<<endl;
        int res = key.compare(arr[mid]);
        cout<<res<<" for "<<key<<" "<<arr[mid]<<endl;
        if(res == 0){
            return mid;
        }else if(res < 0){
            high = mid-1;
        }else{
            low = mid + 1;
        }
        
    }
    return -1;
}

int main() {
    int num;
    cin>>num;
    string key;
    cin>>key;
    vector<string> arr;
    for(int ind = 0; ind<num; ind++){
        string x;
        cin>>x;
        arr.push_back(x);
    }
    for(int i=0;i<num;i++){
        cout<<arr[i]<<endl;
    }
    int index = findInEmptyStringArray(arr,key,num);
    cout<<index;
	return 0;
}
