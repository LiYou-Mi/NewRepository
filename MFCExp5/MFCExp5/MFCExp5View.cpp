
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
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_crlRect);
}


// CMFCExp5View ��ӡ

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


void CMFCExp5View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCExp5Doc*pDoc = GetDocument();
	CRect clientRect;
	GetClientRect(&clientRect);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_crlRect.left > 0)
		{
			pDoc->m_crlRect.left -= 5;
			pDoc->m_crlRect.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_crlRect.right <= (clientRect.right - clientRect.left))
		{
			pDoc->m_crlRect.left += 5;
			pDoc->m_crlRect.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->m_crlRect.top > 0)
		{
			pDoc->m_crlRect.top -= 5;
			pDoc->m_crlRect.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_crlRect.bottom <= (clientRect.bottom - clientRect.top))
		{
			pDoc->m_crlRect.bottom += 5;
			pDoc->m_crlRect.top += 5;
		}
		break;
	case VK_HOME:
		if (pDoc->m_crlRect.left > 0 && pDoc->m_crlRect.top > 0)
		{
			pDoc->m_crlRect.left -= 5;
			pDoc->m_crlRect.top -= 5;
		}
		break;
	case VK_END:
		if ((pDoc->m_crlRect.bottom <= (clientRect.bottom - clientRect.left))
			&& pDoc->m_crlRect.right <= (clientRect.right - clientRect.left))
		{
			pDoc->m_crlRect.bottom += 5;
			pDoc->m_crlRect.right += 5;
		}
	}

	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	
}


void CMFCExp5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCExp5Doc*pDoc = GetDocument();
	CView::OnLButtonDown(nFlags, point);
	pDoc->m_crlRect.left = 200;
	pDoc->m_crlRect.right = 250;
	pDoc->m_crlRect.top = 200;
	pDoc->m_crlRect.bottom = 250;
	InvalidateRect(NULL, TRUE);
}
