#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <math.h>

using namespace std;

class  Coordinates {
    private:
        uint8_t coordinatesX;
        uint8_t coordinatesY;
    public:
        Coordinates(const uint8_t coordinatesX, const uint8_t coordinatesY);
        void setPointX(const uint8_t coordinatesX);
        void setPointY(const uint8_t coordinatesY);
        uint8_t getPointX();
        uint8_t getPointY();    

};

Coordinates::Coordinates(const uint8_t input_coordinatesX, const uint8_t input_coordinatesY){
    coordinatesX = input_coordinatesX;
    coordinatesY = input_coordinatesY;
}

uint8_t Coordinates::getPointX(){
    return coordinatesX;
}

uint8_t Coordinates::getPointY(){
    return coordinatesY;
}

void Coordinates::setPointX(const uint8_t input_coordinatesX){
    coordinatesX = input_coordinatesX;
}

void Coordinates::setPointY(const uint8_t input_coordinatesY){
    coordinatesY = input_coordinatesY;
}


// class Distance:public Coordinates {
//     private:
//         Coordinates firstPoint;
//         Coordinates secondPoint;
//     public:
    //     Distance (const Coordinates firstPoint, const Coordinates secondPoint);
    //     void setFirstPoint(const uint8_t firstPoint);
    //     void setSecondPoint(const uint8_t secondPoint);
    //     double distanceTwoPoint();
// };

// Distance::Distance(const Coordinates firstPoint, const Coordinates secondPoint){

// }

// class TriangleArea{
//     private:
//     Coordinates firstPoint;
//     Coordinates secondPoint;
//     Coordinates thirdPoint;
//     public:
//     TriangleArea(const Coordinates firstPoint, const Coordinates secondPoint, const Coordinates thirdPoint);
//     void setFirstPoint(const uint8_t firstPoint);
//     void setSecondPoint(const uint8_t secondPoint);
//     void setSecondPoint(const uint8_t thirdPoint);
//     double triangleArea();
// };

class Calculator{
    private:
        vector <Coordinates> toaDoDiem;
    public:
        Calculator();
        void nhapDiem();
        void distanceTwoPoint();
        void triangleArea();  //Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint
        void hienThiToaDoDiem();
        void resetToaDo();
};

Calculator::Calculator(){
    HOME:
    resetToaDo();
    printf("Nhan 1 TInh khoang cach hai diem.\n");
    printf("Nhan 2 Tinh dien tich tam giac.\n");
    printf("Nhan 3 Thoat chuong trinh.\n");
    printf("Chon chuong trinh: ");
    int key;
    scanf("%d", &key);
    switch (key)    
    {
    case 1:
        for (uint8_t i = 0; i < 2; i++)
        {
            nhapDiem();
        }
        hienThiToaDoDiem();
        distanceTwoPoint();
        printf("Nhan 0 quay lai HOME");
        scanf("%d", &key);
        goto HOME;
        break;
    case 2:
         for (uint8_t i = 0; i < 3; i++)
        {
            nhapDiem();
        }
        hienThiToaDoDiem();
        triangleArea();
        printf("Nhan 0 quay lai HOME");
        scanf("%d", &key);
        goto HOME;
        break;
    case 3:
        exit(0);
        break;
    }
}

void Calculator::nhapDiem(){
    int input_x;
    int input_y;
    printf("Nhap x = ");
    scanf("%d", &input_x);
    printf("Nhap y = ");
    scanf("%d", &input_y);

    Coordinates viTri(input_x, input_y);

    toaDoDiem.push_back(viTri);
}

void Calculator::distanceTwoPoint(){

    uint8_t i = 0;
    double distance;
    distance = sqrt(pow(toaDoDiem[i+1].getPointX()-toaDoDiem[i].getPointX(),2) + pow(toaDoDiem[i+1].getPointY()-toaDoDiem[i].getPointY(),2)); 
    printf("Khoang cach giua hai diem: %lf\n", distance); 
}

void Calculator::triangleArea(){

    uint8_t i = 0;
    double Xba,Yca,Xca,Yba;
    double area;

    //cho ba diem A,B,C
    //tinh dien tich: CT=1/2|(Xb-Xa)*(Yc-Ya)-(Xc-Xa)*(Yb-Ya)|
    // 
    Xba = toaDoDiem[i+1].getPointX()-toaDoDiem[i].getPointX();
    Yca = toaDoDiem[i+2].getPointY()-toaDoDiem[i].getPointY();
    Xca = toaDoDiem[i+2].getPointX()-toaDoDiem[i].getPointX();
    Yba = toaDoDiem[i+1].getPointY()-toaDoDiem[i].getPointY();
    
    area = (0.5)*fabs((Xba*Yca)-(Xca*Yba));

    
    printf("Dien tich giua 3 diem: %lf\n", area); 
}

void Calculator::hienThiToaDoDiem(){
    printf("Diem\t\tToa Do X\t\t\tToa Do Y\n");
    for (uint8_t i = 0; i < toaDoDiem.size(); i++)
    {
        printf("  %d\t\t   %d\t\t\t\t   %d\n", i+1, toaDoDiem[i].getPointX(),toaDoDiem[i].getPointY());
    }
    
}
void Calculator::resetToaDo(){
    for (uint8_t i = 0; i < toaDoDiem.size(); i++)
    {
        toaDoDiem.clear();
    }
    
}

int main(int argc, char const *argv[])
{
    Calculator cl;
    return 0;
}
