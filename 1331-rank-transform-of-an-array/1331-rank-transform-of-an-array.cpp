class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
         return {};
        set<int>uniqueElements(arr.begin(),arr.end());
        int rank=1;
        unordered_map<int,int>ranks;
        for(const int &i :uniqueElements){
            ranks[i]=rank++;
        }
        vector<int>ans;
        for(int &i :arr)
         ans.push_back(ranks[i]);


         return ans;
        
    }
};