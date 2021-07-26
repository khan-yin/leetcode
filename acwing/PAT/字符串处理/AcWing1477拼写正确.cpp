#include <iostream>
#include <cstring>
#include <algorithm>
#include<string>

using namespace std;
 
int main()
{
    string n;
    cin>>n;
    int res = 0;
    for(char i : n) res += i-'0';
    string s = to_string(res);
    char words[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i=0;i<s.size();i++)
    {
        cout<<words[s[i]-'0']<<" ";
    }
    return 0;
}