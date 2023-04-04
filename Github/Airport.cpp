#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <stdlib.h>

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

/*Set name*/
void Booking::setCustomerName(const char inputCustomerName[]){
    strcpy(customerName, inputCustomerName);
}
/*Set ID*/
void Booking::setFlightID(const uint8_t inputFlightID){
    flightID = inputFlightID;
}
/*Set seat number*/
void Booking::setSeatNumber(const uint8_t inputSeatNumber){
    seatNumber = inputSeatNumber;
}
/*Get ID*/
uint8_t Booking::getId(){
    return Booking::id;
}
/*Get customer name*/
char *Booking::getCustomerName(){
    return customerName;
}
/*Get id flight*/
uint8_t Booking::getFlightId(){
    return flightID;
}
/*Get seat number*/
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
        void removeFlight(int idFlight);
        void searchFlight(char inputOrigin[], char inputDestination[]);
        void getFlightDetail(int idFlight);
        void displayFlight();

        uint8_t chooseFlight();
        void bookingFlight();
        void cancelBooking(int bookingId);
        void viewBooking();
};

Airline::Airline(){
/* add_flight(flight: Flight): thêm một chuyến bay mới vào danh sách.
● remove_flight(flight_id: str): xóa một chuyến bay khỏi danh sách theo
mã chuyến bay.
● search_flights(origin: str, destination: str): tìm kiếm các chuyến bay
theo nơi khởi hành và nơi đến.
● get_flight_details(flight_id: str): lấy thông tin chi tiết của một chuyến
bay theo mã chuyến bay.
● book_flight(customer_name: str, flight_id: str, seat_number: str): đặt vé
cho một chuyến bay, tạo đối tượng Booking và cập nhật thông tin ghế
trống của chuyến bay.
● cancel_booking(booking_id: str): hủy vé đã đặt, xóa đối tượng Booking
và cập nhật thông tin ghế trống của chuyến bay.
● view_bookings(customer_name: str): xem danh sách các vé đã đặt
theo tên khách hàng.*/
    HOME:
    printf("HOME.\n");
    printf("Press 1 Add Flight.\n");
    printf("Press 2 Remove flight.\n");
    printf("Press 3 Seach flight.\n");
    printf("Press 4 Detail Flight.\n");
    printf("Press 5 Booking flight.\n");
    printf("Press 6 Cancle flight.\n");
    printf("Press 7 View booking.\n");
    printf("Press 0 Exit.\n");
    printf("Choose: ");
    int key;
    scanf("%d", &key);
    switch (key)
    {
    case 1: // add flight.
        addFlight:
        addFlight();
        printf("Add success.\n");
        displayFlight();
        printf("Press 1 Continue adding filght.\n");
        printf("Press 2 Comeback HOME\n");
        printf("Choose: ");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            goto addFlight;
            break;
        case 2:
            goto HOME;
            break;
        }
        break;
    case 2: // remove flight.
        if (listFlight.size() > 0)
        {
            displayFlight();
            int id;
            printf("Enter ID remove:");
            scanf("%d", &id);
            removeFlight(id);
            printf("Remove success.\n");
            displayFlight();
            printf("Press 0 go HOME\n");
            scanf("%d", &key);
            goto HOME;
        }else
        {
            printf("Empty list. Press again.\n");
            goto HOME;
        }
        break;    
    case 3: // search flight.
        if (listFlight.size() > 0)
        {   
            char inputOrigin[20];
            char inputDestination[20];
            printf("Enter origin: ");
            scanf("%s", inputOrigin);
            printf("Enter destination: ");
            scanf("%s", inputDestination);
            searchFlight(inputOrigin, inputDestination);
            printf("Press 0 go HOME\n");
            scanf("%d", &key);
            goto HOME;
        }else
        {
            printf("Empty list. Press again.\n");
            goto HOME;
        }
        break;
    case 4: // get detail flight.
        if (listFlight.size() > 0)
        {
            displayFlight();
            int inputId;
            printf("Enter id want to watch detail: ");
            scanf("%d", &inputId);
            
            getFlightDetail(inputId);
            printf("Press 0 go HOME\n");
            scanf("%d", &key);
            goto HOME;
        }
        else
        {
            printf("Empty list. Press again.\n");
            goto HOME;
        }
    case 5: // booking flight.
        if (listFlight.size() > 0)
        {
            displayFlight();
            bookingFlight();
            printf("Press 0 go HOME\n");
            scanf("%d", &key);
            goto HOME;
        }
        {
            printf("Empty list. Press again.\n");
            goto HOME;
        }
        break;
    case 6: // cancel booking flight.
        if (listFlight.size() > 0)
        {
            viewBooking();
            int inputId;
            printf("Enter id want to cancel: ");
            scanf("%d", &inputId);
            cancelBooking(inputId);
            printf("Cancel success\n");
            viewBooking();
            printf("Press 0 go HOME\n");
            scanf("%d", &key);
            goto HOME;
        }else
        {
            printf("Empty list. Press again.\n");
            goto HOME;
        }
        break;
    case 7:
        viewBooking();
        printf("Press 0 go HOME\n");
        scanf("%d", &key);
        goto HOME;
        break;
    case 0:
        exit(0);
        break;
    }

    
}
/*Function display flight*/
void Airline::displayFlight(){
    printf("ID\tOrigin\tDestination\tDeparture time\tArival time\tAvailable seat\n");
    for (uint8_t i = 0; i < listFlight.size(); i++)
    {
        printf("%d\t", listFlight[i].getId());
        printf("%s\t", listFlight[i].getOrigin());
        printf("%s\t\t", listFlight[i].getDestination());
        printf("%d\t\t", listFlight[i].getDepartureTime());
        printf("%d\t\t", listFlight[i].getArrivalTIme());
        printf("%d\n", listFlight[i].getAvailableSeat());
    }
    
}
/*Fuction add flight*/
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
/*Function remove flight*/
void Airline::removeFlight(int inputId){
    bool check = false;
    for (uint8_t i = 0; i < listFlight.size(); i++)
    {
        if (inputId == listFlight[i].getId())
        {
            listFlight.erase(listFlight.begin() + i);
            check = true;
        }
    } 
    if (check == false)
    {
        printf("Invalid");
    }
}
/*Function Search for flights by origin and destinationt*/
void Airline::searchFlight(char inputOrigin[], char inputDestination[]){
    bool check = false;
    char origin[20];
    char destination[20];
    for (uint8_t i = 0; i < listFlight.size(); i++)
    {
        strcpy(origin, listFlight[i].getOrigin());
        strcpy(destination, listFlight[i].getDestination());
        if ((strstr(strupr(origin), strupr(inputOrigin))) && strstr(strupr(destination), strupr(inputDestination)))
        {
            printf("ID\tOrigin\tDestination\tDeparture time\tArival time\tAvailable seat\n");

            printf("%d\t", listFlight[i].getId());
            printf("%s\t", listFlight[i].getOrigin());
            printf("%s\t", listFlight[i].getDestination());
            printf("%d\t", listFlight[i].getDepartureTime());
            printf("%d\t", listFlight[i].getArrivalTIme());
            printf("%d\n", listFlight[i].getAvailableSeat());
            check = true;
        }
        

    }
    
    if (check == false)
    {
        printf("Invalid.\n");
    }
    
}
/*Function get details of a flight by flight code*/
void Airline::getFlightDetail(int inputId){
    
    bool check = false;
    for (uint8_t i = 0; i < listFlight.size(); i++)
    {
        if (inputId == listFlight[i].getId())
        {
            printf("ID\tOrigin\tDestination\tDeparture time\tArival time\tAvailable seat\n");

            printf("%d\t", listFlight[i].getId());
            printf("%s\t", listFlight[i].getOrigin());
            printf("%s   \t", listFlight[i].getDestination());
            printf("%d\t", listFlight[i].getDepartureTime());
            printf("%d\t", listFlight[i].getArrivalTIme());
            printf("%d\n", listFlight[i].getAvailableSeat());
            check = true;
        }
        
    }
    if (check == false)
    {
        printf("Invalid.\n");
    }
}

