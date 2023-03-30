#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <stdlib.h>

using namespace std;



class Fraction {
    private:
        uint16_t numerator;
        uint16_t denominator;
    public:
        Fraction(const uint16_t inputNumerator, const uint16_t inputDenominator);
        void setNumerator(const uint16_t inputNumerator);
        void setDenominator(const uint16_t inputDenominator);
        uint16_t getNumerator();
        uint16_t getDenominator();
        
};

Fraction::Fraction(const uint16_t inputNumerator, const uint16_t inputDenominator){
    numerator = inputNumerator;
    denominator = inputDenominator;
}

/*Set numerator*/
void Fraction::setNumerator(const uint16_t inputNumerator){
    numerator = inputNumerator;
}

/*Set denominator*/
void Fraction::setDenominator(const uint16_t inputDenominator){
    denominator = inputDenominator;
}

/*Get numerator*/
uint16_t Fraction::getNumerator(){
    return numerator;
}

/*Get denominator*/
uint16_t Fraction::getDenominator(){
    return denominator;
}



class calculatorFraction {
    private:
        vector <Fraction> database;
    public:
        calculatorFraction();
        void addNumber();
        void addition();
        void subtraction();
        void multiplication();
        void devision();
        bool checkDenominator (uint16_t inputDenominator);
        void displayFraction();
};

calculatorFraction::calculatorFraction(){
    HOME:
    system("cls");
    database.clear();
    printf("HOME\n");
    printf("Press 1 calculator fraction.\n");
    printf("Press 2 exit.\n");
    printf("Choose: ");
    int key;
    scanf("%d", &key);
    do
    {
        switch (key)
        {
        case 1:
            addNumber();
            addNumber();
            displayFraction();
            addition();
            subtraction();
            multiplication();
            devision();
            printf("Press 0 comeback HOME\n");
            scanf("%d", &key);
            goto HOME;
            break;
        
        case 2:
            exit(0);
            break;
        }
    } while (0 < key > 2 );
    goto HOME;
}

bool calculatorFraction::checkDenominator (uint16_t inputDenominator){
    if (inputDenominator != 0){
        return true;
    }
    else 
    {
        printf("Enter denominator again.\n");
        return false;
    }   
}

/*Enter Fraction*/
void calculatorFraction::addNumber(){
    int inputNumerator;
    int inputDenomination;
    printf("Enter numerator: ");
    scanf("%d", &inputNumerator);
    do
    {
        printf("Enter denominator: ");
        scanf("%d", &inputDenomination);
    }while (checkDenominator(inputDenomination) == false);
    Fraction fr(inputNumerator, inputDenomination);
    database.push_back(fr);
}

/*Addition*/
void calculatorFraction::addition(){
    int resultNumeratorAdditon;
    int resultDenominatorAdditon;
    double resultAddtion;
    uint8_t i = 0;
    /*Result numerator addition*/
    resultNumeratorAdditon = database[i].getNumerator()*database[i+1].getDenominator() + database[i+1].getNumerator()*database[i].getDenominator();
    /*Result denominator addition*/
    resultDenominatorAdditon = database[i].getDenominator()*database[i+1].getDenominator();
    /*Result type double*/
    resultAddtion = (double)(resultNumeratorAdditon) /(double)(resultDenominatorAdditon);
    printf("Resault addition fraction: %d / %d = %0.2lf\n", resultNumeratorAdditon, resultDenominatorAdditon, resultAddtion); 
}

 /*Subtraction*/
void calculatorFraction::subtraction(){
    double resultSubtraction;
    int resultNumeratorSubtraction;
    int resultDenominatorSubtraction;
    uint8_t i = 0;
     /*Result numerator subtraction*/
    resultNumeratorSubtraction = database[i].getNumerator() * database[i+1].getDenominator() - database[i+1].getNumerator() * database[i].getDenominator();
     /*Result denominator subtraction*/
    resultDenominatorSubtraction = database[i].getDenominator()*database[i+1].getDenominator();
    /*Result type double*/
    resultSubtraction = (double)(resultNumeratorSubtraction) / (double)(resultDenominatorSubtraction); 
    printf("Resault subtraction fraction: %d / %d = %0.2lf\n", resultNumeratorSubtraction, resultDenominatorSubtraction, resultSubtraction); 
}

/* Multiplication*/
void calculatorFraction::multiplication(){
    double resultMultiolication;
    int resultNumeratorMultiolication;
    int resultDenominatorMultiolication;
    uint8_t i = 0;
    /*Result numerator multiplication*/
    resultNumeratorMultiolication = database[i].getNumerator()*database[i+1].getNumerator();
    /*Result denominator multiplication*/
    resultDenominatorMultiolication = database[i].getDenominator()*database[i+1].getDenominator();
    /*Result type double*/
    resultMultiolication = (double)(resultNumeratorMultiolication) / (double)(resultDenominatorMultiolication);
    printf("Resault multiplication fraction: %d / %d = %0.2lf\n", resultNumeratorMultiolication, resultDenominatorMultiolication, resultMultiolication);
}

/*Division*/
void calculatorFraction::devision(){
    double resultDevision;
    int resultNumeratorDevision;
    int resultDenominatorDevision;
    uint8_t i = 0;
    /*Result numerator division*/
    resultNumeratorDevision = database[i].getNumerator()*database[i+1].getDenominator();
    /*Result denominator devision*/
    resultDenominatorDevision = database[i].getDenominator()*database[i+1].getNumerator();
    /*Result type double*/
    resultDevision= (double)(resultNumeratorDevision) / (double)(resultDenominatorDevision);
    printf("Resault division fraction: %d / %d = %0.2lf\n",resultNumeratorDevision, resultDenominatorDevision, resultDevision);
}

/*Display Fraction*/
void calculatorFraction::displayFraction(){
    for (uint8_t i = 0; i < database.size(); i++)
    {
        printf("Fraction %d: %d / %d\n", i+1, database[i].getNumerator(), database[i].getDenominator());
    }
}

int main(int argc, char const *argv[])
{
    calculatorFraction cf;
    return 0;
}
