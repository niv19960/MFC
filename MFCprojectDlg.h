
// MFCprojectDlg.h : header file
//

#pragma once
#include <stack>
#include "Figure.h"
#include "RectangleF.h"
#include "EllipseF.h"
#include "LineF.h"
#include "SquareF.h"
//#include "Command.h"
//#include "shape_add.h"
#include "HexagonalF.h"
#include "TrapezeF.h"
#include "RightAngleTrapezeF.h"
#include "TriangleF.h"
#include "RightAngleTriangleF.h"
#include "PentagonF.h"


using namespace std;

// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{
// Construction
public:

	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor
	stack<Figure*> commands, undoes;   // for Clear, Undo and Redo
	
//stack<Command*> commands, undoes;   // for Clear, Undo and Redo
	CTypedPtrArray<CObArray, Figure*> shapes;  // for Clear, Undo and Redo
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end;
	bool isPressed=false;
	 CTypedPtrArray< CObArray, Figure*> figs;
	 int futureFigureKind = 1; //Rectangle (2 - Ellipse)
	 
protected:

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:

	COLORREF bg;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMThemeChangedRadio1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnHey();
	afx_msg void OnNotepad();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedRadio6();
	//afx_msg void OnFileOpen();
	//afx_msg void OnFileSave();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio10();
	afx_msg void OnFileSave32778();
	afx_msg void OnFileOpen32777();
};
