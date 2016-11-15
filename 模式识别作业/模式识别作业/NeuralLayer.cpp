// NeuralLayer.cpp : 实现文件
//

#include "stdafx.h"
#include "模式识别作业.h"
#include "NeuralLayer.h"
#include "afxdialogex.h"


// NeuralLayer 对话框

IMPLEMENT_DYNAMIC(NeuralLayer, CDialogEx)

NeuralLayer::NeuralLayer(CWnd* pParent /*=NULL*/)
	: CDialogEx(NeuralLayer::IDD, pParent)
	, FirstLayer(0)
	, SecondLayer(0)
	, ThridLayer(0)
{

}

NeuralLayer::~NeuralLayer()
{
}

void NeuralLayer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NeuralLayer, CDialogEx)
END_MESSAGE_MAP()


// NeuralLayer 消息处理程序


BOOL NeuralLayer::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	((CComboBox*)GetDlgItem(IDC_FirstLayer)) ->AddString(_T("    2     "));
	((CComboBox*)GetDlgItem(IDC_SecondLayer))->AddString(_T("    2     "));
	((CComboBox*)GetDlgItem(IDC_SecondLayer))->AddString(_T("    3     "));
	((CComboBox*)GetDlgItem(IDC_SecondLayer))->AddString(_T("    4     "));
	((CComboBox*)GetDlgItem(IDC_SecondLayer))->AddString(_T("    5     "));
	((CComboBox*)GetDlgItem(IDC_ThridLayer)) ->AddString(_T("    1     "));
	((CComboBox*)GetDlgItem(IDC_FirstLayer))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_SecondLayer))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_ThridLayer))->SetCurSel(0);

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void NeuralLayer::OnOK()
{
	int index;
	index = ((CComboBox*)GetDlgItem(IDC_FirstLayer))->GetCurSel();
	FirstLayer = index + 2;
	index = ((CComboBox*)GetDlgItem(IDC_SecondLayer))->GetCurSel();
	SecondLayer = index + 2;
	index = ((CComboBox*)GetDlgItem(IDC_ThridLayer))->GetCurSel();
	ThridLayer = index + 1;

	CDialogEx::OnOK();
}
