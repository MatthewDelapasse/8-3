
// 8-3View.cpp : implementation of the CMy83View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "8-3.h"
#endif

#include "8-3Doc.h"
#include "8-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy83View

IMPLEMENT_DYNCREATE(CMy83View, CView)

BEGIN_MESSAGE_MAP(CMy83View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy83View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy83View construction/destruction

CMy83View::CMy83View() noexcept
{
	// TODO: add construction code here

}

CMy83View::~CMy83View()
{
}

BOOL CMy83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy83View drawing

void CMy83View::OnDraw(CDC* /*pDC*/)
{
	CMy83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy83View printing


void CMy83View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy83View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy83View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy83View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy83View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy83View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy83View diagnostics

#ifdef _DEBUG
void CMy83View::AssertValid() const
{
	CView::AssertValid();
}

void CMy83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy83Doc* CMy83View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy83Doc)));
	return (CMy83Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy83View message handlers
