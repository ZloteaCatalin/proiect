#include <bits/stdc++.h> 
#include<string.h>
#include<stdio.h>
using namespace std; 

// definirea clasei Punct
class Punct {
private:
    double x_test, y_test;  // coordonatele punctului de test
    double distanta[2000]; // distanta fata de punctul de testare
    int val[2000]; // tipul punctului (val poate fi: 0 -> emg healty, 1-> emg myopathy, 2-> emg neuropaty)
    int n; // nr de puncte
    double x[2000];  // coordonatele x ale punctelor
    double y[2000]; // coordonatele y ale punctelor   
    int freq1;     // frecventa grupului de 0 (emg healthy)
    int freq2;     // frecventa grupului de 1 (emg myopathy)
    int freq3;     // frecventa grupului de 2 (emg neuropathy) 
public: 
    // definirea constructorului Punct 
	Punct (double x1[2000], double y1[2000], int val1[2000], double x_test1, double y_test1) {
    	for(int i=0;i<2000;i++)
		{
		x[i]=x1[i];
    	y[i]=y1[i];
    	val[i]=val1[i];
		}
    	x_test=x_test1;
    	y_test=y_test1;
    
    }
 //definirea de get-uri
 double getx(){
 	return x[2000];
    } 
 double gety(){
 	return y[2000];
    } 
 int getval(){
 	return val[2000];
    } 
 double getx_test(){
 	return x_test;
    } 
 double gety_test(){
 	return y_test;
    }


// Functie folosita pentru a sorta un sir de puncte prin cresterea ordinii distantei
 static bool comparare(double a, double b)
 {
   return (a < b);
 }
// Functie folosita pentru completarea distantelor tuturor punctelor de la punctul de test    
 double calculare_distanta (double x_p, double y_p, int i)
    {
        distanta[i] = sqrt((x_p - x_test) * (x_p - x_test) +(y_p - y_test) * (y_p - y_test));
    }
// Aceasta functie gaseste clasificarea punctului p folosind algoritmul k nearest neighbour
// Presupune trei grupuri si returneaza 0 daca p apartine grupului 0 (emg healthy), 1 daca p apartine grupului de 1(emg myopathy), altfel 2 daca p apartine grupului de 2(emg neuropathy)
    int clasificarePunct(int k)
    {  int i;
        for ( i = 0; i < n; i++){
            // Completeaza distantele tuturor punctelor de la punctul de testare.
            this->calculare_distanta(x[i],y[i], i);
        }
        
		sortarePuncte();
// Calculam frecventa de aparitie a valorii punctului ( 0 -> emg healthy, 1-> emg myopathy, 2-> emg neuropathy)
        for (int i = 0; i < k; i++)
        {
            if (val[i] == 0)
                freq1++;
            else if (val[i] == 1)
                freq2++;
            else if (val[i] == 2)
                freq3++;
        }
// Verificam care dintre cele 3 frecvente este cea mai mare si returnam rezultatul corespunzator acestei frecvente      
		if(freq1>freq2){
            if(freq1>freq3){
                return 0;
            } else{
                return 2;
            }
        } else {
            if(freq2>freq3){
                return 1;
            } else{
                return 2;
            }
        }
    }
    void sortarePuncte()
    {// Sorteaza punctele dupa distanta de la punctul de test
        int i;
        for (i = n-1; i >= 0; i--)
        {
            for (int j = 1; j = i; j++)
            {
                if (comparare (distanta[j-1], distanta[j]) == 0)
                {
                    double temp_x, temp_y;
                    temp_x = x[j];
                    x[j] = x[j-1];
                    x[j-1] = temp_x;
                    temp_y = y[j];
                    y[j] = y[j-1];
                    y[j-1] = temp_y;
                }
            }
        }
    }
}; 

int main (){

double x1[3]; 
x1[0] = 1; 
x1[1] = 2; 
x1[3] = 3;
double y1[3];
y1[0] = 4;
y1[1] = 5; 
y1[2] = 6;
int val1[3]; 
val1[0] = 0;
val1[1] = 1; 
val1[2] = 2;
double x_test1 = 1; 
double y_test1 = 1;
Punct punct(x1, y1, val1, x_test1, y_test1);
	
	
return 0;	
}
