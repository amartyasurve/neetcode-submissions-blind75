class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=0,mid=0;
        int n=nums.size();
        r=n-1;
        int ans=INT_MAX;
        while(l<=r){
            if(nums[l] < nums[r]){
                ans=min(ans,nums[l]);
            }
            mid=l+(r-l)/2;
            ans=min(ans,nums[mid]);
            if(nums[l]<=nums[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
