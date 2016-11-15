
// 模式识别作业View.cpp : C模式识别作业View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "模式识别作业.h"
#endif



#include "模式识别作业Doc.h"
#include "模式识别作业View.h"

#include <stdlib.h>
#include <random>
#include <vector>
#include "Slider.h"

#include "CreateS.h"
#include "ActivationFuntion.h"
#include "NeuralLayer.h"
#include <string>
#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C模式识别作业View

IMPLEMENT_DYNCREATE(C模式识别作业View, CView)

BEGIN_MESSAGE_MAP(C模式识别作业View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_GaussianDistribution, &C模式识别作业View::OnGaussiandistribution)
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_TrainPointCreate, &C模式识别作业View::OnTrainpointcreate)
	ON_COMMAND(ID_ShowAll, &C模式识别作业View::OnShowall)
	ON_COMMAND(ID_ShowPointVec, &C模式识别作业View::OnShowpointvec)
	ON_COMMAND(ID_ShowTrainPointVec, &C模式识别作业View::OnShowtrainpointvec)
	ON_COMMAND(ID_ID_TrainPointCreateB, &C模式识别作业View::OnIdTrainpointcreateb)
	ON_COMMAND(ID_PerceptronTrain, &C模式识别作业View::OnPerceptrontrain)
	ON_COMMAND(ID_PerceptronTest, &C模式识别作业View::OnPerceptrontest)
	ON_COMMAND(ID_EmptyTrainPointA, &C模式识别作业View::OnEmptytrainpointa)
	ON_COMMAND(ID_EmptyTrainPointB, &C模式识别作业View::OnEmptytrainpointb)
	ON_COMMAND(ID_EmptyTrainPoint, &C模式识别作业View::OnEmptytrainpoint)
	ON_COMMAND(ID_LMSTrain, &C模式识别作业View::OnLmstrain)
	ON_COMMAND(ID_NeuronTrain, &C模式识别作业View::OnNeurontrain)
	ON_COMMAND(ID_NeuronTest, &C模式识别作业View::OnNeurontest)
	ON_COMMAND(ID_EmptyPointVec, &C模式识别作业View::OnEmptypointvec)
END_MESSAGE_MAP()

// C模式识别作业View 构造/析构

C模式识别作业View::C模式识别作业View()
: PointNum(0)
, Flag1(0)
, Flag2(0)
, DrawFlag(0)
{
	// TODO:  在此处添加构造代码

}

C模式识别作业View::~C模式识别作业View()
{
}

BOOL C模式识别作业View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C模式识别作业View 绘制

void C模式识别作业View::OnDraw(CDC* pDC)
{
	C模式识别作业Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	CRect   rect1;
	GetClientRect(rect1);
	pDC->FillSolidRect(rect1, RGB(255, 255,255));

	//所有点作图
	if (DrawFlag == 0)
	{
			for (auto i : PointVec)
			{
				for (auto k = -1; k < 2; ++k)//作九个点
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(0, 0, 0));
					}
				}
			}
			for (auto i : TrainPointVecA)
			{
				for (auto k = -1; k < 2; ++k)//作九个点
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(255, 0, 0));
					}
				}
			}
			for (auto i : TrainPointVecB)
			{
				for (auto k = -1; k < 2; ++k)//作九个点
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(0, 255, 0));
					}
				}
			}
	}
	else if (DrawFlag == 1 )//显示样本点
	{
			for (auto i : PointVec)
			{
				for (auto k = -1; k < 2; ++k)//作九个点
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(0, 0, 0));
					}
				}
			}
	}
	else if (DrawFlag == 2)
	{
			for (auto i : TrainPointVecA)
			{
				for (auto k = -1; k < 2; ++k)//作九个点
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(255, 0, 0));
					}
				}
			}
			for (auto i : TrainPointVecB)
			{
				for (auto k = -1; k < 2; ++k)//作九个点
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(0, 255, 0));
					}
				}
			}
	}
		



}


// C模式识别作业View 打印

BOOL C模式识别作业View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C模式识别作业View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void C模式识别作业View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// C模式识别作业View 诊断

#ifdef _DEBUG
void C模式识别作业View::AssertValid() const
{
	CView::AssertValid();
}

void C模式识别作业View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C模式识别作业Doc* C模式识别作业View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C模式识别作业Doc)));
	return (C模式识别作业Doc*)m_pDocument;
}
#endif //_DEBUG


// C模式识别作业View 消息处理程序


void C模式识别作业View::OnGaussiandistribution()//产生样本点函数
{
	Slider slider;
	if (IDOK == slider.DoModal())
	{
		PointNum = slider.Num;
		Flag1 = 1;//产生样本点flag
	}

}


void C模式识别作业View::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonDblClk(nFlags, point);
}