uint8_t Airline::chooseFlight(){
    Choose:
    int id;
    int index;
    bool check = false;
    printf("Enter id of flight: ");
    scanf("%d", &id);
    for (uint8_t i = 0; i < listFlight.size(); i++)
    {

        if (id == listFlight[i].getId()) //check id true or false;
        {
            if (listFlight[i].getAvailableSeat() > 0) //Check available seat
            {
                index = i;
                check = true;
            }
        }
        
    }
    if (check == false)
    {
        printf("Invalid.\n");
        printf("Enter id again.\n");
        goto Choose;
    }
    
    return index;
}
/*Function book a ticket for a flight, create a Booking object, and update the flight's available seat information.*/
void Airline::bookingFlight(){
    char customerName[20];
    int idFlight;
    int seatNumber;
    int index = 0;
    printf("Enter customer name: ");
    scanf("%s", customerName);
    chooseFlight();
    idFlight = listFlight[index].getId();

    do
    {
        printf("Enter number seat: ");
        scanf("%d", &seatNumber);
    } while (seatNumber >= listFlight[index].getAvailableSeat());
    
    Booking newBoking (customerName, idFlight, seatNumber);
    listBooking.push_back(newBoking);
    

    listFlight[index].setAvailableSeat(listFlight[index].getAvailableSeat()-seatNumber);


}
/*Function cancel booking*/
void Airline::cancelBooking(int inputId){
    
    bool check = false;
    for (uint8_t i = 0; i < listBooking.size(); i++)
    {
        if (inputId == listBooking[i].getId())
        {
            listFlight[i].setAvailableSeat(listFlight[i].getAvailableSeat()+listBooking[i].getSeatNumber());// create available seat
            listBooking.erase(listBooking.begin()+i);
            
            check = true;
        }
        
    }

    if (check == false)
    {
        printf("Invalid.\n");
        printf("Enter ID again.\n");
        
    }
}
/*Function view booking*/
void Airline::viewBooking(){
    printf("ID \tCustomer Name\tIDFlight\n"); 
    for (uint8_t i = 0; i < listBooking.size(); i++)
    {
        printf("%d\t", listBooking[i].getId());
        printf("%s\t\t", listBooking[i].getCustomerName());
        printf("%d\n", listBooking[i].getFlightId());
    }
    
}

int main(int argc, char const *argv[])
{
    Airline al;
    
    return 0;
}





