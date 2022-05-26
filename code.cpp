#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int poli(int chislo) {
    int k = chislo;
    int obr_chislo = 0;
    if (chislo > 9) {
        while (k != 0)
        {
            obr_chislo = obr_chislo * 10 + k % 10;
            k /= 10;
        }
        if (chislo == obr_chislo)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
int kol_vo_poli(int*& massiv, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (poli(massiv[i]) == 1)
            k++;
    }
    return k;
}
int k = 0;
int vuvod(int*& _massiv) {
    string l;
    cout << "Vuvesti date: ";
    cin >> l;
    if (l == "Da") {
        system("cls");
        for (int i = 0; i < k; i++)
            cout << _massiv[i] << endl;
    }
    else {
        system("cls");
        cout << "Ok" << endl;
    }
    return 0;
}

void copy(int*& massiv, int n) {
    int start = clock();
    int j = 0;
    k = n + kol_vo_poli(massiv, n);
    int* _massiv = new int[k];
    for (int i = 0; i < n; i++) {
        if (poli(massiv[i]) == 1) {
            _massiv[j] = massiv[i];
            j = j + 1;
            _massiv[j] = massiv[i];
        }
        else {
            _massiv[j] = massiv[i];
        }
        j = j + 1;
    }
    system("cls");
    int end = clock();
    int t = end - start;
    cout << "Vremia vupolnenia: " << t << endl;
    cout << "Date save" << endl;
    vuvod(_massiv);
}

int main()
{
    int n = 0;
    int k = 0;
    cout << "Vedite kol-vo chisel: ";
    cin >> n;
    int* massiv = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Vedite chislo: ";
        cin >> massiv[i];
    }
    copy(massiv, n);
    return 0;
}
