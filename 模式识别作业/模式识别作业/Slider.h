#pragma once
#include "afxcmn.h"


// Slider �Ի���

class Slider : public CDialogEx
{
	DECLARE_DYNAMIC(Slider)

public:
	Slider(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Slider();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	// ��ֵ
	int Num;
	CSliderCtrl m_Slider;
};
