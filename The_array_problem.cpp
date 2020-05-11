#include <iostream>
using namespace std;

int main() {
	long long int t,k;
	cin>>t;
	for(k=0;k<t;k++) {
	    long long int n,i,sum=0;
	    cin>>n;
	   long long int arr[n];
	    for(i=0;i<n;i++) {
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    for(i=0;i<n;i++) {
	        cout<<sum-arr[i]<<" ";
	    }
	    cout<<endl;
	}
}
