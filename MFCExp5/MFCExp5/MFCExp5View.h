
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
	int count=0;
	CPoint a, b;
	CString s0, s1, s2,s3;

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
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExp5View.cpp �еĵ��԰汾
inline CMFCExp5Doc* CMFCExp5View::GetDocument() const
   { return reinterpret_cast<CMFCExp5Doc*>(m_pDocument); }
#endif

