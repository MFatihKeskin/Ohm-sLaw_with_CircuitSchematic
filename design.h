#ifndef Devre_h 
#define Devre_h
#include <iostream>
using namespace std;

class Devre
{
		int r,i,v;
		char *name;
		public:
			Devre();
			Devre(float ,float ,float ,char*);
			Devre(float ,float ,float );
			Devre(const Devre&);
			Devre &operator = (const Devre &);
			~Devre();
//		cout <<"destructor\n"<<endl;
	
			void Print();
		
		
			void setAll(float,float,float,char*);
			void setR(float);
			void setV(float);
			void setI(float);
			void setName(char*);
	    	void Hesapla();
			
			const float getR();
			const float getI();
			const float getV();
			const char* getName();
		
			Devre operator + (Devre const &obj);
			Devre operator - (Devre const &obj);
			Devre operator * (Devre const &obj);
			Devre operator / (Devre const &obj);
			Devre operator += (Devre const &obj);
			Devre operator -= (Devre const &obj);
//			Devre operator == (Devre const &obj);
//			Devre operator != (Devre const &obj);
			bool operator == (Devre   &obj);
			bool  operator != (Devre   &obj);
		
			class Myexception{
				int resistor,current,voltage;
				public:
					void Hata();
			};
			class DevreCiz{
				float A,x9,y9,z9;
				public:
				void Hata1();
					void Devre9(float x9,float y9,float z9){
					cout <<"\t\t\t     Res="<<x9<<"     I="<<y9<<endl;
					cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
					cout <<"\t\t\t�                   �"<<endl;
					cout <<"\t\t\t�                   �"<<endl;
					cout <<"\t\t\t�                   �"<<endl;
					cout <<"\t\t\t�                   �"<<endl;
					cout <<"\t\t\t�--------|i---------�"<<endl;
					cout <<"\t\t\t        V="<<z9<<endl;}
				
				void Karisik(float s,float p,float i,float rs,float r,float r1,float rp,float rpt){
				cout<<"\nSeri Direnc Sayisi Gir: ";
				cin>>s;
				if(s!=0){
					for(i=0;i<s;i++){
						cout<<"Seri Direnc Degerlerini Sirasiyla Giriniz: ";
						cin>>r;
						rs+=r;
				}}
				else{
					rs=0;
				}
				cout<<"Seri Direnclerin Toplami: "<<rs<<endl<<endl;
				cout<<"Paralel Direnc Sayisi Gir: ";
				cin>>p;
				if(p!=0){
					for(i=0;i<p;i++){
						cout<<"Paralel Direnc Degerlerini Sirasiyla Giriniz: ";
						cin>>r1;
						rp+=1/r1;
						rpt=1/rp;
				}
				}
				else {
					rpt=0;}
				cout<<"Paralel Direnclerin Toplami: "<<rpt<<endl<<endl;
				cout<<"Karisik Devrenin Toplam Direnci: "<<rs+rpt<<endl<<endl;}
				//paralelde bir direnc bile 0 girilirse akim o kablodan gececegi i�in Re� 0 olur.
			};
		
			friend ostream& operator << (ostream &abc, const Devre &obj){
				abc << obj.r << obj.v << obj.i;
    			return abc;}
    		
      		friend ostream& operator >> (ostream &abc, const Devre &obj){
				abc << obj.r << obj.v << obj.i;
    			return abc;}   	

		};
		
		void Devre1(float x1,float y1,float z1);
		void Devre2(float x2,float y2,float z2);
		void Devre3(float x3,float y3,float z2,float z3);
		void Devre4(float x4,float y4,float z3,float z2);
		void Devre5(float x5,float y5,float z2);
		void Devre6(float x6,float y6,float z6);
		void Devre7(float x7,float y7,float z7);
		void Devre8(float x8,float y8,float z8);
		void Devre9(float x9,float y9,float z9);
#endif	
