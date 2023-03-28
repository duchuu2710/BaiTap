#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include <vector>
#include <math.h>

using namespace std;


class Animal{
    private:
        uint8_t id;
        char name[30];
        uint8_t age;
        uint8_t weight;
        uint8_t height;
    public:
        Animal(const char input_name[], const uint8_t input_age, const uint8_t input_weight, const uint8_t input_height);
        void setName(const char input_name[]);
        void setAge(const uint8_t input_age);
        void setWeight(const uint8_t input_weight);
        void setHeight(const uint8_t input_height);
        uint8_t getId();
        char *getName();
        uint8_t getAge();
        uint8_t getWeight();
        uint8_t getHeight();
};

Animal::Animal(const char input_name[], const uint8_t input_age, const uint8_t input_weight, const uint8_t input_height){
    static uint8_t ID = 100;
    Animal::id = ID;
    ID++;
    age = input_age;
    strcpy(name, input_name);
    weight = input_weight;
    height = input_height;
}

void Animal::setName(const char input_name[]){
    strcpy(name, input_name);
}

void Animal::setAge(const uint8_t input_age){
    age = input_age;
}

void Animal::setHeight( const uint8_t input_height){
    height = input_height;
}

void Animal::setWeight(const uint8_t input_weight){
    weight = input_weight;
}

char *Animal::getName(){
    return name;
}

uint8_t Animal::getAge(){
    return age;
}

uint8_t Animal::getHeight(){
    return height;
}

uint8_t Animal::getWeight(){
    return weight;
}

uint8_t Animal::getId(){
    return Animal::id;   //return this->id;
}

class Calculator{
    private:
        vector <Animal> database;
    public:
        Calculator();
        void addAnimal();
        void displayAnimal();//tich hop tinh chi so BMI sau khi them dong vat
        void calculatorBMI();//tinh chi so BMI dong vat khong co trong danh sach
        void compare();
        bool checkExist(int id);
        int checkPosition(int id);
};

Calculator::Calculator(){
    HOME:
    printf("HOME\n");
    printf("Press 1 add Animal.\n");
    printf("Press 2 Display animal with BMI.\n");
    printf("Press 3 Calculator BMI off the list.\n");
    printf("Press 4 Compare index.\n");
    printf("Press 5 Exit.\n");
    printf("Choose: ");
    int key;
    scanf("%d", &key);
    switch (key)
    {
    case 1:
        addAnimal:
        addAnimal();
        displayAnimal();
        printf("Press 1 Continue adding animal.\n");
        printf("Press 2 Comeback HOME\n");
        printf("Choose: ");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            goto addAnimal;
            break;
        case 2:
            goto HOME;
            break;
        }
        break;
    case 2:
        if (database.size() > 0)
        {
            displayAnimal();
            printf("\nPress 0 comeback HOME\n");
            scanf("%d", &key);
            goto HOME;
        }else
        {
            printf("Unavailable\n");
            printf("\nPress 0 comeback HOME\n");
            scanf("%d", &key);
            goto HOME;
        }
        break;
    case 3:
        calculatorBMI:
        calculatorBMI();
        printf("Press 1 Continue calculator BMI.\n");
        printf("Press 2 Comeback HOME\n");
        printf("Choose: ");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            goto calculatorBMI;
            break;
        case 2:
            goto HOME;
            break;
        }
        break;
    case 4:
        if (database.size() >= 2)
        {
            displayAnimal();
            compare();
            
            printf("\nPress 0 comeback HOME\n");
            scanf("%d", &key);
            goto HOME;
        }else
        {
            printf("Unavailable\n");
            printf("\nPress 0 comeback HOME\n");
            scanf("%d", &key);
            goto HOME;
        }
        break;
    case 5:
        exit(0);
        break;
    }       


}

void Calculator::addAnimal(){
    char inputName[30];
    int inputAge;
    int inputWeight;
    int inputHeight;
    printf("Enter name: ");
    scanf("%s", inputName);
    printf("Enter age: ");
    scanf("%d", &inputAge);
    printf("Enter weight(Kg): ");
    scanf("%d", &inputWeight);
    printf("Enter height(Cm): ");
    scanf("%d", &inputHeight);
    Animal information( inputName, inputAge, inputWeight, inputHeight);
    database.push_back(information);
}

void Calculator::displayAnimal(){
    double calculatorBMI;
    printf("Serial\tID\tName\tAge\tWeight\tHeight\tBMI\n");
    
    for (uint8_t i = 0; i < database.size(); i++)
    {
        calculatorBMI = database[i].getWeight()*703/pow(database[i].getHeight(),2); //tinh chi so BMI
        printf("%d\t", i+1);
        printf("%d\t", database[i].getId());
        printf("%s\t", database[i].getName());
        printf("%d\t", database[i].getAge());
        printf("%d\t", database[i].getWeight());
        printf("%d\t", database[i].getHeight());
        printf("%0.2lf\n", calculatorBMI);
    }
}
//tinh chi so BMI dong vat ngoai danh sach
void Calculator::calculatorBMI(){
    double calculatorBMI;
    int weight;
    int height;
    printf("Enter weight: ");
    scanf("%d", &weight);
    printf("Enter height: ");
    scanf("%d", &height);
    
    calculatorBMI = weight*703/pow(height,2);
    printf("\nBMI: %0.2lf\n", calculatorBMI);
}

bool Calculator::checkExist(int id){

    for (uint8_t i = 0; i < database.size(); i++)
    {
        if (id == database[i].getId())
        {
            return true;
        }
    }
}

int Calculator::checkPosition(int id){
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

void Calculator::compare(){
    compare:
    int firstId;
    int secondId;
    int compareAge;
    int compareHeight;
    int compareWeight;
    
    printf("Enter ID1 to compare: ");
    scanf("%d", &firstId);
    printf("Enter ID2 to compare: ");
    scanf("%d", &secondId);
    if (checkExist(firstId) == true && checkExist(secondId) == true)
    {
        compareAge = database[checkPosition(firstId)].getAge() - database[checkPosition(secondId)].getAge();
        compareHeight = database[checkPosition(firstId)].getHeight() - database[checkPosition(secondId)].getHeight();
        compareWeight = database[checkPosition(firstId)].getWeight() - database[checkPosition(secondId)].getWeight();
        // printf("\n%d\n", compareAge);
        // printf("\n%d\n", compareHeight);
        printf("Resault between %s and %s: \n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());
        if (compareAge > 0)
        {
            printf("- Age of %s > %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());
        }else if (compareAge = 0)
        {
            printf("- Age of %s = %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());
        }else 
            printf("- Age of %s < %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());



        if (compareWeight > 0)
        {
            printf("- Weight of %s > %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());
        }
        else if (compareWeight = 0)
        {
            printf("- Weight of %s = %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());
        }
        else 
            printf("- Weight of %s < %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());

        
        if (compareHeight > 0)
        {
            printf("- Height of %s > %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());
        }
        else if (compareHeight = 0)
        {
            printf("- Height of %s = %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());
        }
        else 
            printf("- Height of %s < %s\n", database[checkPosition(firstId)].getName(), database[checkPosition(secondId)].getName());

    }
    else
    {
        printf("ID error. Please enter again.\n");
        goto compare;
    }

}


int main(int argc, char const *argv[])
{
    Calculator cl;
    return 0;
}
