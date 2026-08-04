class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        sort(begin(nums),end(nums));
        int curr=nums[0];
        for(int i=0;i<n;i++,curr++){
            if(curr==nums[i]){
             continue;
             
            }
            else{
             res.push_back(curr);
             i--;
            }
            
        }
        return res;
       
    }
};