#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stdint.h>
#include <conio.h>


using namespace std;

//enum Bool { False, True };
//typedef uint8_t Bool;

#define NHAP_DIEM(mon_hoc, diem)                \
    do                                          \
    {                                           \
        printf("Nhap diem %s: ", mon_hoc);      \
        scanf("%lf", &sv.diem);                 \
    } while (Check(sv.diem, mon_hoc) != 1);     \

#define NHAP_GIOITINH(GioiTinh)\
    do                                              \
    {                                               \
        printf("Nhap gioi tinh: ");                 \
        scanf("%s", sv.GioiTinh);                   \
    } while (Check_GioiTinh(sv.GioiTinh) != 1);
    
#define NHAP_TEN(Ten)                           \
    printf("Nhap ten: ");                       \
    scanf("%s", sv.Ten);

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
    private:
        uint8_t Check (double diem, char *ten);
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
/*Menu*/
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
            printf("Sap xep sinh vien theo diem GPA\n");
            SapXepSinhVienTheoGPA();
            HienThiDanhSach();
            printf("Nhan 0 de quay lai menu\n ");
            scanf("%d", &Key);
            goto menu;
        }else
        {
            printf("Danh sach trong\n");
            printf("Nhan 0 de quay lai menu\n ");
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
/*Ham check diem*/
uint8_t Menu::Check(double DIEM, char *ten){
    if (DIEM <= 10) 
    {
        return 1;
    }else
    {
        printf("Diem %s khong hop le, vui long nhap lai\n", ten);
        return 0;
    }
    
}
/*Ham check gioi tinh*/
uint8_t Check_GioiTinh(char *GioiTinh)
{
    char str[]="nam";
    char str2[]="nu";
    if(strstr(strupr(GioiTinh), strupr(str)) || strstr(strupr(GioiTinh), strupr(str2)))
    {
        return 1;
    }
    else
    {
        printf("Gioi tinh %s khong hop le, vui long nhap lai\n", GioiTinh);
        return 0;
        
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
    
    NHAP_TEN(TEN);
    NHAP_GIOITINH(GIOI_TINH);
 
    NHAP_DIEM("Toan", DIEM_TOAN);
    NHAP_DIEM("Ly", DIEM_LY);
    NHAP_DIEM("Hoa", DIEM_HOA);

    Diem_TB(sv);
    Xep_Loai(sv);

    Database.push_back(sv); 
}
/*Ham cap nhat thong tin sv theo ID*/
void Menu::CapNhatThongTin(int id)
{
    SinhVien sv;
    uint8_t Find = 0;

    for (uint8_t i = 0; i < Database.size(); i++)
    { 
        
        if (Database[i].ID == id)
        {
            NHAP_TEN(TEN);
            NHAP_GIOITINH(GIOI_TINH);
 
            NHAP_DIEM("Toan", DIEM_TOAN);
            NHAP_DIEM("Ly", DIEM_LY);
            NHAP_DIEM("Hoa", DIEM_HOA);
            
            Diem_TB(sv);
            Xep_Loai(sv);

            //Database.push_back(Database[i]);
            
            
            Database.erase(Database.begin() + i);
            Database.insert(Database.begin() + i, sv);

            
            Database[i].ID = i+1;
            //Database.push_back(sv); 
            Find = 1;
            break;
        }
        
    }   
    if (Find == 0)
    {
        printf("Sinh vien co ID %d khong ton tai\n", id);
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
            // printf("Sinh Vien %d:\n", i+1);
            // printf("Ten Sinh Vien: %s\n", Database[i].TEN);
            // printf("Gioi Tinh: %s\n", Database[i].GIOI_TINH);

            // printf("Diem Toan: %0.2f\n", Database[i].DIEM_TOAN);
            // printf("Diem Ly: %0.2f\n", Database[i].DIEM_LY);
            // printf("Diem Hoa: %0.2f\n", Database[i].DIEM_HOA);

            // printf("Diem Trung Binh: %0.2f\n", Database[i].DIEM_TRUNG_BINH);

            // printf("Hoc Luc: %s\n", Database[i].HOC_LUC);
            printf("ID\tTen\tGioi Tinh\tDiem Toan\tDiem Ly\t\tDiem Hoa\tDiem Trung Binh\t\tHoc Luc\n");
            printf("%d\t",Database[i].ID);
            //printf("%d\t", i+1);
            printf("%s\t", Database[i].TEN);
            printf("%s\t\t", Database[i].GIOI_TINH);

            printf("%0.2f\t\t", Database[i].DIEM_TOAN);
            printf("%0.2f\t\t", Database[i].DIEM_LY);
            printf("%0.2f\t\t", Database[i].DIEM_HOA);

            printf("%0.2f\t\t\t", Database[i].DIEM_TRUNG_BINH);

            printf("%s\n", Database[i].HOC_LUC);
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
    //HienThiDanhSach();
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
    HienThiDanhSach();
}
/*Ham hien thi danh sach sinh vien*/
/*Ham dung hien thi cho cac ham khac*/
void Menu::HienThiDanhSach(){
    //system("clear");
    printf("ID\tTen\tGioi Tinh\tDiem Toan\tDiem Ly\t\tDiem Hoa\tDiem Trung Binh\t\tHoc Luc\n");
    for (uint8_t i = 0; i < Database.size(); i++)
    {
       
        printf("%d\t",Database[i].ID);
        //printf("%d\t", i+1);
        printf("%s\t", Database[i].TEN);
        printf("%s\t\t", Database[i].GIOI_TINH);

        printf("%0.2f\t\t", Database[i].DIEM_TOAN);
        printf("%0.2f\t\t", Database[i].DIEM_LY);
        printf("%0.2f\t\t", Database[i].DIEM_HOA);

        printf("%0.2f\t\t\t", Database[i].DIEM_TRUNG_BINH);

        printf("%s\n", Database[i].HOC_LUC);
       
    }
}


int main(int argc, char const *argv[])
{
    Menu mn;
    
}
