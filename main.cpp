#include <iostream>
#include <string.h>
using namespace std;

	class Devre{
		int r,i,v;
		char *name;
		public:
			Devre();
			Devre(float ,float ,float ,char*);
			Devre(float ,float ,float );
			Devre(const Devre&);
			Devre &operator = (const Devre &);
			~Devre(){	};
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
					cout <<"\t\t\tİ                   İ"<<endl;
					cout <<"\t\t\tİ                   İ"<<endl;
					cout <<"\t\t\tİ                   İ"<<endl;
					cout <<"\t\t\tİ                   İ"<<endl;
					cout <<"\t\t\tİ--------|i---------İ"<<endl;
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
				//paralelde bir direnc bile 0 girilirse akim o kablodan gececegi için Reş 0 olur.
			};
		
			friend ostream& operator << (ostream &abc, const Devre &obj){
				abc << obj.r << obj.v << obj.i;
    			return abc;}
    		
      		friend ostream& operator >> (ostream &abc, const Devre &obj){
				abc << obj.r << obj.v << obj.i;
    			return abc;}   	

		};	
		
			void Devre::DevreCiz::Hata1(){
				float A,x9,y9,z9;
				float r,rs,s,i,p,r1,rp,rpt,a;
				cout<<endl;
				cout<<" GIRDIGINIZ DEGERLERE UYGUN ESDEGER DEVRE OLUSTURULACAKTIR"<<endl;
				cout<<endl;
				for(int A=0;A<5;A++){
					cout<<" \n\tYAPMAK ISTEDIGINIZ ISLEMI SECINIZ "<<endl;
					cout<<endl;
					cout<<"~ 0-Volt Bulma ~\t~ 1-Akim Bulma ~\t~ 2-Direnc Bulma ~\t~ 3-Karisik Devre Cozumu ~"<<endl;
					cout<<"\nIslem Numarasi: ";
					cin>>A;
				try{
					if (A==0){
						throw 0;
					}
					else if (A==1){
						throw 1;
					}
					else if (A==2){
						throw 2;
					}
					else if (A==3){
						throw 3;
					}
					else{
						cout<<"\nHatali Tuslama Yaptiniz!\n"<<endl;
					}
					
				}
				catch(int key){
					switch(key){
						case 0:{
							cout<<"Direnc ve Akim giriniz"<<endl;
							cin>>x9>>y9;
							z9=x9*y9;
							cout<<"Volt= "<<z9<<endl;
							Devre9(x9,y9,z9);
							break;
						}
						case 1:{
							cout<<"\nDirenc ve Volt giriniz"<<endl;
							cin>>x9>>z9;
							y9=z9/x9;
							cout<<"Akim="<<y9<<endl;
							Devre9(x9,y9,z9);
							break;
						}
						case 2:{
							cout<<"\nAkim ve Volt giriniz"<<endl;
							cin>>y9>>z9;
							x9=z9/y9;
							cout<<"Direnc="<<x9<<endl;	
							Devre9(x9,y9,z9);
							break;}
						case 3:{
							Karisik(s,p,i,rs,r,r1,rp,rpt);
							break;}
						}
					}
				}
			}
			void Devre::Myexception::Hata(){
				float resistor,current,voltage,A;
				cout<<"--------EXCEPTION HANDLING-----------\n"<<endl;
				for (int Q=0;Q<4;Q++){
					cout<<"\nGirdiginiz Degerler Kontrol Edilecektir."<<endl<<endl;;
					cout<<"Direnc Degeri Giriniz: ";
					cin>>resistor;
					cout<<"Akim Degeri Giriniz:   ";
					cin>>current;
					cout<<"Voltaj Degeri Giriniz: ";
					cin>>voltage;
					try{
					
						if (resistor<=0){
							throw 0;
						}				
						else if (current<=0){
							throw 1;
						}					
						else if (voltage<=0){
							throw 2;	
						}
						else if(voltage!=resistor*current){
							throw 3;
						}
						else {
							cout<<"\nHata Algilanmadi\n"<<endl;
						}
					}
				catch (int kod){
					switch(kod){
						case 0:{
							cout<<"\nHATA---->>Kisa Devre Guc Kaynagini Devreden Cikartiniz\n"<<endl;
							break;}
						case 1:{
							cout<<"\nHATA---->>Devreye Guc Kaynagi Bagli Degildir Veya Acik Devre\n"<<endl;
							break;}
						case 2:{
							cout<<"\nHATA---->>Devreye Guc Kaynagi Bagli Degildir\n"<<endl;
							break;}	
						case 3:{
							cout<<"\nHATA---->>Hatali Guc Kaynagi Sectiniz"<<endl;
							break;
						}
						}
					}
				}
			}
			void Devre1(float,float,float);
			void Devre2(float,float,float);
			void Devre3(float,float,float);
			void Devre4(float,float,float);
			void Devre5(float,float,float);
			void Devre6(float,float,float);
			void Devre7(float,float,float);
			void Devre8(float,float,float);
			void Devre9(float,float,float);
			
		Devre::Devre(){
			r=0;
			i=0;
			v=0;
			name="Yok";	
		}
		
		Devre::Devre(float R,float V,float I,char *Name){
			r=R;
			i=I;
			v=V;
			name=Name;
		}
		Devre::Devre(float R,float I,float V){
			r=R;
			v=V;
			i=I;
			name="Devre";
		}
		Devre::Devre(const Devre &obj){
			r=obj.r;
			i=obj.i;
			v=obj.v;
			name=obj.name;
		}
		Devre& Devre::operator=(const Devre &obj){
			r=obj.r;
			i=obj.i;
			v=obj.v;
			name=obj.name;
		}
		void Devre::setAll(float R,float I,float V,char *Name){
			r=R;
			i=I;
			v=V;
			name=Name;
		}
		void Devre::setI(float I){
			i=I;
		}
		void Devre::setV(float V){
			v=V;
		}
		void Devre::setName(char *Name){
			name=Name;
		}
		void Devre::setR(float R){
			r=R;
		}
		const float Devre::getI(){
			return i;
		}
		const float Devre::getR(){
			return r;
		}
		const float Devre::getV(){
			return v;
		}
		const char* Devre::getName(){
			return name;
		}
           void Devre::Print(){
           cout <<"Devre Elemanlarinin Degerleri : "<<" Direnc = "<<r<<"\tVoltaj = "<<v<<"\tAkim = "<<i<<endl;
		}

        
    	Devre  Devre::operator + (Devre const &obj) { 
         	Devre sum; 
         	sum.v = v + obj.v; 
         	return sum;}
		Devre Devre::operator - (Devre const &obj){ 
			Devre minus;
			minus.v = v - obj.v;
			return minus;}
		Devre Devre::operator / (Devre const &obj){
			Devre split;
			split.v = v / obj.v;
			return split;}
		Devre Devre::operator * (Devre const &obj){
			Devre multi;
			multi.v = v * obj.v;
			return multi;}
		Devre Devre::operator += (Devre const &obj){
			Devre sum_write;
			sum_write.v = v += obj.v;
			return sum_write;}
		Devre Devre::operator -= (Devre const &obj){
			Devre minus_write;
			minus_write.v = v -= obj.v;
			return minus_write;}
