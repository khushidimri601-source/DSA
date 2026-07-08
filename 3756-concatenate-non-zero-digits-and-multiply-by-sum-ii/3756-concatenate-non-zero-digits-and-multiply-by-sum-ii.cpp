class Solution {
public:
   typedef long long ll;
   int MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<ll>sumUpTo(n,0);
        vector<ll>numUptoCount(n,0);
        vector<int>nonZeroCount(n,0);
        vector<ll>pow(n+1,0);
        pow[0]=1;
        for(int i=1;i<=n;i++){
            pow[i]=(pow[i-1]*10) % MOD;
        }
        nonZeroCount[0]=(s[0]!='0')?1:0;
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            nonZeroCount[i]=nonZeroCount[i-1]+ (digit!=0?1:0);
        }
        numUptoCount[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0)
             numUptoCount[i]=(numUptoCount[i-1]*10+digit)%MOD;
            else
             numUptoCount[i]=numUptoCount[i-1];
        }
        sumUpTo[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0)
             sumUpTo[i]=(sumUpTo[i-1]+digit)%MOD;
            else
             sumUpTo[i]=sumUpTo[i-1];
        }
        int q=queries.size();
        vector<int>res(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ll sum=sumUpTo[r]-((l==0)?0:sumUpTo[l-1]);
            ll numBefore=(l==0)?0:numUptoCount[l-1];
            int k=nonZeroCount[r]-((l==0)?0:nonZeroCount[l-1]);
            ll x=(numUptoCount[r]-(numBefore*pow[k])%MOD+MOD)%MOD;
            res[i]=(int)((x*sum)%MOD);
            
        }
        return res;







        
    }
};