#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,k;
	cin>>t;
	for(k=0;k<t;k++) {
	    int a,b;
	    cin>>a>>b;
	    int i,n=b-a+1;
	    int arr[n];
	    for(i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    int flag=0,count=0;
	    for(i=0;i<n-1;i++) {
	      if(arr[i+1]-arr[i]==2) {
	          cout<<arr[i]+1<<endl;
	          flag=1;
	          
	      }
	      count++;
	    }
	    if(flag==0) {
	        if(count>1) {
	            cout<<b<<endl;
	        }
	        else 
	        cout<<a<<endl;
	        
	    }
	}
}
