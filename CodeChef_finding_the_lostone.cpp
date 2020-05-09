#include <bits/stdc++.h> 
using namespace std;

int main() {
	int a,b;
	cin>>a;
	int arr[a];
	int i;
	for(i=0;i<a;i++) {
	    cin>>arr[i];
	}
	cin>>b;
	vector<int> v;
	int brr[b];
	for(i=0;i<b;i++) {
	    cin>>brr[i];
	}
	map<int,int> mapb;
	for(i=0;i<b;i++) {
	    mapb[brr[i]]++;
	}
	map<int,int> mapa;
	for(i=0;i<a;i++) {
	    mapa[arr[i]]++;
	}
	for (auto x : mapb) {
        if(mapb[x.first]!=mapa[x.first]) {
            v.push_back(x.first);
        }
	}
	for(i=0;i<v.size();i++){
	    cout<<v[i]<<" ";
	}
}
