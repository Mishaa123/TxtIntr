#include <iostream> 
#include <unistd.h> 
#include <stdlib.h> 
#include <cstdlib> 
using namespace std; 

void help() 
{ 
std::cout << "Возможные параметры калькулятора:\n'-u' умножение\n'-d' деление\nкол-во операндов: 3-5  \n"; 
exit(1); 
} 
int main(int argc, char **argv) 
{ 
int K=0; 
float a=0,a1=0, a2=1; 
for (int i=1; i<argc; i++) { 
a=strtol(argv[i], nullptr, 10); 
if (a!=0 and K==0) { 
a1=a; 
K=1; 
continue; 
} 
if (a!=0 and K!=0) { 
a2*=a; 
K+=1; 
} 
    } 
    if((K<3)or(K>5)) { 
        help(); 
    } 
    int opt, sd=0; 
    while((opt = getopt(argc, argv, "ud")) != -1) { 
        switch(opt) { 
        case 'u': 
            if (sd == 0) { 
             cout << "Произведение: " << (a1)*(a2) << endl; 
             sd+=1; 
            } 
            break; 
        case 'd': 
            if (sd == 0) { 
             cout << "Частное: " << (a1)/(a2) << endl; 
             sd+=1; 
            } 
            break; 
        } 
    } 
    if (sd == 0) { 
        help(); 
    } 
} 
