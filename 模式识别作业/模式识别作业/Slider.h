#pragma once
#include "afxcmn.h"


// Slider 对话框

class Slider : public CDialogEx
{
	DECLARE_DYNAMIC(Slider)

public:
	Slider(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Slider();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	// 数值
	int Num;
	CSliderCtrl m_Slider;
};
