#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
//
struct Buku{
	string judul, penulis, penerbit;
	int jumlah, kode;
};


class BukuPerpus{
	public:
		void tambahBuku();
		void tampilkan();
		void cariBukuByJudul();
		void cariBukuByPenulis();
		void shortByJudulACS();
		void shortByJudulDESC();
		void tampilkanBukuDenganStokKurangDari5();
		void tampilkanBukuDenganStokTerbanyak();
		void utama();
	
	
	private:
	Buku buku;
};

void BukuPerpus::utama(){
	int pil;
    do{
    cout<<"1. tambah buku\n";
	cout<<"2. lihat buku\n";
	cout<<"3. cari judul buku berdasarkan penulis\n";
	cout<<"4. cari buku berdasarkan judul\n";
	cout<<"5. tambilkan buku dengan stok < 5\n";
	cout<<"6. cari buku dengan stok terbanyak\n";
	cout<<"7. urutkan buku secara ASC\n";
	cout<<"8. Urutkan buku secara DESC\n";
	cout<<"Masukan Salah satu : ";
    cin>>pil;

    if(pil == 1){
       tambahBuku();
    }else if(pil == 2){
    	cout<<"---------------\n";
    	tampilkan();
    }else if(pil == 3){
    	cout<<"\n--------------------\n";
		cariBukuByPenulis();
		cout<<"\n--------------------\n";
    }else if(pil == 4){
    	cariBukuByJudul();
    }else if(pil == 5){
		cout<<"gabisa buat yang ini :)"
    }else if(pil == 6){
		tampilkanBukuDenganStokTerbanyak();
    }else if(pil == 7){
		shortByJudulACS();
    }else if(pil == 8){
		shortByJudulDESC();
    }
    }while(pil != 9);{
    cout<<"keluar\n";
    }
}

void BukuPerpus::tambahBuku(){
	int n;
	cout<<"ingin memasukan berapa buku ? ";
	cin>>n;
	cin.ignore();
	
	Buku* buku = new Buku[n];
	for(int i = 0; i < n; i++){
		cout<<"Masukan Buku yang ke-"<<i+1<<endl;
		cout<<"Masukana Judul buku : ";
		getline(cin, buku[i].judul);
		cout<<"Masukan Penulis buku : ";
		getline(cin, buku[i].penulis);
		cout<<"Masukan Penerbit : ";
		getline(cin, buku[i].penerbit);
		cout<<"masukan jumlah buku : ";
		cin>>buku[i].jumlah;
		cin.ignore();
		cout<<"masukan Kode buku : ";
		cin>>buku[i].kode;
		cin.ignore();
	}
	
	ofstream fileku("buku2.txt", ios::app);
	if(fileku.is_open()){
		for(int i = 0; i< n; i++){
			fileku<<"judul : "<<buku[i].judul<<endl;
			fileku<<"Penulis : "<<buku[i].penulis<<endl;
			fileku<<"Penerbit : "<<buku[i].penerbit<<endl;
			fileku<<"Jumlah : "<<buku[i].jumlah<<endl;
			fileku<<"Kode : "<<buku[i].kode<<endl;
			fileku<<"------------------\n";
		}
		fileku.close();
	}else{
		cout<<"gagal membuka file";
	}
}


void BukuPerpus::tampilkan(){
	ifstream fileku("buku2.txt");
	string baris;
	if(fileku.is_open()){
		while(getline(fileku, baris)){
			cout<<baris<<endl;
		}
		
		fileku.close();
	}else{
		cout<<"gagal ga ada file\n";
	}
}

