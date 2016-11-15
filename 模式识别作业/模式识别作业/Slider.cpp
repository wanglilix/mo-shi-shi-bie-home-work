// Slider.cpp : 实现文件
//

#include "stdafx.h"
#include "模式识别作业.h"
#include "Slider.h"
#include "afxdialogex.h"
#include <string>
using namespace std;
// Slider 对话框

IMPLEMENT_DYNAMIC(Slider, CDialogEx)

Slider::Slider(CWnd* pParent /*=NULL*/)
	: CDialogEx(Slider::IDD, pParent)
	, Num(0)
{

}

Slider::~Slider()
{
}

void Slider::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider);
}


BEGIN_MESSAGE_MAP(Slider, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Slider::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// Slider 消息处理程序


void Slider::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	Num = m_Slider.GetPos() ;
	GetDlgItem(IDC_STATIC)->SetWindowText((LPCTSTR) CString("样本个数："));
	auto str2=to_string(Num);
	CString str(str2.c_str());
	GetDlgItem(IDC_NUMBER)->SetWindowText((LPCTSTR)str);


	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}
