
// MFCAppExpView.cpp : CMFCAppExpView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCAppExp.h"
#endif

#include "MFCAppExpDoc.h"
#include "MFCAppExpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppExpView

IMPLEMENT_DYNCREATE(CMFCAppExpView, CView)

BEGIN_MESSAGE_MAP(CMFCAppExpView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCAppExpView ����/����

CMFCAppExpView::CMFCAppExpView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCAppExpView::~CMFCAppExpView()
{
}

BOOL CMFCAppExpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCAppExpView ����

void CMFCAppExpView::OnDraw(CDC* pDC)
{
	CMFCAppExpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (flag != 0) {
		pDC->Ellipse(0, 0,w, h);
	}
}


// CMFCAppExpView ��ӡ

BOOL CMFCAppExpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCAppExpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCAppExpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCAppExpView ���

#ifdef _DEBUG
void CMFCAppExpView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAppExpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAppExpDoc* CMFCAppExpView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppExpDoc)));
	return (CMFCAppExpDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppExpView ��Ϣ�������


void CMFCAppExpView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC * pDC = GetDC();
	CRect cr;
	this->GetClientRect(cr);
	w = cr.Width();
	h = cr.Height();
	pDC->Ellipse(0, 0, w, h);

	flag++;
	
	this->Invalidate();

	CView::OnLButtonDown(nFlags, point);
	
}