//		Devre Devre::operator == (Devre const &obj){
//			Devre equal;
//			equal.v = v == obj.v;
//			return equal;}
//		Devre Devre::operator != (Devre const &obj){
//			Devre not_equal;
//			not_equal.v = v != obj.v;
//			return not_equal;}
		bool Devre::operator == (Devre  &obj){
			if(obj.v==this->v){
			return true;
			}
			return false;}
		bool Devre::operator != (Devre   &obj){
			if(obj.v==this->v){
			return true;
			}
			return false;}


		void Devre1(float x1,float y1,float z1){
		cout <<"\t\t\t     Res="<<x1<<"    I="<<y1<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ---------|i--------İ"<<endl;
		cout <<"\t\t\t         V="<<z1<<endl;}
		
		void Devre2(float x2,float y2,float z2){
		cout <<"\t\t\t     Res="<<x2<<"    I="<<y2<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ---------|i--------İ"<<endl;
		cout <<"\t\t\t         V="<<z2<<endl;}
		
		void Devre3(float x3,float y3,float z2,float z3){
		cout <<"\t\t\t     Res="<<x3<<"    I="<<y3<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ----i|------|i-----İ"<<endl;
		cout <<"\t\t\t    V="<<z2<<"    V="<<z3<<endl;}
		
		void Devre4(float x4,float y4,float z3,float z2){
		cout <<"\t\t\t     Res="<<x4<<"    I="<<y4<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ----|i-------|i----İ"<<endl;
		cout <<"\t\t\t    V="<<z3<<"     V="<<z2<<endl;
		cout<<endl;}

		void Devre5(float x5,float y5,float z2){
		cout <<"\t\t\t     Res="<<x5<<"     I="<<y5<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ-----|i------i|----İ"<<endl;
		cout <<"\t\t\t     V=20    V=18    "<<endl;}
		
		void Devre6(float x6,float y6,float z6){
		cout <<"\t\t\t     Res="<<x6<<"    I="<<y6<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ----|i-----|i------İ"<<endl;
		cout <<"\t\t\t    V=20   V=180     "<<endl;}
		
		void Devre7(float x7,float y7,float z7){
		cout <<"\t\t\t     Res="<<x7<<"    I="<<y7<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ---|i----|i---|i---İ"<<endl;
		cout <<"\t\t\t   v=20  V=20 V=20  "<<endl;}
		
		void Devre8(float x8,float y8,float z8){
		cout <<"\t\t\t     Res="<<x8<<"    I="<<y8<<endl;
		cout <<"\t\t\t----vvvvvvv----<<----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ---|i----|i---|i---İ"<<endl;
		cout <<"\t\t\t   v=20  V=20 V=20  "<<endl;}
		
		void Devre9(float x9,float y9,float z9){
		cout <<"\t\t\t     Res="<<x9<<"     I="<<y9<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ                   İ"<<endl;
		cout <<"\t\t\tİ--------|i---------İ"<<endl;
		cout <<"\t\t\t        V="<<z9<<endl;}
		
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
		 	 Devre3(x3,y3,z3,z2);
		 	 cout<<endl;
	     	 cout<<"\t\t\t-----OVERLOADING-----"<<endl;
	     	 cout<<endl;
	      	 Devre f=a+d;
	     	 cout<<"\t\t\t~~VOLT TOPLAMI~~(+)="<<f.getV()<<endl;
	     	 cout<<endl;
	     	 Devre g=a-d;
	     	 Devre4(x4,y4,z3,z2);
	     	 cout<<"\t\t\t~~VOLT FARKI~~(-)="<<g.getV()<<endl;
	     	 cout<<endl;
         	 Devre h=a/d;
             Devre3(x3,y3,z3,z2);
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
