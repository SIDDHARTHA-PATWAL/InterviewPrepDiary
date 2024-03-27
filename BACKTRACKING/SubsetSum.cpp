#include<bits/stdc++.h>
using namespace std;
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
inline void debugMode() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}
// function

void backtrack(int index,vector<int>&num,int sum,
vector<int>&sumSubset){
	if(index == num.size()){
		sumSubset.push_back(sum);
		return;
	}
	backtrack(index+1 , num , sum+ num[index] , sumSubset);
	backtrack(index+1 , num , sum             , sumSubset);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int> sumSubset;
	backtrack(0 , num , 0, sumSubset);
	sort(sumSubset.begin(),sumSubset.end());
	return sumSubset;
}


int32_t main(){
	startt
	debugMode();

    int n;
    cin>>n;
	vector<int> num (n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	vector<int> ans ;
	ans= subsetSum(num);
	for(auto it:ans){
		cout<<it<<" ";
	}
	return 0;
}