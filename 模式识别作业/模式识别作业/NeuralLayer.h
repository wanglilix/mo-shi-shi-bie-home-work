#pragma once


// NeuralLayer �������Ի���

class NeuralLayer : public CDialogEx
{
	DECLARE_DYNAMIC(NeuralLayer)

public:
	NeuralLayer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~NeuralLayer();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	// ��һ��ڵ���
	int FirstLayer;
	// �ڶ���ڵ���
	int SecondLayer;
	// �����������ڵ���
	int ThridLayer;
};
