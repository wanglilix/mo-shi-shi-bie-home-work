#pragma once


// NeuralLayer 神经网络层对话框

class NeuralLayer : public CDialogEx
{
	DECLARE_DYNAMIC(NeuralLayer)

public:
	NeuralLayer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~NeuralLayer();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	// 第一层节点数
	int FirstLayer;
	// 第二层节点数
	int SecondLayer;
	// 第三层输出层节点数
	int ThridLayer;
};
