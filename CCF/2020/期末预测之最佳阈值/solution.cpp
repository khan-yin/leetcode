#include<iostream>
#include<algorithm>
using namespace std;
 
// typedef struct stu{
// 	int y;
// 	int result;
// }stu;
 
struct stu{
	int y;
	int result;
};
 
bool cmp(stu a,stu b){
	return a.y<b.y;
}
stu student[100005];

int main(){
	int m;
	ios::sync_with_stdio(false);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>student[i].y>>student[i].result;
	}
    
	sort(student,student+m,cmp); //输入后排序 
    int best=0;
    int bestcnt=0;
    for(int j=0;j<m;j++)
    {
        // cout<<j<<endl;
        int theta = student[j].y;
        int cnt=0;
        for(int k=0;k<m;k++)
        {
            if(student[k].result==0 && student[k].y<theta)
                cnt++;
            else if(student[k].result==1 && student[k].y>=theta)
                cnt++;
        }
        if(cnt>=bestcnt)
        {
            bestcnt = cnt;
            best= theta>best? theta :best;
        }
    }
    cout<<best;
}
