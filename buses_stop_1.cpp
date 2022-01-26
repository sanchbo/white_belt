#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> GetBusesForStop(const string& bus_stop_name, const vector<string>& bus_stops, map <string, vector<string>>& buses_db) {
    vector<string> required_buses;
    for (auto bus: bus_stops) {
        vector<string> stops = buses_db[bus];
        if (count(stops.begin(), stops.end(), bus_stop_name)) {
            if (bus_stop_name.length() > 0)
            required_buses.push_back(bus);
        }
    }

    return required_buses;
}

void NewBus(string bus, int stop_count, map <string, vector<string>>& buses_db) {
    for (int i = 0; i < stop_count; i++) {
        string stop_description;
        cin >> stop_description;
        buses_db[bus].push_back(stop_description);
    }
}

void PrintBusStops(const vector<string>& bus_stops){
    for (auto bus_stop_name: bus_stops) {
        cout << bus_stop_name << " ";
    }
    cout << endl;
}

void BusesForStop(const string& bus_stop_name, const vector<string>& bus_stops, map <string, vector<string>>& buses_db) {
    vector<string> required_buses = GetBusesForStop(bus_stop_name, bus_stops, buses_db);

    if (required_buses.size() == 0) {
        cout << "No stop" << endl;
    } else {
        PrintBusStops(required_buses);
    }
    
}

void StopsForBus(string bus, const vector<string>& bus_stops, map <string, vector<string>>& buses_db) {
    if (buses_db.count(bus) == 0) {
        cout << "No bus" << endl;
    } else {
        vector<string> stops = buses_db[bus];
        for (auto bus_stop_name: stops) {
            vector<string> required_buses = GetBusesForStop(bus_stop_name, bus_stops, buses_db);
            cout << "Stop " << bus_stop_name << ": ";
            if (required_buses.size() == 1) {
                cout << "no interchange" << endl;
            } else {
                auto it = find(required_buses.begin(), required_buses.end(), bus);
                if(it != required_buses.end())
                    required_buses.erase(it);

                PrintBusStops(required_buses);
            }
        }
    }
}

void AllBuses(const map <string, vector<string>>& buses_db) {
    if (buses_db.empty()) {
        cout << "No buses" << endl;
    } else { 
        for (auto bus_stops: buses_db) {
            string bus_name = bus_stops.first;
            vector<string> stops = bus_stops.second;
            cout << "Bus " << bus_name << ": ";
            PrintBusStops(stops);

        }
    }
}

int main() {
    int q;
    cin >> q;

    map <string, vector<string>> buses_db;
    vector <string> buses_names;
    
    for (int i = 0; i < q; i++) {
     
        string CMD;
        cin >> CMD;

        if (CMD == "NEW_BUS") {
            string bus;
            cin >> bus;
            buses_names.push_back(bus);

            int bus_stops;
            cin >> bus_stops;

            NewBus(bus, bus_stops, buses_db);
            
        } else if (CMD == "ALL_BUSES") {
            AllBuses(buses_db);

        } else if (CMD == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            StopsForBus(bus, buses_names, buses_db);

        } else if (CMD == "BUSES_FOR_STOP") {
            string bus_stop;
            cin >> bus_stop;
            BusesForStop(bus_stop, buses_names, buses_db);
        }
    }
    return 0;
}
