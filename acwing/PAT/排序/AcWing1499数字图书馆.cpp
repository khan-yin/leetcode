// PAT甲级真题1022
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
第一行：书的 ID，一个 7 位数字。
第二行：书名，一个长度不超过 80 的字符串。
第三行：作者，一个长度不超过 80 的字符串。
第四行：关键词，每个关键词的长度均不超过 10，且关键词中不包含空格，关键词之间用空格隔开。
第五行：出版商，一个长度不超过 80 的字符串。
第六行：出版年限，一个在 [1000,3000] 范围内的 4 位数字。
*/

/*\
查询方法
1: a book title，查询书名。
2: name of an author，查询作者名。
3: a key word，查询关键词。
4: name of a publisher，查询出版商。
5: a 4-digit number representing the year，查询出版年限。注意，这个年限可能包含前导 0。
输出格式
*/

struct Book
{
    string id;
    string name;
    string author;
    set<string> keywords;
    string publisher;
    string year;
};

vector<Book> books;

int main()
{
    int n,m;
    cin>>n;
    getchar();
    while (n -- )
    {
        string id,name,author,publisher,year;
        string line;
        string keyword;
        set<string> keywords;

        getline(cin,id);
        getline(cin,name);
        getline(cin,author);
        getline(cin,line);
        getline(cin,publisher);
        getline(cin,year);
        stringstream ssin(line);

        while(ssin>>keyword) keywords.insert(keyword);
        books.push_back({id,name,author,keywords,publisher,year});
    }

    // for(auto& book : books) cout<<book.id<<endl;
    cin>>m;
    getchar();

    while(m--)
    {
        string line;
        getline(cin,line);
        cout<<line<<endl;
        string cmd = line.substr(3);
        vector<string> res;
        if(line[0]=='1')
        {
            for(auto &book : books)
            {
                if(book.name==cmd) res.push_back(book.id);
            }
        }
        else if(line[0]=='1')
        {
            for(auto &book : books)
            {
                if(book.name==cmd) res.push_back(book.id);
            }
        }
        else if(line[0]=='2')
        {
            for(auto &book : books)
            {
                if(book.author==cmd) res.push_back(book.id);
            }
        }
        else if(line[0]=='3')
        {
            for(auto &book : books)
            {
                if(book.keywords.count(cmd))
                    res.push_back(book.id);
            }
        }
        else if(line[0]=='4')
        {
            for(auto &book : books)
            {
                if(book.publisher==cmd) res.push_back(book.id);
            }
        }
        else if(line[0]=='5')
        {
            for(auto &book : books)
            {
                if(book.year==cmd) res.push_back(book.id);
            }
        }

        if (res.empty()) puts("Not Found");
        else
        {
            sort(res.begin(), res.end());
            for (auto id : res) cout << id << endl;
        }
    }


    return 0;
}
