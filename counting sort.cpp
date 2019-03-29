#include<iostream>
using namespace std;

int main(){
	int acak[6] = {3,1,7,4,3,5};
				 //0 1 2 3 4 5
	int kumulatif[8] = {0,0,0,0,0,0,0,0};
					  //0 1 2 3 4 5 6 7
	int hasil[6];
	int temp;
	int jumlah;
	int a;
	//cek
	cout << "Deret sebelum diurut adalah ";
	for(int i = 0; i<=5; i++){
		cout << acak[i] << " ";
	}
	cout << endl;
	//langkah pertama
	for(int i = 0; i<=5; i++){
		temp = acak[i]; //satu
		jumlah = kumulatif[temp]; //dua
		jumlah = jumlah + 1; //tiga
		kumulatif[temp] = jumlah;
	}
	
	//langkah kedua
	for(int i = 0; i<7; i++){
		a = kumulatif[i] + kumulatif[i+1];
		kumulatif[i+1] = a;
	}
	int c;
	
	//langkah tiga
	for(int i = 0; i<=5; i++){
		temp = acak[i]; //satu
		c = kumulatif[temp] - 1;
		kumulatif[temp] = c;
		hasil[c] = temp;
	}
	cout << "Deret setelah diurut menjadi ";
	for(int j = 0; j<=5; j++){
		cout << hasil[j] << " ";
	}
}
