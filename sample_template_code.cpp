#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair

vector<vector<ll> >graph;
vector<ll>prime;

//s is the start pint of bfs
//v+1 is the limit of vertices


int bfs(ll s,ll v){
    bool vis[v+1];
    ll level[v+1]={0};
    for(ll i=0;i<=v;i++)
        vis[i]=false;
    queue<ll>q;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        for(ll i=0;i<graph[s].size();i++){
            ll b=graph[s][i];
            if(!vis[b]){
                q.push(b);
                level[b]=level[s]+1;
                vis[b]=true;
            }
        }
    }
    return *max_element(level,level+v+1);

}



void dfs(ll u, ll vis[]){
    vis[u]=1;

    for(ll i=0;i<graph[u].size();i++){
        ll e=graph[u][i];
        if(vis[e]==false){
            dfs(e,vis);
        }
    }
    //return minm;
}


bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

void countprimes(ll n){
    if(n<=1)
        return;
    prime.push_back(2);
    for(ll i=3;i<=n;i+=2){
        if(isPrime(i)){
            prime.push_back(i);
        }
    }

}



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