void C模式识别作业View::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (Flag1 ==1)
	{
		Flag2 = 1;  //左键按下flag
		CreateS(point.x, point.y, PointNum, PointVec);//当前位置产生样本点

		CDC* pDC = GetDC();//先画出来，不刷新
		for (auto i = (PointVec.end()-PointNum); i != PointVec.end(); ++i)//只画最新产生的点
		{

			for (auto k = -1; k < 2; ++k)
			{
				for (auto j = -1; j < 2; ++j)
				{
					pDC->SetPixel((*i).first + k, (*i).second + j, RGB(0, 0, 0));
				}
			}
		}
	}
	if (Flag1 == 2)//训练样本
	{
		Flag2 = 1;  //左键按下flag
		CreateS(point.x, point.y, PointNum, TrainPointVecA);//当前位置产生样本点

		CDC* pDC = GetDC();//先画出来，不刷新
		for (auto i = (TrainPointVecA.end() - PointNum); i != TrainPointVecA.end(); ++i )
		{

			for (auto k = -1; k < 2; ++k)
			{
				for (auto j = -1; j < 2; ++j)
				{
					pDC->SetPixel((*i).first + k, (*i).second + j, RGB(255, 0, 0));
				}
			}
		}
		
	}
	if (Flag1 == 3)//训练样本
	{
		Flag2 = 1;  //左键按下flag
		CreateS(point.x, point.y, PointNum, TrainPointVecB);//当前位置产生样本点

		CDC* pDC = GetDC();//先画出来，不刷新
		for (auto i = (TrainPointVecB.end() - PointNum); i != TrainPointVecB.end(); ++i)
		{

			for (auto k = -1; k < 2; ++k)
			{
				for (auto j = -1; j < 2; ++j)
				{
					pDC->SetPixel((*i).first + k, (*i).second + j, RGB(0, 255, 0));
				}
			}
		}
	}


	CView::OnLButtonDown(nFlags, point);
}


void C模式识别作业View::OnMouseMove(UINT nFlags, CPoint point)
{
	
	if (Flag1 ==1 && Flag2 ==1)//产生样本点
	{
		CreateS(point.x, point.y, PointNum, PointVec);//当前位置产生样本点

		CDC* pDC = GetDC();//先画出来，不刷新
		for (auto i = (PointVec.end() - PointNum); i != PointVec.end(); ++i)//只画最新产生的点
		{

			for (auto k = -1; k < 2; ++k)
			{
				for (auto j = -1; j < 2; ++j)
				{
					pDC->SetPixel((*i).first + k, (*i).second + j, RGB(0, 0, 0));
				}
			}
		}
	}
	if (Flag1 == 2 && Flag2 == 1)//产生训练点A
	{
		CreateS(point.x, point.y, PointNum, TrainPointVecA);//当前位置产生样本点

		CDC* pDC = GetDC();//先画出来，不刷新
		for (auto i = (TrainPointVecA.end() - PointNum); i != TrainPointVecA.end(); ++i)
		{

			for (auto k = -1; k < 2; ++k)
			{
				for (auto j = -1; j < 2; ++j)
				{
					pDC->SetPixel((*i).first + k, (*i).second + j, RGB(255, 0, 0));
				}
			}
		}
	}
	if (Flag1 == 3 && Flag2 == 1)//产生训练点B
	{
		CreateS(point.x, point.y, PointNum, TrainPointVecB);//当前位置产生样本点

		CDC* pDC = GetDC();//先画出来，不刷新
		for (auto i = (TrainPointVecB.end() - PointNum); i != TrainPointVecB.end(); ++i)
		{

			for (auto k = -1; k < 2; ++k)
			{
				for (auto j = -1; j < 2; ++j)
				{
					pDC->SetPixel((*i).first + k, (*i).second + j, RGB(0, 255, 0));
				}
			}
		}
	}
	CView::OnMouseMove(nFlags, point);
}


void C模式识别作业View::OnLButtonUp(UINT nFlags, CPoint point)
{
	if ((Flag2 == 1 && Flag1 == 1) || (Flag2 == 1 && Flag1 == 2) || (Flag2 == 1 && Flag1 == 3))
	{
		Flag2 = 0 ;
	}
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
}


void C模式识别作业View::OnRButtonDown(UINT nFlags, CPoint point)//右键按下 取消画图
{
	if (Flag1 == 1 || Flag1 == 2 || Flag1 == 3)
	{
		Flag1 = 0;
	}

	CView::OnRButtonDown(nFlags, point);
}


void C模式识别作业View::OnTrainpointcreate()
{
	Slider slider;
	if (IDOK == slider.DoModal())
	{
		PointNum = slider.Num;
		Flag1 = 2;//产生训练点flag
	}

}


void C模式识别作业View::OnShowall()
{
	DrawFlag = 0;
	Invalidate(TRUE);
	// TODO:  在此添加命令处理程序代码
}


