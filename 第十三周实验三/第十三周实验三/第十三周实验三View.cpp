
// 第十三周实验三View.cpp : C第十三周实验三View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第十三周实验三.h"
#endif

#include "第十三周实验三Set.h"
#include "第十三周实验三Doc.h"
#include "第十三周实验三View.h"
#include"ADD.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第十三周实验三View

IMPLEMENT_DYNCREATE(C第十三周实验三View, CRecordView)

BEGIN_MESSAGE_MAP(C第十三周实验三View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &C第十三周实验三View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C第十三周实验三View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C第十三周实验三View::OnBnClickedButton3)
END_MESSAGE_MAP()

// C第十三周实验三View 构造/析构

C第十三周实验三View::C第十三周实验三View()
	: CRecordView(IDD_MY_FORM)
	, s(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C第十三周实验三View::~C第十三周实验三View()
{
}

void C第十三周实验三View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C第十三周实验三View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C第十三周实验三View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_第十三周实验三Set;
	CRecordView::OnInitialUpdate();

}


// C第十三周实验三View 诊断

#ifdef _DEBUG
void C第十三周实验三View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C第十三周实验三View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C第十三周实验三Doc* C第十三周实验三View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第十三周实验三Doc)));
	return (C第十三周实验三Doc*)m_pDocument;
}
#endif //_DEBUG


// C第十三周实验三View 数据库支持
CRecordset* C第十三周实验三View::OnGetRecordset()
{
	return m_pSet;
}



// C第十三周实验三View 消息处理程序


void C第十三周实验三View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD dlg;
	int n = dlg.DoModal();
	if (n==IDOK)
	{
		m_pSet->AddNew();
		m_pSet->m_1 = dlg.s;
		m_pSet->Update();
		m_pSet->MoveLast();
		UpdateData(false);
	}

}


void C第十三周实验三View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD dlg;
	dlg.s=m_pSet->m_1;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		m_pSet->Edit();
		m_pSet->m_1 = dlg.s;
		m_pSet->Update();
		UpdateData(false);
	}
}


void C第十三周实验三View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}

