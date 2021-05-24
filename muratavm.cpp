#include <iostream>
#include <fstream>
#include <string.h>
int ms=0;
int const MAX=50;
using namespace std;
enum kontrol{
	dolu,bos
}musteriler[MAX];

class temel1{
	protected:
		string *musteri_id[MAX];	
		string *ad[MAX];
		string *soyad[MAX];
		string *telefon[MAX];
		int *borc[MAX];
	public:
		void ekle();
		void listele();
		void ara();
		

};
void temel1::ekle(){
	char tel[11];
	musteriler[ms]=bos;
	ad[ms]= new string;
	soyad[ms]= new string;
	telefon[ms]= new string;
	borc[ms]= new int;
	cout<<"Ad: ";
	cin>>*ad[ms];
	cout<<"Soyad: ";
	cin>>*soyad[ms];
	do{
	cout<<"Telefon: ";
	cin>>tel;
	
	if(tel[0]=='0' && strlen(tel)==11)
	*telefon[ms]=tel;
	
	else if(tel[0]!='0'){
		cout<<"Telefon numarasinin basinda '0' olmali.."<<endl;
	}
	else{
		cout<<"Numarayi 11 haneli girdiginizden emin olun.."<<endl;
	}
	}while(tel[0]!='0' || strlen(tel)!=11);
	cout<<"Borc: ";
	cin>>*borc[ms];
	
}
void temel1::listele(){
	cout<<"**Kayitli olmayan musteriler program kapandiginda silinir.."<<endl;
	
	for(int i=0; i<ms; i++){
	if(musteriler[i]==dolu){
	
	cout<<"Ad Soyad: "<<*ad[i]<<" "<<*soyad[i];
	cout<<" / Telefon: "<<*telefon[i];
	cout<<" / Borc: "<<*borc[i]<<" TL";
	cout<<" / Musteri ID: "<<*musteri_id[i]<<endl;	
	}
	else{
	cout<<"**Ad Soyad: "<<*ad[i]<<" "<<*soyad[i];
	cout<<" / Telefon: "<<*telefon[i];
	cout<<" / Borc: "<<*borc[i]<<" TL";
	cout<<" / Musteri ID: "<<*musteri_id[i]<<endl;	
	}
}
	if(ms==0)
	cout<<"Kayitli hic musteri yok.."<<endl;
	
	else	cout<<"Musteri sayisi = "<<ms<<endl;
}
void temel1::ara(){
	string ara;
	int olumlu=0;
	cout<<"Aranacak musterinin ID Numarasi: ";
	cin>>ara;
	for(int i=0; i<ms; i++){
		if(ara==*musteri_id[i]){
			if(olumlu==0)
			cout<<"ID Numarasi '"<<ara<<"' olan musteri; "<<endl;
			cout<<"Ad Soyad: "<<*ad[i]<<" "<<*soyad[i];
			cout<<" / Telefon: "<<*telefon[i];
			cout<<" / Borc: "<<*borc[i]<<" TL"<<endl;	
			olumlu=1;
		}
	}
	if(olumlu!=1)
	cout<<"ID Numarasi '"<<ara<<"' olan musteri yok!! "<<endl;
}

