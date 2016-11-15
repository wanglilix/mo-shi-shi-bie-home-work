#include "StdAfx.h"
#include "CreateS.h"
#include "MainFrm.h"
#include <random>

void CreateS(int X, int Y, int N, vector<pair<int, int>>& PointVec)
{
	double D=(double)N/(double)10+20;			//��׼��
	std::normal_distribution<> gus_noise(0, D);	//��һ������Ϊƽ���Ҷȼ����ڶ�������Ϊ��׼��
	std::default_random_engine dre(time(0));	//����
	vector < pair < double, double>> PointTmp;  //�洢��İ뾶�ͽǶ�

	for (auto i = 0; i < N;++i)
	{
		PointTmp.push_back(std::move(make_pair(gus_noise(dre), 0)));//����n����r��0����r���Ӹ�˹�ֲ�
	}

	//srand((unsigned int)time(NULL));	//��ʱ��Ϊ����
	static double randhelp=0;			//��������������
	randhelp += 1.5;					//��ת����
	static uniform_real_distribution<double> u(0, 2*3.1415926);//���ȷֲ�������ֲ����� ��̬���Ա���״̬

	for (auto& i : PointTmp)			//�����Ƕ�
	{
		i.second = u(dre) + randhelp;
		while (i.second >= 3.14159265*2)
		{
		 	i.second  -= 3.1415926 * 2;
		}

		i.first = abs(i.first);			//�뾶ȡ����ֵ

		int x, y;			//�ݴ�������
		if (0 <= i.second && i.second < (double)3.1415926 / (double)2.0)
		{
			x = X + i.first * sin(i.second);
			y = Y - i.first * cos(i.second);
		}else if ((double)3.1415926/(double)2 <= i.second  && i.second < 3.1415926 )
		{
			i.second = i.second - (double)3.1415926 / (double)2;
			x = X + i.first * cos(i.second);
			y = Y + i.first * sin(i.second);
		}
		else if (3.1415926 <= i.second  && i.second < (double)3.1415926*(double)3/(double)2)
		{
			i.second = i.second - (double)3.1415926;
			x = X - i.first * sin(i.second);
			y = Y + i.first * cos(i.second);
		}
		else if ((double)3.1415926*(double)3 / (double)2 <= i.second && i.second <= 3.1415926*(double)2) //0~2pi
		{
			i.second = i.second - (double)3.1415926*(double)3 / (double)2;
			x = X - i.first * cos(i.second);
			y = Y - i.first * sin(i.second);
		}

		PointVec.push_back(std::move(make_pair(x, y))); //�洢����������
	}
	


}
