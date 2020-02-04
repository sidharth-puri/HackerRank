#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'checkPangram' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY strings as parameter.
 */

string checkPangram(vector<string> strings) {
    int i,n=strings.size();
     string str;
    for(i=0;i<n;i++){
        int arr[26],j;
        for(j=0;j<26;j++){
            arr[j]=0;
        }
        int l=strings[i].length();
        for(j=0;j<l;j++){
            if(strings[i][j]==' '){
                j++;
            }
            arr[strings[i][j]-'a']=1;
            
        }
       
        int flag=1;
        for(j=0;j<26;j++){
            if(arr[j]==0){
                flag=0;
                break;
            }
        }
       
        if(flag==1){
            str+='1';
        }
        else {
            str+='0';
        }
        
    }
    return str;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string strings_count_temp;
    getline(cin, strings_count_temp);

    int strings_count = stoi(ltrim(rtrim(strings_count_temp)));

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    string result = checkPangram(strings);

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
