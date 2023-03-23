#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <cstring>
#include <stdlib.h>
using namespace std;

class Dienthoai {
    private:
        uint8_t id;
        char tenDienThoai[30];
        char hangSanXuat[20];
        double gia;
    public:
        Dienthoai(char ten[], char hang[], double gia);
        uint8_t getId();
        char *getTenDienThoai();
        char *getHangSanXuat();
        double getGia();
        void setTenDienThoai(char ten[]);
        void setHangSanXuat(char hang[]);
        void setGia(double gia);
};

Dienthoai::Dienthoai(char ten[], char hang[], double input_gia){
    static uint8_t ID = 100;
    Dienthoai::id = ID;
    ID++;
    strcpy(tenDienThoai, ten);
    strcpy(hangSanXuat, hang);
    gia = input_gia;
}

uint8_t Dienthoai::getId()
{
    return Dienthoai::id;
}
char *Dienthoai::getTenDienThoai()
{
    return tenDienThoai;
}

char* Dienthoai::getHangSanXuat()
{
    return hangSanXuat;
}

double Dienthoai::getGia()
{
    return gia;
}

void Dienthoai::setTenDienThoai( char ten[])
{
    strcpy(tenDienThoai, ten);
}

void Dienthoai::setHangSanXuat( char hang[])
{
    strcpy(hangSanXuat, hang);
}

void Dienthoai::setGia(double input_gia)
{
    gia = input_gia;
}

class QuanLyDienThoai{
    private:
        vector<Dienthoai>danhSachDienThoai;
    public:
    QuanLyDienThoai();
    void themDienThoai();
    void suaDienThoai(uint8_t id);
    void xoaDienThoai(uint8_t id);
    void hienThiDanhSachDienThoai();
};

QuanLyDienThoai::QuanLyDienThoai(){
    HOME:
    //system("cls");
    printf("Nhan 1 Them dien thoai\n");
    printf("Nhan 2 Xoa dien thoai\n");
    printf("Nhan 3 Sua thong tin dien thoai\n");
    printf("Nhan 4 Hien thi danh sach dien thoai\n");
    printf("Nhan 5 de thoat chuong trinh\n");
    printf("Chon che do: ");
    int key;
    scanf("%d", &key);
    switch (key)
    {
    case 1:
        ThemDienThoai:
        themDienThoai();
        printf("1. Tiep tuc them dien thoai\n");
        printf("2. Quay lai HOME\n");
        printf("Chon che do: ");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            goto ThemDienThoai;
            break;
        case 2:
            goto HOME;
            break;
        }
        break;
    case 2:
        if (danhSachDienThoai.size() > 0){
            uint8_t input_id;
            printf("Nhap id can xoa: ");
            scanf("%d", &input_id);
            xoaDienThoai(input_id);
            goto HOME;
        }
        else 
        {
            printf("Danh sach trong \n");
            printf("Nhan phim 1 de quay lai... \n");
            scanf("%d", &key);
            goto HOME;
        }
        break;
    case 3:
        SuaThem:
        hienThiDanhSachDienThoai();
        if (danhSachDienThoai.size() > 0){
            uint8_t input_id;
            printf("Nhap id can sua: ");
            scanf("%d", &input_id);
            suaDienThoai(input_id);
            printf("Nhan 1 de sua dien thoai khac\n ");
            printf("Nhan 2 de quay lai home\n ");
            scanf("%d", &key);
            switch (key)
            {
            case 1:
                goto SuaThem;
                break;
            case 2:
                goto HOME;
                break;
            }
        }
        else 
        {
            printf("Danh sach trong \n");
            printf("Nhan phim 1 de quay lai... \n");
            scanf("%d", &key);
            goto HOME;
        }
        break;
    case 4:
        if (danhSachDienThoai.size() > 0){
            hienThiDanhSachDienThoai();
            printf("Nhan phim 1 de quay lai... \n");
            goto HOME;
        }
        else 
        {
            printf("Danh sach trong \n");
            printf("Nhan phim 1 de quay lai... \n");
            scanf("%d", &key);
            goto HOME;
        }
        break;
    case 5:
        exit(0);
        break;
    }
}
void QuanLyDienThoai::hienThiDanhSachDienThoai(){
    printf("ID\tHang\t\tTen\t\tGia\n");
    for (uint8_t i = 0; i < danhSachDienThoai.size(); i++)
    {
        
        printf("%d\t%s\t\t%s\t\t%d\n", danhSachDienThoai[i].getId(), danhSachDienThoai[i].getHangSanXuat(), danhSachDienThoai[i].getTenDienThoai(), danhSachDienThoai[i].getGia());
    }
    
}

