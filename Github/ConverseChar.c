// C program to reverse a string
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// typedef struct
// {
//     uint8_t size;
//     uint8_t *firstAdd;
// } typeArray;

//hàm đảo ngược
void reverse(char* begin, char* end)
{
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin = *end;
        *begin++;
        *end = temp;
        *end--;
    }
}
 
// hàm đảo ngược từ

void reverseWords(char* s)
{
    char* word_begin = s;
    char* temp = s;

    while (*temp != '\0' )
    {
        temp++;                             // temp cchạy từ từ đến khi temp = khoảng trống thì nó sẽ đảo ngược cái từ vừa quét đc
        if (*temp == ' ') {
            reverse(word_begin, temp - 1);   
            word_begin = temp + 1;
        }
        else if (*temp == '\0') {             // đối với từ cuối cùng sẽ có ký tự null
            reverse(word_begin, temp - 1);
        }
         
    }
    
 
    // sau khi đã đảo ngược cái chữ cái trong từ, ta bắt đầu đảo ngược từng từ
    reverse(s, temp - 1);
}
//hàm in hoa

int INHOA (char s[], int n) {
    int i;
    for(i = 0; i<n; i++) 
    {
        if(s[i] >= 'a' && s[i]<='z') 
        {
            s[i] = (char)(('A'-'a') + s[i] );
        }
        
    }
    
}
int INTHUONG(char s[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            //s[i] = (char)(s[i] + ('a' - 'A'));
            s[i] =  s[i] + 32;
        }   
        

    }   
}

int INHOA_DAU_CAU (char s[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        if ((s[i-1] == ' ' && s[i-2] == '.') || (i == 0 && s[i] == ' '))
        {
            //s[i] = (char)(('A'-'a') + s[i] );
            s[i] =  s[i] - 32;
        }
        else if (s[i] >= 'A' && s[i]<='Z')
            s[i] =  s[i];

        
    }
}


 

int main()
{
    char s[] = "A man, woman and child were killed, police said. An additional adult woman was shot and was undergoing treatment at a local hospital, officials said.";
    int n = sizeof(s);

    printf("Cau nguyen mau: %s\n\n", s);

    INHOA_DAU_CAU(s,n);
    printf("In hoa chu cai dau cau: %s\n\n", s);

    char* temp = s;
    reverseWords(s);
    printf("Dao nguoc tu: %s\n\n", s);

    INHOA(s,n);
    printf("In hoa toan bo cau: %s\n", s);

    INTHUONG(s,n);
    printf("In thuong toan bo cau: %s\n", s);

    

    return 0;
}