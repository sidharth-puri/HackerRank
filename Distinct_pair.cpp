#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. LONG_INTEGER k
 */
 typedef pair<int, int> pairs; 
int binary_search(vector<int> &arr,int l,int r,int x){
    while(r>=l){
        int mid=l+(r-l)/2;
        if(arr[mid]==x){
            return arr[mid];
        }
        else if (arr[mid]<x){
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    return -1;
}
int countPairs(vector<int> arr, long k) {
    sort(arr.begin(),arr.end());
    set<pairs> s;
    int count=0,i,n=arr.size()-1,x,y;
    for(i=0;i<n;i++){
        int y=binary_search(arr,i+1,n,k-arr[i]);
        if(y!=-1){
            x=arr[i];
            pairs p = make_pair(x, y);
            s.insert(p);
        }
    }
    return s.size();
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    string k_temp;
    getline(cin, k_temp);

    long k = stol(ltrim(rtrim(k_temp)));

    int result = countPairs(arr, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
