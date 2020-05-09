#include <iostream>
using namespace std;

int main() {
	int t,k;
	cin>>t;
	for(k=0;k<t;k++) {
	    int n;
	    cin>>n;
	    int arr[n],a[n];
	    int i;
	    for(i=0;i<n;i++) {
	        cin>>arr[i];
	        a[i]=arr[i];
	    }
	    for(i=0;i<n/2;i++) {
	        swap(a[i],a[n-1-i]);
	    }
	    int sum[n],carry=0;
	    for(i=n-1;i>=0;i--) {
	        sum[i]=arr[i]+a[i]+carry;
	        if(sum[i]>9){
	            sum[i]=sum[i]%10;
	            carry=1;
	        }
	        else {
	            carry=0;
	        }
	    }
	    if(carry==1){
	        cout<<"1 ";
	    }
	    for(i=0;i<n;i++) {
	        cout<<sum[i]<<" ";
	    }
	    cout<<endl;
	}
	
	
}
