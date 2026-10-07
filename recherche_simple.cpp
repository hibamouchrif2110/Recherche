#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
using namespace std::chrono;
using namespace std;
 bool recherche(string &mot1, string &mot2){
     int j=0;
     string &longue=(mot1.size()>mot2.size())?mot1:mot2;
     string &courte=(mot1.size()>mot2.size())?mot2:mot1;
     
        for(int i=0;i<longue.size() && j<courte.size();i++){
            if(longue[i]==courte[j])
                j++;
        }
        return j==courte.size();
     
     return false;
    }
int main(){
    string mot1, mot2;

    cout<<"entrer le mot1:"<<endl;
    cin>> mot1;
    cout<<"entrer le mot2:"<<endl;  
    cin>> mot2;

    
    auto debut=high_resolution_clock::now();
    bool result=recherche(mot1, mot2);
    auto fin=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(fin-debut);
    if(result){
        cout<< "mot2 existe  dans mot1"<<endl;
        cout<< "temps d'execution : "<<duration.count()<<" microsecondes"<<endl;
    }else {
        cout<< "mot2 n'existe pas dans mot1"<<endl;
        cout<< "temps d'execution : "<<duration.count()<<" microsecondes"<<endl;
        }

    return 0;
}
