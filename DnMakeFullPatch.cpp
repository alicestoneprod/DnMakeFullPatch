// DnMakeFullPatch.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "DnMakeFullPatch.h"
#include "DnMakeFullPatchDlg.h"
#include "LogWnd.h"

#pragma comment( lib, "dbghelp.lib" )

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDnMakeFullPatchApp

BEGIN_MESSAGE_MAP(CDnMakeFullPatchApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDnMakeFullPatchApp ����

CDnMakeFullPatchApp::CDnMakeFullPatchApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CDnMakeFullPatchApp ��ü�Դϴ�.

CDnMakeFullPatchApp theApp;




void TokenizeA( const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters /* = " " */ )
{
	// �� ù ���ڰ� �������� ��� ����
	std::string::size_type lastPos = str.find_first_not_of( delimiters, 0 );
	// �����ڰ� �ƴ� ù ���ڸ� ã�´�
	std::string::size_type pos = str.find_first_of( delimiters, lastPos );

	while( std::string::npos != pos || std::string::npos != lastPos )
	{
		// token�� ã������ vector�� �߰��Ѵ�
		tokens.push_back( str.substr( lastPos, pos - lastPos ) );
		// �����ڸ� �پ�Ѵ´�.  "not_of"�� �����϶�
		lastPos = str.find_first_not_of( delimiters, pos );
		// ���� �����ڰ� �ƴ� ���ڸ� ã�´�
		pos = str.find_first_of( delimiters, lastPos );
	}
}

// CDnMakeFullPatchApp �ʱ�ȭ

BOOL CDnMakeFullPatchApp::InitInstance()
{

	LogWnd::CreateLog();

	CString szCmdLine;

	szCmdLine = m_lpCmdLine;
	if ( szCmdLine.IsEmpty() == FALSE )
	{
		CDnMakeFullPatchDlg dlg;

		std::vector<std::string>	tokens;
		TokenizeA( std::string(szCmdLine.GetBuffer()), tokens, std::string(" ") );
		if ( tokens.size() != 2 )
			return FALSE;

		dlg.m_szEditPath = tokens[0].c_str();
		dlg.m_szEditOutFolder = tokens[1].c_str();	

		dlg.DropFolder(tokens[0].c_str());
		dlg.Build();
		return TRUE;
	}


	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("An application created by a local application wizard"));

	CDnMakeFullPatchDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ���⿡ [Ȯ��]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ���⿡ [���]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�  ���� ���α׷��� ���� �� �ֵ��� FALSE��
	// ��ȯ�մϴ�.
	return FALSE;
}
