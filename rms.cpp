#include <bits/stdc++.h> 
using namespace std; 
  
// Functia care calculeaza RMS (Root Mean Square)
float rmsValue(float arr[],  float n) 
{ 
    int square = 0; 
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
  
// Apelarea functiei RMS 
int main() 
{ 
   float arr[] = {37.035, 0.0933,
37.0352, 0.0950,
37.0355, 0.0783,
37.0358, 0.0767,
37.036, 0.0633,
37.0363, 0.0633,
37.0365, 0.0283 }; 
    float n = sizeof(arr) / sizeof(arr[0]); 
  
    cout <<"Valoarea RMS este " << rmsValue(arr, n); 
  
    return 0; 
} 
