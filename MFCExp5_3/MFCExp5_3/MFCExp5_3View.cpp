
// MFCExp5_3View.cpp : CMFCExp5_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExp5_3.h"
#endif

#include "MFCExp5_3Doc.h"
#include "MFCExp5_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp5_3View

IMPLEMENT_DYNCREATE(CMFCExp5_3View, CView)

BEGIN_MESSAGE_MAP(CMFCExp5_3View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCExp5_3View 构造/析构

CMFCExp5_3View::CMFCExp5_3View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
	}
}

CMFCExp5_3View::~CMFCExp5_3View()
{
}

BOOL CMFCExp5_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp5_3View 绘制

void CMFCExp5_3View::OnDraw(CDC* pDC)
{
	CMFCExp5_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);
			set = false;
		}
	}
	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
}


// CMFCExp5_3View 诊断

#ifdef _DEBUG
void CMFCExp5_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp5_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp5_3Doc* CMFCExp5_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp5_3Doc)));
	return (CMFCExp5_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp5_3View 消息处理程序


void CMFCExp5_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect crect;
	this->GetClientRect(&crect);
	int i = nIDEvent;
	
	if(flags==0)
	{
		cr[i].top += 10;
		cr[i].bottom += 10;

		if ((cr[i].bottom - crect.bottom) > 0)
			flags = 1;
	}
	 else if (flags==1)
		
	{
	    cr[i].top -= 10;
		cr[i].bottom -=10;
		if (cr[i].top <= 0)
			flags = 0;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
