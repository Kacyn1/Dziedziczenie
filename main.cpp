#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct towar{
	int id;
	float koszt;
	string nazwa;
};
struct buty:public towar{
	int rozmiar;
	string model,kolor;
	
};
struct pasty:public towar{
	string kolor;
};

class sklep{
	vector <struct buty> ile_butow;
	vector <struct pasty> ile_past;
	ifstream buty;
	ifstream pasty;
	ofstream towary;
public:
	sklep();
	~sklep();
			
void wczytaj_z_pliku();
void zapisz_do_pliku();
};

sklep::sklep(){
	
	towary.open("towary.txt");
	buty.open("buty.txt");
   	pasty.open("pasty.txt");	
}

void sklep::wczytaj_z_pliku(){
	struct buty para;
	struct pasty rodzaj;
	while(!buty.eof()){
		buty>>para.id>>para.koszt>>para.nazwa>>para.rozmiar>>para.model>>para.kolor;
		ile_butow.push_back(para);
		}
	while(!pasty.eof()){
		pasty>>rodzaj.id>>rodzaj.koszt>>rodzaj.nazwa>>rodzaj.kolor;
		ile_past.push_back(rodzaj);
	}
}
	
void sklep::zapisz_do_pliku(){
	towary<<"["<<endl;
	for(vector <struct buty>::iterator it = ile_butow.begin(); it != ile_butow.end(); ++it){
		towary<<"{\"rodzaj_towaru"":\"\para\", \"id\":\""<<it->id<<"\", \"koszt\":\""<<it->koszt<<"\", \"nazwa\":\""<<it->nazwa<<"\", \"rozmiar\":\""<<it->rozmiar<<"\", \"model\":\""<<it->model<<"\", \"kolor\":\""<<it->kolor<<"\"},"<<endl;
		}
	for(vector <struct pasty>::iterator it = ile_past.begin(); it != ile_past.end(); ++it){
		towary<<"{\"rodzaj_towaru"":\"\rodzaj\", \"id\":\""<<it->id<<"\", \"koszt\":\""<<it->koszt<<"\", \"nazwa\":\""<<it->nazwa<<"\", \"kolor\":\""<<it->kolor<<"\"},"<<endl;
	}
	towary<<"]";
}
	sklep::~sklep(){
		buty.close();
    	pasty.close();
    	towary.close();
}

int main(int argc, char** argv) {
	
	sklep p1;
	p1.wczytaj_z_pliku();
	p1.zapisz_do_pliku();
	
	return 0;
}
