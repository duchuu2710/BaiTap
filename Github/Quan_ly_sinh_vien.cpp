#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stdint.h>
#include <conio.h>


using namespace std;

class SinhVien {
    public:
        SinhVien();
        uint8_t ID;
        char TEN[20];
        char GIOI_TINH[4];
        uint8_t TUOI;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        double DIEM_TRUNG_BINH;
        char HOC_LUC[11];    
};

typedef SinhVien SV;


SinhVien::SinhVien () {
    static uint8_t id = 1;
    SinhVien::ID = id;
    id++;
}

class Menu {
    public:
        Menu();
        
        void ThemSinhVien();
        void CapNhatThongTin(int id);
        void XoaSinhVien(int id);
        void TimKiemSinhVien(char Ten_can_tim[30]);
        void SapXepSinhVienTheoGPA();
        void SapXepSinhVienTheoTen();
        void HienThiDanhSach();
};
vector<SinhVien> Database;

Menu::Menu(){
    int Key;  //Khoi tao phim nhan
    int id;
    menu:
    
    printf("\nMENU\n");
    printf("Nhan 1: Them Sinh Vien\n");
    printf("Nhan 2: Cap nhat thong tin sinh vien boi ID\n");
    printf("Nhan 3: Xoa Sinh vien boi ID\n");
    printf("Nhan 4: Tim kiem Sinh Vien theo ten\n");
    printf("Nhan 5: Sap xep sinh vien theo diem trung binh GPA\n");
    printf("Nhan 6: Sap xep sinh vien theo ten\n");
    printf("Nhan 7: Hien thi danh sach Sinh Vien\n");
    printf("Nhan 8: Ghi danh sach sinh vien vao file SinhVien.txt\n");
    printf("Nhan 0: Thoat khoi chuong trinh");

    printf("\nNhap chuong trinh ban muon: ");

    scanf("%d", &Key);
    switch (Key)
    {
    case 1://Them Sinh Vien
        ThemSinhVien();
        printf("Nhan 0 de quay lai menu");
        scanf("%d", &Key);
        goto menu;
        break;
    case 2://Cap nhat thong tin sinh vien boi ID
        if (Database.size()>0)
        {
            printf("Nhap ID: ");
            scanf("%d", &id);
            CapNhatThongTin(id);
            printf("Nhan 0 de quay lai menu");
            scanf("%d", &Key);
            goto menu;
        }
        else    
        {
            printf("Danh sach trong");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }
            break;
    case 3://Xoa Sinh vien boi ID
        if (Database.size()>0)
        {
            printf("Nhap ID can xoa: ");
            scanf("%d", &id);
            XoaSinhVien(id);
            printf("Da xoa thanh cong \n");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }
        else
        {
            printf("Danh sach trong\n");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }
        break;
    case 4://Tim kiem Sinh Vien theo ten
        
        if (Database.size()>0)
        {
            char Ten_can_tim[30];
            printf("Nhap ten can tim: ");
            scanf("%s", Ten_can_tim);
            TimKiemSinhVien(Ten_can_tim);
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }
        else{
            printf("Danh sach trong\n");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }
        break;
    case 5://Sap xep sinh vien theo diem trung binh GPA
        if (Database.size()>0)
        {
            printf("Sap xep sinh vien theo diem GPA");
            SapXepSinhVienTheoGPA();
            HienThiDanhSach();
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }else
        {
            printf("Danh sach trong\n");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }
        break;
    case 6://Sap xep sinh vien theo ten
        if (Database.size()>0)
        {
            SapXepSinhVienTheoTen();
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }else
        {
            printf("Danh sach trong\n");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
        }
        break;
    case 7://Hien thi danh sach Sinh Vien
    if (Database.size()>0)
    {
        printf("HIEN THI THONG TIN SINH VIEN\n");
        HienThiDanhSach();
        printf("Nhan 0 de quay lai menu ");
        scanf("%d", &Key);
        goto menu;
    }else
    {
        printf("Danh sach trong\n");
            printf("Nhan 0 de quay lai menu ");
            scanf("%d", &Key);
            goto menu;
    }
        break;
    case 0: 
        printf("Ban da thoat chuong trinh \n");
        getch();
        break;
    }
}
/*Ham tinh diem TB*/
void Diem_TB(SV &sv)
{
    sv.DIEM_TRUNG_BINH = (sv.DIEM_TOAN + sv.DIEM_LY + sv.DIEM_HOA) / 3;
}
/*Ham xep loai hoc luc*/
void Xep_Loai(SV &sv)
{
    if (sv.DIEM_TRUNG_BINH >= 8)
        strcpy(sv.HOC_LUC, "GIOI");
    else if (sv.DIEM_TRUNG_BINH < 8 && sv.DIEM_TRUNG_BINH >= 6.5)
        strcpy(sv.HOC_LUC,"KHA");
    else if (sv.DIEM_TRUNG_BINH < 6.5 && sv.DIEM_TRUNG_BINH >= 5)
        strcpy(sv.HOC_LUC,"TRUNG BINH");
    else
        strcpy(sv.HOC_LUC,"YEU");
}
/*Ham them sinh vien*/
void Menu::ThemSinhVien(){
    SinhVien sv;
    printf("Them sinh vien: \n");
    printf("Nhap ten sinh vien: ");
    scanf("%s", sv.TEN);

    printf("Gioitinh: ");
    scanf("%s", sv.GIOI_TINH);

    printf("Nhap diem toan: ");
    scanf("%lf", &sv.DIEM_TOAN);

    printf("Nhap diem ly: ");
    scanf("%lf", &sv.DIEM_LY);

    printf("Nhap diem hoa: ");
    scanf("%lf", &sv.DIEM_HOA);

    Diem_TB(sv);
    Xep_Loai(sv);

    Database.push_back(sv); 
}
/*Ham cap nhat thong tin sv theo ID*/
void Menu::CapNhatThongTin(int id)
{
    SinhVien sv;
    
    //printf("Nhap ID can cap nhat thong tin: ");
    for (uint8_t i = 0; i < Database.size(); i++)
    { 
        
        if (Database[i].ID == id)
        {
            
            printf("Nhap ten sinh vien: ");
            scanf("%d", Database[i].TEN);

            printf("Gioitinh: ");
            scanf("%s", Database[i].GIOI_TINH);

            printf("Nhap diem toan: ");
            scanf("%lf", &Database[i].DIEM_TOAN);

            printf("Nhap diem ly: ");
            scanf("%lf", &Database[i].DIEM_LY);

            printf("Nhap diem hoa: ");
            scanf("%lf", &Database[i].DIEM_HOA);

            

            Diem_TB(Database[i]);
            Xep_Loai(Database[i]);
        }
        else
            printf("Sinh vien co ID %d khong ton tai", id);
    }
}
/*Ham xoa sinh vien theo ID*/
void Menu::XoaSinhVien(int id){
     
    //printf("Nhap ID can xoa: ");
    //scanf("%d", &id);
    for (int i=0;i<Database.size();i++){
        if (Database[i].ID == id){
            Database.erase(Database.begin() + i);
        }
    }
}
/*Ham tim kiem sinh vien theo ten */
void Menu::TimKiemSinhVien(char Ten_can_tim[]){
    char tenSV[30];
    uint8_t find = 0;
    uint8_t vitri = 0;
    for (uint8_t i = 0; i < Database.size(); i++)
    {
       
        strcpy(tenSV, Database[i].TEN);
        if(strstr(strupr(tenSV), strupr(Ten_can_tim))) {
            printf("Sinh Vien %d:\n", i+1);
            printf("Ten Sinh Vien: %s\n", Database[i].TEN);
            printf("Gioi Tinh: %s\n", Database[i].GIOI_TINH);

            printf("Diem Toan: %0.2f\n", Database[i].DIEM_TOAN);
            printf("Diem Ly: %0.2f\n", Database[i].DIEM_LY);
            printf("Diem Hoa: %0.2f\n", Database[i].DIEM_HOA);

            printf("Diem Trung Binh: %0.2f\n", Database[i].DIEM_TRUNG_BINH);

            printf("Hoc Luc: %s\n", Database[i].HOC_LUC);
            find =1;
        } 
  
    } 
    if (find ==0)
    {   
        printf("Sinh vien khong co trong danh sach\n");
    }
      
}
/*Ham xep loai sinh vien theo diem TB */
void Menu::SapXepSinhVienTheoGPA()
{
    SV temp;
    for (int i = 0; i < Database.size(); i++)
    {
        for (int j = i+1; j < Database.size(); j++)
        {
            if (Database[i].DIEM_TRUNG_BINH > Database[j].DIEM_TRUNG_BINH)
            {
                temp = Database[i];
                Database[i] = Database[j];
                Database[j] = temp;
            }  
        } 
    }
}
/*Ham sap xep sinh vien theo ten */
void Menu::SapXepSinhVienTheoTen(){
    SV temp;
    char tenSV1[30];
    char tenSV2[30];
    for(int i = 0;i < Database.size(); i++) {
        strcpy(tenSV1, Database[i].TEN);
        for(int j = i+1; j < Database.size(); j++) {
            strcpy(tenSV2, Database[j].TEN);
            if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
                temp = Database[i];
                Database[i] = Database[j];
                Database[j] = temp;
            }
        }
    }
}
/*Ham hien thi danh sach sinh vien*/
void Menu::HienThiDanhSach(){
    //system("clear");
    
    for (uint8_t i = 0; i < Database.size(); i++)
    {
        printf("Sinh Vien %d:\n", i+1);
        printf("Ten Sinh Vien: %s\n", Database[i].TEN);
        printf("Gioi Tinh: %s\n", Database[i].GIOI_TINH);

        printf("Diem Toan: %0.2f\n", Database[i].DIEM_TOAN);
        printf("Diem Ly: %0.2f\n", Database[i].DIEM_LY);
        printf("Diem Hoa: %0.2f\n", Database[i].DIEM_HOA);

        printf("Diem Trung Binh: %0.2f\n", Database[i].DIEM_TRUNG_BINH);

        printf("Hoc Luc: %s\n", Database[i].HOC_LUC);
       
    }
}



int main(int argc, char const *argv[])
{
    Menu mn;
    
}
