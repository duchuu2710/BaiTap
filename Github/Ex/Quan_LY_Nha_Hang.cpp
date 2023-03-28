#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;


typedef struct 
{
    //uint8_t STT;
    uint8_t ID;
    char TEN_MON[50];
    uint32_t GIA;
}Thuc_Don;

typedef struct 
{
    char TEN_MON[30];
    Thuc_Don THONG_TIN_MON;
    uint8_t SO_LUONG;
}SO_LUONG_MON;

typedef struct 
{
    uint8_t SO_BAN;
    uint8_t TRANG_THAI;
    vector <SO_LUONG_MON> data_MON;
}THONG_TIN_BAN;

static vector <Thuc_Don> Database_thuc_don;
static vector <THONG_TIN_BAN> Database_Thong_Tin_Ban;

class Display {
    public:
        Display();
};


class Quan_Ly { 
    private:
    public:
        Quan_Ly();
        
        void Them_Mon();
        void Sua_Mon(int id);
        void Xoa_Mon(int id);
        void Hien_Thi_Danh_Sach_Mon();
};

// Quan_Ly::Quan_Ly () {
//     static uint8_t id = 1;
//     Quan_Ly::ID = id;
//     id++;
// }
void pressAnyKey() {
    printf( "\n\nBam phim bat ky de tiep tuc...\n");
    getch();
    system("cls");
}
Quan_Ly::Quan_Ly(){
    int id;
    Quanly:
    system("cls");
    printf("QUAN LY\n");
    printf("Nhan 1: Them mon\n");
    printf("Nhan 2: Sua mon\n");
    printf("Nhan 3: Xoa mon\n");
    printf("Nhan 4: Hien thi thuc don\n");
    printf("Nhan 5: Quay lai Home\n");
    printf("Chon che do: ");

    int phim;
    scanf("%d", &phim);
    switch (phim)
    {
    case 1:
        Themmon:
        Them_Mon();
        printf("Nhan 1: Tiep Tuc Them Mon\n");
        printf("Nhan 2: Quay Lai Trang Quan Ly\n");    
        scanf("%d", &phim);        
        switch (phim)
        {
            case 1:
                goto Themmon;
                break;
            case 2:
                goto Quanly;
                break;                  
            default:
                break;
        }     
        break;
        
    case 2:
        if (Database_thuc_don.size()>0)
        {
            printf("Nhap ID: ");
            scanf("%d", &id);
            Sua_Mon(id);
            printf("Nhan 0 de quay lai menu");
            scanf("%d", &phim);
            goto Quanly;
        }
        else    
        {
            printf("Danh sach trong");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &phim);
            goto Quanly;
        }
        break;
    case 3:
        if (Database_thuc_don.size()>0)
        {
            printf("Nhap ID: ");
            scanf("%d", &id);
            Xoa_Mon(id);
            Hien_Thi_Danh_Sach_Mon();
            printf("Nhan 0 de quay lai menu");
            scanf("%d", &phim);
            goto Quanly;
        }
        else    
        {
            printf("Danh sach trong");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &phim);
            goto Quanly;
        }
        break;
    case 4:
            if (Database_thuc_don.size()>0)
            {
                Hien_Thi_Danh_Sach_Mon();
                pressAnyKey();
                goto Quanly;      
            }
            else    
            {
                printf("Danh sach trong");
                printf("Nhan 0 de quay lai menu ");
                scanf("%d", &phim);
                goto Quanly;
            }
        break;
    case 5:
        Display();
    default:
        printf("\n\nInvalid. Please choose again.\n\n");
        goto Quanly;
        break;
    }
}

Display::Display(){
    Home:
    //system("cls");
    printf("HOME\n");
    printf("Nhan 1: Quan ly\n");
    printf("Nhan 2: Nhan vien\n");
    printf("Nhan 3: Thoat chuong trinh\n");
    printf("Chon che do: ");
    int Key = 0;

    scanf("%d", &Key);
    switch (Key)
    {
        case 1:
            Quan_Ly(); 
            //goto Home;
            break;
        case 2:
            //Nhan_Vien();
           // goto Home;
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid. Please choose again.\n");
            goto Home;
            break;
    }
}

