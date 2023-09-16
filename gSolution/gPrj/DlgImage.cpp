// DlgImage.cpp : implementation file
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage dialog

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage message handlers

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: Add your control notification handler code here
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetWindowText(_T("Origin Image"));
	MoveWindow(0, 0, 1280, 600);
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgImage::InitImage()
{
	int nWidth = 1280;//640
	int nHeight = 600;//480
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialogEx::OnPaint() for painting messages

	if (m_image)
		m_image.Draw(dc, 0, 0);

	drawData(&dc);
}

void CDlgImage::drawData(CDC* pDC)
{
	CRect rect;
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, COLOR_YELLOW);
	CPen* pOldPen = pDC->SelectObject(&pen);
	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(m_nDataSize, m_nDataSize);

		//원 그리기
		drawCircle(pDC, m_ptData[i].x, m_ptData[i].y, m_nDataSize);

		//원중심 십자그리기
		drawCrossLine(pDC, m_ptData[i].x, m_ptData[i].y);
	}
		
	pDC->SelectObject(pOldPen);
}

void CDlgImage::drawCircle(CDC* pDC, int nCenterX, int nCenterY, int nRadius)
{

	double dPi = 3.1415926535897932384626433832795;
	int nVertex = 365;

	double x = nRadius * cos(0.0) + nCenterX;
	double y = nRadius * sin(0.0) + nCenterY;
	pDC->MoveTo(x, y);

	for (int i = 0; i <= nVertex; i++)
	{
		double radian = i * 2 * dPi / nVertex;
		double x = nRadius * cos(radian) + nCenterX;
		double y = nRadius * sin(radian) + nCenterY;
		pDC->LineTo(x, y);
	}
}

void CDlgImage::drawCrossLine(CDC* pDC, int nCenterX, int nCenterY)
{
	pDC->MoveTo(nCenterX - 4, nCenterY);
	pDC->LineTo(nCenterX + 4, nCenterY);
	pDC->MoveTo(nCenterX, nCenterY - 4);
	pDC->LineTo(nCenterX, nCenterY + 4);
}


