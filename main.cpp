/*
	Description: Ohm's Law with Circuit Schematic / Devre şeması ve Ohm Kanunu
	Copyright: Muhammet Fatih KESKIN - 2018
*/
#include <iostream>
#include "Devre.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
			
int main(){
		float x1=4,x2=2,x3=2,x4=2,x5=2,x6=2,x7=2,x8=2,x9;
		float y1=5,y2=10,y3=5,y4=15,y5=1,y6=100,y7=30,y8=30,y9;
		float z1=20,z2=20,z3=10,z4=30,z5=10,z6=2,z7=200,z8=60,z9;
		  	 cout<<"\n-------------------------------COSTRUCTOR-------------------------------"<<endl;
		  	 cout<<endl;
	      	 Devre a(4,20,5,"Devre");//r-v-i
	      	 a.Print();
	      	 Devre b=a;
	     	 b.Print();
	      	 Devre c;
	     	 c=a;
	     	 c.Print();
	     	 cout<<endl;
	     	 Devre1(x1,y1,z1);
	     	 cout<<endl;
		 	 Devre d(2,20,10,"Degerler:");
	     	 d.Print();
	     	 cout<<endl;
		 	 Devre2(x2,y2,z2);
		 	 cout<<endl;
	     	 d.setI(5);
	     	 d.setV(10);
	     	 Devre e=d;
	     	 cout<<"\nHesaplama Sonrasi Yeni "<<e.getName()<<" Direnc = "<<e.getR()<<"\tVoltaj = "<<e.getV()<<"\tAkim = "<<e.getI()<<endl;
	      	 cout<<endl;
		 	 Devre3(x3,y3,z2,z3);
		 	 cout<<endl;
	     	 cout<<"\t\t\t-----OVERLOADING-----"<<endl;
	     	 cout<<endl;
	      	 Devre f=a+d;
	     	 cout<<"\t\t\t~~VOLT TOPLAMI~~(+)="<<f.getV()<<endl;
	     	 cout<<endl;
	     	 Devre g=a-d;
	     	 Devre4(x4,y4,z2,z4);
	     	 cout<<"\t\t\t~~VOLT FARKI~~(-)="<<g.getV()<<endl;
	     	 cout<<endl;
         	 Devre h=a/d;
             Devre3(x3,y3,z2,z3);
          	 cout<<endl;
          	 cout<<"\t\t\t~~VOLT BOLUMU~~(/)="<<h.getV()<<endl;
          	 cout<<endl;
             Devre5(x5,y5,z5);
          	 cout<<endl;
	      	 Devre j=a*d;
	      	 cout<<"\t\t\t~~VOLT CARPIMI~~(*)="<<j.getV()<<endl;
	      	 cout<<endl;
	      	 Devre6(x6,y6,z6);
	      	 Devre k;
	      	 for(int ii=0;ii<2;ii++){
	      		k+=a+k;
		  		}
		  	 cout<<endl;
	      	 cout<<"\t\t\t~~TOPLAM VOLTAJ~~(+=)="<<k.getV()<<endl;
	      	 cout<<endl;
	      	 Devre7(x7,y7,z7);
	      	 cout<<endl;
	      	 Devre l;
		     for( int ii=0;ii<2;ii++){
	      		l-=a-l;
		   		}
		   	 cout<<endl;
	         cout<<"\t\t\t~~FARK VOLTAJ~~(-=)="<<l.getV()<<"(Akim Ters Yondedir)"<<endl;
	         cout<<endl;
	  	     Devre8(x8,y8,z8);
	  	     cout<<endl;
	  	     cout <<"\t\t~~ESIT ESIT MIDIR VOLTAJ~~(==)"<<j.getV()<<"?"<<k.getV()<<endl;
	  	     cout<<endl;
			   if(j==k){
	  	     	cout<<"\t\tVoltaj Degerleri Esittir "<<"True"<<endl;
			   }
			 else{
			 	cout<<"\t\tVoltaj Degerleri Esit Degildir "<<"False"<<endl;
			 }
			 cout<<endl;
			 cout <<"\t\t~~ESIT DEGIL MIDIR VOLTAJ~~(!=)"<<j.getV()<<"?"<<k.getV()<<endl;
			 cout<<endl;
			   if(j!=k){
	  	     	cout<<"\t\tVoltaj Degerleri Esittir "<<"False"<<endl;
			   }
			 else{
			 	cout<<"\t\tVoltaj Degerleri Esit Degildir "<<"True"<<endl;
			 }
		   
		Devre::DevreCiz QQ;
		QQ.Hata1();
		Devre::Myexception Q;
		Q.Hata();
		
		return 0;
	}
