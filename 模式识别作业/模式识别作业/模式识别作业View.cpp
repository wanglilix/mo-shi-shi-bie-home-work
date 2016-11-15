
// ģʽʶ����ҵView.cpp : Cģʽʶ����ҵView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ģʽʶ����ҵ.h"
#endif



#include "ģʽʶ����ҵDoc.h"
#include "ģʽʶ����ҵView.h"

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


// Cģʽʶ����ҵView

IMPLEMENT_DYNCREATE(Cģʽʶ����ҵView, CView)

BEGIN_MESSAGE_MAP(Cģʽʶ����ҵView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_GaussianDistribution, &Cģʽʶ����ҵView::OnGaussiandistribution)
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_TrainPointCreate, &Cģʽʶ����ҵView::OnTrainpointcreate)
	ON_COMMAND(ID_ShowAll, &Cģʽʶ����ҵView::OnShowall)
	ON_COMMAND(ID_ShowPointVec, &Cģʽʶ����ҵView::OnShowpointvec)
	ON_COMMAND(ID_ShowTrainPointVec, &Cģʽʶ����ҵView::OnShowtrainpointvec)
	ON_COMMAND(ID_ID_TrainPointCreateB, &Cģʽʶ����ҵView::OnIdTrainpointcreateb)
	ON_COMMAND(ID_PerceptronTrain, &Cģʽʶ����ҵView::OnPerceptrontrain)
	ON_COMMAND(ID_PerceptronTest, &Cģʽʶ����ҵView::OnPerceptrontest)
	ON_COMMAND(ID_EmptyTrainPointA, &Cģʽʶ����ҵView::OnEmptytrainpointa)
	ON_COMMAND(ID_EmptyTrainPointB, &Cģʽʶ����ҵView::OnEmptytrainpointb)
	ON_COMMAND(ID_EmptyTrainPoint, &Cģʽʶ����ҵView::OnEmptytrainpoint)
	ON_COMMAND(ID_LMSTrain, &Cģʽʶ����ҵView::OnLmstrain)
	ON_COMMAND(ID_NeuronTrain, &Cģʽʶ����ҵView::OnNeurontrain)
	ON_COMMAND(ID_NeuronTest, &Cģʽʶ����ҵView::OnNeurontest)
	ON_COMMAND(ID_EmptyPointVec, &Cģʽʶ����ҵView::OnEmptypointvec)
END_MESSAGE_MAP()

// Cģʽʶ����ҵView ����/����

Cģʽʶ����ҵView::Cģʽʶ����ҵView()
: PointNum(0)
, Flag1(0)
, Flag2(0)
, DrawFlag(0)
{
	// TODO:  �ڴ˴���ӹ������

}

Cģʽʶ����ҵView::~Cģʽʶ����ҵView()
{
}

BOOL Cģʽʶ����ҵView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cģʽʶ����ҵView ����

void Cģʽʶ����ҵView::OnDraw(CDC* pDC)
{
	Cģʽʶ����ҵDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	CRect   rect1;
	GetClientRect(rect1);
	pDC->FillSolidRect(rect1, RGB(255, 255,255));

	//���е���ͼ
	if (DrawFlag == 0)
	{
			for (auto i : PointVec)
			{
				for (auto k = -1; k < 2; ++k)//���Ÿ���
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(0, 0, 0));
					}
				}
			}
			for (auto i : TrainPointVecA)
			{
				for (auto k = -1; k < 2; ++k)//���Ÿ���
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(255, 0, 0));
					}
				}
			}
			for (auto i : TrainPointVecB)
			{
				for (auto k = -1; k < 2; ++k)//���Ÿ���
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(0, 255, 0));
					}
				}
			}
	}
	else if (DrawFlag == 1 )//��ʾ������
	{
			for (auto i : PointVec)
			{
				for (auto k = -1; k < 2; ++k)//���Ÿ���
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
				for (auto k = -1; k < 2; ++k)//���Ÿ���
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(255, 0, 0));
					}
				}
			}
			for (auto i : TrainPointVecB)
			{
				for (auto k = -1; k < 2; ++k)//���Ÿ���
				{
					for (auto j = -1; j < 2; ++j)
					{
						pDC->SetPixel(i.first + k, i.second + j, RGB(0, 255, 0));
					}
				}
			}
	}
		



}


