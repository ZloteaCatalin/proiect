#include <cstdio>
#include <cstdlib> // Pentru functia exit 
#include <iostream>
#include <bits/stdc++.h>  
#include <vector> 

using namespace std;

// Functia care calculeaza RMS (Root Mean Square)
float rmsValue(vector<float> arr, float n) 
{ 
    float square = 0; 
    float mean = 0.0, root = 0.0; 
  
    // Calculul patratului 
    for (int i = 0; i < n; i++) { 
        square += pow(arr[i], 2); 
    } 
  
    // Calculul mediei 
    mean = (square / (float)(n)); 
  
    // Calculul radacini 
    root = sqrt(mean); 
    
    return root; 
}
 

int main() { 

vector<float> vect1;
vector<float> vect2;
vector<float> vect3;
    
	FILE *fptr1;
    float x;
    if ((fptr1 = fopen("emg_healthy.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
   
    while (fscanf(fptr1,"%f",&x) != EOF) {
        vect1.push_back(x);
    }   
    fclose(fptr1);
    
    float n1 = sizeof(vect1) / sizeof(vect1[0]); 
    float rezultat1; 
    rezultat1=rmsValue(vect1, n1); 
    cout<<endl<<"RMS emg healty: "<<rezultat1;
    cout<<endl;
	 
    FILE *fptr2; 
    float y;
    if ((fptr2 = fopen("emg_myopathy.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
   
    while (fscanf(fptr2,"%f",&y) != EOF) {
        vect2.push_back(y);
    } 
    fclose(fptr2); 
    
    float n2 = sizeof(vect2) / sizeof(vect2[0]); 
    float rezultat2; 
    rezultat2=rmsValue(vect2, n2); 
    cout<<endl<<"RMS emg myopathy: "<<rezultat2; 
    cout<<endl;
    
    
    FILE *fptr3;
    float z;
    if ((fptr3 = fopen("emg_neuropathy.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
   
    while (fscanf(fptr3,"%f",&z) != EOF) {
        vect3.push_back(z);
    } 
    fclose(fptr3); 
    
	float n3 = sizeof(vect3) / sizeof(vect2[0]); 
    float rezultat3; 
    rezultat3=rmsValue(vect3, n3); 
    cout<<endl<<"RMS emg neuropathy: "<<rezultat3; 
    cout<<endl;


    return 0;
}
