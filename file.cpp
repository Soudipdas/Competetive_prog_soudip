#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair

ll setBitNumber(ll n){
    ll k = (ll)(log2(n));
    return (ll)(pow(2, k));
}

bool isPowerOfTwo (int x) {
    return x && (!(x&(x-1)));
}

int binarySearch(int arr[], int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
}


ll gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


// Function to find gcd of array of
// numbers
ll findGCD(ll arr[], int n)
{
    ll result = arr[0];
    for (ll i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

int maxSubArraySum(vector<int>&a, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int prevPowerofK(int n, int k){
    
    int p = (int)(log(n) / log(k));
    return (int)pow(k, p);
}

ll mex(ll arr[],ll n){
    
    ll ha[105]={0};
    ll ans=0;
    for(ll i=0;i<105;i++){
        if(ha[i]==0){
            ans=i;
            break;
        }
    }
    return ans;

}

void solve() {
	
	
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //t=1;
    cin>>t;
    while(t--){
        solve();
    }
}

