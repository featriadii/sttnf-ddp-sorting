#include<iostream>
using namespace std;

void selectioniteratif(int n, int data[]){
	int tabInt, temp;
	for (int i=0; i<n-1; i++){
		int indeks = i;
//		perulangan nilai mencari nilai minimun sebanyak indeks i+1
		for (int j=i+1; j<n; j++){
			if(data[indeks]>data[j]){
				indeks = j;
			}
		}
//		penukaran posisi elemen
		temp = data[i];
		data[i] = data[indeks];
		data[indeks] = temp;
	}
}

void tampil(int n, int data[]){
	for (int i = 0; i<n; i++){
		cout << data[i] << "  ";
	}
}

int main(){
	int n, i, j, temp;
	char pilihan;
	
	cout << "=====================================================\n";
	cout << "================== Selection Sort ===================\n";
	cout << "=====================================================\n";

	cout << "\nMasukkan jumlah data yang akan diurutkan = ";
	cin >> n;
	cout << endl;
	
	int data[n];
		
	for(int i = 0; i<n; i++){
		cout << "Masukkan data ke-"<< i+1 << " = ";
		cin >> data[i];
	}
	
	selectioniteratif(n, data);
	cout << "\nHasil pengurutan data yang diinput adalah \n";
	tampil(n, data);
}
