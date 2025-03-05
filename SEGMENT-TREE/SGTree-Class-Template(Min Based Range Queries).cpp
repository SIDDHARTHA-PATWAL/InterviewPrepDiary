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


void solve() {
    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    SGTree ds(n);
	int q;
	cin>>q;
	while(q--){
		int type; cin>>type;
		if(type==1){
			int l,r;
			cin>>l>>r;
			cout<<ds.query(0,0,n-1,l,r)<<endl;
		}
		else{
			int i, val;
			cin>>i>>val;
			ds.update(0,0,n-1,i,val);
			arr[i]=val;
		}
	}

	
}

int main() {
    startt
    debugMode();
    solve();
}
