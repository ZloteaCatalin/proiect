#include <cstdio>
#include <cstdlib> // For exit() function
#include <iostream>
using namespace std;
int main() {
   /* FILE *fptr1;
    cout<<"emg healty"<<endl;
    float x;
    if ((fptr1 = fopen("emg_healthy.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
   
    while (fscanf(fptr1,"%f",&x) != EOF) {
        cout<<x<<endl;
    } 
    cout<<endl;
    fclose(fptr1);*/
    
    /*cout<<"emg myopathy"<<endl;
    FILE *fptr2;
    float y;
    if ((fptr2 = fopen("emg_myopathy.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
   
    while (fscanf(fptr2,"%f",&y) != EOF) {
        cout<<y<<endl;
    } 
    cout<<endl;
    fclose(fptr2);*/
    
    cout<<"emg neuropathy"<<endl;
    FILE *fptr3;
    float z;
    if ((fptr3 = fopen("emg_neuropathy.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
   
    while (fscanf(fptr3,"%f",&z) != EOF) {
        cout<<z<<endl;
    } 
    cout<<endl;
    fclose(fptr3);


    return 0;
}
