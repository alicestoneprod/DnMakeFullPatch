// DnMakeFullPatchDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


typedef struct _FILELIST
{
	int		nIndex;
	char	szFilePath[512+1];
	DWORD	nFileSize;
	DWORD	nCompressFileSize;
	char	szChecksum[64+1];

	_FILELIST()
	{
		nIndex = -1;
		nFileSize = 0;
		nCompressFileSize = 0;
		ZeroMemory(szFilePath, sizeof(szFilePath));
		ZeroMemory(szChecksum, sizeof(szChecksum));
	}

}FILELIST;



// CDnMakeFullPatchDlg ��ȭ ����
class CDnMakeFullPatchDlg : public CDialog
{
// �����Դϴ�.
public:
	CDnMakeFullPatchDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DNMAKEFULLPATCH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSetPath();
	afx_msg void OnBnClickedButtonSetOutPath();
	afx_msg void OnBnClickedButtonBuild();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	void DropFile(HDROP hDrop);
	void DropFolder(const TCHAR* szPath);

	void _UpdateFileList();
	void Build();
	void _BuildChecksumFile();
public:

	CString			m_szEditPath;
	CString			m_szEditOutFolder;
	CString			m_szStaticMsg;
	CProgressCtrl	m_ProgressCurrent;
	CProgressCtrl	m_ProgressTotal;
	CListCtrl		m_ListCtrlFileList;

	std::vector<FILELIST>	m_FileList;

	bool			m_bSetInputFolder;
	bool			m_bSetOutputFolder;
	
public:
	

	
};

