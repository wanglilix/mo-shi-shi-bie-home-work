
// 模式识别作业View.h : C模式识别作业View 类的接口
//

#pragma once
#include <vector>
using namespace std;

class C模式识别作业View : public CView
{
protected: // 仅从序列化创建
	C模式识别作业View();
	DECLARE_DYNCREATE(C模式识别作业View)

// 特性
public:
	C模式识别作业Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C模式识别作业View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGaussiandistribution();
	// 保存坐标vector
	vector<pair<int,int>>  PointVec;
	// 一次产生点个数
	int PointNum;
	// //按下按钮，开始作图flag
	int Flag1;
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// 左键按下flag
	int Flag2;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	// 作图 Flag
	int DrawFlag;
	// 训练样本集vector
	vector<pair<int, int>> TrainPointVecA;
	vector<pair<int, int>> TrainPointVecB;
	afx_msg void OnTrainpointcreate();
	afx_msg void OnShowall();
	afx_msg void OnShowpointvec();
	afx_msg void OnShowtrainpointvec();
	afx_msg void OnIdTrainpointcreateb();
	// 感知器算法W
	vector<double> W;
	afx_msg void OnPerceptrontrain();
	afx_msg void OnPerceptrontest();
	afx_msg void OnEmptytrainpointa();
	afx_msg void OnEmptytrainpointb();
	afx_msg void OnEmptytrainpoint();
	afx_msg void OnLmstrain();
	//神经训练函数
	afx_msg void OnNeurontrain();
	//神经测试函数
	afx_msg void OnNeurontest();
	// 存储所有神经元输入
	vector<vector<double>> VecIn;
	// 存储所有神经元输出
	vector<vector<double>> VecOut;
	// 存储所有神经元权值
	vector<vector<vector<double>>> VecWeight;
	// 存储所有神经元偏置
	vector<vector<double>> VecBias;
	// 存储所有节点误差
	vector<vector<double>> VecError;
	afx_msg void OnEmptypointvec();
};

#ifndef _DEBUG  // 模式识别作业View.cpp 中的调试版本
inline C模式识别作业Doc* C模式识别作业View::GetDocument() const
   { return reinterpret_cast<C模式识别作业Doc*>(m_pDocument); }
#endif

