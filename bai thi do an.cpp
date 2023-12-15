#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SOSV_TOIDA 100 //so sinh toi da 
struct SinhVien{
    char masv[10], gioitinh[10];
    int tuoi;
    char hoten[40];
    float dqt, dt, dtb; 
    char xeploai[20];
    char ngaysinh[10];
} sv[SOSV_TOIDA];
int sosv; //So sinh vien thuc te hien tai  
int menu(void);
int xeploai();
int themsv(int);
int nhapdssv(int); 
int timkiemtheomsv();
void indanhsachsv(int);
int xoasinhvien(int n); //xoa tai vi tri n
int themsinhvien(); //
int main(){
    int chon, n;
    do{
        chon = menu(); 
        if(chon ==0) break; 
        switch(chon){
            case 1: 
                printf("Nhap danh sach sinh vien \n");
                printf("So luong sinh vien can nhap: ");
                scanf("%d", &n);
                sosv = nhapdssv(n);
                break;
            case 2:
            	themsinhvien();
                break; 
            case 3:
                indanhsachsv(sosv);
                break;
            case 4:
                break;
            case 5:{
                int vitri = timkiemtheomsv(); 
                int ketqua = xoasinhvien(vitri);
                if(ketqua ==0) 
                    printf("khong co sinh vien duoc xoa \n");
                else
                    indanhsachsv(sosv);   
                break;
            }
            case 6:{
                int vitri = timkiemtheomsv();
                if (vitri >=0){
                    printf("sinh vien : %s \n", sv[vitri].hoten );
                    printf("ÐQT = %.1f\n diem thi = %.1f\n diem TB = %.1f\n", sv[vitri].dqt, sv[vitri].dt, sv[vitri].dtb);
                }else{
                    printf("khong tim thay !");
                }
                break;
            }
            default:
                printf("chi duoc chon tu 0-5\n");
        }
    }while(1);
    return 0; 
}
//Chi ti?t các hàm
int menu(){
    int chon;
    printf("+========================= MENU ===========================\n");
    printf("|            1. nhap danh sach sinh vien                  |\n");
    printf("|            2. them 1 sinh vien                          |\n");
    printf("|            3. in danh sach sinh vien                    |\n");
    printf("|            4. tinh diem da xep loai                     |\n");
    printf("|            5. xoa 1 sinh vien                           |\n");
    printf("|            6. tim kiem sinh vien (theo msv)             |\n");
    printf("|            0. thoat khoi chuong tirnh                   |\n");
    printf("|_________________________________________________________|\n");
    printf("   moi ban chon : ");
    scanf("%d", &chon);
    return chon;
}
//ham nhap moi danh sach sinh vien, tra laij so sinh da nhap thanh cong 
int nhapdssv(int n){
    int i;
    for(i =0; i<n; i++){
        printf("nhap ma sinh vien thu %d: \n",i+1);
        fflush(stdin);
        printf("nhap ma so: ");
        scanf("%s", &sv[i].masv); 
        fflush(stdin); 
        printf("nhap ho va ten: ");
        fgets(sv[i].hoten, 40, stdin);
        sv[i].hoten[strcspn(sv[i].hoten, "\n")] = '\0';
        printf("nhap gioi tinh: ");
        scanf("%s", &sv[i].gioitinh);
        printf("nhap ngay thang nam sinh: ");
        scanf("%s", &sv[i].ngaysinh);
        printf("Nhap diem qua trinh: ");
        scanf("%f", &sv[i].dqt);
        printf("nhap diem thi: ");
        scanf("%f", &sv[i].dt);
		sv[i].dtb= sv[i].dqt*0.4+sv[i].dt*0.6; 
    }
    return n; //tra lai so sinh vien da nhap 
}
int timkiemtheomsv(){
    char masv[10]; 
    int i, n = sosv; 
    fflush(stdin);
    printf("Nhap ma sinh vien can tim: ");
    scanf("%s", masv); 
    for(i=0; i<n; i++){
        if(strcmp(sv[i].masv, masv) == 0)
            return i; //tim co, tra lai vi tri dau tien tim thay 
    }
    return -1;  //tim khong co, tra lai -1
}
void indanhsachsv(int n){
    //xuat len mang hinh
    for (int i=0; i<n; i++){
		if(sv[i].dtb>=9.0){
			printf("xuat sac\n");
			strcpy(sv[i].xeploai, "xuat sac");
		}
		else if(sv[i].dtb>=8.0){
			printf("gioi\n");
			strcpy(sv[i].xeploai, "gioi");
		}
		else if(sv[i].dtb>=7.0){
			printf("kha\n");
			strcpy(sv[i].xeploai, "kha");
		}
		else if(sv[i].dtb>=5.0){
			printf("trung binh\n");
			strcpy(sv[i].xeploai, "trung binh");
		}
		else{
	 	    printf("yeu");	
	 	    strcpy(sv[i].xeploai, "yeu");
		}
	}
    printf("========================= DANH SACH SINH VIEN ==========================\n");
    printf("+-----------------------------------------------------------------------+\n");
    printf("|%5s|%10s|%10s|%30s|%10s|%5s|%5s|%5s|%10s| \n", "STT","MASV","NS","HOTEN", "GT", "DQT", "DT", "DTB", "XEPLOAI");
    printf("+-----------------------------------------------------------------------+\n");
    for(int i=0; i< n; i++){
        printf("|%5d|%10s|%10s|%30s|%10s|%5.1f|%5.1f|%5.1f|%10s| \n",
                    i+1, sv[i].masv, sv[i].ngaysinh, sv[i].hoten, sv[i].gioitinh, sv[i].dqt, sv[i].dt, sv[i].dtb, sv[i].xeploai);
    }
    printf("+-----------------------------------------------------------------------+\n");
}

int xoasinhvien(int n){
    if (n < 0) return 0; //khong co de xoa
    int i;
    int slsv = sosv; 
    for(i=n; i< slsv-1; i++){
        sv[i] = sv[i+1];
    }
    sosv = sosv - 1; 
    return 0; //xoa thanh cong
}
int themsinhvien() {
    printf("Nhap thong tin sinh vien\n");
    printf("Ma so sinh vien: ");
    fflush(stdin);
    scanf("%s", sv[sosv].masv);

    fflush(stdin);
    printf("Ho va ten: ");
    fgets(sv[sosv].hoten, 40, stdin);
    sv[sosv].hoten[strcspn(sv[sosv].hoten, "\n")] = '\0';

    printf("Gioi tinh: ");
    scanf("%s", sv[sosv].gioitinh);

    printf("Ngay thang nam sinh: ");
    scanf("%s", sv[sosv].ngaysinh);

    printf("Diem qua trinh: ");
    scanf("%f", &sv[sosv].dqt);

    printf("Diem thi: ");
    scanf("%f", &sv[sosv].dt);

    sv[sosv].dtb = sv[sosv].dqt * 0.4 + sv[sosv].dt * 0.6;

    sosv++;

    printf("Sinh vien da duoc them vao danh sach.\n");

    return 1; // tra ve 1 de biet them thanh cong
}
