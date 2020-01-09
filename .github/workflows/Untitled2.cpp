#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<string.h>
#include<windows.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
class DTM
{
	protected:
		string ma;
		string hang;
		string mau;
	public:
		DTM(){
			
		}
		DTM(string m,string h,string n)
		{
			ma = m;
			hang = h;
			mau = n;
		}
		DTM(DTM&a)
		{
		    ma  = a.ma;
			hang = a.hang;
			mau = a.mau;	
		}

	  void add()
		{
			cout<<"\nnhap ma so may tinh: "; cin.ignore(); getline(cin,ma); 
			cout<<"nhap hang ma tinh: "; cin.ignore(); getline(cin,hang);
			cout<<"nhap mau may tinh: "; cin.ignore(); getline(cin,mau);
			
		}
		void display()
		{
			cout<<setw(4)<<char(179)<<setw(6)<<ma<<setw(5)<<char(179)<<setw(10)<<hang<<setw(4)<<char(179)<<setw(6)<<mau;	
		}
		void in()
		{
			cout<<setw(12)<<ma<<setw(12)<<hang<<setw(12)<<mau;
	    }
		string getm()
		{
			return ma;
		}
		string geth()
		{
			return hang;
		}
		string getn()
		{
			return mau;
		}	
};

//===================================================================
class SV
{
	protected:
	     int masinhvien;
	     string hoten;
	     string lop;
	     string khoa;
	public:
		SV(){	
		}
		SV(string ht,string l,string k,int msv)
		{
			hoten = ht;
			masinhvien = msv;
			lop = l;
			khoa = k;
		
		}
		~SV()
		{	
		}
		SV(SV&a)
		{
			hoten = a.hoten;
			masinhvien = a.masinhvien;
			lop = a.lop;
			khoa = a.khoa;
		}
			void nhap()
		{
			cout<<"\nnhap ho ten: ";cin.ignore();getline(cin,hoten);
			cout<<"nhap msv: ";cin>>masinhvien;
			cout<<"nhap lop: ";cin.ignore();getline(cin,lop);
			cout<<"nhap khoa: ";cin.ignore();getline(cin,khoa);
		}
		void in()
		{
//			cout<<"\n"<<setw(14)<<"HOTEN"<<setw(15)<<"MSV"<<setw(12)<<"LOP"<<setw(12)<<"KHOA\n";
			cout<<setw(2)<<char(179)<<setw(19)<<hoten<<setw(4)<<char(179)<<setw(13)<<masinhvien<<setw(4)<<char(179)<<setw(11)<<lop<<setw(4)<<char(179)<<setw(8)<<khoa;
		}
		void intt()
		{
			cout<<setw(12)<<hoten<<setw(20)<<masinhvien<<setw(18)<<lop<<setw(12)<<khoa;
		}

	
};
//=======================================================
class TT : public DTM,public SV
{
	protected : 
	   string tinhtrang;
		
	public : 
	
		TT():DTM(),SV(){
		}
		TT(string m,string h,string n,string ht,string l,string k,string tt,int msv):DTM(m,h,n),SV(ht,l,k,msv)
		{
			tinhtrang = tt;
			
		}
		TT(TT&a):DTM((DTM&)a),SV((SV&)a){
		    tinhtrang = a.tinhtrang;
			
		}
		~TT(){
		}
		void add()
		{
			cout<<"tinh trang"; cin>>tinhtrang;//nhap thong tin may va tinh tranng
			DTM::add();	
			cout<<endl;	
		}
		void thongkemayroi()
		{  
		    if(tinhtrang=="roi"){
			
			   display();
			   cout<<setw(4)<<char(179)<<setw(6)<<tinhtrang<<setw(3)<<char(179)<<setw(1);//thong ke may roi 
			}			
		}
		void mayroi()
		{
			tinhtrang="roi";
			DTM::in();                         
			cout<<setw(10)<<tinhtrang<<endl;//chuyen tinh trang may tinh ban sang roi
		}
		void nhap()
		{
			if(tinhtrang=="roi")
		      return SV::nhap();		//nhap thong tin sinh vien thuc hanh khi may tinh roi
		}
		void thongkemayban()
		{
			  tinhtrang="ban"; 	
			  SV::in(),display(); 
			  cout<<setw(4)<<char(179)<<setw(6)<<tinhtrang<<setw(3)<<char(179)<<setw(1);//thong ke may ban khi them sinh vien vao
	    }
	    void chuyentt(){     
	    	
	    	if(tinhtrang=="ban"){    // chuyen tinh trang may ban sang roi
	    		tinhtrang="roi";
			}
		}
		void themsvkhimayroi(){  //them thong tin khi may roi
			tinhtrang="ban";
		}
	
	
	    void mayban()
		{ 	if(tinhtrang=="ban")
			SV::in(),display(); 
		    cout<<setw(4)<<char(179)<<setw(6)<<tinhtrang<<setw(3)<<char(179)<<setw(1);//khi tinh trang ban xuat danh sach sinh vien

		}
		string gettt(){
			return tinhtrang;
		}
	
};