void C模式识别作业View::OnShowpointvec()
{
	DrawFlag = 1;
	Invalidate(TRUE);
	// TODO:  在此添加命令处理程序代码
}


void C模式识别作业View::OnShowtrainpointvec()
{
	DrawFlag = 2;
	Invalidate(TRUE);
	// TODO:  在此添加命令处理程序代码
}


void C模式识别作业View::OnIdTrainpointcreateb()
{
	Slider slider;
	if (IDOK == slider.DoModal())
	{
		PointNum = slider.Num;
		Flag1 = 3;//产生训练点flag
	}
}

//感知器算法训练
void C模式识别作业View::OnPerceptrontrain()
{
	if (TrainPointVecA.empty()|| TrainPointVecB.empty())
	{
		MessageBox((LPCTSTR)CString("请先输入两个训练集！"));
		return;
	}

	if (W.empty())
	{
		W.push_back(1);
		W.push_back(0);
		W.push_back(-1000);
	}
	CDC* pDC = GetDC();

	while (1)
	{
		int flag=0;
		int sum=0;//迭代次数，用于不可分退出
		int step = 1+ 1000 * flag /(TrainPointVecA.size()+TrainPointVecB.size());
		auto i = 0, j = 0;
		double n;
		if (TrainPointVecA.size() > 3000 && TrainPointVecB.size() > 3000)//调节速度步长
		{
			 n = 2;
		}
		else if (TrainPointVecA.size() > 300 && TrainPointVecB.size() > 300)
		{
			n = 20;
		}else
		{
			 n = 500;
		}
		
		//for (; i < TrainPointVecA.size() && j < TrainPointVecB.size(); i += step ,j +=step )
		//{
		//	if ((TrainPointVecA[i]).first * W[0]+(TrainPointVecA[i]).second * W[1]+ W[2] <= 0)
		//	{
		//		W[0] += (TrainPointVecA[i]).first*n;
		//		W[1] += (TrainPointVecA[i]).second *n;
		//		W[2] += n;
		//		++ flag ;

		//	}
		//	if ((TrainPointVecB[j]).first * W[0] + (TrainPointVecB[j]).second * W[1] + W[2] >= 0)
		//	{
		//		W[0] -= (TrainPointVecB[j]).first * n;
		//		W[1] -= (TrainPointVecB[j]).second * n;
		//		W[2] -= n;
		//		 ++ flag;

		//	}

		//}

		for ( ; i < TrainPointVecA.size() ; ++i )
		{
			if ((TrainPointVecA[i]).first * W[0] + (TrainPointVecA[i]).second * W[1] + W[2] <= 0)
			{
				W[0] += (TrainPointVecA[i]).first * n/* * (double)abs((TrainPointVecA[i]).first * W[0] + (TrainPointVecA[i]).second * W[1] + W[2]) / (double)((TrainPointVecA[i]).first*(TrainPointVecA[i]).first + (TrainPointVecA[i]).second*(TrainPointVecA[i]).second+1)*/;
				W[1] += (TrainPointVecA[i]).second * n;
				W[2] += n * 300 ;
				++ flag;

			}
		}

		for (; j < TrainPointVecB.size(); ++j)
		{
			if ((TrainPointVecB[j]).first * W[0] + (TrainPointVecB[j]).second * W[1] + W[2] >= 0)
			{
				W[0] -= (TrainPointVecB[j]).first * n /** (double)abs((TrainPointVecB[i]).first * W[0] + (TrainPointVecB[i]).second * W[1] + W[2]) / (double)((TrainPointVecB[i]).first*(TrainPointVecB[i]).first + (TrainPointVecB[i]).second*(TrainPointVecB[i]).second + 1)*/;
				W[1] -= (TrainPointVecB[j]).second * n;
				W[2] -= n * 300;
				++flag;

			}
		}
	

		
		if (abs((W[0] / W[1])) >= 0.5)
		{
			for (auto y = 0; y < 1000; y += 20)
			{
				auto x = -(W[2]+y*W[1]) / W[0];
				pDC->SetPixel(x, y, RGB(0, 0, 255));
				pDC->SetPixel(x + 1, y + 1, RGB(0, 0, 255));
				pDC->SetPixel(x + 1, y, RGB(0, 0, 255));
				pDC->SetPixel(x, y + 1, RGB(0, 0, 255));
			}
		}
		else
		{
			for (auto x = 0; x < 2000; x += 50)
			{
				auto y = -(W[2] + x*W[0]) / W[1];
				pDC->SetPixel(x, y, RGB(0, 0, 255));
				pDC->SetPixel(x + 1, y + 1, RGB(0, 0, 255));
				pDC->SetPixel(x + 1, y, RGB(0, 0, 255));
				pDC->SetPixel(x, y + 1, RGB(0, 0, 255));
			}
		}

		
		++sum;
		if (sum > 2000)//判定线性不可分，强制退出
		{
			break;
		}
		if (flag == 0)
		{
			break;
		}


	}


	Invalidate(1);
	MessageBox((LPCTSTR)CString("训练完成！"));
	if (abs((W[0]/W[1])) >= 0.5 )
	{
		for (auto y = 0; y < 2000; y += 20)
		{
			auto x = -(W[2] + y*W[1]) / W[0];
			pDC->SetPixel(x, y, RGB(0, 0, 255));
			pDC->SetPixel(x + 1, y + 1, RGB(0, 0, 255));
			pDC->SetPixel(x + 1, y, RGB(0, 0, 255));
			pDC->SetPixel(x, y + 1, RGB(0, 0, 255));
		}
	}
	else
	{
		for (auto x = 0; x < 2000; x += 20)
		{
			auto y = -(W[2] + x*W[0]) / W[1];
			pDC->SetPixel(x, y, RGB(0, 0, 255));
			pDC->SetPixel(x + 1, y + 1, RGB(0, 0, 255));
			pDC->SetPixel(x + 1, y, RGB(0, 0, 255));
			pDC->SetPixel(x, y + 1, RGB(0, 0, 255));
		}
	}

}


