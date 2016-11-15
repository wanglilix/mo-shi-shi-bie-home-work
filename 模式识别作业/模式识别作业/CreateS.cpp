#include "StdAfx.h"
#include "CreateS.h"
#include "MainFrm.h"
#include <random>

void CreateS(int X, int Y, int N, vector<pair<int, int>>& PointVec)
{
	double D=(double)N/(double)10+20;			//标准差
	std::normal_distribution<> gus_noise(0, D);	//第一个参数为平均灰度级，第二个参数为标准差
	std::default_random_engine dre(time(0));	//引擎
	vector < pair < double, double>> PointTmp;  //存储点的半径和角度

	for (auto i = 0; i < N;++i)
	{
		PointTmp.push_back(std::move(make_pair(gus_noise(dre), 0)));//存入n个（r，0），r服从高斯分布
	}

	//srand((unsigned int)time(NULL));	//以时间为种子
	static double randhelp=0;			//帮助随机数更随机
	randhelp += 1.5;					//旋转因子
	static uniform_real_distribution<double> u(0, 2*3.1415926);//均匀分布的随机分布对象 静态可以保持状态

	for (auto& i : PointTmp)			//产生角度
	{
		i.second = u(dre) + randhelp;
		while (i.second >= 3.14159265*2)
		{
		 	i.second  -= 3.1415926 * 2;
		}

		i.first = abs(i.first);			//半径取绝对值

		int x, y;			//暂存点的坐标
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

		PointVec.push_back(std::move(make_pair(x, y))); //存储点坐标数据
	}
	


}
