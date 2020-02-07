#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxTrailing' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY levels as parameter.
 */

int maxTrailing(vector<int> levels) {
    int i,j,max=INT_MIN,maxnum=levels[0];

    for(i=1;i<levels.size();i++){
        if(levels[i]>maxnum){
            maxnum=levels[i];
        }
            for(j=i-1;j>=0;j--){
            if((levels[i]-levels[j])>=max){
                max=(levels[i]-levels[j]);
            }
        }
    }
    if(maxnum==levels[0]){
        return -1;
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string levels_count_temp;
    getline(cin, levels_count_temp);

    int levels_count = stoi(ltrim(rtrim(levels_count_temp)));

    vector<int> levels(levels_count);

    for (int i = 0; i < levels_count; i++) {
        string levels_item_temp;
        getline(cin, levels_item_temp);

        int levels_item = stoi(ltrim(rtrim(levels_item_temp)));

        levels[i] = levels_item;
    }

    int result = maxTrailing(levels);

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
