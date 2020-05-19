#include <bits/stdc++.h>
#include<string.h>
#include<stdio.h>
using namespace std;

// definirea clasei Punct
class Punct {
private:
    double x_test, y_test;  // coordonatele punctului de test
    double distanta[60000]; // distanta fata de punctul de testare
    int val[60000]; // tipul punctului (val poate fi: 0 -> emg healty, 1-> emg myopathy, 2-> emg neuropaty)
    int n; // nr de puncte
    double x[60000];  // coordonatele x ale punctelor
    double y[60000]; // coordonatele y ale punctelor
    int freq1;     // frecventa grupului de 0 (emg healthy)
    int freq2;     // frecventa grupului de 1 (emg myopathy)
    int freq3;     // frecventa grupului de 2 (emg neuropathy)
public:
    // definirea constructorului Punct
    Punct (vector<float> x1, vector<float> y1, vector<int> val1, double x_test1, double y_test1) {
        for(int i=0;i<x1.size();i++)
        {
        x[i]=x1[i];
        y[i]=y1[i];
        val[i]=val1[i];
        }
        x_test=x_test1;
        y_test=y_test1;

  }
 
 //definirea de get-uri
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

// Aceasta functie gaseste clasificarea punctului p folosind algoritmul K nearest neighbour
// Presupune trei grupuri si returneaza 0 daca punctul apartine grupului 0 (emg healthy), 
// 1 daca punctul apartine grupului de 1 (emg myopathy), altfel 2 daca punctul apartine grupului de 2 (emg neuropathy)
  	
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

vector<float> vect1;
vector<float> vectx;
vector<float> vecty;
vector<int> val1; 
double x_test1 = 10;
double y_test1 = 10; 
int k;  
cout<<"Introduceti numarul de vecini k=";
cin>>k; 

// daca k este par se decrementeaza
if(k % 2 == 0)
	{
		k--; 
		cout<<"K-NN se realizeaza pentru un numar k impar!"<<endl; 
		cout<<"K-NN se va realiza pentru k-1 = "<<k<<endl;
		if(k <= 0)
			k = 1; 
	}

    FILE *fptr1; // pointer catre fisier
    float x;
    if ((fptr1 = fopen("emg_healthy.txt", "r")) == NULL) { // deschidem fisierul
        printf("Error! opening file");
        // Iesim din program daca pointerul catre fisier este NULL
        exit(1);
    }

    while (fscanf(fptr1,"%f",&x) != EOF) { // EOF = End Of File (vectorul care pointeaza catre finalul fisierului)
        vect1.push_back(x); // adaugam in vectorul vect1 valoarea x citita din fisier
    }
   
    fclose(fptr1); // inchidem fisierul
    
	for(int i = 0; i< k; i++) 
    {
        if(i%2 == 0) {
            vectx.push_back(vect1[i]); 
            val1.push_back(0);
        } else {
            vecty.push_back(vect1[i]);
        }
    }
    Punct punct(vectx, vecty, val1, x_test1, y_test1); 
    cout<<"Rezultatul algoritmului K-NN este: "<<punct.clasificarePunct(vectx.size())<<" ";
    if(punct.clasificarePunct(vectx.size()) == 0) 	
    	cout<<"=> emg healty";
    else if (punct.clasificarePunct(vectx.size()) == 1) 
    	cout<<"=> emg myopathy"; 
    else 
		cout<<"=> emg neuropathy";

return 0;
} 

