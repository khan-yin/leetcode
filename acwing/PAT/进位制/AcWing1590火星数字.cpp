// PAT甲级真题1100
#include <iostream>
#include <sstream>

using namespace std;

char names[][5] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
};

int get(string word)
{
    for (int i = 0; i < 25; i ++ )
        if (names[i] == word)
        {
            if (i < 13) return i;
            return (i - 12) * 13;
        }
    return -1;  // 一定不会执行
}

int main()
{
    int n;
    cin >> n;
    getchar();

    while (n -- )
    {
        string line;
        getline(cin, line);

        stringstream ssin(line);
        if (line[0] <= '9')
        {
            int v;
            ssin >> v;
            if (v < 13) cout << names[v] << endl;
            else
            {
                cout << names[12 + v / 13];
                if (v % 13 == 0) cout << endl;
                else cout << ' ' << names[v % 13] << endl;
            }
        }
        else
        {
            int res = 0;
            string word;
            while (ssin >> word) res += get(word);
            cout << res << endl;
        }
    }

    return 0;
}
