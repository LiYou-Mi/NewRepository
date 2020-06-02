
// MFCAppExpView.cpp : CMFCAppExpView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCAppExpView 构造/析构

CMFCAppExpView::CMFCAppExpView()
{
	// TODO: 在此处添加构造代码

}

CMFCAppExpView::~CMFCAppExpView()
{
}

BOOL CMFCAppExpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCAppExpView 绘制

void CMFCAppExpView::OnDraw(CDC* pDC)
{
	CMFCAppExpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (flag != 0) {
		pDC->Ellipse(0, 0,w, h);
	}
}


// CMFCAppExpView 打印

BOOL CMFCAppExpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCAppExpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCAppExpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCAppExpView 诊断

#ifdef _DEBUG
void CMFCAppExpView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAppExpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAppExpDoc* CMFCAppExpView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppExpDoc)));
	return (CMFCAppExpDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppExpView 消息处理程序


void CMFCAppExpView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
