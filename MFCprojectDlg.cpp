
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCprojectDlg dialog

CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CMFCprojectDlg::OnBnClickedCancel)
	ON_NOTIFY(NM_THEMECHANGED, IDC_RADIO1, &CMFCprojectDlg::OnNMThemeChangedRadio1)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCprojectDlg::OnBnClickedRadio4)
	ON_COMMAND(ID_HEY, &CMFCprojectDlg::OnHey)
	ON_COMMAND(ID_NOTEPAD, &CMFCprojectDlg::OnNotepad)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCprojectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCprojectDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCprojectDlg::OnBnClickedRadio6)
	//ON_COMMAND(ID_FILE_OPEN, &CMFCprojectDlg::OnFileOpen)
	//ON_COMMAND(ID_FILE_SAVE, &CMFCprojectDlg::OnFileSave)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCprojectDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CMFCprojectDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &CMFCprojectDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &CMFCprojectDlg::OnBnClickedRadio10)
	ON_COMMAND(ID_FILE_SAVE32778, &CMFCprojectDlg::OnFileSave32778)
	ON_COMMAND(ID_FILE_OPEN32777, &CMFCprojectDlg::OnFileOpen32777)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc, figs[i]->getColor());
	}

	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	isPressed = true;
	Figure *n = 0; // for Clear, Undo and Redo
	switch (futureFigureKind)
	{
	case 1:
		figs.Add(new RectangleF(start, start, bg));
		//n = new RectangleF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 2:
  	    figs.Add(new EllipseF(start, start, bg));
		//n = new EllipseF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 3:
		figs.Add(new LineF(start, start, bg));
		//n = new LineF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 4:
		figs.Add(new SquareF(start, start, bg));
		//n = new SquareF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 5:
		figs.Add(new HexagonalF(start, start, bg));
		//n = new HexagonalF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 6:
		figs.Add(new TrapezeF(start, start, bg));
		//n = new TrapezeF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 7:
		figs.Add(new RightAngleTrapezeF(start, start, bg));
		//n = new RightAngleTrapezeF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 8:
		figs.Add(new TriangleF(start, start, bg));
		//n = new TriangleF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 9:
		figs.Add(new RightAngleTriangleF(start, start, bg));
		//n = new RightAngleTriangleF(start, start, bg); // for Clear, Undo and Redo
		break;
	case 10:
		figs.Add(new PentagonF(start, start, bg));
		//n = new PentagonF(start, start, bg); // for Clear, Undo and Redo
		break;
	}
	
	//Command *c = new shape_add(figs, n); // for Clear, Undo and Redo
	//c->perform(); // for Clear, Undo and Redo
//	commands.push(c); // for Clear, Undo and Redo

	Invalidate();
	
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	if (isPressed)
	{
		end = point;
		isPressed = false;
	//	figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize()-1]->Redefine(start,end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	
		CDialogEx::OnMouseMove(nFlags, point);
}

void CMFCprojectDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here

	futureFigureKind = 1;
}


void CMFCprojectDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	
	futureFigureKind = 2;
}


void CMFCprojectDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	             /// FALSE to SAVE

	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CMFCprojectDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
		// TRUE to LOAD

	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	int message = AfxMessageBox(L"?Are you sure", MB_YESNO | MB_ICONINFORMATION | MB_RTLREADING); // another features: | MB_ICONERROR | MB_RTLREADING
	if (message == IDYES)
		CDialogEx::OnCancel();
}


void CMFCprojectDlg::OnNMThemeChangedRadio1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows XP or greater.
	// The symbol _WIN32_WINNT must be >= 0x0501.
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMFCprojectDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 3;
}


void CMFCprojectDlg::OnHey()
{
	// TODO: Add your command handler code here
	 AfxMessageBox(L"Hello dear user!  \nThanks for using the app :)");
}


void CMFCprojectDlg::OnNotepad()
{
	// TODO: Add your command handler code here
	WinExec("notepad.exe", SW_SHOW);
}


void CMFCprojectDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 4;
}


void CMFCprojectDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	// Clear:
	
	figs.RemoveAll();

	while (!undoes.empty())
	{
		undoes.pop();
	}
	Invalidate();

	/*while (!commands.empty())
	{
		Command *c = commands.top();
		c->rollback();
		undoes.push(c);
		commands.pop();
		Invalidate();
	}
	return;
	*/
}


void CMFCprojectDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	//Undo:
	
	if (figs.GetSize() >= 1)
	{
		Figure *figure = figs[figs.GetSize() - 1];
		figs.RemoveAt(figs.GetSize() - 1, 1);
		undoes.push(figure);
		Invalidate();
	}
	
	/*if (commands.empty())
		return;
	Command *c = commands.top();
	c->rollback();
	undoes.push(c);
	commands.pop();
	Invalidate();*/
}


void CMFCprojectDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	//Redo:

	if (!undoes.empty())
	{
		Figure *figure = undoes.top();
		figs.Add(figure);
		undoes.pop();
		Invalidate();
	}

	/*
	if (undoes.empty())
		return;
	figure *c = undoes.top();
	c->perform();
	commands.push(c);
	undoes.pop();
	Invalidate();
	*/
}



void CMFCprojectDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 5;
}


void CMFCprojectDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	CColorDialog dcolor;	if (dcolor.DoModal() == IDOK)	{		bg = dcolor.GetColor();	}
}


void CMFCprojectDlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 6;
}


void CMFCprojectDlg::OnBnClickedRadio7()
{
	// TODO: Add your control notification handler code here

	futureFigureKind = 7;
}


void CMFCprojectDlg::OnBnClickedRadio8()
{
	// TODO: Add your control notification handler code here

	futureFigureKind = 8;
}


void CMFCprojectDlg::OnBnClickedRadio9()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 9;
}


void CMFCprojectDlg::OnBnClickedRadio10()
{
	// TODO: Add your control notification handler code here

	futureFigureKind = 10;
}


void CMFCprojectDlg::OnFileSave32778()
{
	// TODO: Add your command handler code here

	/// FALSE to SAVE

	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CMFCprojectDlg::OnFileOpen32777()
{
	// TODO: Add your command handler code here
	// TRUE to LOAD

	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}
