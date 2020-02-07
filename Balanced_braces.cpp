#include <bits/stdc++.h>

using namespace std;



// Complete the braces function below.
int ismatching(char a,char b){
    if(a=='}' && b=='{'){
        return 1;
    }
     if(a==')' && b=='('){
        return 1;
    }
     if(a==']' && b=='['){
        return 1;
    }
    return 0;
}
vector<string> braces(vector<string> values) {
    stack<char> s;
    vector<string> v;
    int i,j;
    for(i=0;i<values.size();i++){
        for(j=0;j<values[i].length();j++){
            if(values[i][j]=='('||values[i][j]=='{'||values[i][j]=='['){
                s.push(values[i][j]);
            }
            else {
                if(s.empty()){
                    // v.push_back("NO");
                    s.push('s');
                    break;
                }
                if(ismatching(values[i][j],s.top())){
                    s.pop();
                }
                else {
                  //  v.push_back("NO");
                    break;
                }
            }
        }
        if(s.empty()){
            v.push_back("YES");
        }
        else {
            v.push_back("NO");
        }
        while(!s.empty()){
            s.pop();
        }
    }
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int values_count;
    cin >> values_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> values(values_count);

    for (int i = 0; i < values_count; i++) {
        string values_item;
        getline(cin, values_item);

        values[i] = values_item;
    }

    vector<string> res = braces(values);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
