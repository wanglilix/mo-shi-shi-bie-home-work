// Slider.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ģʽʶ����ҵ.h"
#include "Slider.h"
#include "afxdialogex.h"
#include <string>
using namespace std;
// Slider �Ի���

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


// Slider ��Ϣ�������


void Slider::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	Num = m_Slider.GetPos() ;
	GetDlgItem(IDC_STATIC)->SetWindowText((LPCTSTR) CString("����������"));
	auto str2=to_string(Num);
	CString str(str2.c_str());
	GetDlgItem(IDC_NUMBER)->SetWindowText((LPCTSTR)str);


	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
