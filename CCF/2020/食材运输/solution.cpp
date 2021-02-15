#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int Q,M,N;//M是输入，N是门的个数
int S;//试验次数
const int MAX_N = 505;
int in_degree[MAX_N];
enum TYPE {XOR,NOT,AND,OR,NAND,NOR};
struct Door{
	TYPE type;
	int ans;
	vector<int> input;//输入,负数表示输入端，正数表示逻辑门的编号 
	vector<int> output;//输出 
};
Door door[MAX_N];

TYPE stt(const string &s)
{
	if(s=="XOR")return XOR;
	if(s=="NOT")return NOT;
	if(s=="AND")return AND;
	if(s=="OR")return OR;
	if(s=="NAND")return NAND;
	if(s=="NOR")return NOR;
	cout<<"EROOR"<<endl;//不该出现的情况，用于debug 
	exit(0);
}

int calculate(int x,int y,TYPE type)
{
	switch(type)
	{
		case XOR:
			return (x^y)&1;
		case AND:
			return x&y;
		case OR:
			return x|y;
		case NAND:
			return !(x&y);
		case NOR:
			return !(x|y);
		default:
			cout<<"ERROR"<<endl;
			break;
	}
}


bool toposort(Door* door,vector<int> &topo)
{
	stack<int> stk;
    for(int i=1;i<=N;i++)
    {
        if(in_degree[i]==0)//入度为0的点初始化入栈
            stk.push(i);
    }

    while(!stk.empty())
    {
        int x = stk.top();
        stk.pop();
        topo.push_back(x);
        for(int i=0;i<door[x].output.size();i++)
        {
            int y = door[x].output[i];
            in_degree[y]--;//相关节点入读--
            if(in_degree[y]==0)//入度为0压栈
                stk.push(y);
        }
    }

    if(topo.size()==N)
            return true;//topo排序成功 
	    else 
            return false;

}


inline int get_value(Door* door,vector<int> &input,int x)
{
	if(x<0)return input[-x];
	else return door[x].ans;
}

void run(Door* door,vector<int> &topo,vector<int> &input_value)//input[i]表示输入i的值 
{
	for(int i=0;i<topo.size();i++)
    {
        int k=topo[i];//第几个门
        if(door[k].type==NOT)
            door[k].ans=!get_value(door,input_value,door[k].input[0]);
        else
        {
            door[k].ans=calculate(get_value(door,input_value,door[k].input[0]),get_value(door,input_value,door[k].input[1]),door[k].type);
			for(int j=2;j<door[k].input.size();j++)//多个逻辑输入的计算
				door[k].ans=calculate(door[k].ans,get_value(door,input_value,door[k].input[j]),door[k].type);
        }
    }
}

int main()
{
    scanf("%d",&Q);
    
    while(Q--)
    {
        scanf("%d %d",&M,&N);//输入M，门的个数N
        for(int i=1;i<=N;i++)
        {
            string op;
            cin>>op;
            door[i].type=stt(op);
            int cnt=0;
            cin>>cnt;
            while(cnt--)
			{
				getchar();
				char c=getchar();
                int x;
				cin>>x;
				if(c=='I')//输入用负数来表示 
					door[i].input.push_back(-x);
				else//输出用正数，表示下标 
				{
					in_degree[i]++;
					door[i].input.push_back(x);
					door[x].output.push_back(i);
				}
			}
        }
		cin>>S;
		vector<vector<int> > input_value(S,vector<int>(M+1));
		for(int i=0;i<S;i++)
			for(int j=1;j<=M;j++)//由于要对应编号，所以需要从下标1开始 
				cin>>input_value[i][j];
        


        vector<int> topo;//拓扑序列
        bool flag = toposort(door,topo);
        if(!flag)
		{
            int x;
			cout<<"LOOP\n";
			for(int i=0;i<S;i++)//空读
			{
				int s_i;
				cin>>s_i; 
				while(s_i--)
                    cin>>x;
			}
			continue;
		}
        
        for(int i=0;i<S;i++)
		{
            int x;
			run(door,topo,input_value[i]);
			int s_i;
			cin>>s_i; 
			while(s_i--)
			{
				cin>>x;
				cout<<door[x].ans<<" ";
			}
			cout<<endl;
		}
    }
    return 0;
}