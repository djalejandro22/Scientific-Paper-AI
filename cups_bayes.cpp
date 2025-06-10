#include <iostream>
#include <array>
using namespace std;

struct World { bool cup1, cup2, clue; };

// Prior exclusivo: P(Cup1) = 0.5.  Cup2 depende de Cup1.
double priorCup1(bool v) { return 0.5; }
double pCup2GivenCup1(bool cup1, bool cup2) {
    return (cup1 ? (cup2 ? 0.0 : 1.0)      // si Cup1=T ⇒ Cup2=F con prob 1
                 : (cup2 ? 1.0 : 0.0));    // si Cup1=F ⇒ Cup2=T con prob 1
}
// Clue depende solo de Cup1 como antes
double pClueGivenCup1(bool cup1, bool clue) {
    return (cup1 ? (clue ? 0.0 : 1.0)       // Cup1=T ⇒ Clue=F seguro
                 : (clue ? 1.0 : 0.0));     // Cup1=F ⇒ Clue=T seguro
}

int main() {
    array<World,4> worlds {{
        {false,true ,true },  // mundo válido
        {false,false,false},  // inválido (prob=0 vía pCup2GivenCup1)
        {true ,false,false},  // mundo válido
        {true ,true ,true }   // inválido
    }};

    double norm=0, pC1T=0, pC2T=0;
    for(const auto& w: worlds) {
        if(w.clue!=true) continue;            // evidencia Clue=T
        double joint = priorCup1(w.cup1) *
                       pCup2GivenCup1(w.cup1,w.cup2) *
                       pClueGivenCup1(w.cup1,w.clue);
        norm += joint;
        if(w.cup1) pC1T += joint;
        if(w.cup2) pC2T += joint;
    }
    cout<<"P(Cup1|clue)= "<<pC1T/norm<<"\n";
    cout<<"P(Cup2|clue)= "<<pC2T/norm<<"\n";
}
