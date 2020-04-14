// Program C++ pentru a gasi grupuri necunoscute
// Puncte care folosesc algoritmul kNN (k- nearest neighbour) 
#include <bits/stdc++.h> 
using namespace std; 
  
struct Punct 
{ 
    int val;     // grupul de puncte
    double x, y;     // coordonatele punctului
    double distanta; // distanta fata de punctul de testare 
}; 
  
// Functie folosita pentru a sorta un sir de puncte prin cresterea ordinii distantei
bool comparare(Punct a, Punct b) 
{ 
    return (a.distanta < b.distanta); 
} 
  
// Aceasta functie gaseste clasificarea punctului p folosind algoritmul k nearest neighbour
// Presupune trei grupuri si returneaza 0 daca p apartine grupului 0 (emg healthy), 1 daca p apartine grupului de 1(emg myopathy), altfel 2 daca p apartine grupului de 2(emg neuropathy)
int clasificarePunct(Punct arr[], int n, int k, Punct p) 
{ 
    // Completeaza distantele tuturor punctelor de la p.
    for (int i = 0; i < n; i++) 
        arr[i].distanta = 
            sqrt((arr[i].x - p.x) * (arr[i].x - p.x) + 
                 (arr[i].y - p.y) * (arr[i].y - p.y)); 
  
    // Sorteaza punctele dupa distanta de la p
    sort(arr, arr+n, comparare);  

  
    // Acum consideram primele k elemnete si trei grupuri
    int freq1 = 0;     // frecventa grupului de 0 (emg healthy)
    int freq2 = 0;     // frecventa grupului de 1 (emg myopathy)
    int freq3 = 0;     // frecventa grupului de 2 (emg neuropathy)
    for (int i = 0; i < k; i++) 
    { 
        if (arr[i].val == 0) 
            freq1++; 
        else if (arr[i].val == 1) 
            freq2++; 
        else if (arr[i].val == 2) 
            freq3++; 
    } 
  
    if(freq1 > freq2)
    	return 0; 
    else return 1; 
    
	if(freq1 > freq3 ) 
    	return 0; 
    else return 2; 
    
	if(freq2 > freq3) 
		return 1;
	else return 2;
} 
  

int main() 
{ 
    int n = 10; // numarul de puncte de date
    Punct arr[n]; 
  
    arr[0].x = 1; 
    arr[0].y = 12; 
    arr[0].val = 0; 
  
    arr[1].x = 2; 
    arr[1].y = 5; 
    arr[1].val = 2; 
  
    arr[2].x = 5; 
    arr[2].y = 3; 
    arr[2].val = 1; 
  
    arr[3].x = 3; 
    arr[3].y = 2; 
    arr[3].val = 1; 
  
    arr[4].x = 3; 
    arr[4].y = 6; 
    arr[4].val = 0; 
  
    arr[5].x = 1.5; 
    arr[5].y = 9; 
    arr[5].val = 2; 
  
    arr[6].x = 7; 
    arr[6].y = 2; 
    arr[6].val = 1; 
  
    arr[7].x = 6; 
    arr[7].y = 1; 
    arr[7].val = 1; 
  
    arr[8].x = 3.8; 
    arr[8].y = 3; 
    arr[8].val = 1; 
  
    arr[9].x = 3; 
    arr[9].y = 10; 
    arr[9].val = 2; 
  
    // punctul de testare
    Punct p; 
    p.x = 10; 
    p.y = 10; 
  
    // parametru pentru a decide grupul punctului de testare
    int k = 3; 
    printf ("Valoarea clasificata la punctul necunoscut este %d.\n", clasificarePunct(arr, n, k, p)); 
    return 0; 
} 
