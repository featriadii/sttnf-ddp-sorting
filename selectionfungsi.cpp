#include <iostream>
#include <limits>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

const string SRANDOMARRAY5000 = "../Data/random5000.txt";
const string SRANDOMARRAY25000 = "../Data/random25000.txt";
const string SRANDOMARRAY100000 = "../Data/random100000.txt";
const string SUNIFORMARRAY5000 = "../Data/uniform5000.txt";
const string SUNIFORMARRAY25000 = "../Data/uniform25000.txt";
const string SUNIFORMARRAY100000 = "../Data/uniform100000.txt";
const string SALMOSTSORTEDARRAY5000 = "../Data/almostsorted5000.txt";
const string SALMOSTSORTEDARRAY25000 = "../Data/almostsorted25000.txt";
const string SALMOSTSORTEDARRAY100000 = "../Data/almostsorted100000.txt";
const string SSORTEDARRAY5000 = "../Data/sorted5000.txt";
const string SSORTEDARRAY25000 = "../Data/sorted25000.txt";
const string SSORTEDARRAY100000 = "../Data/sorted100000.txt";
const string SREVERSEDSORTEDARRAY5000 = "../Data/reversedsorted5000.txt";
const string SREVERSEDSORTEDARRAY25000 = "../Data/reversedsorted25000.txt";
const string SREVERSEDSORTEDARRAY100000 = "../Data/reversedsorted100000.txt";

// Swapping integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
	int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}

// Print Array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Fill array with integer from file
void fillArrayFromFile(int arr[], int arrSize, char fileName[])
{
    ifstream in(fileName,ios::in);
    int number;
    int i = 0;
    while (in >> number && i < arrSize)
    {
        arr[i] = number;
        i++;
    }
}

void testInsertionSort(int arrSize, char fileName[])
{
    int arr[arrSize];
    fillArrayFromFile(arr, arrSize, fileName);

    int iterNumber = 100;
    float duration = 0;
    float sumDuration = 0;
    for (int i=0; i<iterNumber; i++)
    {
        clock_t tStart = clock();
        insertionSort(arr, arrSize);
        clock_t tStop = clock();
        duration = (float)(difftime(tStop, tStart)) / CLOCKS_PER_SEC * 1000;
//        cout << duration << endl;
        sumDuration += duration;
    }
    float avgDuration = sumDuration / iterNumber;
    cout << avgDuration << endl << endl;
}

int main()
{
    // Test Insertion Sort Random 5000
    cout << "Insertion Sort Random 5000" << endl;
    char randomArray5000[SRANDOMARRAY5000.length() + 1];
    testInsertionSort(5000, strcpy(randomArray5000, SRANDOMARRAY5000.c_str()));

    // Test Insertion Sort Random 25000
    cout << "Insertion Sort Random 25000" << endl;
    char randomArray25000[SRANDOMARRAY25000.length() + 1];
    testInsertionSort(25000, strcpy(randomArray25000, SRANDOMARRAY25000.c_str()));

    // Test Insertion Sort Random 100000
    cout << "Insertion Sort Random 100000" << endl;
    char randomArray100000[SRANDOMARRAY100000.length() + 1];
    testInsertionSort(100000, strcpy(randomArray100000, SRANDOMARRAY100000.c_str()));

    // Test Insertion Sort Seragam 5000
    cout << "Insertion Sort Seragam 5000" << endl;
    char uniformArray5000[SUNIFORMARRAY5000.length() + 1];
    testInsertionSort(5000, strcpy(uniformArray5000, SUNIFORMARRAY5000.c_str()));

    // Test Insertion Sort Seragam 25000
    cout << "Insertion Sort Seragam 25000" << endl;
    char uniformArray25000[SUNIFORMARRAY25000.length() + 1];
    testInsertionSort(25000, strcpy(uniformArray25000, SUNIFORMARRAY25000.c_str()));

    // Test Insertion Sort Seragam 100000
    cout << "Insertion Sort Seragam 100000" << endl;
    char uniformArray100000[SUNIFORMARRAY100000.length() + 1];
    testInsertionSort(100000, strcpy(uniformArray100000, SUNIFORMARRAY100000.c_str()));

    // Test Insertion Sort 80% Terurut 5000
    cout << "Insertion Sort 80% Terurut 5000" << endl;
    char almostSortedArray5000[SALMOSTSORTEDARRAY5000.length() + 1];
    testInsertionSort(5000, strcpy(almostSortedArray5000, SALMOSTSORTEDARRAY5000.c_str()));

    // Test Insertion Sort 80% Terurut 25000
    cout << "Insertion Sort 80% Terurut 25000" << endl;
    char almostSortedArray25000[SALMOSTSORTEDARRAY25000.length() + 1];
    testInsertionSort(25000, strcpy(almostSortedArray25000, SALMOSTSORTEDARRAY25000.c_str()));

    // Test Insertion Sort 80% Terurut 100000
    cout << "Insertion Sort 80% Terurut 100000" << endl;
    char almostSortedArray100000[SALMOSTSORTEDARRAY100000.length() + 1];
    testInsertionSort(100000, strcpy(almostSortedArray100000, SALMOSTSORTEDARRAY100000.c_str()));

    // Test Insertion Sort Terurut 5000
    cout << "Insertion Sort Terurut 5000" << endl;
    char sortedArray5000[SSORTEDARRAY5000.length() + 1];
    testInsertionSort(5000, strcpy(sortedArray5000, SSORTEDARRAY5000.c_str()));

    // Test Insertion Sort Terurut 25000
    cout << "Insertion Sort Terurut 25000" << endl;
    char sortedArray25000[SSORTEDARRAY25000.length() + 1];
    testInsertionSort(25000, strcpy(sortedArray25000, SSORTEDARRAY25000.c_str()));

    // Test Insertion Sort Terurut 100000
    cout << "Insertion Sort Terurut 100000" << endl;
    char sortedArray100000[SSORTEDARRAY100000.length() + 1];
    testInsertionSort(100000, strcpy(sortedArray100000, SSORTEDARRAY100000.c_str()));

    // Test Insertion Sort Terurut Terbalik 5000
    cout << "Insertion Sort Terurut Terbalik 5000" << endl;
    char reversedSortedArray5000[SREVERSEDSORTEDARRAY5000.length() + 1];
    testInsertionSort(5000, strcpy(reversedSortedArray5000, SREVERSEDSORTEDARRAY5000.c_str()));

    // Test Insertion Sort Terurut Terbalik 25000
    cout << "Insertion Sort Terurut Terbalik 25000" << endl;
    char reversedSortedArray25000[SREVERSEDSORTEDARRAY25000.length() + 1];
    testInsertionSort(25000, strcpy(reversedSortedArray25000, SREVERSEDSORTEDARRAY25000.c_str()));

    // Test Insertion Sort Terurut Terbalik 100000
    cout << "Insertion Sort Terurut Terbalik 100000" << endl;
    char reversedSortedArray100000[SREVERSEDSORTEDARRAY100000.length() + 1];
    testInsertionSort(100000, strcpy(reversedSortedArray100000, SREVERSEDSORTEDARRAY100000.c_str()));

    return 0;
}
