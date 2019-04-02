#include<iostream>
using namespace std;

void quickSort(int data[], int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = data[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (data[i] < pivot)
                  i++;
            while (data[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = data[i];
                  data[i] = data[j];
                  data[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(data, left, j);
      if (i < right)
            quickSort(data, i, right);
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
	cout << "==================== Quick Sort =====================\n";
	cout << "=====================================================\n";

	cout << "\nMasukkan jumlah data yang akan diurutkan = ";
	cin >> n;
	cout << endl;
	
	int data[n];
		
	for(int i = 0; i<n; i++){
		cout << "Masukkan data ke-"<< i+1 << " = ";
		cin >> data[i];
	}
	
	quickSort(data, 0, n-1);
	cout << "\nHasil pengurutan data yang diinput adalah \n";
	tampil(n, data);
}
