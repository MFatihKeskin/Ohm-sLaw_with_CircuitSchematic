#include "Devre.h"
#include <iostream>

using namespace std;



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
//		void Devre::setI(float I){
//			i=I;
//		}
//		void Devre::setV(float V){
//			v=V;
//		}
//		void Devre::setName(char *Name){
//			name=Name;
//		}
//		void Devre::setR(float R){
//			r=R;
//		}
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
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�---------|i--------�"<<endl;
		cout <<"\t\t\t         V="<<z1<<endl;}
		
		void Devre2(float x2,float y2,float z2){
		cout <<"\t\t\t     Res="<<x2<<"    I="<<y2<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�---------|i--------�"<<endl;
		cout <<"\t\t\t         V="<<z2<<endl;}
		
		void Devre3(float x3,float y3,float z2,float z3){
		cout <<"\t\t\t     Res="<<x3<<"    I="<<y3<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�----i|------|i-----�"<<endl;
		cout <<"\t\t\t    V="<<z2<<"    V="<<z3<<endl;}
		
		void Devre4(float x4,float y4,float z3,float z2){
		cout <<"\t\t\t     Res="<<x4<<"    I="<<y4<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�----|i-------|i----�"<<endl;
		cout <<"\t\t\t    V="<<z3<<"     V="<<z2<<endl;
		cout<<endl;}

		void Devre5(float x5,float y5,float z2){
		cout <<"\t\t\t     Res="<<x5<<"     I="<<y5<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�-----|i------i|----�"<<endl;
		cout <<"\t\t\t     V=20    V=18    "<<endl;}
		
		void Devre6(float x6,float y6,float z6){
		cout <<"\t\t\t     Res="<<x6<<"    I="<<y6<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�----|i-----|i------�"<<endl;
		cout <<"\t\t\t    V=20   V=180     "<<endl;}
		
		void Devre7(float x7,float y7,float z7){
		cout <<"\t\t\t     Res="<<x7<<"    I="<<y7<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�---|i----|i---|i---�"<<endl;
		cout <<"\t\t\t   v=20  V=20 V=20  "<<endl;}
		
		void Devre8(float x8,float y8,float z8){
		cout <<"\t\t\t     Res="<<x8<<"    I="<<y8<<endl;
		cout <<"\t\t\t----vvvvvvv----<<----"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�---|i----|i---|i---�"<<endl;
		cout <<"\t\t\t   v=20  V=20 V=20  "<<endl;}
		
		void Devre9(float x9,float y9,float z9)
		{
		cout <<"\t\t\t     Res="<<x9<<"     I="<<y9<<endl;
		cout <<"\t\t\t----vvvvvvv---->>----"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�                   �"<<endl;
		cout <<"\t\t\t�--------|i---------�"<<endl;
		cout <<"\t\t\t        V="<<z9<<endl;
		}
		
		Devre::~Devre()
		{
		 	delete[] name;
		}
