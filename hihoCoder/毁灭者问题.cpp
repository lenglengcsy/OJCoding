/*
这个暴力算法果然是超时了，先mark下，之后再来解决
*/

#include <iostream>
#include <vector>

using namespace std;

struct MagUnit
{
	int s;  //初始法力
	int m;  //法力上限
	int r;  //秒回法力
	int lastTime;  //记录最近一次被抽取的时间

	MagUnit():lastTime(0){}

	int update(int time)
	{
		int curM;
		if(lastTime == 0)
		{
			curM = (time * r + s) > m ? m : time * r + s;
		}
		else
		{
			curM = (time - lastTime)*r > m ? m : (time - lastTime)*r;
		}

		lastTime = time;

		return curM;
	}
};

struct CtrlUnit
{
	int t;  //时间
	int l;	//被操作单位起始
	int r;	//被操作单位结束
};

void updateMagVec(vector<MagUnit> &magVec)
{

}
int main()
{
	int n;  //魔法单位的数目
	while(cin >> n)
	{
		/*--------------数据录入-------------*/
		vector<MagUnit> magVec;
		while(n--)
		{
			MagUnit mu;
			cin >> mu.s >> mu.m >> mu.r;
			magVec.push_back(mu);
		}

		int m;  //操作的数目
		vector<CtrlUnit> ctrlVec;
		cin >> m;
		while(m--)
		{
			CtrlUnit cu;
			cin >> cu.t >> cu.l >> cu.r;
			ctrlVec.push_back(cu);
		}

		/*-----------------计算开始--------------*/
		int sum = 0;

		for(auto x : ctrlVec)
		{
			for(int i = x.l-1 ; i < x.r; ++i)
			{
				sum += magVec[i].update(x.t);
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}