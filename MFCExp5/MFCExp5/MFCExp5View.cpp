
// MFCExp5View.cpp : CMFCExp5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCExp5View 构造/析构

CMFCExp5View::CMFCExp5View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp5View::~CMFCExp5View()
{
}

BOOL CMFCExp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp5View 绘制

void CMFCExp5View::OnDraw(CDC* pDC)
{
	CMFCExp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_crlRect);
}


// CMFCExp5View 打印

BOOL CMFCExp5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExp5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExp5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExp5View 诊断

#ifdef _DEBUG
void CMFCExp5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp5Doc* CMFCExp5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp5Doc)));
	return (CMFCExp5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp5View 消息处理程序


void CMFCExp5View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExp5Doc*pDoc = GetDocument();
	CView::OnLButtonDown(nFlags, point);
	pDoc->m_crlRect.left = 200;
	pDoc->m_crlRect.right = 250;
	pDoc->m_crlRect.top = 200;
	pDoc->m_crlRect.bottom = 250;
	InvalidateRect(NULL, TRUE);
}
