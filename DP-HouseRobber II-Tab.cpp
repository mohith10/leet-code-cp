class Solution {
    long long int f(vector<int> nums){
        
        
        long long int take =0, nonTake =0,prev = nums[0], doublePrev = 0, curr = 0;
        for(int i=1;i<nums.size();i++){
            take = nums[i];
            if(i-2>=0){
                take += doublePrev;
            }
            nonTake = prev;
            curr = max(take,nonTake);
            doublePrev = prev;
            prev = curr; 
        }
        return prev;
    }
    public:
    long long int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
            
        }
        
        int res1 = f(temp1);
        int res2 = f(temp2);


        return max(res1,res2);
    }       
};