void QuanLyDienThoai::themDienThoai(){
    char ten[30];
    char hang[20];
    double gia;
    int key;

    printf("Nhap ten dien thoai: ");
    scanf("%s", ten);
    printf("Nhap hang dien thoai: ");
    scanf("%s", hang);
    printf("Nhap gia dien thoai: ");
    scanf("%d", &gia);
    Dienthoai new_dienthoai(ten, hang, gia);
    danhSachDienThoai.push_back(new_dienthoai);

}

void QuanLyDienThoai::xoaDienThoai(uint8_t input_id){
    int check = 0;

    for (uint8_t i = 0; i < danhSachDienThoai.size(); i++)
    {
        if (input_id == danhSachDienThoai[i].getId())
        {
            danhSachDienThoai.erase(danhSachDienThoai.begin()+ i);
            check = 1;
        } 
    }
    
    if (check == 0)
    {
        printf("Dien thoai co %d khong ton tai\n", input_id);
    }
    printf("Danh sach sau khi xoa:\n");
    hienThiDanhSachDienThoai();
}


void QuanLyDienThoai::suaDienThoai(uint8_t input_id){

    int check = 0;
    //hienThiDanhSachDienThoai();
    for (uint8_t i = 0; i < danhSachDienThoai.size(); i++)
    {
        if (input_id == danhSachDienThoai[i].getId())
        {
            Suathem:
            printf("Nhan 1 Sua ten dien thoai\n");
            printf("Nhan 2 Sua ten hang dien thoai\n");
            printf("Nhan 3 Sua gia dien thoai\n");
            printf("Nhan 4 de ket thuc\n");
            printf("Chon che do: ");
            
            int key;
            scanf("%d", &key);

            switch (key)
            {
            case 1:
                char input_ten[30];
                printf("Nhap ten moi: ");
                scanf("%s", input_ten);
                danhSachDienThoai[i].setTenDienThoai(input_ten);
                hienThiDanhSachDienThoai();
                printf("Nhan 1 de sua gia hoac hang san xuat \n");
                printf("Nhan 2 ket thuc\n");
                printf("Chon che do: ");
                scanf("%d", &key);
                switch (key)
                {
                case 1:
                    goto Suathem;
                    break;
                }
                break;
            case 2:
                    char input_hang[30];
                    printf("Nhap hang san xuat moi: ");
                    scanf("%s", input_hang);
                    danhSachDienThoai[i].setHangSanXuat(input_hang);
                printf("Nhan 1 de sua gia hoac ten \n");
                //printf("Nhan 2 de sua mot dien thoai khac\n");
                printf("Nhan 2 de ketthuc\n");
                printf("Chon che do");
                scanf("%d", &key);
                switch (key)
                {
                case 1:
                    goto Suathem;
                    break;
                }
                break;
            case 3:
                    double input_gia;
                    printf("Nhap gia: ");
                    scanf("%d", &input_gia);
                    danhSachDienThoai[i].setGia(input_gia);
                
                printf("Nhan 1 de sua hang san xuat hoac ten \n");
                //printf("Nhan 2 de sua mot dien thoai khac\n");
                printf("Nhan 2 ket thuc\n");
                printf("Chon che do: ");
                scanf("%d", &key);
                switch (key)
                {
                case 1:
                    goto Suathem;
                    break;
                }
                break;
            }

            check = 1;
        }
        
    }
    if(check == 0) {
        printf("Khong co dien thoai co so id %d nay", input_id);
    }

    
}

class SmartPhone:public Dienthoai {
    private:
        uint16_t dungLuongPin;
        uint8_t dungLuongBoNho;
    public:
        SmartPhone(char ten[], char hang[], double gia, uint16_t pin, uint8_t bo_nho);
        uint16_t getDungLuongPin();
        uint8_t getDungLuongBoNho();
        void setDungLuongPin(uint16_t dung_luong);
        void setDungLuongBoNho(uint8_t dung_luong_bo_nho);

};






int main(int argc, char const *argv[])
{
    QuanLyDienThoai ql;
    return 0;
}
