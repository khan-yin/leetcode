#include<vector>
#include<algorithm>
using namespace std;
class StreamRank {
public:
    vector<int> res;
    StreamRank() {

    }
    
    void track(int x) {
        res.push_back(x);
        sort(res.begin(),res.end());
    }
    
    int getRankOfNumber(int x) {
        int k = upper_bound(res.begin(),res.end(),x) - res.begin();
        return k;
    }
};