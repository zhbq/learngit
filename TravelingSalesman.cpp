#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <math.h>
#include <time.h>
using namespace std;


int main() {
    clock_t tic = clock();
    int i = 0,b,r,c[1000],seq[1000];
    double a,dt,d=2000,x[1000],y[1000],xmin[1000],ymin[1000];
    ifstream inputFile("tsp.txt");

    string buf_l, buf_r;
    while (inputFile>>buf_l>>buf_r) {
        x[i]=stod(buf_l);
        y[i]=stod(buf_r);
        i++;
    }
    

    for(int j = 0; j < i; j++){
        /* printf("%f %f\n",x[j],y[j]); */
    } 
    
    inputFile.close();


    srand(time(NULL));
    

    for(int z = 0; z < 100; z++){

        for(i = 0; i < 1000; i++){
            c[i] = i;
        }

        for(i = 999; i >= 0; i--){
            r = rand()%i;
            seq[i-1] = c[r];            
            while (r<i-1){
                c[r]=c[r+1];
                r++;
            }
        }

        
        
        dt = sqrt(pow((x[seq[0]]-x[seq[999]]),2)+pow((y[seq[0]]-y[seq[999]]),2)); 


        for(i = 0; i < 1000; i++){
            if (seq[i] != 0)
                a = sqrt(pow((x[seq[i]]-x[seq[i]-1]),2)+pow((y[seq[i]]-y[seq[i]-1]),2)); 
            /* printf("%d %f %f %f %f\n",seq[i],a,dt,x[seq[i]],y[seq[i]]); */
            dt += a;
        }   
        if (dt < d){
            d = dt;
            printf("Current min parameter is %f %f\n",d,dt);
            for(i = 0; i < 1000; i++){
                xmin[i] = x[seq[i]];
                ymin[i] = y[seq[i]];
            }
        }    

    }   

    ofstream outputfile ("result.txt");
    for(i = 0; i < 1000; i++){
        outputfile << xmin[i] << "  " << ymin[i] << "\n";
    }
    outputfile.close();


    /* for(i = 0; i < 1000; i++){
        a = sqrt(pow((xmin[i]-xmin[i-1]),2)+pow((ymin[i]-ymin[i-1]),2)); 
        printf("%f  %f  %f   %f     %f\n",xmin[i],xmin[i-1],ymin[i],ymin[i-1],a);
    } */
    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    return 0;      
}