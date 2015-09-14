/*
��������㷨��Ȼ�ǳ�ʱ�ˣ���mark�£�֮���������
*/

#include <iostream>
#include <vector>

using namespace std;

struct MagUnit
{
	int s;  //��ʼ����
	int m;  //��������
	int r;  //��ط���
	int lastTime;  //��¼���һ�α���ȡ��ʱ��

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
	int t;  //ʱ��
	int l;	//��������λ��ʼ
	int r;	//��������λ����
};

void updateMagVec(vector<MagUnit> &magVec)
{

}
int main()
{
	int n;  //ħ����λ����Ŀ
	while(cin >> n)
	{
		/*--------------����¼��-------------*/
		vector<MagUnit> magVec;
		while(n--)
		{
			MagUnit mu;
			cin >> mu.s >> mu.m >> mu.r;
			magVec.push_back(mu);
		}

		int m;  //��������Ŀ
		vector<CtrlUnit> ctrlVec;
		cin >> m;
		while(m--)
		{
			CtrlUnit cu;
			cin >> cu.t >> cu.l >> cu.r;
			ctrlVec.push_back(cu);
		}

		/*-----------------���㿪ʼ--------------*/
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