class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // vector<int> ans;
        int n=numbers.size();
        int l=0,r=n-1;
        while(l<r){
            int sum=numbers[l]+numbers[r];
            if(sum==target)return {l+1,r+1};
            else if(sum<target)l++;
            else r--;
        }
    }
};
