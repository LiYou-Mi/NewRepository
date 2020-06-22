
// MFCExp5View.h : CMFCExp5View 类的接口
//

#pragma once


class CMFCExp5View : public CView
{
protected: // 仅从序列化创建
	CMFCExp5View();
	DECLARE_DYNCREATE(CMFCExp5View)

// 特性
public:
	CMFCExp5Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CMFCExp5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExp5View.cpp 中的调试版本
inline CMFCExp5Doc* CMFCExp5View::GetDocument() const
   { return reinterpret_cast<CMFCExp5Doc*>(m_pDocument); }
#endif