class temel2: public temel1{
	public:
		void sil();
		void kaydi_sil();
		void kaydet();
		void kaydet(char sakla[]);
		void guncelle();
};
void temel2::sil(){
		int sira=0;
		string okunan_ad,okunan_soyad,okunan_telefon,okunan_id;
		string checkID;
		int okunan_borc,y;
		
		cout<<"Silinecek musterinin ID numarasini giriniz.."<<endl;
		cin>>checkID;
		
		
		ifstream dosya_oku;
		ofstream dosya_yaz;
		dosya_oku.open("musteri bilgileri.txt");
		dosya_yaz.open("yeni musteri bilgileri.txt");
		
		if(dosya_oku.is_open() && dosya_yaz.is_open()){
		while(dosya_oku>>okunan_ad>>okunan_soyad>>okunan_telefon>>okunan_borc>>okunan_id){
		if(checkID==okunan_id){
			
		for(int i=sira; i<ms-1; i++){
				
			
			ad[i]=ad[i+1];
			soyad[i]=soyad[i+1];
			telefon[i]=telefon[i+1];
			borc[i]=borc[i+1];
			musteri_id[i]=musteri_id[i+1];
			
		
		
		}
		delete ad[ms-1];
		delete soyad[ms-1];
		delete telefon[ms-1];
		delete borc[ms-1];
		delete musteri_id[ms-1];
		
		
		ms--;
		
		cout<<"Musteri  silindi!!"<<endl;
		y=1;
	}
		else if(checkID!=okunan_id){
		
		dosya_yaz<<okunan_ad<<" ";
		dosya_yaz<<okunan_soyad<<" ";
		dosya_yaz<<okunan_telefon<<" ";
		dosya_yaz<<okunan_borc<<" ";
		dosya_yaz<<okunan_id<<endl;
		
	
}
					
	sira++;	
}

		dosya_yaz.close();
		dosya_oku.close();
		
		remove("musteri bilgileri.txt");
		rename("yeni musteri bilgileri.txt", "musteri bilgileri.txt");
		
		
		if(y!=1)
		cout<<"Musteri bulunamadi."<<endl;
}
	else cout<<"Dosya acilirken bir hata olustu."<<endl;
}
void temel2::kaydi_sil(){
	string secim;
	cout<<"Butun veriler silinecek!! Eminseniz 'sil' yazin.."<<endl;
	cin>>secim;
	
	if(secim=="sil"){
		remove("musteri bilgileri.txt");
		cout<<"Butun veriler silindi."<<endl;
		for(int i=0; i<ms; i++){
			delete ad[i];
			delete soyad[i];
			delete telefon[i];
			delete borc[i];
			delete musteri_id[i];
		}
		ms=0;
	}
	else cout<<"Islem basarisiz."<<endl;
}
void temel2::kaydet(){
		ofstream dosya_yaz;
	dosya_yaz.open("musteri bilgileri.txt",ios::app);
	
	if(dosya_yaz.is_open()){
	for(int i=0; i<ms; i++){
		
	if(musteriler[i]==bos){
	dosya_yaz<<*ad[i]<<" ";
	dosya_yaz<<*soyad[i]<<" ";
	dosya_yaz<<*telefon[i]<<" ";
	dosya_yaz<<*borc[i]<<" ";
	dosya_yaz<<*musteri_id[i]<<endl;
	musteriler[i]=dolu;
	}
}	
	dosya_yaz.close();
	cout<<"Guncel liste kaydedildi!!"<<endl;
}
	else cout<<"Dosya acilirken bir hata olustu."<<endl;
}
void temel2::kaydet(char sakla[]){
		ofstream dosya_yaz;
	dosya_yaz.open(sakla);
	
	if(dosya_yaz.is_open()){
	for(int i=0; i<ms; i++){
		
	if(musteriler[i]==dolu){
	dosya_yaz<<*ad[i]<<" ";
	dosya_yaz<<*soyad[i]<<" ";
	dosya_yaz<<*telefon[i]<<" ";
	dosya_yaz<<*borc[i]<<" ";
	dosya_yaz<<*musteri_id[i]<<endl;
	}
}	
	dosya_yaz.close();
	cout<<"Kayitli veriler "<<sakla<<" adi altinda kaydedildi."<<endl;
}
	else cout<<"Dosya acilirken bir hata olustu."<<endl;
}
void temel2::guncelle(){
		string okunan_ad,okunan_soyad,okunan_telefon,okunan_id;
		string checkID;
		string yeni_string_bilgi;
		int yeni_int_bilgi;
		int okunan_borc,y;
		int secim,sira=0;
		
		cout<<"Duzenlenecek musterinin ID numarasini giriniz.."<<endl;
		cin>>checkID;
		
		ifstream dosya_oku;
		ofstream dosya_yaz;
		dosya_oku.open("musteri bilgileri.txt");
		dosya_yaz.open("yeni musteri bilgileri.txt");
		
		if(dosya_oku.is_open() && dosya_yaz.is_open()){
		while(dosya_oku>>okunan_ad>>okunan_soyad>>okunan_telefon>>okunan_borc>>okunan_id){
		if(checkID==okunan_id){
			
			cout<<"Musterinin hangi verisini degistirmek istiyorsunuz?"<<endl;
			cout<<"1.Ad"<<endl;
			cout<<"2.Soyad"<<endl;
			cout<<"3.Telefon"<<endl;
			cout<<"4.Borc"<<endl;
			cout<<"5.Musteri ID"<<endl;
			cin>>secim;
			switch(secim){
				case 1:
					cout<<"Yeni Ad: ";
					cin>>yeni_string_bilgi;
					*ad[sira]=yeni_string_bilgi;
					okunan_ad=yeni_string_bilgi;
					break;
				case 2:
					cout<<"Yeni Soyad: ";
					cin>>yeni_string_bilgi;
					*soyad[sira]=yeni_string_bilgi;
					okunan_soyad=yeni_string_bilgi;
					break;
				case 3:
					cout<<"Yeni Telefon: ";
					cin>>yeni_string_bilgi;
					*telefon[sira]=yeni_string_bilgi;
					okunan_telefon=yeni_string_bilgi;
					break;
				case 4:
					cout<<"Yeni Borc: ";
					cin>>yeni_int_bilgi;
					*borc[sira]=yeni_int_bilgi;
					okunan_borc=yeni_int_bilgi;
					break;
				case 5:
					cout<<"Yeni Musteri ID: ";
					cin>>yeni_string_bilgi;
					*musteri_id[sira]=yeni_string_bilgi;
					okunan_id=yeni_string_bilgi;
					break;
				default:
					cout<<"gecersiz giris!!"<<endl;
					break;
			}
			
		dosya_yaz<<okunan_ad<<" ";
		dosya_yaz<<okunan_soyad<<" ";
		dosya_yaz<<okunan_telefon<<" ";
		dosya_yaz<<okunan_borc<<" ";
		dosya_yaz<<okunan_id<<endl;
		
		
		
		
		cout<<"Musteri  guncellendi!!"<<endl;
		y=1;
	}
		else if(checkID!=okunan_id){
		
		dosya_yaz<<okunan_ad<<" ";
		dosya_yaz<<okunan_soyad<<" ";
		dosya_yaz<<okunan_telefon<<" ";
		dosya_yaz<<okunan_borc<<" ";
		dosya_yaz<<okunan_id<<endl;
		
	
}
					
sira++;	
}

		dosya_yaz.close();
		dosya_oku.close();
		
		remove("musteri bilgileri.txt");
		rename("yeni musteri bilgileri.txt", "musteri bilgileri.txt");
		
		
		if(y!=1)
		cout<<"Musteri bulunamadi."<<endl;
}
	else cout<<"Dosya acilirken bir hata olustu."<<endl;
}

