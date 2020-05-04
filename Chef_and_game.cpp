#include <iostream>
using namespace std;

int main() {
	int t,k;
	cin>>t;
	for(k=0;k<t;k++) {
	    int n;
	    cin>>n;
	    int i,arr[n];
	    for(i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    int count=0,max=-999999,zerocount=0,pos;
	    for(i=0;i<n;i++) {
	        if(arr[i]==1){
	            count++;
	            if(count>max){
	                max=count;
	            }
	        }
	        else if(arr[i]==0 && zerocount<1) {
	            count++;
	            pos=i;
	            zerocount++;
	            if(count>max){
	                max=count;
	            }
	        }
	        else if(arr[i]==0 && zerocount==1){
	            count=0;
	            zerocount=0;
	            i=pos;
	        }
	    }
	    cout<<max<<endl;
	}
	return 0;
}
