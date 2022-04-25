#include<bits/stdc++.h>

using namespace std;

vector<int> NGE(vector<int> &v){
	vector<int> nge(v.size());
	stack<int> st;
	for(int i = 0; i < v.size(); i++){
		while(!st.empty() && v[st.top()]<v[i]){
			nge[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		nge[st.top()] = -1;
		st.pop();
	}
	return nge;
}

void PrintVector(vector<int> &v, vector<int> &nge){
	for(int i = 0; i < nge.size(); i++){
		if(nge[i]==-1) cout << v[i] << " " << -1 << endl;
		else cout << v[i] << " " << v[nge[i]] << endl;
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<int> nge = NGE(v);
	PrintVector(v,nge);
}