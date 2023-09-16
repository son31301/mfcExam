#pragma once

#define MAX_POINT	100
// CDlgImage dialog

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgImage();

	CWnd* m_pParent;
	CImage m_image;
	int m_nDataCount = 0;
	CPoint m_ptData[MAX_POINT];
	int m_nDataSize = 0;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

private:
	void InitImage();
	void drawData(CDC* pDC);
	void drawCircle(CDC* pDC, int x, int y, int nRadius);
	void drawCrossLine(CDC* pDC, int x, int y);
};
