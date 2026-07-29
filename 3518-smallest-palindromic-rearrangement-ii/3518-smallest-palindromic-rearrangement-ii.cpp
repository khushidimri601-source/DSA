class Solution {
public:
    long long nCr(int n,int r,int k){
        r=min(r,n-r);
        long long result=1;
        for(int i=1;i<=r;i++){
            result=result*(n-r+i)/i;
            if(result>=k)
             return k;
           
        }
         return result;
    }
    string smallestPalindrome(string s, int K) {
        int n=s.length();
        char mid=' ';
        if(n%2==1)
          mid=s[n/2];
        vector<int>count(26,0);
        for(int i=0;i<n;i++){
         if(n%2==1 && i==n/2)
          continue;
        count[s[i]-'a']++;}
        for(int i=0;i<26;i++)
        count[i]/=2;
        string halfResult="";
        int half=n/2;
        for(int i=0;i<half;i++){
            bool placeHolder=false;
            for(int j=0;j<26;j++){
                if(count[j]>0){
                 count[j]-=1;
                long long ways=1;
                int letter=0;
            for(int i=0;i<26;i++)
            letter+=count[i];
            for(int i=0;i<26;i++){
                if(count[i]>0){
                    ways*=nCr(letter,count[i],K);
                    letter-=count[i];
                }
                if(ways>=K)
                break;
            }
            if(ways>=K){
             halfResult.push_back(j+'a');
             placeHolder=true;
             break;
            }
            K-=ways;
            count[j]+=1;
                }
            }
        if(placeHolder==false)
        return "";
        }
        string rev=halfResult;
        reverse(begin(rev),end(rev));
        if(mid!=' ')
        halfResult.push_back(mid);
        //return halfResult+rev;}
        return halfResult+rev;

    }
};