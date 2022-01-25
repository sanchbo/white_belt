#include <iostream>
#include <string>
#include <map>

using namespace std;

void ChangeCapital(string country, string new_capital, map <string, string>& countries_db) {
// принимает 2 названия столицы (старое, новое)
// словарь (БД), где нужно обновить значение
if (countries_db.count(country) == 0) {
    countries_db[country] = new_capital;
    cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    // cout << "Added capital: " << countries_db[country] << endl;
} else if (countries_db[country] == new_capital) { 
    cout << "Country " << country << " hasn't changed its capital" << endl;
} else {
    string old_capital = countries_db[country];
    countries_db[country] = new_capital;
    cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
}
}

void Rename(string old_country_name, string new_country_name, map <string, string>& countries_db) {
    // Если новое название страны = старому (Ukraine, Ukraine)
    // Если страна не существует (UkraineRussia)
    // Если новая страна уже существует (Ukraine, Russia)
    if (old_country_name == new_country_name || countries_db.count(old_country_name) == 0 || countries_db.count(new_country_name) == 1) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        string capital = countries_db[old_country_name];
        cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
        countries_db.erase(old_country_name);
        countries_db[new_country_name] = capital;
    }
}

void About(string country, map <string, string>& countries_db) {
    if (countries_db.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << countries_db[country] << endl;
    }
}


void Dump(map <string, string>& countries_db) {
    if (countries_db.empty()) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (auto country_capital : countries_db) {
            cout << country_capital.first << "/" << country_capital.second << " ";
        }
        cout << endl;
     }
}

int main() {
    int q;
    cin >> q;
    map <string, string> countries_db;
    for (int i = 0; i < q; i++) {
        string CMD;
        cin >> CMD;
        if (CMD == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            ChangeCapital(country, new_capital, countries_db);
        } else if (CMD == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            Rename(old_country_name, new_country_name, countries_db);
        } else if (CMD == "ABOUT") {
            string country;
            cin >> country;
            About(country, countries_db);
        } else if (CMD == "DUMP") {
            Dump(countries_db);
        }
    }
    return 0;
}

// CHANGE_CAPITAL RussianEmpire Petrograd
// RENAME RussianEmpire RussianRepublic
// ABOUT RussianRepublic
// RENAME RussianRepublic USSR
// CHANGE_CAPITAL USSR Moscow
// DUMP

// Your output:
// Incorrect rename, skip
// Country FarFarAway doesnt't exist
// There are no countries in the world
// Introduce new country TsardomOfRussia with capital Moscow
// Country TsardomOfRussia hasn't changed its capital
// Introduce new country ColonialBrazil with capital Salvador
// Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
// Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
// Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
// Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
// Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
// ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg 
// Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
// Country RussianEmpire has capital SaintPetersburg
// Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
// Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
// Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
// Country RussianRepublic with capital Petrograd has been renamed to USSR
// Country USSR has changed its capital from Petrograd to Moscow
// Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
// Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
// Country RussianEmpire doesnt't exist
// FederativeRepublicOfBrazil/Brasilia USSR/Moscow 
// Incorrect rename, skip

// Correct output:
// Incorrect rename, skip
// Country FarFarAway doesn't exist
// There are no countries in the world
// Introduce new country TsardomOfRussia with capital Moscow
// Country TsardomOfRussia hasn't changed its capital
// Introduce new country ColonialBrazil with capital Salvador
// Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
// Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
// Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
// Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
// Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
// ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg
// Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
// Country RussianEmpire has capital SaintPetersburg
// Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
// Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
// Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
// Country RussianRepublic with capital Petrograd has been renamed to USSR
// Country USSR has changed its capital from Petrograd to Moscow
// Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
// Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
// Country RussianEmpire doesn't exist
// FederativeRepublicOfBrazil/Brasilia USSR/Moscow
// Incorrect rename, skip