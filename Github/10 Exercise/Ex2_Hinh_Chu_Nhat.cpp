#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <math.h>

using namespace std;

class HinhChuNhat{
    private:
        uint8_t lenght;
        uint8_t width;
    public:
        HinhChuNhat(const uint8_t lenght, const uint8_t width);
        void setLenght(const uint8_t lenght);
        void setWidth(const uint8_t width);
        uint8_t getLenght();
        uint8_t getWidth();
};

HinhChuNhat::HinhChuNhat(const uint8_t input_lenght, const uint8_t input_width){
    lenght = input_lenght;
    width = input_width;
}

void HinhChuNhat::setLenght(const uint8_t input_lenght){
    lenght = input_lenght;
}

void HinhChuNhat::setWidth(const uint8_t input_width){
    width = input_width;
}

uint8_t HinhChuNhat::getLenght(){
    return lenght;
}

uint8_t HinhChuNhat::getWidth(){
    return width;
}

class Calculator{
    private:
        vector <HinhChuNhat> database;
    public:
        Calculator();
        void enterLenght();
        void perimeter();
        void area();
        void diagonaLine();
        void checkSquare();
        void resetLenght();
        void display();
};

Calculator::Calculator(){
    HOME:
    system("cls");
    resetLenght();
    printf("Nhan 1 Tinh chu vi.\n");
    printf("Nhan 2 Tinh dien tich hinh chu nhat.\n");
    printf("Nhan 3 Tinh do danh duong cheo.\n");
    printf("Nhan 4 kiem tra xem co phai la hinh vuong?.\n");
    printf("Nhan 5 Thoat.\n");
    printf("Chon chuong trinh: ");
    int key;
    scanf("%d", &key);
    switch (key)    
    {
    case 1:
        enterLenght();
        display();
        perimeter();
        printf("Nhan 0 quay lai HOME");
        scanf("%d", &key);
        goto HOME;
        break;
    case 2:
        enterLenght();
        display();
        area();
        printf("Nhan 0 quay lai HOME");
        scanf("%d", &key);
        goto HOME;
        break;
    case 3: 
        enterLenght();
        display();
        diagonaLine();
        printf("Nhan 0 quay lai HOME");
        scanf("%d", &key);
        goto HOME;
        break;
    case 4:
        enterLenght();
        display();
        checkSquare();
        printf("Nhan 0 quay lai HOME");
        scanf("%d", &key);
        goto HOME;
        break;
    case 5:
        exit(0);
        break;
    }
}

void Calculator::enterLenght(){
    int inputLenght;
    int inputWidth;
    printf("Nhap chieu dai: ");
    scanf("%d", &inputLenght);
    printf("Nhap chieu rong: ");
    scanf("%d", &inputWidth);
    HinhChuNhat hcn(inputLenght, inputWidth);
    database.push_back(hcn);
}

void Calculator::perimeter(){
    double perimeter;
    uint8_t i = 0;
    perimeter = (database[i].getLenght() + database[i].getWidth())*2;
    printf("Perimeter: %0.2lf\n", perimeter);
}

void Calculator::area(){
    double area;
    uint8_t i = 0;
    //ct: area = lenght*width
    area = database[i].getLenght() * database[i].getWidth();
    printf("Area: %0.2lf\n", area);
}

void Calculator::diagonaLine(){
    double diagonaLine;
    uint8_t i = 0;
    //ct: diagonaLine= sqrt()
    diagonaLine = sqrt(pow(database[i].getLenght(),2) + pow(database[i].getWidth(),2));
    printf("Diagona line: %0.2lf\n", diagonaLine);
}

void Calculator::resetLenght(){
    for (uint8_t i = 0; i < database.size(); i++)
    {
        database.clear();
    }
}

void Calculator::display(){
    uint8_t i = 0;
    printf("Lenght: %d\n", database[i].getLenght());
    printf("Width: %d\n", database[i].getWidth());
}

void Calculator::checkSquare(){
    uint8_t i = 0;
    if (database[i].getLenght() == database[i].getWidth())
    {
        printf("This's Square.\n");
    }
    else
        printf("This's rectangle.\n");
    
}

int main(int argc, char const *argv[])
{
    Calculator cl;
    return 0;
}
