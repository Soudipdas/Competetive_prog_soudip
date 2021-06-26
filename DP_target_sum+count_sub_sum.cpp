class Solution {
public:
  
  /*
  A bit complex
  
  Given a difference we have to check how many possible combination of subsets can give the difference
  arr[]={1,2,1};
  diff=1
  
  One possible combo -- 1+2-1=1
  
  So S1-- Subset 1  S2-- Subset 2
  S1-S2=diff
  
  S1-(Sum_of_array-S2)=diff
  S1= (diff+ soa)/2;
  
  Now make a subset sum count function for S1;
  And when the number in array is zero skip the number and don't consider it.
  
  Baaki see the code and understand
  
  */  
    int dp[23][1004];
    
    int rec(vector<int>& a,int n,int sum){
        if(sum==0){
            dp[n][sum]=1;
            return 1;
        }
        if(n==0){
            dp[n][sum]=0;
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(a[n-1]==0){
            dp[n][sum]=rec(a,n-1,sum);
            return dp[n][sum];
        }
        if(a[n-1]>sum){
            dp[n][sum]=rec(a,n-1,sum);
            return dp[n][sum];
        }
        dp[n][sum]= rec(a,n-1,sum-a[n-1]) + rec(a,n-1,sum);
        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>& a, int dif) {
        
        
        int n=a.size();
        int sum_ar=0;       
        
        int zer=0;
        for(int i=0;i<n;i++){
            sum_ar+=a[i];
            if(a[i]==0)
                zer++;
        }
        
        if(dif>sum_ar)
            return 0;
        int sum=(dif+sum_ar)/2;
        
        if((dif+sum_ar)%2!=0){
            return 0;
        }
        
        memset(dp,-1,sizeof(dp));
        int p= rec(a,n,sum);
        cout<<p<<" ";
        
        return p*pow(2,zer);
    }
};
