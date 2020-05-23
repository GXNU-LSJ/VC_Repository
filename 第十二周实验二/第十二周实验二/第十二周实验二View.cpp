
// 第十二周实验二View.cpp : C第十二周实验二View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第十二周实验二.h"
#endif

#include "第十二周实验二Set.h"
#include "第十二周实验二Doc.h"
#include "第十二周实验二View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第十二周实验二View

IMPLEMENT_DYNCREATE(C第十二周实验二View, CRecordView)

BEGIN_MESSAGE_MAP(C第十二周实验二View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C第十二周实验二View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C第十二周实验二View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C第十二周实验二View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C第十二周实验二View::OnRecordLast)
	ON_EN_CHANGE(IDC_EDIT1, &C第十二周实验二View::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C第十二周实验二View 构造/析构

C第十二周实验二View::C第十二周实验二View()
	: CRecordView(IDD_MY_FORM)
	, filename(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\Users\\Hasee\\Desktop\\学生相片\\");
}

C第十二周实验二View::~C第十二周实验二View()
{
}

void C第十二周实验二View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column8);
}

BOOL C第十二周实验二View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C第十二周实验二View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_第十二周实验二Set;
	CRecordView::OnInitialUpdate();

}


// C第十二周实验二View 诊断

#ifdef _DEBUG
void C第十二周实验二View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C第十二周实验二View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C第十二周实验二Doc* C第十二周实验二View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第十二周实验二Doc)));
	return (C第十二周实验二Doc*)m_pDocument;
}
#endif //_DEBUG


// C第十二周实验二View 数据库支持
CRecordset* C第十二周实验二View::OnGetRecordset()
{
	return m_pSet;
}



// C第十二周实验二View 消息处理程序
void C第十二周实验二View::Draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sy = (rect.Height() - h) / 2;
		sx = 0;
	}
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}




void C第十二周实验二View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void C第十二周实验二View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void C第十二周实验二View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void C第十二周实验二View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void C第十二周实验二View::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void C第十二周实验二View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()

	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	Draw_pic(filename);
}
