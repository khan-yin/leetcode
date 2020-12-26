#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int changedirection=2;//每次替换位置需要移动2个棋子
    int keepdirection=4;//沿方向继续走需要移动4个棋子
public: 
    int minimumMoves(int x, int y) {
        if (x<y)
            return minimumMoves(y,x);
        
        int route=x+y-2;//该节点起点到终点移动的距离
        int first_step=x+y-3;//第一步需要移动的其他棋子数
        int reverse_step=2*(y-1)*changedirection; //向右向下交替移动的其他棋子数，最大交替数只能选min(x,y)
        int remain_step=max(-2,keepdirection*(x-y-1)); //4*(x-y-1)是交替移动后在x方向还剩下的步骤
        //这里有个处理是-2主要是因为当x=y的时候，上面的reverse_step多算了一个step所以需要-2,刚好后面的-4小于-2
        return route+first_step+reverse_step+remain_step;
    }
};


int main()
{
    Solution solution;
    int res=solution.minimumMoves(10,10);
    cout<<res;
    return 0;
}