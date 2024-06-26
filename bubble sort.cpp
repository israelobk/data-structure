#include <iostream>
#include <stdlib.h> 
using namespace std;

void printArray (int dizi[], int elemanSayisi) {
    cout << "dizi[] = { " ;
    for (int i = 0; i < elemanSayisi; i++) {
        cout << dizi[i] << ", ";
    }
    cout << "}\n";
}

void bubbleSort(int dizi[], int elemanSayisi) {
    int temp,i,j;
    bool isSwap = false;      
    printArray(dizi, elemanSayisi);
    
    for (i = 0; i < elemanSayisi; i++) {
         isSwap = false;
        for (j = 0; j < elemanSayisi-i-1; j++) {
            if ( dizi[j] > dizi[j+1] ) {
                temp = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp;
                 isSwap = true;
            }
        }
        if (isSwap == false) {
          break;   
        }
    }
    
    printArray(dizi, elemanSayisi);
}

int main(int argc, const char * argv[]) {
    
    int ornekDizi[100];
    
    for (int i = 0; i < 100; i++) {
        ornekDizi[i] = rand() % 100 + 1;
    }
    
    bubbleSort(ornekDizi, 100);
    
    return 0;
}