int main(){
     TT *s[10];	
     string m,h,n,ht,l,k,tt;
     int msv;
     FILE *G;
     G = freopen("danhsach2.txt","r",stdin);//doc tep
   
	  int j = 0;
     while(true)
     { 
     	getline(cin,m);     	
		if(m.size()==0) break;
     	getline(cin,h);
     	getline(cin,n);
     	getline(cin,ht);
     	scanf("%d\n",&msv);
     	if(ht.size()==0) break;
     	getline(cin,l);
     	getline(cin,k);
     	getline(cin,tt);
     	scanf("%d\n",&msv);
     	s[j++]=new TT(m,h,n,ht,l,k,tt,msv);//doc thong tin trong tep;
    
	 }
	 
	 cout<<"***************************************************Thong tin may roi****************************************************\n\n";
	 cout<<setw(35)<<char(218)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(191);
	 cout<<"\n"<<setw(35)<<char(179)<<setw(3)<<"May"<<setw(4)<<char(179)<<setw(6)<<"MA"<<setw(5)<<char(179)<<setw(9)<<"HANG"<<setw(5)<<char(179)<<setw(7)<<"MAU"<<setw(3)<<char(179)<<setw(6)<<"TT"<<setw(3)<<char(179)<<setw(1)<<"\n";
	 for(int i=0;i<j;i++){
	 	cout<<"                                  "<<char(179)<<i+1<<"  "; s[i]->thongkemayroi();	//hien thi may tinh roi
		cout<<"\n"; 
	
	 }
	cout<<setw(35)<<char(192)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(217)<<"\n";
//	 freopen("thongtinmayban.txt","w",stdout);
	  cout<<"\n\n===================================================Thong tin may ban====================================================\n\n";
	  cout<<(char)218<<(char)196<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(191)<<"\n";
	  cout<<char(179)<<setw(4)<<"May"<<setw(2)<<char(179)<<setw(15)<<"HOTEN"<<setw(8)<<char(179)<<setw(10)<<"MSV"<<setw(7)<<char(179)<<setw(9)<<"LOP"<<setw(6)<<char(179)<<setw(8)<<"KHOA"<<setw(4)<<char(179)<<setw(6)<<"MA"<<setw(5)<<char(179)<<setw(9)<<"HANG"<<setw(5)<<char(179)<<setw(7)<<"MAU"<<setw(3)<<char(179)<<setw(6)<<"TT"<<setw(3)<<char(179)<<"\n"<<setw(1);
	  for(int i=0;i<j;i++){
        cout<<char(179)<<setw(2)<<i+1<<"  ";s[i]->thongkemayban();//hien thi may tinh ban va danh sach sinh vien
        cout<<"\n";
     }
     cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(217)<<"\n";
	 cout<<endl;


	
	 
	 
	 cout<<"An phim bat ky de hien thi thong tin chuyen doi trang thai\n\n";
	 getch();
	int g=3;
	cout<<"chuyen tinh trang may thu "<<g+2;
	s[g+1]->chuyentt();//chuyen tinh trang may thu 3
	 cout<<"\n***************************************************Thong tin may roi****************************************************\n\n";
	 cout<<setw(35)<<char(218)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(191);
	 cout<<"\n"<<setw(35)<<char(179)<<setw(5)<<"May"<<setw(2)<<char(179)<<setw(6)<<"MA"<<setw(5)<<char(179)<<setw(9)<<"HANG"<<setw(5)<<char(179)<<setw(7)<<"MAU"<<setw(3)<<char(179)<<setw(6)<<"TT"<<setw(3)<<char(179)<<setw(1)<<"\n";
	 	cout<<"                                  "<<char(179)<<g+2<<"  "; s[g+1]->thongkemayroi();	//hien thi may tinh roi
		cout<<"\n"; 
	cout<<setw(35)<<char(192)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(217)<<"\n";
   
	cout<<"An phim bat ky de hien thi thong tin chuyen doi trang thai\n\n";
	 getch();
	 
	
	
	
	
	cout<<"\n\n=======================================Thong tin may ban va thong tin may roi =====================================\n\n";
	cout<<(char)218<<(char)196<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(191)<<"\n";
	cout<<char(179)<<setw(4)<<"May"<<setw(2)<<char(179)<<setw(15)<<"HOTEN"<<setw(8)<<char(179)<<setw(10)<<"MSV"<<setw(7)<<char(179)<<setw(9)<<"LOP"<<setw(6)<<char(179)<<setw(8)<<"KHOA"<<setw(4)<<char(179)<<setw(6)<<"MA"<<setw(5)<<char(179)<<setw(9)<<"HANG"<<setw(5)<<char(179)<<setw(7)<<"MAU"<<setw(3)<<char(179)<<setw(6)<<"TT"<<setw(3)<<char(179)<<"\n"<<setw(1);
	for(int i=0;i<j;i++){
		cout<<char(179)<<setw(2)<<i+1<<"  "; s[i]->mayban();//thong tin may khi sau khi chuyen tinh trang
		cout<<"\n";
	}
	cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(217)<<"\n";
	cout<<endl;
	
	cout<<"An phim bat ky de hien thi thong tin chuyen doi trang thai\n\n";
	 getch();
	
	cout<<"Them sinh vien khi may tinh roi";
	s[g+1]->themsvkhimayroi();//them them thong tin nhung may roi
	cout<<"\n\n============================================Thong tin may ban sau khi bo sung==========================================\n\n";
	cout<<(char)218<<(char)196<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(191)<<"\n";
	cout<<char(179)<<setw(4)<<"May"<<setw(2)<<char(179)<<setw(15)<<"HOTEN"<<setw(8)<<char(179)<<setw(10)<<"MSV"<<setw(7)<<char(179)<<setw(9)<<"LOP"<<setw(6)<<char(179)<<setw(8)<<"KHOA"<<setw(4)<<char(179)<<setw(6)<<"MA"<<setw(5)<<char(179)<<setw(9)<<"HANG"<<setw(5)<<char(179)<<setw(7)<<"MAU"<<setw(3)<<char(179)<<setw(6)<<"TT"<<setw(3)<<char(179)<<"\n"<<setw(1);
	for(int i=0;i<j;i++){
		cout<<char(179)<<setw(2)<<i+1<<"  "; s[i]->thongkemayban();//thong tin may sau khi chuyen tinh trang
		cout<<"\n";
	}
	cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(217)<<"\n";
	cout<<endl;





//	 freopen("thongtinmayroi.d","w",stdout);
//	 cout<<"=======================Thong tin may roi======================\n\n";
//	 for(int i=0;i<j;i++){
//	 	cout<<setw(2)<<i+1<<". ";s[i]->thongkemayban();
//	 }
//	 freopen("thongtinmayban.txt","w",stdout);
//	  cout<<"=======================Thong tin may ban======================\n\n";
//	 for(int i=0;i<j;i++){
//	 	cout<<setw(2)<<i+1<<". ";s[i]->mayban();
//}
//	
	  

}

	
	
	



