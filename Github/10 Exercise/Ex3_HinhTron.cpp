#include <stdio.h>
#include <stdint.h>
#include <math.h>



class Circle{
    private:
        double radius;
    public:
        Circle();
        void setRadius(const double radius);
        double getRadius();
        void enterRadiusCircle();
        void perimeterCircle();
        void areaCircle();
       
};

Circle::Circle(){
    HOME:
    system("cls");
    printf("Press 1 Perimeter Circle.\n");
    printf("Press 2 Area Circle.\n");
    printf("Press 3 Exit.\n");
    printf("Choose: ");
    int key;
    scanf("%d", &key);
    do
    {
        switch (key)
        {
        case 1:
            enterRadiusCircle();
            perimeterCircle();
            printf("Press 0 comeback HOME");
            scanf("%d", &key);
            goto HOME;
            break;
        case 2:
            enterRadiusCircle();
            areaCircle();
            printf("Press 0 comeback HOME");
            scanf("%d", &key);
            goto HOME;
            break;
        case 3:
            exit(0);
            break;
        }
    }while(key < 0 && key > 3); 
    goto HOME;
}

void Circle::setRadius(const double input_radius){
    radius = input_radius;
}
double Circle::getRadius(){
    return radius;
}

void Circle::enterRadiusCircle(){
    int radius;
    printf("Enter radius: ");
    scanf("%d", &radius);
    setRadius(radius); 
    printf("Radius: %0.2lf\n", getRadius());
}

void Circle::perimeterCircle(){
    double perimeterCircle;
    //getRadius();
    //printf("%0.2lf", getRadius());
    perimeterCircle = (getRadius()*2)*3.14;
    printf("Perimeter Circle: %0.2lf\n", perimeterCircle);
}

void Circle::areaCircle(){
    double areaCircle;
    //getRadius();
    areaCircle = 3.14*pow(getRadius(),2); 
    printf("Area Circle: %0.2lf\n", areaCircle);
}

int main(int argc, char const *argv[])
{
    Circle cr;
    
    
    return 0;
}
