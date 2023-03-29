#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <cstring>
#include <stdlib.h>


using namespace std;


class Personal {
    private:
        uint8_t id;
        char name[30];
        uint16_t yearOfBirth;
        uint8_t age;
        char address[30];
    public:
        Personal(const char inputName[], const uint16_t inputYearOfBirth, /*const uint8_t inputAge,*/ const char inputAddress[]);
        void setName(const char inputName[]);
        void setYearOfBirth(const uint16_t inputYearOfBirth);
        void setAge(const uint8_t inputAge);
        void setAddress(const char inputAddress[]);
        char *getName();
        uint16_t getYearOfBirth();
        uint8_t getAge();
        char *getAddress();
        uint8_t getId();
};

Personal::Personal(const char inputName[], const uint16_t inputYearOfBirth, /*const uint8_t inputAge,*/ const char inputAddress[]){

    static uint8_t Id = 100;
    Personal::id = Id;
    Id++;
    strcpy(name, inputName);
    yearOfBirth = inputYearOfBirth;
    //age = inputAge;
    strcpy(address, inputAddress);

}

void Personal::setName(const char inputName[]){
    strcpy(name, inputName);
}

void Personal::setYearOfBirth(const uint16_t inputYearOfBirth){
    yearOfBirth = inputYearOfBirth;
}

void Personal::setAge(const uint8_t inputAge){
    age = inputAge;
}

void Personal::setAddress(const char inputAddress[]){
    strcpy(address, inputAddress);
}

char *Personal::getName(){
    return name;
}

uint16_t Personal::getYearOfBirth(){
    return yearOfBirth;
}

uint8_t Personal::getAge(){
    return age;
}

char *Personal::getAddress(){
    return address;
}

uint8_t Personal::getId(){
    return Personal::id;
}

class Information {
    private:
        vector <Personal> database;
    public:
        Information();
        void addpersonal();
        void displayInformation();
        void calculatorAge();
        uint8_t checkExistID(uint8_t id);
        uint8_t checkPosition(uint8_t id);
};

Information::Information(){
    HOME:
    printf("HOME\n");
    printf("Press 1 Add Personal.\n");
    printf("Press 2 Display Infomation.\n");
    printf("Press 3 Calculator Age.\n");
    printf("Press 4 Exit.\n");
    printf("Choose: ");
    int key;
    do
    {
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            addPersonal:
            addpersonal();
            displayInformation();
            printf("Press 1 Continue adding Personal.\n");
            printf("Press 2 Comeback HOME\n");
            printf("Choose: ");
            scanf("%d", &key);
            switch (key)
            {
            case 1:
                goto addPersonal;
                break;
            case 2:
                goto HOME;
                break;
            }
            break;
        case 2:
            if (database.size() > 0)    
            {
                displayInformation();
                printf("\nPress 0 comeback HOME\n");
                scanf("%d", &key);
                goto HOME;
            }
            else
            {
                printf("Unavailable\n");
                printf("\nPress 0 comeback HOME\n");
                scanf("%d", &key);
                goto HOME;
            }
            break;
        case 3:
            if (database.size() > 0)    
            {
                displayInformation();
                calculatorAge();
                printf("\nPress 0 comeback HOME\n");
                scanf("%d", &key);
                goto HOME;
            }
            else
            {
                printf("Unavailable\n");
                printf("\nPress 0 comeback HOME\n");
                scanf("%d", &key);
                goto HOME;
            }
            break;
        case 4:
            exit(0);
            break;  
        }    
    } while (key < 5);
    printf ("Unavailable\n");
    printf ("Press again\n");
    goto HOME;

}

void Information::addpersonal(){
    char inputName[30];
    char inputAddress[30];
    int inputYearOfBirth;
    uint8_t inputAge;
    

    printf("Enter name: ");
    scanf("%s", inputName);
    printf("Enter year of birth: ");
    scanf("%d", &inputYearOfBirth);
    printf("Enter address: ");
    scanf("%s", inputAddress);
    Personal detail(inputName, inputYearOfBirth, inputAddress);
    database.push_back(detail);

}

uint8_t Information::checkExistID(uint8_t id){
    uint8_t check = false;
    for (uint8_t i = 0; i < database.size(); i++)
    {
        if (id == database[i].getId())
        {
            check = true;
        }
    }
    return check;
}

uint8_t Information::checkPosition(uint8_t id){
    int position;
    for (uint8_t i = 0; i < database.size(); i++)
    {
        if (id == database[i].getId())
        {
            position = i;
        }
    }
    return position;
}


void Information::calculatorAge(){
    uint16_t currentYear;
    uint8_t currentAge;
    int id;
    
    printf("Enter ID calculator Age: ");
    scanf("%d", &id);

    if (checkExistID(id) == true)
    {
        printf("Enter curent year: ");
        scanf("%d",&currentYear); 
        currentAge = currentYear - database[checkPosition(id)].getYearOfBirth();
        database[checkPosition(id)].setAge(currentAge);
        printf("Current age of %s: %d", database[checkPosition(id)].getName(), database[checkPosition(id)].getAge());
    }
}

void Information::displayInformation(){
    printf("ID\tName\tYearOfBirth\tAddress\n");
    for (uint8_t i = 0; i < database.size(); i++)
    {   
        printf("%d\t", database[i].getId());
        printf("%s\t", database[i].getName());
        printf("%d\t\t", database[i].getYearOfBirth());
        printf("%s\n", database[i].getAddress());

    }
    
}

int main(int argc, char const *argv[])
{
    Information info;
    return 0;
}
