#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'newPassword' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string newPassword(string a, string b) {
    string c;
    int i=0,j=0,la=a.length()-1,lb=b.length()-1;
    while(i<=la && j<=lb){
        c+=a[i];
        i++;
        c+=b[j];
        j++;
    }
    while(i<=la){
        c+=a[i];
        i++;
    }
    while(j<=lb){
        c+=b[j];
        j++;
    }
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    string result = newPassword(a, b);

    fout << result << "\n";

    fout.close();

    return 0;
}
