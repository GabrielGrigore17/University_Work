#include <iostream>
#include <string>
using namespace std;

class Sofer {
public:
    string nume;
    Sofer() {}
    Sofer(string nume) {
        this->nume = nume;
    }
    string getNume() {
        return this->nume;
    }
    void setNume(string nume) {
        this->nume = nume;
    }
};

class Masina {
public:
    int virsta;
    Sofer sofer;
    Masina(int virsta, string numeSofer) {
        this->virsta = virsta;
        this->sofer = Sofer(numeSofer); // use the constructor Sofer(nume)
    }
    Masina(int virsta, Sofer sofer){  // creem un constructor nou  care accepta ca parametru un obiect de tip sofer in loc de numele soferului
        this->virsta = virsta;
        this->sofer = sofer;
    }
    int getVirsta() {
        return this->virsta;
    }
    Sofer getSofer() {
        return this->sofer;
    }
};

void swap_drivers(Masina &masina_1, Masina &masina_2){
    Sofer tmp{"None"};
    tmp=masina_1.sofer;
    masina_1.sofer=masina_2.sofer;
    masina_2.sofer=tmp;
}

int main() {
    Sofer sofer("Ionel");
    Masina m(23, sofer);
    cout << "virsta masinii: " << m.getVirsta() << endl;
    cout << "nume sofer: " << m.getSofer().getNume() << endl<<endl;
    
    Sofer sofer_2("Costel");
    Masina m_2(30, sofer_2);
    cout << "virsta masinii: " << m_2.getVirsta() << endl;
    cout << "nume sofer: " << m_2.getSofer().getNume() << endl<<endl;
    
    swap_drivers(m,m_2);

    cout << "virsta masinii: " << m.getVirsta() << endl;
    cout << "nume sofer: " << m.getSofer().getNume() << endl<<endl;    

    cout << "virsta masinii: " << m_2.getVirsta() << endl;
    cout << "nume sofer: " << m_2.getSofer().getNume() << endl<<endl;
    
    return 0;
}