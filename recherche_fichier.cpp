#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
using namespace std::chrono;
using namespace std;
//RECHERCHE NORMALE 
 /*bool recherche(string &mot1, string &mot2){
     int j=0;
     string &longue=(mot1.size()>mot2.size())?mot1:mot2;
     string &courte=(mot1.size()>mot2.size())?mot2:mot1;
     
        for(int i=0;i<longue.size() && j<courte.size();i++){
            if(longue[i]==courte[j])
                j++;
        }
        return j==courte.size();
     
     return false;
    }*/
    /// RECHERCHE AVEC FIND 
   /*bool recherche(const string &mot1, const string &mot2){
    const string &longue=(mot1.size()>mot2.size())?mot1:mot2;
    const string &courte=(mot1.size()>mot2.size())?mot2:mot1;

    return longue.find(courte) != -1;
}*/
/// RECHERCHE AVEC REMPLACEMENT
bool recherche( string &mot, const string &sous_chaine, const string &nouveau){
    int pos=mot.find(sous_chaine);
    if(pos!=-1){
        mot.replace(pos,sous_chaine.size(),nouveau);
        return true;        
    }
    return false;
   
}

int main(){
    /// RECHERCHE SANS REMPLACEMENT 
    /*string  mot2, mot1;
    ifstream fichier("fichier.txt");
    if(!fichier.is_open()){
        cout<<"erreur d'ouverture du fichier"<<endl;
        return 1;
    }
    
    cout<<"entrer le mot2:"<<endl;
    cin>> mot2;
    auto debutTotal=high_resolution_clock::now();
   while(fichier>>mot1){
        auto debut=high_resolution_clock::now();
        bool result=recherche(mot1, mot2);
        auto fin=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(fin-debut);
        if(result)
            cout << mot2 << " existe dans " << mot1;
            
        else
            cout << mot2 << " n'existe pas dans " << mot1;

            cout << "  --> temps : " << duration.count() << " microsecondes" << endl;
    }
    auto finTotal=high_resolution_clock::now();
    auto durationTotal=duration_cast<microseconds>(finTotal-debutTotal);
    cout << "\nTemps total de recherche : " << durationTotal.count()
         << " microsecondes" << endl;

    fichier.close();*/
    /// RECHERCHE AVEC REMPLACEMENTS
    string mot, sous_chaine, nouveau;
    vector<string>mots;
    ifstream fichier("fichier.txt");
    if(!fichier.is_open()){
        cout<<"erreur d'ouverture du fichier"<<endl;
        return 1;
    }
    cout<<"entrer la sous_chaine:"<<endl;
    cin>> sous_chaine;
    cout<<"entrer la nouvelle sous-chaine:"<<endl;
    cin>> nouveau;
    while(fichier>>mot){
        mots.push_back(mot);
    }
    fichier.close();
    auto debutTotal=high_resolution_clock::now();
    for(string &m : mots){
        auto debut=high_resolution_clock::now();
        bool result=recherche(m, sous_chaine, nouveau);
        auto fin=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(fin-debut);

        if(result)
            cout << sous_chaine << " existe, remplace par " << nouveau << " --> " << m;
        else
            cout << sous_chaine << " n'existe pas dans " << m;

        cout << "  --> temps : " << duration.count() << " microsecondes" << endl;
    }
    auto finTotal=high_resolution_clock::now();
    auto durationTotal=duration_cast<microseconds>(finTotal-debutTotal);
    cout << "\nTemps total de recherche : " << durationTotal.count()
         << " microsecondes" << endl;

    return 0;
}
