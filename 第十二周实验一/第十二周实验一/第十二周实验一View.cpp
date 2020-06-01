
// 第十二周实验一View.cpp : C第十二周实验一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第十二周实验一.h"
#endif

#include "第十二周实验一Set.h"
#include "第十二周实验一Doc.h"
#include "第十二周实验一View.h"
#include"Dialogo1.h"
#include"ADD.h"
#include"query.h"
#include"record_set.h"
#include"sort.h"
#include"increase.h"
#include"prompt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第十二周实验一View

IMPLEMENT_DYNCREATE(C第十二周实验一View, CRecordView)

BEGIN_MESSAGE_MAP(C第十二周实验一View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &C第十二周实验一View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &C第十二周实验一View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C第十二周实验一View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C第十二周实验一View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C第十二周实验一View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON2, &C第十二周实验一View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &C第十二周实验一View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &C第十二周实验一View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &C第十二周实验一View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &C第十二周实验一View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C第十二周实验一View::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &C第十二周实验一View::OnBnClickedButton8)
END_MESSAGE_MAP()

// C第十二周实验一View 构造/析构

C第十二周实验一View::C第十二周实验一View()
	: CRecordView(IDD_MY_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birthday(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, filename(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\Users\\Hasee\\Desktop\\学生相片\\");
}

C第十二周实验一View::~C第十二周实验一View()
{
}

void C第十二周实验一View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->column8);
	
}

BOOL C第十二周实验一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C第十二周实验一View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_第十二周实验一Set;
	CRecordView::OnInitialUpdate();

}


// C第十二周实验一View 诊断

#ifdef _DEBUG
void C第十二周实验一View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C第十二周实验一View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C第十二周实验一Doc* C第十二周实验一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第十二周实验一Doc)));
	return (C第十二周实验一Doc*)m_pDocument;
}
#endif //_DEBUG


// C第十二周实验一View 数据库支持
CRecordset* C第十二周实验一View::OnGetRecordset()
{
	return m_pSet;
}



// C第十二周实验一View 消息处理程序


void C第十二周实验一View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Dialogo1 dlg;
	if (m_pSet->column8 == "")
		dlg.s = "";
	else dlg.s = path+m_pSet->column8;
	int n = dlg.DoModal();
	//if (n != IDOK)return;
	/*if (n == IDOK)
	{
		CImage img;
		img.Load(m_pSet->column8);
		CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC,  sx, sy, w, h);
		ReleaseDC(pDC);
	}*/
}


void C第十二周实验一View::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	CString file, s;
	GetDlgItemText(IDC_EDIT9, s);
	file = path + s;
	if (s != "") {
		CImage img;
		img.Load(file);
		pDC = GetDlgItem(IDC_STATIC)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void C第十二周实验一View::foo(CImage&img, int&sx, int&sy, int&w, int&h)
{
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
}



void C第十二周实验一View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void C第十二周实验一View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void C第十二周实验一View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if(m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void C第十二周实验一View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void C第十二周实验一View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	increase dlg;
	dlg.path = path;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		if (dlg.name=="")
		{
			prompt pro;
			int t = pro.DoModal();
			return;
		}
		m_pSet->AddNew();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.sex;
		m_pSet->column5 = dlg.birthday;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.address;
		m_pSet->column8 = dlg.filename;
		m_pSet->Update();
		m_pSet->MoveLast();
		UpdateData(false);
		Invalidate();
	}
}


void C第十二周实验一View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD dlg;
	int f;
	dlg.file= path + m_pSet->column8;
	if (m_pSet->column8 == "")
	{
		dlg.s = ""; f = 0;
	}
	else { dlg.s = path + m_pSet->column8; f = 1; }
	dlg.path = path;
	dlg.name = m_pSet->column1;
	dlg.number = m_pSet->column2;
	dlg.major= m_pSet->column3;
	dlg.sex = m_pSet->column4;
	dlg.birthday = m_pSet->column5;
	dlg.phone = m_pSet->column6;
	dlg.address = m_pSet->column7;
	dlg.filename = m_pSet->column8;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		if (f == 0) { f = dlg.f; }
		if (dlg.filename == ""&&f==1&&dlg.name == "")
		{
			prompt pro;
			int t=pro.DoModal();
			return;
		}
		m_pSet->Edit();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major ;
		m_pSet->column4 = dlg.sex ;
		m_pSet->column5 = dlg.birthday ;
		m_pSet->column6 = dlg.phone ;
		m_pSet->column7 = dlg.address;
		if (f == 1) {
			CString file = path + dlg.filename;
			rename(CT2A(dlg.s.GetString()), CT2A(file.GetString()));
		}
		m_pSet->column8 = dlg.filename;
		m_pSet->Update();
		UpdateData(false);
	}
}

void C第十二周实验一View::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}




void C第十二周实验一View::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	query q;
	int n = q.DoModal();
	if (n == IDOK) {
		UpdateData(true);
		m_pSet->m_strFilter = q.s;
		m_pSet->Requery();
		UpdateData(false);
	}
	Invalidate();

}


void C第十二周实验一View::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	sort s;
	int n = s.DoModal();
	if (n == IDOK) {
		UpdateData(true);
		m_pSet->m_strSort = s.s;
		m_pSet->Requery();
		UpdateData(false);
	}

}


void C第十二周实验一View::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	record_set r;

	CString str = _T("ID   姓名       学号     专业          性别   出生年月  手机号码  家庭住址     照片文件名 \r\n"), s;
	int t = m_pSet->GetODBCFieldCount();
	int f = m_pSet->m_ID; //记录指针弹出窗口前的位置ID
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		for (int i = 0; i < t; i++) {
			m_pSet->GetFieldValue((short)i, s);
			str = str + "  " + s;
		}
		str = str + _T("\r\n");
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	while (m_pSet->m_ID != f)  //退出窗口时指针指回弹出窗口前的位置
	{
		m_pSet->MoveNext();
	}
	r.s = str;
	r.DoModal();
	UpdateData(false);
}


void C第十二周实验一View::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter = _T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);
}
