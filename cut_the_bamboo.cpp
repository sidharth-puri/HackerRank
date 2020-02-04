#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'cutBamboo' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY lengths as parameter.
 */

vector<int> cutBamboo(vector<int> lengths) {
    int i,max=INT_MIN,maxi=0,n=lengths.size();
    for(i=0;i<n;i++){
        if(lengths[i]>max){
            max=lengths[i];
            maxi=i;
        }
    }
    vector<int> v;
    while(lengths[maxi]!=0){
        int min=INT_MAX,count=0;
        for(i=0;i<n;i++){
            if(lengths[i]<min && lengths[i]>0){
                min=lengths[i];
            }
        }
        for(i=0;i<n;i++){
            if(lengths[i]>0){
                lengths[i]=lengths[i]-min;
                count++;
            }
        }
       // cout<<count<<"\n";
        v.push_back(count);
    }
    return v;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lengths_count_temp;
    getline(cin, lengths_count_temp);

    int lengths_count = stoi(ltrim(rtrim(lengths_count_temp)));

    vector<int> lengths(lengths_count);

    for (int i = 0; i < lengths_count; i++) {
        string lengths_item_temp;
        getline(cin, lengths_item_temp);

        int lengths_item = stoi(ltrim(rtrim(lengths_item_temp)));

        lengths[i] = lengths_item;
    }

    vector<int> result = cutBamboo(lengths);

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
