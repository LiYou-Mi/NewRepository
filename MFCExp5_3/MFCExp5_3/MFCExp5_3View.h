
// MFCExp5_3View.h : CMFCExp5_3View ��Ľӿ�
//

#pragma once


class CMFCExp5_3View : public CView
{
protected: // �������л�����
	CMFCExp5_3View();
	DECLARE_DYNCREATE(CMFCExp5_3View)

// ����
public:
	CMFCExp5_3Doc* GetDocument() const;

// ����
public:
	int  N;
	CArray<CRect, CRect> cr;
	bool set;
	int flags = 0;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCExp5_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCExp5_3View.cpp �еĵ��԰汾
inline CMFCExp5_3Doc* CMFCExp5_3View::GetDocument() const
   { return reinterpret_cast<CMFCExp5_3Doc*>(m_pDocument); }
#endif

