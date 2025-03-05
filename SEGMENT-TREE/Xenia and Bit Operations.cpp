// // // Xenia and Bit Operations

// https://codeforces.com/contest/339/problem/D
// Codeforces Round 197 (Div. 2)

// time limit per test2 seconds
// memory limit per test256 megabytes
// Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1,a2,...,a2^n. 
// Xenia is currently studying bit operations. To better understand how they work, Xenia decided to calculate some value v for a.

// Namely, it takes several iterations to calculate value v. 
// At the first iteration, Xenia writes a new sequence a1 or a2,a3 or a4,...,a2^n-1 or a2^n, consisting of 2^(n-1) elements. 
// In other words, she writes down the bit-wise OR of adjacent elements of sequence a.
//  At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. 
// At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration.
//  And so on; the operations of bitwise exclusive OR and bitwise OR alternate. 
// In the end, she obtains a sequence consisting of one element, and that element is v.

// Let's consider an example. Suppose that sequence a=(1,2,3,4). 
// Then let's write down all the transformations (1,2,3,4) → (1 or 2=3,3  or 4=7) → (3 xor 7=4). The result is v = 4.

// You are given Xenia's initial sequence. 
// But to calculate value v for a given sequence would be too easy, so you are given additional m queries.
//  Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment ap = b.
//  After each query, you need to print the new value v for the new sequence a.

// Input
// The first line contains two integers n and m (1≤n≤17,1≤m≤10^5). The next line contains 2n integers a1,a2,...,a^2n (0≤ai<230). Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.

// Output
// Print m integers — the i-th integer denotes value v for sequence a after the i-th query.

// Examples
// Input
// 2 4
// 1 6 3 5
// 1 4
// 3 4
// 1 2
// 1 2
// Output
// 1
// 3
// 3
// 3
// Note
// For more information on the bit operations, you can follow this link: http://en.wikipedia.org/wiki/Bitwise_operation



#include <bits/stdc++.h>
using namespace std;

#define startt ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
ll mod = 1e9 + 7;

inline void debugMode() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
class SGTree{
	vector<int> seg;
public:
	SGTree(int n){
		seg.resize(4*n+1);
	}
	void build(int ind, int low, int high, vector<int>& arr){
		if(low==high){
			seg[ind]=arr[low];
			return;
		}
		int mid= (low + high)/2;
		build(2*ind+1, low, mid,arr);
		build(2*ind+2,mid+1, high,arr);
		seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
	}
	int query(int ind, int low, int high, int l , int r){
		//no over lap
		if(high<l || low>r){
			return INT_MAX;
		}
		// complete overlap
		else if(low>=l && high<=r){
			return seg[ind];
		}
		//partial overlap
		else {
			int mid= (low+high)/2;
			int left = query(2*ind+1,low, mid,l,r);
			int right= query(2*ind+2,mid+1,high, l,r);
			return min(left,right);
		}
	}
	void update(int ind, int low, int high, int i, int val){
		
		if(low==high){
			seg[ind]=val;
			return;
		}
		int mid=(low+high)/2;
		if(i<=mid) update(2*ind+1,low, mid, i, val);
		else update(2*ind+2,mid+1,high,i,val);
		seg[ind]= min(seg[2*ind+1],seg[2*ind+2]);
	}
};

ll fact[200005+1];
ll mi[200005+1];

ll power(ll a, ll b) {
    if(b == 0) return 1;
    ll x = power(a, b / 2);
    ll ans = (x * x) % mod;
    if(b % 2 == 1) return (ans * a) % mod;
    return ans;
}

ll modinverse(ll n) {
    return power(n, mod - 2);
}

ll nCr(ll n, ll r) {    
    ll numerator = fact[n];
    ll denominator = (mi[n - r] * mi[r]) % mod;
    return (numerator * denominator) % mod;
}

ll bin_search(vector<ll> & b, ll x, ll prev){
	ll l=0,h=b.size()-1;
	ll mid,ans=-1;
	while(l<=h){
		mid= l+(h-l)/2;
		if(b[mid]-x>=prev){
			ans=mid;
			h=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}


void build(ll ind,ll low,ll high, vector<ll>& arr,vector<ll>&seg,bool orr){
	if(low==high){
		seg[ind]=arr[low]; return;
	}
	ll mid= low+(high-low)/2;
	build(2*ind+1,low,mid,arr,seg,!orr );
	build(2*ind+2,mid+1,high, arr,seg,!orr);
	seg[ind]= orr?(seg[2*ind+1]|seg[2*ind+2]):(seg[2*ind+1]^seg[2*ind+2]);
}
void update(ll ind, ll low, ll high,ll i, ll val,vector<ll>& seg,bool orr){
	if(low==high){
		seg[ind]=val;
		return;
	}
	ll mid= low+(high-low)/2;
	if(i<=mid) update(2*ind+1,low,mid,i,val,seg,!orr);
	else update(2*ind+2,mid+1,high,i,val,seg,!orr);
	seg[ind]= orr?seg[2*ind+1]|seg[2*ind+2]:seg[2*ind+1]^seg[2*ind+2];
}
void solve2(){

	ll n, q; cin>>n>>q;
	ll el=power(2,n);
	vector<ll> arr(el);
	for(int i=0;i<el;i++){
		cin>>arr[i];
	}

	vector<ll> seg(4*el);

	if(n%2==0) build(0,0,el-1,arr,seg,0);
	else build(0,0,el-1,arr,seg,1);
	// cout<<"hello"<<endl;
	while(q--){
		ll i,val; cin>>i>>val;
		i--;
		if(n%2==0){
			update(0,0,el-1,i,val,seg,0);
		}
		else{
			update(0,0,el-1,i,val,seg,1);
		} 
		cout<<seg[0]<<endl;
	}


}

int main() {
    startt
    debugMode();
    solve2();
}