void C模式识别作业View::OnPerceptrontest()
{
	if (W.empty())
	{
		MessageBox((LPCTSTR)CString("请先进行训练！"));
		return;
	}
	if (PointVec.empty())
	{
		MessageBox((LPCTSTR)CString("样本集为空！"));
		return;
	}
	CDC* pDC = GetDC();//先画出来，不刷新

	if (abs((W[0] / W[1])) >= 0.5)//画出分界线
	{
		for (auto y = 0; y < 2000; y += 20)
		{
			auto x = -(W[2] + y*W[1]) / W[0];
			pDC->SetPixel(x, y, RGB(0, 0, 255));
			pDC->SetPixel(x + 1, y + 1, RGB(0, 0, 255));
			pDC->SetPixel(x + 1, y, RGB(0, 0, 255));
			pDC->SetPixel(x, y + 1, RGB(0, 0, 255));
		}
	}
	else
	{
		for (auto x = 0; x < 2000; x += 20)
		{
			auto y = -(W[2] + x*W[0]) / W[1];
			pDC->SetPixel(x, y, RGB(0, 0, 255));
			pDC->SetPixel(x + 1, y + 1, RGB(0, 0, 255));
			pDC->SetPixel(x + 1, y, RGB(0, 0, 255));
			pDC->SetPixel(x, y + 1, RGB(0, 0, 255));
		}
	}

	for (auto i : PointVec)//画出样本点
	{
		if (i.first * W[0] + i.second * W[1] + W[2] > 0)//A	
		{
			
				for (auto k = -1; k < 2; ++k)
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(255, 0, 0));
					}
				}

		}
		else//B
		{

			for (auto k = -1; k < 2; ++k)
			{
				for (auto j = -1; j < 2; ++j)
				{
					pDC->SetPixel(i.first + k, i.second + j, RGB(0,255, 0));
				}
			}

		}
	}
}


void C模式识别作业View::OnEmptytrainpointa()
{
	TrainPointVecA.clear();
	Invalidate(1);
}


void C模式识别作业View::OnEmptytrainpointb()
{
	TrainPointVecB.clear();
	Invalidate(1);
}


void C模式识别作业View::OnEmptytrainpoint()
{
	TrainPointVecA.clear();
	TrainPointVecB.clear();
	Invalidate(1);
}

//LM算法训练函数
void C模式识别作业View::OnLmstrain()
{
	// TODO:  在此添加命令处理程序代码
}

