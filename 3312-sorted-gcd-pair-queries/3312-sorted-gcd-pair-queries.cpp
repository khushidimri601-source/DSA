class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int mx=*max_element(begin(nums),end(nums));
        vector<int>divisionfrequency(mx+1,0);
        for(int i=0;i<n;i++){
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    divisionfrequency[j]++;
                    if(nums[i]/j!=j)
                     divisionfrequency[nums[i]/j]++;
                }

            }
        }
        vector<long long>pairGcd(mx+1,0);
        for(int i=mx;i>=1;i--){
            long long count=divisionfrequency[i];
            pairGcd[i]=count*(count-1)/2;
            for(int f=2*i;f<=mx;f+=i){
                pairGcd[i]-=pairGcd[f];
            }
        }
        vector<long long>pairCountGcd(mx+1,0);
        for(int i=1;i<=mx;i++){
            pairCountGcd[i]=pairCountGcd[i-1]+pairGcd[i];
        }
        vector<int>result;
        for(long long i :queries){
            int l=1;
            int r=mx;
            int temp=1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(pairCountGcd[mid]>i){
                    temp=mid;
                    r=mid-1;
                }
                else
                 l=mid+1;
            }
            result.push_back(temp);
        }
return result;

    }
};