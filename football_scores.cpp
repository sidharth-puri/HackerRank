#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'counts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY teamA
 *  2. INTEGER_ARRAY teamB
 */

int binary_search(vector<int> &a,int x){
    int l=0;
    int r=a.size()-1;
    int count=0;
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[mid]<=x){
            ans=mid;
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    return ans;
}
vector<int> counts(vector<int> teamA, vector<int> teamB) {
    int i,j,count=0;
    vector<int> v;
    sort(teamA.begin(),teamA.end());
    for(i=0;i<teamB.size();i++){
        int pos=binary_search(teamA,teamB[i]);
        v.push_back(pos+1);
    }
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string teamA_count_temp;
    getline(cin, teamA_count_temp);

    int teamA_count = stoi(ltrim(rtrim(teamA_count_temp)));

    vector<int> teamA(teamA_count);

    for (int i = 0; i < teamA_count; i++) {
        string teamA_item_temp;
        getline(cin, teamA_item_temp);

        int teamA_item = stoi(ltrim(rtrim(teamA_item_temp)));

        teamA[i] = teamA_item;
    }

    string teamB_count_temp;
    getline(cin, teamB_count_temp);

    int teamB_count = stoi(ltrim(rtrim(teamB_count_temp)));

    vector<int> teamB(teamB_count);

    for (int i = 0; i < teamB_count; i++) {
        string teamB_item_temp;
        getline(cin, teamB_item_temp);

        int teamB_item = stoi(ltrim(rtrim(teamB_item_temp)));

        teamB[i] = teamB_item;
    }

    vector<int> result = counts(teamA, teamB);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
