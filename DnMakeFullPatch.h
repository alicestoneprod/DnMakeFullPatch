// DnMakeFullPatch.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDnMakeFullPatchApp:
// �� Ŭ������ ������ ���ؼ��� DnMakeFullPatch.cpp�� �����Ͻʽÿ�.
//

class CDnMakeFullPatchApp : public CWinApp
{
public:
	CDnMakeFullPatchApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDnMakeFullPatchApp theApp;