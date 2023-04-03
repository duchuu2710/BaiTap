#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>

using namespace  std;

class Flight{
    private:
        uint8_t id;
        char origin[20];
        char destination[20];
        uint8_t departureTime;
        uint8_t arrivalTime;
        uint8_t availableSeat;
    public:
        Flight(const char inputOrigin[], const char inputDestination[], const uint8_t inputDepartureTime, const uint8_t inputArrivalTime, const uint8_t inputAvailableSeat);
        void setOrigin(const char inputOrigin[]);
        void setDestination(const char inputDestination[]);
        void setDepartureTime(const uint8_t inputDepartureTime);
        void setArrivalTime(const uint8_t inputArrivalTime);
        void setAvailableSeat(const uint8_t inputAvailableSeat);
        uint8_t getId();
        char *getOrigin();
        char *getDestination();
        uint8_t getDepartureTime();
        uint8_t getArrivalTIme();
        uint8_t getAvailableSeat();
};

Flight::Flight(const char inputOrigin[], const char inputDestination[], const uint8_t inputDepartureTime, const uint8_t inputArrivalTime, const uint8_t inputAvailableSeat){
    static uint8_t ID = 100;
    Flight::id = ID;
    ID++;

    strcpy(origin, inputOrigin);
    strcpy(destination, inputDestination);
    departureTime = inputDepartureTime;
    arrivalTime = inputArrivalTime;
    availableSeat = inputAvailableSeat;   
}

void Flight::setOrigin(const char inputOrigin[]){
    strcpy(origin, inputOrigin);
}

void Flight::setDestination(const char inputDestination[]){
    strcpy(destination, inputDestination);
}

void Flight::setArrivalTime(const uint8_t inputArrivalTime){
    arrivalTime = inputArrivalTime;
}

void Flight::setDepartureTime(const uint8_t inputDepartureTime){
    departureTime = inputDepartureTime;
}

void Flight::setAvailableSeat(const uint8_t inputAvailableSeat){
    availableSeat = inputAvailableSeat;   
}

uint8_t Flight::getId(){
    return Flight::id;
}

char *Flight::getOrigin(){
    return origin;
}

char *Flight::getDestination(){
    return destination;
}

uint8_t Flight::getDepartureTime(){
    return departureTime;
}

uint8_t Flight::getArrivalTIme(){
    return arrivalTime;
}

uint8_t Flight::getAvailableSeat(){
    return availableSeat;
}



class Booking{
    private: 
        uint8_t id;
        char customerName[20];
        uint8_t flightID;
        uint8_t seatNumber;
    public:
        Booking(const char inputCustomerName[], const uint8_t inputFlightID, const uint8_t inputSeatNumber);
        void setFlightID(const uint8_t inputFlightID);
        void setCustomerName(const char inputCustomerName[]);
        void setSeatNumber(const uint8_t inputSeatNumber);
        uint8_t getId();
        char *getCustomerName();
        uint8_t getFlightId();
        uint8_t getSeatNumber();
};

Booking::Booking(const char inputCustomerName[], const uint8_t inputFlightID, const uint8_t inputSeatNumber){
    static uint8_t ID = 100;
    Booking::id = ID;
    ID++;
    strcpy(customerName, inputCustomerName);
    flightID = inputFlightID;
    seatNumber = inputSeatNumber;
}

void Booking::setCustomerName(const char inputCustomerName[]){
    strcpy(customerName, inputCustomerName);
}

void Booking::setFlightID(const uint8_t inputFlightID){
    flightID = inputFlightID;
}

void Booking::setSeatNumber(const uint8_t inputSeatNumber){
    seatNumber = inputSeatNumber;
}

uint8_t Booking::getId(){
    return Booking::id;
}

char *Booking::getCustomerName(){
    return customerName;
}

uint8_t Booking::getFlightId(){
    return flightID;
}

uint8_t Booking::getSeatNumber(){
    return seatNumber;
}

class Airline{
    private: 
        vector <Flight> listFlight;
        vector <Booking> listBooking;
    public:
        Airline();
        void addFlight();
        void removeFlight(uint8_t idFlight);
        void searchFlight(char inputOrigin, char inputDestination);
        void getFlightDetail(uint8_t idFlight);
        void bookingFlight(char customerName, uint8_t idFlight, uint8_t seatNumber);
        void cancelBooking( uint8_t bookingId);
        void viewBooking(char customerName);
};

Airline::Airline(){

}

void Airline::addFlight(){
    char inputOrigin[20];
    char inputDestination[20];
    int inputDepartureTime;
    int inputArrivalTime;
    int inputAvailableSeat;

    printf("Enter origin: ");
    scanf("%s", inputOrigin);
    printf("Enter destination: ");
    scanf("%s", inputDestination);
    printf("Enter departure time: ");
    scanf("%d", &inputDepartureTime);
    printf("Enter arrival time: ");
    scanf("%d", &inputArrivalTime);
    printf("Enter available seat: ");
    scanf("%d", &inputAvailableSeat);

    Flight newFlight (inputOrigin, inputDestination, inputDepartureTime, inputArrivalTime, inputAvailableSeat);
    listFlight.push_back(newFlight);
}


int main(int argc, char const *argv[])
{
    Airline al;
    
    return 0;
}





