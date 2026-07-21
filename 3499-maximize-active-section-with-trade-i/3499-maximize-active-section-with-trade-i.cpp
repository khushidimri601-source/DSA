class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int activeCount=count(begin(s),end(s),'1');
        vector<int>inactiveBlock;
        int i=0,start;
        while(i<n){
            if(s[i]=='0'){
            start=i;
            while(i<n && s[i]=='0')
            i++;
            inactiveBlock.push_back(i-start);
            }
            else
            i++;
        }
        int maxPairsum=0;
        for(int i=1;i<inactiveBlock.size();i++)
         maxPairsum=max(maxPairsum,(inactiveBlock[i]+inactiveBlock[i-1]));
        return maxPairsum+activeCount;

        
    }
};