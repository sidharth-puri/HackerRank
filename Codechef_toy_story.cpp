#include <iostream>
using namespace std;

int main() {
	int t,k;
	cin>>t;
	for(k=0;k<t;k++) {
	    int n,count=0,i;
	    cin>>n;
	    string arr;
	    cin>>arr;
	    for(i=0;i<n;i++) {
	        if(arr[i]!=arr[i+1]) {
	            continue;
	        }
	        else {
	            count++;
	        }
	    }
	    cout<<count<<endl;
	}
}
