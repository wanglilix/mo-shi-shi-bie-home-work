
// ģʽʶ����ҵView.h : Cģʽʶ����ҵView ��Ľӿ�
//

#pragma once
#include <vector>
using namespace std;

class Cģʽʶ����ҵView : public CView
{
protected: // �������л�����
	Cģʽʶ����ҵView();
	DECLARE_DYNCREATE(Cģʽʶ����ҵView)

// ����
public:
	Cģʽʶ����ҵDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cģʽʶ����ҵView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGaussiandistribution();
	// ��������vector
	vector<pair<int,int>>  PointVec;
	// һ�β��������
	int PointNum;
	// //���°�ť����ʼ��ͼflag
	int Flag1;
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// �������flag
	int Flag2;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	// ��ͼ Flag
	int DrawFlag;
	// ѵ��������vector
	vector<pair<int, int>> TrainPointVecA;
	vector<pair<int, int>> TrainPointVecB;
	afx_msg void OnTrainpointcreate();
	afx_msg void OnShowall();
	afx_msg void OnShowpointvec();
	afx_msg void OnShowtrainpointvec();
	afx_msg void OnIdTrainpointcreateb();
	// ��֪���㷨W
	vector<double> W;
	afx_msg void OnPerceptrontrain();
	afx_msg void OnPerceptrontest();
	afx_msg void OnEmptytrainpointa();
	afx_msg void OnEmptytrainpointb();
	afx_msg void OnEmptytrainpoint();
	afx_msg void OnLmstrain();
	//��ѵ������
	afx_msg void OnNeurontrain();
	//�񾭲��Ժ���
	afx_msg void OnNeurontest();
	// �洢������Ԫ����
	vector<vector<double>> VecIn;
	// �洢������Ԫ���
	vector<vector<double>> VecOut;
	// �洢������ԪȨֵ
	vector<vector<vector<double>>> VecWeight;
	// �洢������Ԫƫ��
	vector<vector<double>> VecBias;
	// �洢���нڵ����
	vector<vector<double>> VecError;
	afx_msg void OnEmptypointvec();
};

#ifndef _DEBUG  // ģʽʶ����ҵView.cpp �еĵ��԰汾
inline Cģʽʶ����ҵDoc* Cģʽʶ����ҵView::GetDocument() const
   { return reinterpret_cast<Cģʽʶ����ҵDoc*>(m_pDocument); }
#endif