// bool Check(Thuc_Don g){
//     if (g.GIA > 1000)
//         return true;
//     else
//     {
//         printf("Nhap gia khong hop le, vui long nhap lai\n");
//         return false;
//     }
    
// }

void Nhap_Gia(Thuc_Don *TD){
    printf("Nhap gia: ");
    scanf("%i", &TD->GIA);
}

void Nhap_Mon(Thuc_Don *TD){
    
    printf("Ten mon: ");
    scanf("%s", &TD->TEN_MON);
    
}

void Quan_Ly::Them_Mon() {
    Thuc_Don TD;
    static uint8_t id = 100;
    TD.ID = id;
    id++;
    //TD.STT = Database_thuc_don.size() + 1;
    Nhap_Mon(&TD);
    Nhap_Gia(&TD);
    Database_thuc_don.push_back(TD); //Them mon an vao danh sach bang vector

}
void Quan_Ly::Sua_Mon(int id){
    Thuc_Don td;
    uint8_t find_ID = 0;
    for (uint8_t i = 0; i < Database_thuc_don.size(); i++)
    {
        if (Database_thuc_don[i].ID == id)
        {
            //td.STT = i+1;
            Nhap_Mon(&td);
            Nhap_Gia(&td);
            td.ID = id;
            Database_thuc_don.erase(Database_thuc_don.begin() + i);
            Database_thuc_don.insert(Database_thuc_don.begin() + i, td);
            find_ID = 1;
        }
        
        
    }
    if (find_ID == 0)
    {
        printf("Mon an co ID %d khong ton tai\n", id);
    }
}

void Quan_Ly::Xoa_Mon(int id){
    Thuc_Don TD;
    uint8_t find_ID;
    for (uint8_t i = 0; i < Database_thuc_don.size(); i++)
    {
        if (Database_thuc_don[i].ID == id)
        {
            Database_thuc_don.erase(Database_thuc_don.begin() + i);
            find_ID = 1;
        }
    }
    if (find_ID == 0)
    {
        printf("Mon an co ID %d khong ton tai\n", id);
    }
}

void Quan_Ly::Hien_Thi_Danh_Sach_Mon(){
    system("cls");
    printf("\nThuc Don: \n");
    printf("STT\tID\tTEN MON\t\tGIA\n");
    for (uint8_t i = 0; i < Database_thuc_don.size(); i++)
    {
        printf("%d\t", i+1);
        //printf("%d\t", Database_thuc_don[i].STT);
        printf("%d\t", Database_thuc_don[i].ID);
        printf("%s\t\t", Database_thuc_don[i].TEN_MON);
        printf("%i\n", Database_thuc_don[i].GIA);

    }
}


class Nhan_Vien {
    public:
        Nhan_Vien (vector <Thuc_Don> Database);
        void Goi_Mon();
        void Tinh_Tien();

};

Nhan_Vien::Nhan_Vien(vector <Thuc_Don> Database){
    printf("Day la trang nhan vien\n");
    for (int i = 0; i < Database.size(); i++)
    {
        Database_thuc_don.push_back(Database[i]);
    }
    
}

void Nhan_Vien::Goi_Mon(){
    printf("\nThuc Don: \n");
    printf("STT\tID\tTEN MON\t\tGIA\n");
    for (uint8_t i = 0; i < Database_thuc_don.size(); i++)
    {
        //printf("%d\t", Database_thuc_don[i].STT);
        printf("%d\t", Database_thuc_don[i].ID);
        printf("%s\t\t", Database_thuc_don[i].TEN_MON);
        printf("%i\n", Database_thuc_don[i].GIA);

    }
}




int main(int argc, char const *argv[])
{
    // Thuc_Don test;

    // printf("Dia chi: %p\n", &test);
    //Display dp;

    //Quan_Ly ql;

   // ql.Them_Mon();
 
    //ql.Hien_Thi_Danh_Sach_Mon();
    // Nhan_Vien nv(ql.Database_thuc_don);
    
    // nv.Goi_Mon();
    Display dp;

    return 0;
}
