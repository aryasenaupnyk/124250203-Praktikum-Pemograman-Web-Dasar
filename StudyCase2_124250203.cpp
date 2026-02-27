#include <iostream>
using namespace std;

void binare();
void sekuensial();

struct toko{
	string nama;
	int harga;
};

toko buku[6];
bool found;
int cari;

int main(){
	buku[0].nama="what";
	buku[0].harga=50000;
	
	buku[1].nama="who";
	buku[1].harga=60000;
	
	buku[2].nama="when";
	buku[2].harga=70000;
	
	buku[3].nama="where";
	buku[3].harga=80000;
	
	buku[4].nama="how";
	buku[4].harga=100000;
	
	buku[5].nama="hai";
	buku[5].harga=0;
	
	int metode;
	do{
		cout<<"\n== toko buku =="<<endl;
		cout<<"1. pencarian biner"<<endl;
		cout<<"2. pencarian sekuensial"<<endl;
		cout<<"3. keluar"<<endl;
		cout<<"pilih metode: ";cin>>metode;
		
		if(metode==1){
			binare();
		}else if(metode==2){
			sekuensial();
		}else if(metode!=3){
			cout<<"pilihan tidak valid"<<endl;
		}
		
	}while(metode!=3);
	
	cout<<"terima kasih sudah berkunjung :)"<<endl;
	return 0;
}

void binare(){
	int i=0, j=4, k;
	cout<<"\n-- pencarian biner --"<<endl;
	cout<<"masukkan harga buku: ";cin>>cari;
	found=false;
	
	while(found==false && i<=j){
		k=(i+j)/2;
		if(cari==buku[k].harga){
			found=true;
		}else if(cari<buku[k].harga){
			j=k-1;
		}else{
			i=k+1;
		}
	}
	
	if(found){
		cout<<"buku ditemukan!"<<endl;
		cout<<"judul  : "<<buku[k].nama<<endl;
		cout<<"harga  : "<<buku[k].harga<<endl;
	}else{
		cout<<"buku dengan harga "<<cari<<" tidak ditemukan"<<endl;
	}
}

void sekuensial(){
	int pilih, i;
	do{
		cout<<"\n-- pencarian sekuensial --"<<endl;
		cout<<"1. dengan sentinel"<<endl;
		cout<<"2. tanpa sentinel"<<endl;
		cout<<"3. kembali"<<endl;
		cout<<"pilih: ";cin>>pilih;
		
		if(pilih==1){
			cout<<"masukkan harga buku: ";cin>>cari;
			buku[5].harga=cari;
			i=0;
			while(buku[i].harga!=cari){
				i++;
			}
			if(i<5){
				cout<<"buku ditemukan!"<<endl;
				cout<<"judul  : "<<buku[i].nama<<endl;
				cout<<"harga  : "<<buku[i].harga<<endl;
			}else{
				cout<<"buku dengan harga "<<cari<<" tidak ditemukan"<<endl;
			}
			
		}else if(pilih==2){
			cout<<"masukkan harga buku: ";cin>>cari;
			found=false;
			i=0;
			while(i<5 && found==false){
				if(buku[i].harga==cari){
					found=true;
				}else{
					i++;
				}
			}
			if(found){
				cout<<"buku ditemukan!"<<endl;
				cout<<"judul  : "<<buku[i].nama<<endl;
				cout<<"harga  : "<<buku[i].harga<<endl;
			}else{
				cout<<"buku dengan harga "<<cari<<" tidak ditemukan"<<endl;
			}
			
		}else if(pilih!=3){
			cout<<"pilihan tidak valid"<<endl;
		}
		
	}while(pilih!=3);
}
