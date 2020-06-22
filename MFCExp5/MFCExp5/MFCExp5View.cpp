
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
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCExp5View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
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
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp5View 打印


void CMFCExp5View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

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


void CMFCExp5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFCExp5Doc *pDoc = GetDocument();
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	a.x = point.x;
}


void CMFCExp5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CView::OnLButtonUp(nFlags, point);
	b.x = point.x;
	int m = abs(b.x - a.x);
	s2.Format(_T("%d"), m);
	s3 = "横向移动像素个数";
	dc.TextOutW(200, 250,s3 + s2);
}


void CMFCExp5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    count++;
	CView::OnMouseMove(nFlags, point);
	//pDC->TextOutW(100, 200, s1);
	//wsprintf(s, "s1 %s  s0: %d");
	CClientDC dc(this);
	s1 = "MouseMove发生次数为：";
	s0.Format(_T("%d"), count);
	dc.TextOutW(200, 200, s1 + s0);
	
}
