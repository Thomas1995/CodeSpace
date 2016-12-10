#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pacient {
protected:
	int varsta;
	string nume, prenume, adresa;
	int colesterol, tensiune;
	string dataAnalize;

public:
	Pacient(string nume, string prenume, int varsta, string adresa,
		int colesterol, int tensiune, string dataAnalize) {

			this->nume = nume;
			this->prenume = prenume;
			this->varsta = varsta;
			this->adresa = adresa;
			this->colesterol = colesterol;
			this->tensiune = tensiune;
			this->dataAnalize = dataAnalize;
	}

	int getVarsta() {
		return varsta;
	}

	string getNume() {
		return nume;
	}

	string getPrenume() {
		return prenume;
	}

	string getAdresa() {
		return adresa;
	}

	virtual void output(ostream& os) {
		os<<"\n"<<nume<<" "<<prenume<<", "<<varsta<<" ani , "<<adresa<<"\n";
		os<<"Data analize: "<<dataAnalize<<"\n";
		os<<"Colesterol: "<<colesterol<<"\n";
		os<<"Tensiune: "<<tensiune<<"\n";
	}
};

class Adult : public Pacient {
public:
	Adult(string nume, string prenume, int varsta, string adresa,
		int colesterol, int tensiune, string dataAnalize) :
		Pacient(nume, prenume, varsta, adresa, colesterol, tensiune, dataAnalize) {}

	virtual void output(ostream& os) {
		Pacient::output(os);
	}
};

class Adult40 : public Adult {
protected:
	bool fumator;
	int sedentarism;
public:
	Adult40(string nume, string prenume, int varsta, string adresa,
		int colesterol, int tensiune, string dataAnalize,
		bool fumator, int sedentarism) :
		Adult(nume, prenume, varsta, adresa, colesterol, tensiune, dataAnalize) {

			this->fumator = fumator;
			this->sedentarism = sedentarism;
	}

	virtual void output(ostream& os) {
		Adult::output(os);
		os<<"Fumator: "<<(fumator ? "Da" : "Nu")<<"\n";
		os<<"Sedentarism: "<<sedentarism<<"\n";
	}
};

class Copil : public Pacient {
protected:
	int proteinaC;
	Pacient *mama, *tata;
public:
	Copil(string nume, string prenume, int varsta, string adresa,
		int colesterol, int tensiune, string dataAnalize,
		int proteinaC, Pacient* mama, Pacient* tata) :
		Pacient(nume, prenume, varsta, adresa, colesterol, tensiune, dataAnalize) {

			this->proteinaC = proteinaC;
			this->mama = mama;
			this->tata = tata;
	}

	virtual void output(ostream& os) {
		Pacient::output(os);
		os<<"Nivel Proteina C: "<<proteinaC<<"\n";
	}
};

ostream& operator << (ostream& os, Pacient* p) {
	p->output(os);
	os<<"\n";
	return os;
}

class Factory {

public:
	Pacient* citestePacient() {

		cout<<"\n";

		string nume, prenume, adresa, dataAnalize;
		int varsta, colesterol, tensiune;
		cout<<"Nume: ";
		cin>>nume;
		cout<<"Prenume: ";
		cin>>prenume;
		cout<<"Varsta: ";
		cin>>varsta;
		cout<<"Adresa: ";
		cin>>adresa;
		cout<<"Valoarea totala a colesterolului: ";
		cin>>colesterol;
		cout<<"Valoarea tensiunii arteriale: ";
		cin>>tensiune;
		cout<<"Data la care s-au facut analizele: ";
		cin>>dataAnalize;

		if(varsta <= 10) {

			int proteinaC;
			cout<<"Proteina C reactiva: ";
			cin>>proteinaC;

			Pacient *mama, *tata;
			cout<<"Mama copil:\n";
			mama = citestePacient();
			cout<<"Tata copil:\n";
			tata = citestePacient();

			return new Copil(nume, prenume, varsta, adresa, colesterol,
				tensiune, dataAnalize, proteinaC, mama, tata);
		}
		else {
			if(varsta >= 40) {
				return new Adult(nume, prenume, varsta, adresa, colesterol,
					tensiune, dataAnalize);
			}
			else {
				bool fumator;
				int sedentarism;
				cout<<"Fumator? 0 - nu, 1 - da: ";
				cin>>fumator;
				cout<<"Nivel de miscare (0-10), 0 - deloc, 10 - intens: ";
				cin>>sedentarism;
				sedentarism = 10-sedentarism;

				return new Adult40(nume, prenume, varsta, adresa, colesterol,
					tensiune, dataAnalize, fumator, sedentarism);
			}
		}
	}
};

int main() {

	vector<Pacient*> pacienti;

	int nrPacienti;
	cout<<"Numarul de pacienti este: ";
	cin>>nrPacienti;

	Factory f;
	for(int i=1;i<=nrPacienti;++i) {
		pacienti.push_back(f.citestePacient());
	}

	for(int i=0;i<pacienti.size();++i) {
		cout<<pacienti[i];
	}

	return 0;
}
