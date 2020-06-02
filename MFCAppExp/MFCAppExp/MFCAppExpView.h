
// MFCAppExpView.h : CMFCAppExpView ��Ľӿ�
//

#pragma once


class CMFCAppExpView : public CView
{
protected: // �������л�����
	CMFCAppExpView();
	DECLARE_DYNCREATE(CMFCAppExpView)

// ����
public:
	CMFCAppExpDoc* GetDocument() const;
// ����
public:
	int r;
	int flag = 0;
	int w, h;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCAppExpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCAppExpView.cpp �еĵ��԰汾
inline CMFCAppExpDoc* CMFCAppExpView::GetDocument() const
   { return reinterpret_cast<CMFCAppExpDoc*>(m_pDocument); }
#endif

