class Solution {
public:
    int lower_bound(vector<int>& nums,int n ,int target){
        int low=0;
        int high =n-1;
        int answer=n;
        while(low<=high){
            int mid = (low+high)/2;
            //maybe an answer
            if (nums[mid]>=target){
                answer=mid;
                high = mid-1;
                // looks for more small index on left
            }
            else{
                low = mid+1;//look for right
            }
        }
        return answer;
    }
    int upper_bound(vector<int>& nums,int n,int target ){
        int low=0;
        int high=n-1;
        int answer=n;
        while(low<=high){
            int mid = (low+high)/2;
            //maybe an answer

            if (nums[mid]>target){
                answer=mid;
                high = mid-1;
                // looks for more small index on left
            }
            else{
                low = mid+1;
                // looks for right
            }
        }
        return answer;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        int lb = lower_bound(nums,n,target);
        if (lb == n || nums[lb]!=target) return {-1,-1};
        else return {lb,upper_bound(nums,n,target)-1};
        
    }
};