class avm: public temel2{

	public:
		avm(){
			for(int i=0; i<MAX; i++)
			musteriler[i]=bos;
		
	
		
		string okunan_ad,okunan_soyad,okunan_telefon,okunan_id;
		int okunan_borc;
		int i=0;
		
		ifstream dosya_oku;
		dosya_oku.open("musteri bilgileri.txt");
		
		
		while(dosya_oku>>okunan_ad>>okunan_soyad>>okunan_telefon>>okunan_borc>>okunan_id){
			ad[i]= new string;
			soyad[i]= new string;
			telefon[i]= new string;
			borc[i]= new int;
			musteri_id[i]= new string;
			
			
			*ad[i]=okunan_ad;
			*soyad[i]=okunan_soyad;
			*telefon[i]=okunan_telefon;
			*borc[i]=okunan_borc;
			*musteri_id[i]=okunan_id;
			
			ms++;
			i++;
		}
			dosya_oku.close();
			
		for(int i=0; i<ms; i++)
		musteriler[i]=dolu;
		
	
	
		
		}
		~avm(){}
		
		void setMusteri_id(string &musteri_id);
		string getMusteri_id(int boyut);
};

void avm::setMusteri_id(string &musteri_id){
	this->musteri_id[ms]= new string;
	this->musteri_id[ms]= &musteri_id;	}
	
string avm::getMusteri_id(int boyut){
	return *musteri_id[boyut];	}


int main (){

avm murat;

char sakla[20];
string id;
int secim,id_kontrol;
	string cikis;
	cout<<"==============="<<endl;
	cout<<" MURAT MARKET |"<<endl;
	do{
	cout<<"==============="<<endl;
	cout<<"1.Yeni Musteri|"<<endl;
	cout<<"2.Listele     |"<<endl;
	cout<<"3.Ara         |"<<endl;
	cout<<"4.Musteri Sil |"<<endl;
	cout<<"5.Guncelle    |"<<endl;
	cout<<"6.Kaydi Sil   |"<<endl;
	cout<<"7.Kaydet      |"<<endl;
	cout<<"8.Sakla       |"<<endl;
	cout<<"0.Cikis       |"<<endl;
	cout<<"==============="<<endl;
	cin>>secim;
	
	switch(secim){
		case 1:
			
			murat.ekle();
			do{
			id_kontrol=0;
			
			cout<<"Musteri ID Numarasi (6 Hane): ";
			cin>>id;
			for(int i=0; i<ms; i++){
				if(id==murat.getMusteri_id(i))
				id_kontrol=1;
			}
			if(id.size()!=6){
				cout<<"ID Numarasi 6 haneli olmalidir!!"<<endl;
			}
			else if(id_kontrol==1){
				cout<<"Bu ID Numarasi mevcut!!"<<endl;
			}
		}while(id.size()!=6 || id_kontrol==1);
			murat.setMusteri_id(id);
		
			ms++;
			break;
		case 2:
			murat.listele();
			break;
		case 3:
			murat.ara();
			break;
		case 4:
			murat.sil();
			break;
		case 5:
			murat.guncelle();
			break;
		case 6:
			murat.kaydi_sil();
			break;
		case 7:
			murat.kaydet();
			break;
		case 8:
			cout<<"Mevcut kayitli verilerin kaydedilecegi belgenin adini giriniz: ";
			cin>>sakla;
			murat.kaydet(sakla);
			break;
		case 0:
			cout<<"Kayitli olmayan verileriniz kaybolacak!!"<<endl;
			cout<<"Devam etmek istiyorsaniz 'evet' yazin. "<<endl;
			cin>>cikis;
			if(cikis=="evet")
			exit(1);
			break; 
		default:
			cout<<"Hatali giris. Tekrar deneyiniz.."<<endl;
	}
}while(0==0);
}