void BukuPerpus::cariBukuByJudul(){
	string cari;
	cout<<"Masukan judul yang ingin dicari : ";
	cin.ignore();
	getline(cin, cari);
	
	ifstream fileku("buku2.txt");
	ofstream fileCari("cari_judul.txt", ios::app); 
	string baris;
	bool ditemukan = false;
	
	if(fileku.is_open() && fileCari.is_open()){
		fileCari<<"==========================================\n";
		fileCari<<"Hasil Pencarian Berdasarkan Judul: "<<cari<<endl;
		fileCari<<"==========================================\n";
		
		while(getline(fileku, baris)){
			if(baris.find("judul : ") != string::npos){
				string dariFile = baris.substr(8);
				if(dariFile.find(cari) != string::npos){
					cout<<baris<<endl;
					fileCari<<baris<<endl; 
					
					for(int i = 0; i < 4 && getline(fileku, baris); i++){
						cout << baris << endl;
						fileCari << baris << endl; 
					}
					fileCari<<"------------------\n";
					ditemukan = true;
				}			
			}
		}
		
		if(!ditemukan){
			cout<<"judul buku tidak ada\n";
			fileCari<<"Judul buku tidak ditemukan\n";
		}
		
		fileCari<<"\n\n";
		fileku.close();
		fileCari.close();
		
		if(ditemukan){
			cout<<"Hasil pencarian telah disimpan ke file cari_judul.txt\n";
		}
	}else{
		cout<<"gagal Buka File\n";
	}
}

void BukuPerpus::cariBukuByPenulis(){
	string cari;
	cout<<"Masukan PENULIS Buku yang dicari : ";
	cin.ignore();
	getline(cin, cari);
	
	string baris;
	ifstream fileku("buku2.txt");
	ofstream fileCari("cari_penulis.txt", ios::app); 
	bool ditemukan = false;
	
	if(fileku.is_open() && fileCari.is_open()){
		fileCari<<"==========================================\n";
		fileCari<<"Hasil Pencarian Berdasarkan Penulis: "<<cari<<endl;
		fileCari<<"==========================================\n";
		
		while(getline(fileku, baris)){
			if(baris.find("Penulis : ") != string::npos){
				string dariFile = baris.substr(10);
				if(dariFile.find(cari) != string::npos){
					cout<<"Buku Ditemukan\n";
					fileCari<<"Buku Ditemukan\n";
					
					cout<<baris<<endl;
					fileCari<<baris<<endl;
					
					for(int i = 0; i < 3 && getline(fileku, baris); i++){
						cout<<baris<<endl;
						fileCari<<baris<<endl;
					}
					fileCari<<"------------------\n";
					ditemukan = true;
				}
			}
		}
		
		if(!ditemukan){
			cout<<"Penulis Buku tidak ada\n";
			fileCari<<"Penulis Buku tidak ditemukan\n";
		}
		
		fileCari<<"\n\n";
		fileku.close();
		fileCari.close();
		
		if(ditemukan){
			cout<<"Hasil pencarian telah disimpan ke file cari_penulis.txt\n";
		}
	}else{
		cout<<"Gagal membuka file\n";
	}
}

void BukuPerpus::shortByJudulACS(){
	string baris;
	ifstream fileku("buku2.txt");
	
	int jumlahBuku = 0;
	Buku* buku = new Buku[100];
	
	if(fileku.is_open()){
		while(getline(fileku, baris)){
			if(baris.find("judul : ") != string::npos){
				buku[jumlahBuku].judul = baris.substr(8);
				
				getline(fileku, baris);
				buku[jumlahBuku].penulis = baris.substr(10);
				
				getline(fileku, baris);
				buku[jumlahBuku].penerbit = baris.substr(10);
				
				getline(fileku, baris);
				buku[jumlahBuku].jumlah = atoi(baris.substr(8).c_str());
				
				getline(fileku, baris);
				buku[jumlahBuku].kode = atoi(baris.substr(7).c_str());
				
				getline(fileku, baris);
				jumlahBuku++;
			}
		}
	}else{
		cout<<"File tidak ditemukan : \n";
		delete[] buku;
		return;
	}
	
	for(int i = 0; i < jumlahBuku - 1; i++){
		for(int j = 0; j < jumlahBuku-i-1; j++){
			if(buku[j].judul > buku[j+1].judul){
				Buku temp = buku[j];
				buku[j] = buku[j+1];
				buku[j+1] = temp;
			}
		}
	}
	
	cout<<"buku dirurutkan berdasarkan judul ASC\n";
	for(int i = 0; i < jumlahBuku; i++){
		cout<<"judul : "<<buku[i].judul<<endl;
		cout<<"Penulis : "<<buku[i].penulis<<endl;
		cout<<"Penerbit : "<<buku[i].penerbit<<endl;
		cout<<"Jumlah : "<<buku[i].jumlah<<endl;
		cout<<"Nomor Buku : "<<buku[i].kode<<endl;
		cout<<"----------------------\n";
	}
	
	delete[] buku;
}


