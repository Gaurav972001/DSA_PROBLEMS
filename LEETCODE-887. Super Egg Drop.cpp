class Solution {
public:
    int dp[101][10001];
    int solve(int k, int n){
        if(n==1 || n==0)
            return n;
        if(k==1)
            return n;
        if(dp[k][n]!=-1)
            return dp[k][n];
        int l=0, h=n, ans=INT_MAX;
        while(l<=h){
            
            int mid=(l+h)>>1;
            int left=solve(k-1, mid-1);
            int right=solve(k,n-mid);
            int temp = 1+max(left, right);
            if(left<right)
                l=mid+1;
            else
                h=mid-1;
            ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp, -1 ,sizeof(dp));
        return solve(k,n);
    }
};