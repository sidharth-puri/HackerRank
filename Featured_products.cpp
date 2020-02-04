#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'featuredProduct' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY products as parameter.
 */

string featuredProduct(vector<string> products) {
    int n=products.size();
    vector<int> freq(n);
    int i;
    for(i=0;i<n;i++){
        freq[i]=-1;
    }
    int count=0,j,max=INT_MIN;
    for(i=0;i<n;i++){
        count=1;
        for(j=i+1;j<n;j++){
            if(products[i].compare(products[j])==0){
                count++;
                freq[j]=0;
            }
        }
        if(freq[i]!=0){
            freq[i]=count;
        }
        if(freq[i]>max){
            max=freq[i];
        }
    }
    vector<string> v;
    for(i=0;i<n;i++){
        if(freq[i]==max){
            v.push_back(products[i]);
        }
    }
    sort(v.begin(),v.end());
    return v[v.size()-1];
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string products_count_temp;
    getline(cin, products_count_temp);

    int products_count = stoi(ltrim(rtrim(products_count_temp)));

    vector<string> products(products_count);

    for (int i = 0; i < products_count; i++) {
        string products_item;
        getline(cin, products_item);

        products[i] = products_item;
    }

    string result = featuredProduct(products);

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