void BukuPerpus::tampilkanBukuDenganStokTerbanyak(){
	ifstream fileku("buku2.txt");
	string baris;
	
	if(fileku.is_open()){
		int jumlahTerbanyak = -1;
		string judulTemp, penulisTemp, penerbitTemp, jumlahTemp, kodeTemp;
		bool bukuAda = false;
		
		while(getline(fileku, baris)){
			if(baris.find("judul : ") != string::npos){
				string judul = baris;
				string penulis, penerbit, jumlah, kode;
				
				if(getline(fileku, baris)) penulis = baris;
				if(getline(fileku, baris)) penerbit = baris;
				if(getline(fileku, baris)) jumlah = baris;
				if(getline(fileku, baris)) kode = baris;
				
				int nilaiJumlah = atoi(jumlah.substr(8).c_str());
				
				if(nilaiJumlah > jumlahTerbanyak){
					jumlahTerbanyak = nilaiJumlah;
					judulTemp = judul;
					penulisTemp = penulis;
					penerbitTemp = penerbit;
					jumlahTemp = jumlah;
					kodeTemp = kode;
					bukuAda = true;
					
				}
			}
		}
		fileku.close();
		
		if(bukuAda){
			cout<<"\nBuku dengan stok terbanyak\n";
			cout<<"==========================\n";
			cout<<judulTemp<<endl;
			cout<<penulisTemp<<endl;
			cout<<penerbitTemp<<endl;
			cout<<jumlahTemp<<endl;
			cout<<kodeTemp<<endl;
		}
	}
}


void BukuPerpus::shortByJudulDESC(){
	ifstream fileku("buku2.txt");
	string baris;
	
	Buku* buku = new Buku[100];
	int jumlahBuku = 0;
	
	if(fileku.is_open()){
		while(getline(fileku, baris)){
			if(baris.find("judul : ") != string::npos){
				buku[jumlahBuku].judul = baris.substr(8);
				
				getline(fileku, baris);
				buku[jumlahBuku].penulis = baris.substr(10);
				
				getline(fileku, baris);
				buku[jumlahBuku].penerbit = baris.substr(10);
				
				getline(fileku, baris);
				buku[jumlahBuku].jumlah = atoi(baris.substr(8).c_str());
				
				getline(fileku, baris);
				buku[jumlahBuku].kode = atoi(baris.substr(7).c_str());
				
				getline(fileku, baris);
				jumlahBuku++;
			}
		}
		fileku.close();
	}else{
		cout<<"gagal Membuka file\n";
	}
	
	
	for(int i = 0; i < jumlahBuku-1; i++){
		for(int j = 0; j < jumlahBuku-i-1; j++){
			if(buku[j].judul < buku[j+1].judul){
				Buku temp = buku[j];
				buku[j] = buku [j +1];
				buku[j+1] = temp;
			}
		}
	}
	
	
	cout<<"Buku setelah diurutkan !!\n";
	for(int i = 0; i < jumlahBuku; i++){
		cout<<"Judul : "<<buku[i].judul<<endl;
		cout<<"Penulis : "<<buku[i].penulis<<endl;
		cout<<"Penerbit : "<<buku[i].penerbit<<endl;
		cout<<"Jumlah : "<<buku[i].jumlah<<endl;
		cout<<"Nomor BUku : "<<buku[i].kode<<endl;
		cout<<"-----------------------\n";
	}
	delete[] buku;
}

void BukuPerpus::tampilkanBukuDenganStokKurangDari5(){

}

int main(){
	BukuPerpus x;
	x.utama();
	
}
