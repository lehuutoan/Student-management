#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//tao cau truc sinh vien
struct ngaysinh 
	{
		int ngay, thang, nam;
	};
struct SinhVien
{
	int masv, gioitinh;
	ngaysinh sinhngay;
	char hoten[50], diachi[100], lop[12], khoa[7];
};
//tao cau truc danh sach lien ket don;
struct Node
{
	SinhVien *data;
	Node *link;
};
struct List
{
	Node *first;
	Node *last;
};
//khoi tao danh sach lien ket don
void Initialize(List *&list)
{
	list=new List;
	list->first=NULL;
}
//nhap thong tin sinh vien
SinhVien *NhapSinhVien()
{
	SinhVien *sv=new SinhVien;
	cout<<"Nhap ho va ten:"<<endl;
	gets(sv->hoten);
	cout<<"Nhap MSSV:"<<endl;
	cin>>sv->masv;
	cin.ignore();
	cout<<"Sinh ngay"<< endl;
	cout<<"ngay:"<<endl;
	cin>>sv->sinhngay.ngay;
	cout<<"thang:"<<endl;
	cin>>sv->sinhngay.thang;
	cout<<"nam:"<<endl;
	cin>>sv->sinhngay.nam;
	cin.ignore();
	cout<<"diachi:"<<endl;
	gets(sv->diachi);
	cout<<"lop:"<<endl;
	gets(sv->lop);
	cout<<"khoa:"<<endl;
	gets(sv->khoa);
	return sv;
}
//tao node sinh vien
Node *CreateNode(SinhVien *sv)
{
	Node *pNode=new Node;
	if(pNode!=NULL)
	{
		pNode->data=sv;
		pNode->link=NULL;
	}
	else
	{
		cout<<"cap phat bo nho that bai!!!";
	}
	return pNode;
}
//them node vao cuoi danh sach
void InsertLast(List *&list,SinhVien *sv)
{
	Node *pNode=CreateNode(sv);
	if(list->first==NULL)
	{
		list->first=pNode;
	}
	else
	{
		Node *pTmp=list->first;
		
		while(pTmp->link!=NULL)
		{
			pTmp=pTmp->link;
		}
		pTmp->link=pNode;
	}
}
//hien thi danh sach
void PrintList(List *list)
{
	Node *pTmp=list->first;
	if(pTmp==NULL)
	{
		cout<<"Danh sach rong";
		return;
	}
	while(pTmp!=NULL)
	{
		SinhVien *sv=pTmp->data;
		cout<<"hovaten: "<<sv->hoten<<endl<<"mssv: "<<sv->masv<<endl<<"diachi: "<<sv->diachi<<endl<<"lop: "<<sv->lop<<endl<<"khoa: "<<sv->khoa<<endl;
		pTmp=pTmp->link;
	}
}
//sap xep
void SortList(List *&list)
{
	for(Node *pTmp=list->first;pTmp!=NULL;pTmp=pTmp->link)
	{
		for(Node *pTmp2=pTmp->link;pTmp2!=NULL;pTmp2=pTmp2->link)
		{	
			SinhVien *svTmp=pTmp->data;
			SinhVien *svTmp2=pTmp2->data;
			if(svTmp2->masv<svTmp->masv)
			{
				int masv=svTmp->masv;
				char hoten[50];
				strcpy(hoten,svTmp->hoten);
				
				svTmp->masv=svTmp2->masv;
				strcpy(svTmp->hoten,svTmp2->hoten);
				svTmp2->masv=masv;
				strcpy(svTmp2->hoten,hoten);				
			}
		}	
	}
}
//xoa
void RemoveNode(List *&list,int masv)
{
	Node *pDel=list->first;
	if(pDel==NULL)
	{
		cout<<"Danh sach rong!";
	}
	else
	{
		Node *pPre=NULL;
		while(pDel!=NULL)
		{
			SinhVien *sv=pDel->data;
			if(sv->masv==masv)
				break;
			pPre=pDel;
			pDel=pDel->link;
		}
		if(pDel==NULL)
		{
			cout<<"khong tim thay MSSV: "<<masv;
		}
		else
		{
			if(pDel==list->first)
			{
				list->first=list->first->link;
				pDel->link=NULL;
				delete pDel;
				pDel=NULL;
			}
			else
			{
				pPre->link=pDel->link;
				pDel->link=NULL;
				delete pDel;
				pDel=NULL;
			}
		}
	}
}
int main(int argc, char** argv) {
	List *list;
	Initialize(list);
	SinhVien *toan=NhapSinhVien();
	InsertLast(list,toan);
	SinhVien *trung=NhapSinhVien();
	InsertLast(list,trung);
	SinhVien *tuan=NhapSinhVien();
	InsertLast(list,tuan);
	PrintList(list);
	SortList(list);
	cout<<"\nSau khi sap xep:\n";
	PrintList(list);
	cout<<"\nBan muon xoa sinh vien co MSSV: ";
	int masv;
	cin>>masv;
	RemoveNode(list,masv);
	cout<<"\nSau khi xoa:\n";
	PrintList(list);

}
