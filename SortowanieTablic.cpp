#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int n = 100;

void SortujPrzezWybor(int tab[], int rozmiar) {
	int idMin;

	for (int j = 0; j < rozmiar - 1; j++) {
		idMin = j;

		for (int k = j + 1; k < rozmiar; k++) {
			if (tab[k] < tab[idMin]) idMin = k;
			
		}
		swap(tab[idMin], tab[j]);
	}
}

int szukajPrzezPolowienie(int tab[], int liczba, int n) {
	int id; 

	int srodek, L = 0, P = n - 1;

	while (true) {
		if (L > P) {
			id = -1;
			break;
		}
		srodek = (L + P) / 2;
		if (tab[srodek] == liczba) {
			id = srodek + 1;
			break;
		}
		else if (tab[srodek] < liczba) {
			L = srodek + 1;

		}
		else {
			P = srodek - 1;
		}

		
	}
	return id;
}

int main() {
	int t[n];
	cout << "Wylosowanie liczby" << endl;
	srand(time(NULL));
	for(int i= 0; i<n;i++){
		t[i] = rand() % 1000 + 1;
	}
	for (int i = 0; i < n; i++) {
		cout << t[i] << ',';
	}
	cout << endl << "*******************"<<endl;
	SortujPrzezWybor(t, n);

	cout << "Posortowana tablica: " << endl;
	for (int i = 0; i < n; i++) { 
		cout << t[i] << ','; 
	}
	int x;

	cout << endl << "*******************" << endl;

	cout << "Podaj liczbe do odszukania " << endl;
	cin >> x;

	int wynik = szukajPrzezPolowienie(t, x, n);
	if (wynik > -1) {
		cout << "Szukana liczba jest na pozycji: " << wynik << endl;

	}
	else {
		cout << "Nie znaleziono!";
	}
	

	return 0;

}