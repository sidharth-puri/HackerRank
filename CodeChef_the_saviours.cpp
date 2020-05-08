#include <bits/stdc++.h> 
using namespace std;

int main() {
	stack<int> s;
	int n,k;
	cin>>n;
	for(k=0;k<n;k++) {
	    string str;
	    cin>>str;
	    int i,count=0,flag=1;
	    s.push(0);
	    for(i=0;i<str.length();i++) {
	      if(str[i]=='0') {
	          if(s.top()==0) {
	             // cout<<"NO"<<endl;
	              flag=0;
	             
	          }
	          else if(s.top()==1 || s.top()==2) {
	              int a=s.top();
	              a=a-1;
	              s.push(a);
	          }
	      }
	      else if(str[i]=='*') {
	          if(s.top()==1 ||s.top()==2) {
	              s.pop();
	              s.push(2);
	          }
	          else {
	              s.push(2);
	          }
	      }
	      
	    }
	    if(s.top()>=0 && flag==1) {
	        cout<<"YES\n";
	    }
	    else  {
	        cout<<"NO\n";
	    }
	    while(!s.empty()){
	        s.pop();
	    }
	    
	}
	return 0;
}
