#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <chrono> 
#include <algorithm>
#include <ctime>
#include <math.h>
#include <random> 
#include <time.h>
#include <vector>
using namespace std;



int main() {
    clock_t tic = clock();
    int i = 0,b,r,c[1000];
    char *pEnd;
    double a,dt=0.0,d=2000.0,x[1000],y[1000],xmin[1000],ymin[1000];
    vector<int> seq(1000);
    ifstream inputFile("tsp.txt");

    string buf_l, buf_r;
    while (inputFile>>buf_l>>buf_r) {
        x[i] = 0;
        y[i] = 0;
        x[i]=stod(buf_l);
        y[i]=stod(buf_r);

        i++;
    }
    

    inputFile.close();


    srand(time(NULL));
    for(i = 0; i < 1000; i++){
        seq[i] = i;
    }    

    for(int z = 0; z < 10000; z++){


        unsigned seed = chrono::system_clock::now().time_since_epoch().count();

        shuffle(seq.begin(), seq.end(), default_random_engine(seed));
        
        
        // for(i = 0; i < 1000; i++){
        //     cout<< seq[i] << endl;
        // }


        
        dt = 0;
        

        for(i = 0; i < 1000; i++){
            if (seq[i] != 0) 
                a = sqrt(pow((x[seq[i]]-x[seq[i]-1]),2)+pow((y[seq[i]]-y[seq[i]-1]),2));
                
            /* printf("%d %f %f %f %f\n",seq[i],a,dt,x[seq[i]],y[seq[i]]); */
            dt += a;
        } 
        dt += sqrt(pow((x[seq[0]]-x[seq[999]]),2)+pow((y[seq[0]]-y[seq[999]]),2)); 

        if (dt < d){
            d = dt;
            printf("Current min parameter is %f %f\n",d,dt);
            cout << z << endl;
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