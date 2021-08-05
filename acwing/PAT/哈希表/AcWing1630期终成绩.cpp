// PAT甲级真题1137
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Student
{
    string id;
    int p, m, f, s;

    Student(): p(-1), m(-1), f(-1), s(0) {}

    void calc()
    {
        if (f >= m) s = f;
        else s = round(m * 0.4 + f * 0.6);
    }

    bool operator< (const Student& t) const
    {
        if (s != t.s) return s > t.s;
        return id < t.id;
    }
};

int main()
{
    int p, m, n;
    cin >> p >> m >> n;

    unordered_map<string, Student> hash;
    string id;
    int s;
    for (int i = 0; i < p; i ++ )
    {
        cin >> id >> s;
        hash[id].id = id;
        hash[id].p = s;
    }

    for (int i = 0; i < m; i ++ )
    {
        cin >> id >> s;
        hash[id].id = id;
        hash[id].m = s;
    }

    for (int i = 0; i < n; i ++ )
    {
        cin >> id >> s;
        hash[id].id = id;
        hash[id].f = s;
    }

    vector<Student> students;
    for (auto item : hash)
    {
        auto stu = item.second;

        stu.calc();
        if (stu.p >= 200 && stu.s >= 60)
            students.push_back(stu);
    }

    sort(students.begin(), students.end());

    for (auto s : students)
        cout << s.id << ' ' << s.p << ' ' << s.m << ' ' << s.f << ' ' << s.s << endl;

    return 0;
}