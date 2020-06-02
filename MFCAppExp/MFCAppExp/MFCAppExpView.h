
// MFCAppExpView.h : CMFCAppExpView 类的接口
//

#pragma once


class CMFCAppExpView : public CView
{
protected: // 仅从序列化创建
	CMFCAppExpView();
	DECLARE_DYNCREATE(CMFCAppExpView)

// 特性
public:
	CMFCAppExpDoc* GetDocument() const;
// 操作
public:
	int r;
	int flag = 0;
	int w, h;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCAppExpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCAppExpView.cpp 中的调试版本
inline CMFCAppExpDoc* CMFCAppExpView::GetDocument() const
   { return reinterpret_cast<CMFCAppExpDoc*>(m_pDocument); }
#endif

