
// MFCExp5View.h : CMFCExp5View ��Ľӿ�
//

#pragma once


class CMFCExp5View : public CView
{
protected: // �������л�����
	CMFCExp5View();
	DECLARE_DYNCREATE(CMFCExp5View)

// ����
public:
	CMFCExp5Doc* GetDocument() const;

// ����
public:

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
	virtual ~CMFCExp5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExp5View.cpp �еĵ��԰汾
inline CMFCExp5Doc* CMFCExp5View::GetDocument() const
   { return reinterpret_cast<CMFCExp5Doc*>(m_pDocument); }
#endif

