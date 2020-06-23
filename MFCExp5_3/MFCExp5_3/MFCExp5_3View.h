
// MFCExp5_3View.h : CMFCExp5_3View 类的接口
//

#pragma once


class CMFCExp5_3View : public CView
{
protected: // 仅从序列化创建
	CMFCExp5_3View();
	DECLARE_DYNCREATE(CMFCExp5_3View)

// 特性
public:
	CMFCExp5_3Doc* GetDocument() const;

// 操作
public:
	int  N;
	CArray<CRect, CRect> cr;
	bool set;
	int flags = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCExp5_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCExp5_3View.cpp 中的调试版本
inline CMFCExp5_3Doc* CMFCExp5_3View::GetDocument() const
   { return reinterpret_cast<CMFCExp5_3Doc*>(m_pDocument); }
#endif

