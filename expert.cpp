#include <bits/stdc++.h>
using namespace std;

class Flight{
    public:
    string flightnumber;
    string departure;
    string destination;
    string departuretime;
    
    Flight(string n,string dep,string dest,string time){
        this->flightnumber = n;
        this->departure = dep;
        this->destination = dest;
        this->departuretime = time;
    }
    bool isOverlap(const Flight &other){
        return departure==other.departure && departuretime==other.departuretime;
    }
    void display(){
        cout << "Flight: " << flightnumber << ", Departure: " << departure
             << ", Destination: " << destination << ", Departure Time: " << departuretime << endl;
    }
    friend class airLineSystem;
};

class airLineSystem{
    public:
    vector<Flight>flights;
    bool isFlightOverlap(Flight &curr_flight){
        for(Flight& f : flights){
            if(f.isOverlap(curr_flight)) return true;
        }
        return false;
    }
    string adjustTime(string time,int adjust){
        int hrs = stoi(time.substr(0,2));
        int minutes = stoi(time.substr(3));

        hrs = (hrs + adjust)%24;

        //convert to string
        string newtime = (hrs < 10 ? "0":"") + to_string(hrs) + ":"+(minutes<10?"0":"")+to_string(minutes);
        return newtime;
    }
    void addFlight(Flight& curr_flight){
        if(!isFlightOverlap(curr_flight)){
            flights.push_back(curr_flight);
            cout << "Flight added successfully." << endl;
        }
        else{
            cout << "Error: Flight overlaps with existing flights. Please choose a different schedule." << endl;
            cout<<"Expert Opinion:------"<<endl;
            cout<<"You can schedule your flight:"<<endl;
            cout<<"1. 1 hour after "<<curr_flight.departuretime<<" that is "<<adjustTime(curr_flight.departuretime,1)<<endl;
            cout<<"2. 1 hour before "<<curr_flight.departuretime<<" that is "<<adjustTime(curr_flight.departuretime,-1)<<endl;
            cout<<"3. To cancel your flight"<<endl;
            cout<<"Enter your Choice:";
            int ch;
            cin>>ch;
            int adjust;
            if(ch == 1 || ch == 2){
                adjust = (ch==1) ? 1 : -1;
                Flight temp = Flight(curr_flight.flightnumber,curr_flight.departure,curr_flight.destination,curr_flight.departuretime);
                addFlight(temp);
            }else{
                cout<<"Your Flight Scheduling Request has been cancelled"<<endl;
            }
        }
    }
    void removeFlight(string &fn){
        auto it = find_if(flights.begin(),flights.end(),[&fn](const Flight& flight){
            return flight.flightnumber == fn;
        });

        if(it != flights.end()){
            flights.erase(it);
            cout << "Flight " << fn << " removed successfully." << endl;
        }else{
            cout << "Error: Flight " << fn << " not found." << endl;
        }
    }

    void displayFlights(){
        if (flights.empty()) {
            cout << "No flights scheduled." << endl;
        } else {
            cout << "Scheduled Flights:" << endl;
            for ( Flight& flight : flights) {
                flight.display();
            }
        }
    }
    
    void searchFlightsByDepartureCity(string& depCity){
        bool found = false;
        cout << "Flights departing from " << depCity << ":" << endl;
        for (Flight& flight : flights) {
            if (flight.departure == depCity) {
                flight.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No flights found departing from " << depCity << endl;
        }
    }
    
    void displayFlightsSortedByDepartureTime(){
        vector<Flight>sortedFlights = flights;
        sort(sortedFlights.begin(),sortedFlights.end(),[](const Flight &a,const Flight &b){
            return a.departure < b.departure;
        });
        cout << "Flights Sorted by Departure Time:" << endl;
        for (Flight& flight : sortedFlights) {
            flight.display();
        }
    }

};


int main() {
    airLineSystem system;
    int choice;

    do {
        cout << "\nAirline Scheduling System\n";
        cout << "1. Add Flight\n";
        cout << "2. Remove Flight\n";
        cout << "3. View Flights\n";
        cout << "4. Search Flights by Departure City\n";
        cout << "5. Display Flights Sorted by Departure Time\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string number, dep, dest, time;
                cout << "Enter flight number: ";
                cin >> number;
                cout << "Enter departure city: ";
                cin >> dep;
                cout << "Enter destination city: ";
                cin >> dest;
                cout << "Enter departure time (HH:MM): ";
                cin >> time;
                Flight f = Flight(number,dep,dest,time);
                system.addFlight(f);
                break;
            }
            case 2: {
                string number;
                cout << "Enter flight number to remove: ";
                cin >> number;
                system.removeFlight(number);
                break;
            }
            case 3:
                system.displayFlights();
                break;
            case 4: {
                string depCity;
                cout << "Enter departure city to search for flights: ";
                cin >> depCity;
                system.searchFlightsByDepartureCity(depCity);
                break;
            }
            case 5:
                system.displayFlightsSortedByDepartureTime();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}