// Cģʽʶ����ҵView ��ӡ

BOOL Cģʽʶ����ҵView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cģʽʶ����ҵView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cģʽʶ����ҵView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cģʽʶ����ҵView ���

#ifdef _DEBUG
void Cģʽʶ����ҵView::AssertValid() const
{
	CView::AssertValid();
}

void Cģʽʶ����ҵView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cģʽʶ����ҵDoc* Cģʽʶ����ҵView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cģʽʶ����ҵDoc)));
	return (Cģʽʶ����ҵDoc*)m_pDocument;
}
#endif //_DEBUG


// Cģʽʶ����ҵView ��Ϣ�������


void Cģʽʶ����ҵView::OnGaussiandistribution()//���������㺯��
{
	Slider slider;
	if (IDOK == slider.DoModal())
	{
		PointNum = slider.Num;
		Flag1 = 1;//����������flag
	}

}


void Cģʽʶ����ҵView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnRButtonDblClk(nFlags, point);
}


void Cģʽʶ����ҵView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (Flag1 ==1)
	{
		Flag2 = 1;  //�������flag
		CreateS(point.x, point.y, PointNum, PointVec);//��ǰλ�ò���������

		CDC* pDC = GetDC();//�Ȼ���������ˢ��
		for (auto i = (PointVec.end()-PointNum); i != PointVec.end(); ++i)//ֻ�����²����ĵ�
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
	if (Flag1 == 2)//ѵ������
	{
		Flag2 = 1;  //�������flag
		CreateS(point.x, point.y, PointNum, TrainPointVecA);//��ǰλ�ò���������

		CDC* pDC = GetDC();//�Ȼ���������ˢ��
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
	if (Flag1 == 3)//ѵ������
	{
		Flag2 = 1;  //�������flag
		CreateS(point.x, point.y, PointNum, TrainPointVecB);//��ǰλ�ò���������

		CDC* pDC = GetDC();//�Ȼ���������ˢ��
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


void Cģʽʶ����ҵView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	if (Flag1 ==1 && Flag2 ==1)//����������
	{
		CreateS(point.x, point.y, PointNum, PointVec);//��ǰλ�ò���������

		CDC* pDC = GetDC();//�Ȼ���������ˢ��
		for (auto i = (PointVec.end() - PointNum); i != PointVec.end(); ++i)//ֻ�����²����ĵ�
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
	if (Flag1 == 2 && Flag2 == 1)//����ѵ����A
	{
		CreateS(point.x, point.y, PointNum, TrainPointVecA);//��ǰλ�ò���������

		CDC* pDC = GetDC();//�Ȼ���������ˢ��
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
	if (Flag1 == 3 && Flag2 == 1)//����ѵ����B
	{
		CreateS(point.x, point.y, PointNum, TrainPointVecB);//��ǰλ�ò���������

		CDC* pDC = GetDC();//�Ȼ���������ˢ��
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


void Cģʽʶ����ҵView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if ((Flag2 == 1 && Flag1 == 1) || (Flag2 == 1 && Flag1 == 2) || (Flag2 == 1 && Flag1 == 3))
	{
		Flag2 = 0 ;
	}
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonUp(nFlags, point);
}


void Cģʽʶ����ҵView::OnRButtonDown(UINT nFlags, CPoint point)//�Ҽ����� ȡ����ͼ
{
	if (Flag1 == 1 || Flag1 == 2 || Flag1 == 3)
	{
		Flag1 = 0;
	}

	CView::OnRButtonDown(nFlags, point);
}


void Cģʽʶ����ҵView::OnTrainpointcreate()
{
	Slider slider;
	if (IDOK == slider.DoModal())
	{
		PointNum = slider.Num;
		Flag1 = 2;//����ѵ����flag
	}

}


void Cģʽʶ����ҵView::OnShowall()
{
	DrawFlag = 0;
	Invalidate(TRUE);
	// TODO:  �ڴ���������������
}


void Cģʽʶ����ҵView::OnShowpointvec()
{
	DrawFlag = 1;
	Invalidate(TRUE);
	// TODO:  �ڴ���������������
}


void Cģʽʶ����ҵView::OnShowtrainpointvec()
{
	DrawFlag = 2;
	Invalidate(TRUE);
	// TODO:  �ڴ���������������
}


void Cģʽʶ����ҵView::OnIdTrainpointcreateb()
{
	Slider slider;
	if (IDOK == slider.DoModal())
	{
		PointNum = slider.Num;
		Flag1 = 3;//����ѵ����flag
	}
}

//��֪���㷨ѵ��
void Cģʽʶ����ҵView::OnPerceptrontrain()
{
	if (TrainPointVecA.empty()|| TrainPointVecB.empty())
	{
		MessageBox((LPCTSTR)CString("������������ѵ������"));
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
		int sum=0;//�������������ڲ��ɷ��˳�
		int step = 1+ 1000 * flag /(TrainPointVecA.size()+TrainPointVecB.size());
		auto i = 0, j = 0;
		double n;
		if (TrainPointVecA.size() > 3000 && TrainPointVecB.size() > 3000)//�����ٶȲ���
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
		if (sum > 2000)//�ж����Բ��ɷ֣�ǿ���˳�
		{
			break;
		}
		if (flag == 0)
		{
			break;
		}


	}


	Invalidate(1);
	MessageBox((LPCTSTR)CString("ѵ����ɣ�"));
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


void Cģʽʶ����ҵView::OnPerceptrontest()
{
	if (W.empty())
	{
		MessageBox((LPCTSTR)CString("���Ƚ���ѵ����"));
		return;
	}
	if (PointVec.empty())
	{
		MessageBox((LPCTSTR)CString("������Ϊ�գ�"));
		return;
	}
	CDC* pDC = GetDC();//�Ȼ���������ˢ��

	if (abs((W[0] / W[1])) >= 0.5)//�����ֽ���
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

	for (auto i : PointVec)//����������
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


void Cģʽʶ����ҵView::OnEmptytrainpointa()
{
	TrainPointVecA.clear();
	Invalidate(1);
}


void Cģʽʶ����ҵView::OnEmptytrainpointb()
{
	TrainPointVecB.clear();
	Invalidate(1);
}


void Cģʽʶ����ҵView::OnEmptytrainpoint()
{
	TrainPointVecA.clear();
	TrainPointVecB.clear();
	Invalidate(1);
}

//LM�㷨ѵ������
void Cģʽʶ����ҵView::OnLmstrain()
{
	// TODO:  �ڴ���������������
}

//��ѵ������
void Cģʽʶ����ҵView::OnNeurontrain()
{
	if (TrainPointVecA.empty() || TrainPointVecB.empty() )//û������ѵ����!
	{
		MessageBox((LPCTSTR)CString("��������ѵ������"));
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	//��һ�� �洢��TrainPointVecAtmp Btmp ��
	double minX, maxX, minY, maxY, tmpxy;
	//A�����Сֵ
	minX = (*std::min_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	maxX = (*std::max_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	minY = (*std::min_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	maxY = (*std::max_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	//����B �������Сֵ
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
		//���ϲ������������ֵ��Сֵ
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

	if (!(VecBias.empty() || VecWeight.empty()))//ѵ����,���
	{
		VecIn.clear();
		VecOut.clear();
		VecBias.clear();
		VecError.clear();
		VecWeight.clear();
	}

	if (IDOK == dlg.DoModal())//��ȷ��
	{
		for (auto i = 0; i < 3; ++i)//��ʱֻ������
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
		
		for (auto k = 0; k < 3; ++k)//������
		{
			for (auto i = 0; i < LayerArry[k]; ++i)
			{
				VecIn[k].push_back(0);
				VecOut[k].push_back(0);
				VecWeight[k].push_back(vector<double>());
				VecBias[k].push_back(0.2);//ƫ��Ҳ�ǣ��������
				VecError[k].push_back(0);
			}
			if (k != 3) //���������ȨֵΪ��
			{
				for (auto i = 0; i < LayerArry[k + 1]; ++i)
				{
					for (auto j = 0; j < LayerArry[k]; ++j)
					{
						VecWeight[k][j].push_back(  0.1 ); //Ȩֵ ��������������-1��1
					}
				}
			}

		}
	}
	else {		//��ȡ��
		return;
	}
	
	CDC* pDC = GetDC();
	double runtime = 0.4;//��������:��Ϊ�̶�ѧ����
	int layer = 3;	//�񾭲���
	double ErrorFlag = 1; //�����������Flag
	/*����� ActivationFuntion();*/
	int T;					//��ǰѵ��������ȷ��� A:1 ; B:0
	int boom=5000;			//ǿ������ѭ��  
	while (ErrorFlag == 1 )
	{
		ErrorFlag = 0;		//0 ��Falg��ʶ��ǰ�޴�����
		if (--boom < 0)
		{
			break;
		}
//		++runtime;			//��������
		for (auto & X : TrainPointVecAtmp)//�Լ���Atmp����
		{
			//////////////////////////////////////////////////////////////////////////
			//���� ��� ��� ����
			for (auto k = 0; k < 3; ++k)//������
			{
				for (auto i = 0; i < LayerArry[k]; ++i)
				{
					VecIn[k][i] = 0;
					VecOut[k][i] = 0;
					VecError[k][i] = 0;
				}
			}
			/////////////////////////////////////////////////////////////////////////
			T = 1;			// A ����ȷ������Ϊ 1
			////////////////////////////////////////////////////////////////////////
			//�����������
			VecIn[0][0] =(double) X.first;//�����
			VecIn[0][1] = (double)X.second;
			VecOut[0][0] = (double)X.first;
			VecOut[0][1] = (double)X.second; //���������������
			//������������������
			for (auto clayer = 1; clayer < layer; ++clayer) //clayer: Current Layer :0 1 2 ...layer-1
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)
				{
					for (auto k = 0; k < VecIn[clayer - 1].size();++k)	//ǰһ�������� Ȩֵ
					{
						VecIn[clayer][i] += VecOut[clayer - 1][k] * VecWeight[clayer - 1][k][i];
					}
					VecIn[clayer][i] += VecBias[clayer][i];				//����ƫ��

					VecOut[clayer][i] = ActivationFuntion(VecIn[clayer][i]);
					auto tmp = VecOut[clayer][i];
					tmp = 0;
				}
			}
			//////////////////////////////////////////////////////////////////////////
			//�������
			auto Q = VecOut[layer-1][0];//���յ����
			VecError[layer - 1][0] = (Q)*(1 - Q)*(T - Q); //���������
			//������������������ //����㲻�ü������ ������������
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
			//����Ȩ��:����㲻�ø���Ȩֵ
			for (auto clayer = 0; clayer < layer - 1;++clayer)//��ÿһ��
			{
				for (auto i = 0; i < VecIn[clayer].size();++i)//��ÿһ���ڵ�
				{
					for (auto j = 0; j < VecIn[clayer + 1].size();++j)//��ÿһ��Ȩ��ij
					{
						auto tmp = VecOut[clayer][i] * VecError[clayer + 1][j] * (double)runtime;
						VecWeight[clayer][i][j] += tmp;
						tmp = VecWeight[clayer][i][j];
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////
			//����ƫ��:����㲻�ø���ƫ��
			for (auto clayer = 1; clayer < layer;++clayer)//��ÿһ��
			{
				for (auto i = 0; i < VecIn[clayer].size();++i)//��ÿһ��ƫ��
				{
					auto tmp = VecError[clayer][i] * (double)runtime;
					VecBias[clayer][i] += tmp;
				}
			}

			if (VecOut[layer-1][0] < 0.8)
			{
				//ErrorFlag = VecOut[layer - 1][0];
				ErrorFlag = 1;//�����ж� ��Flag
			}
		}//Aȫ���������

////////////////////////////////////////////////////////////////////////////
		////��ʾ
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

		for (auto & X : TrainPointVecBtmp)//�Լ���Btmp����
		{
			//////////////////////////////////////////////////////////////////////////
			//���� ��� ��� ����
			for (auto k = 0; k < 3; ++k)//������
			{
				for (auto i = 0; i < LayerArry[k]; ++i)
				{
					VecIn[k][i] = 0;
					VecOut[k][i] = 0;
					VecError[k][i] = 0;
				}
			}
			/////////////////////////////////////////////////////////////////////////
			T = 0;			// B ����ȷ������Ϊ0
			////////////////////////////////////////////////////////////////////////
			//�����������
			VecIn[0][0] = (double)X.first;//�����
			VecIn[0][1] = (double)X.second;
			VecOut[0][0] = (double)X.first;
			VecOut[0][1] = (double)X.second; //���������������
			//������������������
			for (auto clayer = 1; clayer < layer; ++clayer) //clayer: Current Layer :0 1 2 ...layer-1
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)
				{
					for (auto k = 0; k < VecIn[clayer - 1].size(); ++k)	//ǰһ�������� Ȩֵ
					{
						VecIn[clayer][i] += VecOut[clayer - 1][k] * VecWeight[clayer - 1][k][i];
					}
					VecIn[clayer][i] += VecBias[clayer][i];				//����ƫ��

					VecOut[clayer][i] = ActivationFuntion(VecIn[clayer][i]);
					auto tmp = VecOut[clayer][i];
					tmp = 0;
				}
			}
			//////////////////////////////////////////////////////////////////////////
			//�������
			auto Q = VecOut[layer - 1][0];//���յ����
			VecError[layer - 1][0] = (Q)*(1 - Q)*(T - Q); //���������
			//������������������ //����㲻�ü������ ������������
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
			//����Ȩ��:����㲻�ø���Ȩֵ
			for (auto clayer = 0; clayer < layer - 1; ++clayer)//��ÿһ��
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)//��ÿһ���ڵ�
				{
					for (auto j = 0; j < VecIn[clayer + 1].size(); ++j)//��ÿһ��Ȩ��ij
					{
						auto tmp = VecOut[clayer][i] * VecError[clayer + 1][j] * (double)runtime;
						VecWeight[clayer][i][j] += tmp;
						tmp = VecWeight[clayer][i][j];
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////
			//����ƫ��:����㲻�ø���ƫ��
			for (auto clayer = 1; clayer < layer; ++clayer)//��ÿһ��
			{
				for (auto i = 0; i < VecIn[clayer].size(); ++i)//��ÿһ��ƫ��
				{
					auto tmp = VecError[clayer][i] * (double)runtime;
					VecBias[clayer][i] += tmp;
				}
			}

			if (VecOut[layer - 1][0] > 0.2)
			{
				//ErrorFlag = VecOut[layer - 1][0];
				ErrorFlag = 1;//�����ж� ��Flag
			}
		}//Bȫ���������

		//��ʾȨ��
		Invalidate(TRUE);
		int N = 100;
		pDC->TextOut(100, 200, CString(_T("Ȩ��:")));
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



	}//whileѭ������

	if (boom < 1)
	{
		MessageBox(_T("ѵ��ǿ���˳���"));
	}
	else
	{
		MessageBox(_T("������ѵ����ɣ�"));
	}

	Invalidate(TRUE);
	int N = 100;
	pDC->TextOut(100, 200, CString(_T("Ȩ��:")));
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



//�񾭲��Ժ���
void Cģʽʶ����ҵView::OnNeurontest()
{
	if ( PointVec.empty())//û��������
	{
		MessageBox((LPCTSTR)CString("���Ȳ�����������"));
		return;
	}
	if (TrainPointVecA.empty() || TrainPointVecB.empty())//û��ѵ����
	{
		MessageBox((LPCTSTR)CString("����ѵ������"));
		return;
	}
	
	if (VecWeight.empty() || VecBias.empty() || PointVec.empty())//û��ѵ��
	{
		MessageBox((LPCTSTR)CString("���Ƚ�������ѵ����"));
		return;
	}
	CDC* pDC = GetDC();
	int layer = 3;


	double minX,maxX,minY,maxY,tmpxy;
	//A�����Сֵ
	minX = (*std::min_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first<b.first; })).first;
	maxX = (*std::max_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first<b.first; })).first;
	minY = (*std::min_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second<b.second; })).first;
	maxY = (*std::max_element(TrainPointVecA.begin(), TrainPointVecA.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second<b.second; })).first;
	//����B �������Сֵ
	tmpxy = (*std::min_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	minX  = tmpxy > minX ? minX : tmpxy;
	tmpxy = (*std::max_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	maxX  = tmpxy < minX ? minX : tmpxy;
	tmpxy = (*std::min_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	minY  = tmpxy > minY ? minY : tmpxy;
	tmpxy = (*std::max_element(TrainPointVecB.begin(), TrainPointVecB.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second<b.second; })).first;
	maxY  = tmpxy < maxY ? maxY : tmpxy;
	//���ϲ������������ֵ��Сֵ
	tmpxy = (*std::min_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	minX = tmpxy > minX ? minX : tmpxy;
	tmpxy = (*std::max_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.first < b.first; })).first;
	maxX = tmpxy < minX ? minX : tmpxy;
	tmpxy = (*std::min_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	minY = tmpxy > minY ? minY : tmpxy;
	tmpxy = (*std::max_element(PointVec.begin(), PointVec.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; })).first;
	maxY = tmpxy < maxY ? maxY : tmpxy;

	vector<pair<double, double>> PointVectmp;//��ʱvec
	for (auto &i : PointVec)
	{
		PointVectmp.push_back(make_pair((double)(i.first - minX) / (double)(maxX - minX), (double)(i.second - minY) / (double)(maxY - minY)));
	}
	
	for (auto &X : PointVectmp)
	{
		//////////////////////////////////////////////////////////////////////////
		//����
		for (auto k = 0; k < 3; ++k)//������
		{
			for (auto i = 0; i < VecIn[k].size(); ++i)
			{
				VecIn[k][i] = 0;
				VecOut[k][i] = 0;
				VecError[k][i] = 0;
			}
		}

		////////////////////////////////////////////////////////////////////////
		//�����������
		VecIn[0][0] = (double)X.first;//�����
		VecIn[0][1] = (double)X.second;
		VecOut[0][0] = (double)X.first;
		VecOut[0][1] = (double)X.second; //���������������
		//������������������
		for (auto clayer = 1; clayer < layer; ++clayer) //clayer: Current Layer :0 1 2 ...layer-1
		{
			for (auto i = 0; i < VecIn[clayer].size(); ++i)
			{
				for (auto k = 0; k < VecIn[clayer - 1].size(); ++k)	//ǰһ�������� Ȩֵ
				{
					VecIn[clayer][i] += VecOut[clayer - 1][k] * VecWeight[clayer - 1][k][i];
				}
				VecIn[clayer][i] += VecBias[clayer][i];				//����ƫ��

				VecOut[clayer][i] = ActivationFuntion(VecIn[clayer][i]);
			}
		}
		//����
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
	// TODO:  �ڴ���������������
}


void Cģʽʶ����ҵView::OnEmptypointvec()
{
	PointVec.clear();
	Invalidate(TRUE);
	// TODO:  �ڴ���������������
}
