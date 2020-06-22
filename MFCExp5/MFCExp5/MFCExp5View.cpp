
// MFCExp5View.cpp : CMFCExp5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCExp5.h"
#endif

#include "MFCExp5Doc.h"
#include "MFCExp5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp5View

IMPLEMENT_DYNCREATE(CMFCExp5View, CView)

BEGIN_MESSAGE_MAP(CMFCExp5View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCExp5View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCExp5View ����/����

CMFCExp5View::CMFCExp5View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCExp5View::~CMFCExp5View()
{
}

BOOL CMFCExp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCExp5View ����

void CMFCExp5View::OnDraw(CDC* pDC)
{
	CMFCExp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCExp5View ��ӡ


void CMFCExp5View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCExp5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCExp5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCExp5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CMFCExp5View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCExp5View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCExp5View ���

#ifdef _DEBUG
void CMFCExp5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp5Doc* CMFCExp5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp5Doc)));
	return (CMFCExp5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp5View ��Ϣ�������


void CMFCExp5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFCExp5Doc *pDoc = GetDocument();
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
	a.x = point.x;
}


void CMFCExp5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CView::OnLButtonUp(nFlags, point);
	b.x = point.x;
	int m = abs(b.x - a.x);
	s2.Format(_T("%d"), m);
	s3 = "�����ƶ����ظ���";
	dc.TextOutW(200, 250,s3 + s2);
}


void CMFCExp5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    count++;
	CView::OnMouseMove(nFlags, point);
	//pDC->TextOutW(100, 200, s1);
	//wsprintf(s, "s1 %s  s0: %d");
	CClientDC dc(this);
	s1 = "MouseMove��������Ϊ��";
	s0.Format(_T("%d"), count);
	dc.TextOutW(200, 200, s1 + s0);
	
}