//神经训练函数
void C模式识别作业View::OnNeurontrain()
{
	if (TrainPointVecA.empty() || TrainPointVecB.empty() )//没有输入训练集!
	{
		MessageBox((LPCTSTR)CString("请先输入训练集！"));
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	//归一化 存储于TrainPointVecAtmp Btmp 中
	double minX, maxX, minY, maxY, tmpxy;
	//A最大最小值
	minX = (*std::min_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	maxX = (*std::max_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	minY = (*std::min_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	maxY = (*std::max_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	//算上B 的最大最小值
	tmpxy = (*std::min_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	minX = tmpxy > minX ? minX : tmpxy;
	tmpxy = (*std::max_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	maxX = tmpxy < minX ? minX : tmpxy;
	tmpxy = (*std::min_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	minY = tmpxy > minY ? minY : tmpxy;
	tmpxy = (*std::max_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	maxY = tmpxy < maxY ? maxY : tmpxy;
	if (!PointVec.empty())
	{
		//算上测试样本的最大值最小值
		tmpxy = (*std::min_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
		minX = tmpxy > minX ? minX : tmpxy;
		tmpxy = (*std::max_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
		maxX = tmpxy < minX ? minX : tmpxy;
		tmpxy = (*std::min_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
		minY = tmpxy > minY ? minY : tmpxy;
		tmpxy = (*std::max_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
		maxY = tmpxy < maxY ? maxY : tmpxy;
	}
	

	vector<pair<double, double>> TrainPointVecAtmp;
	vector<pair<double, double>> TrainPointVecBtmp;

	for (auto &i:TrainPointVecA)
	{
		TrainPointVecAtmp.push_back(make_pair((double)(i.first - minX) / (double)(maxX - minX), (double)(i.second - minY) / (double)(maxY - minY)));
	}
	for (auto &i : TrainPointVecB)
	{
		TrainPointVecBtmp.push_back(make_pair((double)(i.first - minX) / (double)(maxX - minX), (double)(i.second - minY) / (double)(maxY - minY)));
	}

	NeuralLayer dlg;
	int LayerArry[3]; 

	if (!(VecBias.empty() || VecWeight.empty()))//训练过,清空
	{
		VecIn.clear();
		VecOut.clear();
		VecBias.clear();
		VecError.clear();
		VecWeight.clear();
	}

	if (IDOK == dlg.DoModal())//点确定
	{
		for (auto i = 0; i < 3; ++i)//暂时只有三层
		{
			VecIn.push_back(vector<double>());
			VecOut.push_back(vector<double>());
			VecBias.push_back(vector<double>());
			VecError.push_back(vector<double>());
			VecWeight.push_back(vector<vector<double>>());
		}

		LayerArry[0]= dlg.FirstLayer;
		LayerArry[1] = dlg.SecondLayer;
		LayerArry[2] = dlg.ThridLayer;
		
		for (auto k = 0; k < 3; ++k)//共三层
		{
			for (auto i = 0; i < LayerArry[k]; ++i)
			{
				VecIn[k].push_back(0);
				VecOut[k].push_back(0);
				VecWeight[k].push_back(vector<double>());
				VecBias[k].push_back(0.2);//偏置也是，不能相等
				VecError[k].push_back(0);
			}
			if (k != 3) //输出层向后的权值为空
			{
				for (auto i = 0; i < LayerArry[k + 1]; ++i)
				{
					for (auto j = 0; j < LayerArry[k]; ++j)
					{
						VecWeight[k][j].push_back(  0.1 ); //权值 必须随机不能相等-1—1
					}
				}
			}

		}
	}
	else {		//点取消
		return;
	}
	
	CDC* pDC = GetDC();
	double runtime = 0.4;//迭代次数:改为固定学籍率
	int layer = 3;	//神经层数
	double ErrorFlag = 1; //发生分类错误Flag
	/*激活函数 ActivationFuntion();*/
	int T;					//当前训练集的正确结果 A:1 ; B:0
	int boom=5000;			//强制跳出循环  
	while (ErrorFlag == 1 )
	{
		ErrorFlag = 0;		//0 ：Falg标识当前无错误发生
		if (--boom < 0)
		{
			break;
		}
//		++runtime;			//迭代次数
		for (auto & X : TrainPointVecAtmp)//对集合Atmp处理
		{
			//////////////////////////////////////////////////////////////////////////
			//输入 输出 误差 清零
			for (auto k = 0; k < 3; ++k)//共三层
			{
				for (auto i = 0; i < LayerArry[k]; ++i)
				{
					VecIn[k][i] = 0;
					VecOut[k][i] = 0;
					VecError[k][i] = 0;
				}
			}
			/////////////////////////////////////////////////////////////////////////
			T = 1;			// A 的正确输出结果为 1
			////////////////////////////////////////////////////////////////////////
			//计算输入输出
			VecIn[0][0] =(double) X.first;//输入层
			VecIn[0][1] = (double)X.second;
			VecOut[0][0] = (double)X.first;
			VecOut[0][1] = (double)X.second; //输入层输入等于输出
			//对所有其他层计算输出
			for (auto clayer = 1; clayer < layer; ++clayer) //clayer: Current Layer :0 1 2 ...layer-1
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)
				{
					for (auto k = 0; k < VecIn[clayer - 1].size();++k)	//前一层的输出乘 权值
					{
						VecIn[clayer][i] += VecOut[clayer - 1][k] * VecWeight[clayer - 1][k][i];
					}
					VecIn[clayer][i] += VecBias[clayer][i];				//加上偏置

					VecOut[clayer][i] = ActivationFuntion(VecIn[clayer][i]);
					auto tmp = VecOut[clayer][i];
					tmp = 0;
				}
			}
			//////////////////////////////////////////////////////////////////////////
			//计算误差
			auto Q = VecOut[layer-1][0];//最终的输出
			VecError[layer - 1][0] = (Q)*(1 - Q)*(T - Q); //输出层的误差
			//对所有其他层计算误差 //输入层不用计算误差 ：输入等于输出
			for (auto clayer = 1; clayer < layer - 1;++clayer)
			{
				for (auto i = 0; i < VecIn[clayer].size() ; ++i)
				{
					auto Q   = VecOut[clayer][i];
					double WErr=0;// W*Error
					for (auto j = 0; j < VecIn[clayer + 1].size();++j)
					{
						WErr += VecError[clayer + 1][j] * VecWeight[clayer][i][j];
					}
					VecError[clayer][i] = (Q )*(1 - Q)*WErr;
				}
			}
			//////////////////////////////////////////////////////////////////////////
			//更新权重:输出层不用更新权值
			for (auto clayer = 0; clayer < layer - 1;++clayer)//对每一层
			{
				for (auto i = 0; i < VecIn[clayer].size();++i)//对每一个节点
				{
					for (auto j = 0; j < VecIn[clayer + 1].size();++j)//对每一个权重ij
					{
						auto tmp = VecOut[clayer][i] * VecError[clayer + 1][j] * (double)runtime;
						VecWeight[clayer][i][j] += tmp;
						tmp = VecWeight[clayer][i][j];
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////
			//更新偏置:输入层不用更新偏置
			for (auto clayer = 1; clayer < layer;++clayer)//对每一层
			{
				for (auto i = 0; i < VecIn[clayer].size();++i)//对每一个偏置
				{
					auto tmp = VecError[clayer][i] * (double)runtime;
					VecBias[clayer][i] += tmp;
				}
			}

			if (VecOut[layer-1][0] < 0.8)
			{
				//ErrorFlag = VecOut[layer - 1][0];
				ErrorFlag = 1;//错误判断 立Flag
			}
		}//A全部处理结束

////////////////////////////////////////////////////////////////////////////
		////显示
		//CDC* pDC = GetDC();
		//Invalidate(TRUE);
		//pDC->TextOut(100 - 100, 200, CString(to_string(VecIn[0][0]).c_str()));
		//pDC->TextOut(100 - 100, 400, CString(to_string(VecIn[0][1]).c_str()));
		//pDC->TextOut(600 - 100, 100, CString(to_string(VecIn[1][0]).c_str()));
		//pDC->TextOut(600 - 100, 300, CString(to_string(VecIn[1][1]).c_str()));
		////	pDC->TextOut(600 - 100, 500, CString(to_string(VecIn[1][2]).c_str()));
		//pDC->TextOut(1200 - 100, 300, CString(to_string(VecIn[2][0]).c_str()));
		//pDC->TextOut(100, 200 + 20, CString(to_string(VecError[0][0]).c_str()));
		//pDC->TextOut(100, 400 + 20, CString(to_string(VecError[0][1]).c_str()));
		//pDC->TextOut(600, 100 + 20, CString(to_string(VecError[1][0]).c_str()));
		//pDC->TextOut(600, 300 + 20, CString(to_string(VecError[1][1]).c_str()));
		////	pDC->TextOut(600, 500 + 20, CString(to_string(VecError[1][2]).c_str()));
		//pDC->TextOut(1200, 300 + 20, CString(to_string(VecError[2][0]).c_str()));
		//pDC->TextOut(100, 200 - 20, CString(to_string(VecBias[0][0]).c_str()));
		//pDC->TextOut(100, 400 - 20, CString(to_string(VecBias[0][1]).c_str()));
		//pDC->TextOut(600, 100 - 20, CString(to_string(VecBias[1][0]).c_str()));
		//pDC->TextOut(600, 300 - 20, CString(to_string(VecBias[1][1]).c_str()));
		////	pDC->TextOut(600, 500 - 20, CString(to_string(VecBias[1][2]).c_str()));
		//pDC->TextOut(1200, 300 - 20, CString(to_string(VecBias[2][0]).c_str()));
		//pDC->TextOut(100 + 80, 200, CString(to_string(VecOut[0][0]).c_str()));
		//pDC->TextOut(100 + 80, 400, CString(to_string(VecOut[0][1]).c_str()));
		//pDC->TextOut(600 + 80, 100, CString(to_string(VecOut[1][0]).c_str()));
		//pDC->TextOut(600 + 80, 300, CString(to_string(VecOut[1][1]).c_str()));
		////	pDC->TextOut(600 + 80, 500, CString(to_string(VecOut[1][2]).c_str()));
		//pDC->TextOut(1200 + 80, 300, CString(to_string(VecOut[2][0]).c_str()));
		//pDC->TextOut(100 + 200, 200 - 40, CString(to_string(VecWeight[0][0][0]).c_str()));
		//pDC->TextOut(100 + 200, 200, CString(to_string(VecWeight[0][0][1]).c_str()));
		////	pDC->TextOut(100 + 200, 200 +40, CString(to_string(VecWeight[0][0][2]).c_str()));
		//pDC->TextOut(100 + 200, 400 - 40, CString(to_string(VecWeight[0][1][0]).c_str()));
		//pDC->TextOut(100 + 200, 400, CString(to_string(VecWeight[0][1][1]).c_str()));
		////	pDC->TextOut(100 + 200, 400 + 40,  CString(to_string(VecWeight[0][1][2]).c_str()));
		//pDC->TextOut(600 + 200, 100, CString(to_string(VecWeight[1][0][0]).c_str()));
		//pDC->TextOut(600 + 200, 300, CString(to_string(VecWeight[1][1][0]).c_str()));
		////	pDC->TextOut(600 + 200, 500, CString(to_string(VecWeight[1][2][0]).c_str()));
////////////////////////////////////////////////////////////////////////////

		for (auto & X : TrainPointVecBtmp)//对集合Btmp处理
		{
			//////////////////////////////////////////////////////////////////////////
			//输入 输出 误差 清零
			for (auto k = 0; k < 3; ++k)//共三层
			{
				for (auto i = 0; i < LayerArry[k]; ++i)
				{
					VecIn[k][i] = 0;
					VecOut[k][i] = 0;
					VecError[k][i] = 0;
				}
			}
			/////////////////////////////////////////////////////////////////////////
			T = 0;			// B 的正确输出结果为0
			////////////////////////////////////////////////////////////////////////
			//计算输入输出
			VecIn[0][0] = (double)X.first;//输入层
			VecIn[0][1] = (double)X.second;
			VecOut[0][0] = (double)X.first;
			VecOut[0][1] = (double)X.second; //输入层输入等于输出
			//对所有其他层计算输出
			for (auto clayer = 1; clayer < layer; ++clayer) //clayer: Current Layer :0 1 2 ...layer-1
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)
				{
					for (auto k = 0; k < VecIn[clayer - 1].size(); ++k)	//前一层的输出乘 权值
					{
						VecIn[clayer][i] += VecOut[clayer - 1][k] * VecWeight[clayer - 1][k][i];
					}
					VecIn[clayer][i] += VecBias[clayer][i];				//加上偏置

					VecOut[clayer][i] = ActivationFuntion(VecIn[clayer][i]);
					auto tmp = VecOut[clayer][i];
					tmp = 0;
				}
			}
			//////////////////////////////////////////////////////////////////////////
			//计算误差
			auto Q = VecOut[layer - 1][0];//最终的输出
			VecError[layer - 1][0] = (Q)*(1 - Q)*(T - Q); //输出层的误差
			//对所有其他层计算误差 //输入层不用计算误差 ：输入等于输出
			for (auto clayer = 1; clayer < layer - 1; ++clayer)
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)
				{
					auto Q = VecOut[clayer][i];
					double WErr = 0;// W*Error
					for (auto j = 0; j < VecIn[clayer + 1].size(); ++j)
					{
						WErr += VecError[clayer + 1][j] * VecWeight[clayer][i][j];
					}
					VecError[clayer][i] = (Q)*(1 - Q)*WErr;
				}
			}
			//////////////////////////////////////////////////////////////////////////
			//更新权重:输出层不用更新权值
			for (auto clayer = 0; clayer < layer - 1; ++clayer)//对每一层
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)//对每一个节点
				{
					for (auto j = 0; j < VecIn[clayer + 1].size(); ++j)//对每一个权重ij
					{
						auto tmp = VecOut[clayer][i] * VecError[clayer + 1][j] * (double)runtime;
						VecWeight[clayer][i][j] += tmp;
						tmp = VecWeight[clayer][i][j];
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////
			//更新偏置:输入层不用更新偏置
			for (auto clayer = 1; clayer < layer; ++clayer)//对每一层
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)//对每一个偏置
				{
					auto tmp = VecError[clayer][i] * (double)runtime;
					VecBias[clayer][i] += tmp;
				}
			}

			if (VecOut[layer - 1][0] > 0.2)
			{
				//ErrorFlag = VecOut[layer - 1][0];
				ErrorFlag = 1;//错误判断 立Flag
			}
		}//B全部处理结束

		//显示权重
		Invalidate(TRUE);
		int N = 100;
		pDC->TextOut(100, 200, CString(_T("权重:")));
		for (auto clayer = 0; clayer < layer; ++clayer)
		{
			for (auto j = 0; j < VecIn[clayer].size(); ++j)
			{
				for (auto i = 0; i < VecWeight[clayer][j].size(); ++i)
				{
					pDC->TextOut(200 + clayer * 2 * N, 200 + i*N + j*VecWeight[clayer][j].size()*N, CString(to_string(VecWeight[clayer][j][i]).c_str()));
				}
			}
		}



	}//while循环结束

	if (boom < 1)
	{
		MessageBox(_T("训练强制退出！"));
	}
	else
	{
		MessageBox(_T("神经网络训练完成！"));
	}

	Invalidate(TRUE);
	int N = 100;
	pDC->TextOut(100, 200, CString(_T("权重:")));
	for (auto clayer = 0; clayer < layer ; ++clayer)
	{
		for (auto j = 0; j < VecIn[clayer].size(); ++j)
		{
			for (auto i = 0; i < VecWeight[clayer][j].size(); ++i)
			{
				pDC->TextOut(200 + clayer * 2 * N,200+ i*N + j*VecWeight[clayer][j].size()*N, CString(to_string(VecWeight[clayer][j][i]).c_str()));
			}
		}
	}
}



//神经测试函数
void C模式识别作业View::OnNeurontest()
{
	if ( PointVec.empty())//没有样本集
	{
		MessageBox((LPCTSTR)CString("请先产生样本集！"));
		return;
	}
	if (TrainPointVecA.empty() || TrainPointVecB.empty())//没有训练集
	{
		MessageBox((LPCTSTR)CString("请先训练集！"));
		return;
	}
	
	if (VecWeight.empty() || VecBias.empty() || PointVec.empty())//没有训练
	{
		MessageBox((LPCTSTR)CString("请先进行网络训练！"));
		return;
	}
	CDC* pDC = GetDC();
	int layer = 3;


	double minX,maxX,minY,maxY,tmpxy;
	//A最大最小值
	minX = (*std::min_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first<b.first; })).first;
	maxX = (*std::max_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first<b.first; })).first;
	minY = (*std::min_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second<b.second; })).first;
	maxY = (*std::max_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second<b.second; })).first;
	//算上B 的最大最小值
	tmpxy = (*std::min_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	minX  = tmpxy > minX ? minX : tmpxy;
	tmpxy = (*std::max_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	maxX  = tmpxy < minX ? minX : tmpxy;
	tmpxy = (*std::min_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	minY  = tmpxy > minY ? minY : tmpxy;
	tmpxy = (*std::max_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second<b.second; })).first;
	maxY  = tmpxy < maxY ? maxY : tmpxy;
	//算上测试样本的最大值最小值
	tmpxy = (*std::min_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	minX = tmpxy > minX ? minX : tmpxy;
	tmpxy = (*std::max_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	maxX = tmpxy < minX ? minX : tmpxy;
	tmpxy = (*std::min_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	minY = tmpxy > minY ? minY : tmpxy;
	tmpxy = (*std::max_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	maxY = tmpxy < maxY ? maxY : tmpxy;

	vector<pair<double, double>> PointVectmp;//临时vec
	for (auto &i : PointVec)
	{
		PointVectmp.push_back(make_pair((double)(i.first - minX) / (double)(maxX - minX), (double)(i.second - minY) / (double)(maxY - minY)));
	}
	
	for (auto &X : PointVectmp)
	{
		//////////////////////////////////////////////////////////////////////////
		//清零
		for (auto k = 0; k < 3; ++k)//共三层
		{
			for (auto i = 0; i < VecIn[k].size(); ++i)
			{
				VecIn[k][i] = 0;
				VecOut[k][i] = 0;
				VecError[k][i] = 0;
			}
		}

		////////////////////////////////////////////////////////////////////////
		//计算输入输出
		VecIn[0][0] = (double)X.first;//输入层
		VecIn[0][1] = (double)X.second;
		VecOut[0][0] = (double)X.first;
		VecOut[0][1] = (double)X.second; //输入层输入等于输出
		//对所有其他层计算输出
		for (auto clayer = 1; clayer < layer; ++clayer) //clayer: Current Layer :0 1 2 ...layer-1
		{
			for (auto i = 0; i < VecIn[clayer].size(); ++i)
			{
				for (auto k = 0; k < VecIn[clayer - 1].size(); ++k)	//前一层的输出乘 权值
				{
					VecIn[clayer][i] += VecOut[clayer - 1][k] * VecWeight[clayer - 1][k][i];
				}
				VecIn[clayer][i] += VecBias[clayer][i];				//加上偏置

				VecOut[clayer][i] = ActivationFuntion(VecIn[clayer][i]);
			}
		}
		//分类
		if (VecOut[2][0] >0.5)
		{
			for (auto k = -1; k < 2; ++k)
			{
				for (auto j = -1; j < 2; ++j)
				{
					pDC->SetPixel(X.first*(maxX-minX)+minX + k, X.second*(maxY-minY)+minY + j, RGB(255, 0, 0));
				}
			}
		}else
			if (VecOut[2][0] < 0.5)
			{
				for (auto k = -1; k < 2; ++k)
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(X.first*(maxX - minX) +minX+ k, X.second *(maxY - minY)+minY + j, RGB(0, 255, 0));
					}
				}
			}



	}
	// TODO:  在此添加命令处理程序代码
}


void C模式识别作业View::OnEmptypointvec()
{
	PointVec.clear();
	Invalidate(TRUE);
	// TODO:  在此添加命令处理程序代码
}
