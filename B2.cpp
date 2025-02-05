/******************************
Pāvels Petrovs, pp23055
B2. Dots naturāls skaitlis n < 1000. Izdrukāt doto skaitli romiešu pierakstā.
Programma izveidota: 01.10.2023
******************************/

#include <iostream>
#include <string> 
using namespace std;

string NormalToRoman(int n) { //Definēta funkcija 'NormalToRoman', kas kā argumentu pieņem veselu skaitli 'n' un atgriež virkni.
    string a = ""; //Inicializē tukšu virknes mainīgo 'a', kurā tiks saglabāts romiešu ciparu atveidojums.
    int Normal_numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string Roman_numbers[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++) { //Ar šo rindu tiek sākta 'for' cikls. Cikls turpinās 13 reizes.
        while (n >= Normal_numbers[i]) { //Šīs cikls darbojas tik ilgi, kamēr ieejas skaitļa 'n' vērtība ir lielāka vai vienāda ar kārtējo elementu masīvā 'Normal_numbers'. Tā nodrošina ieejas skaitļa konvertēšanu uz tā attēlojumu ar romiešu cipariem.
            a += Roman_numbers[i]; //Atbilstošais romiešu ciparu atveidojums tiek pievienots virknei 'a'.
            n -= Normal_numbers[i]; //Šis atņemšanas solis ir izšķirošs, lai atrastu atlikušo skaitļa daļu, kas jāpārvērš romiešu ciparos.
        } 
    }
    
    return a;
}

int main() {
    int n, ok;
    do {
        do {
            cout << "Ievadiet naturālu skaitļu n: ";
            cin >> n;
            if (n <= 0) { //Pārbaude, vai 'n' ir naturāls skaitlis.
                cout << "N nav naturals skaitlis\n";
                cout << endl;
            } else if (n > 1000) { //Pārbaude, vai 'n' nav lielāks nekā 1000.
                cout << "N ir lielāks nekā 1000\n";
                cout << endl;
            }
        } while (n <= 0 || n > 1000); // Pārbauda, ​​vai nosacījums 'n <= 0' un 'n > 1000' joprojām ir patiess.
                                     // Ja tas ir patiess, iekšējā cilpa atkārtosies, aicinot lietotāju vēlreiz ievadīt skaitli, līdz tiek ievadīts naturāls skaitlis.

        string a = NormalToRoman(n); //Tiek izsaukta funkcija 'NormalToRoman', un tās atgrieztā vērtība tiek piešķirta mainīgajam 'a'.
        cout << "Romiešu pieraksts:" << a << endl;

        cout << "Vai turpināt (1) vai beigt (0)?\n";
        cin >> ok;
        cout << endl;

    } while (ok == 1); //Pārbauda, ​​vai vērtība 'ok' ir vienāda ar 1. 
                       //Ja tā, programma atkārtojas no sākuma, liekot lietotājam ievadīt jaunu vērtību 'n'. Ja 'ok' nav vienāds ar 1, programma beidzas.

    return 0;
}