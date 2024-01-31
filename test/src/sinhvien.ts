import * as readlineSync from 'readline-sync';
class Sinhvien {
    hoten: string;
    diem1: number;
    diem2: number;
    diem3: number;
    constructor(hoten: string, diem1: number, diem2: number, diem3: number){
        this.hoten = hoten;
        this.diem1 = diem1;
        this.diem2 = diem2;
        this.diem3 = diem3;
    }

    public diemTB() {
        return this.diemTong() / 3;
    }

    private diemTong() {
        return this.diem1 + this.diem2 + this.diem3;
    }
}
// khai bao co n sinh vien
let n: number = parseInt(readlineSync.question("Nhap so sinh vien co trong danh sach: "));
let DSSinhvien: Sinhvien[] =[];
let SortSV: Sinhvien[] = [];
for (let i = 0; i < n; i++){
    const hoten: string = readlineSync.question(`Nhap ten sinh vien thu ${i + 1}: `);
    const diem1: number = parseFloat(readlineSync.question(`Nhap so diem mon 1 cua sinh vien ${i + 1}: `));
    const diem2: number = parseFloat(readlineSync.question(`Nhap so diem mon 2 cua sinh vien ${i + 1}: `));
    const diem3: number = parseFloat(readlineSync.question(`Nhap so diem mon 3 cua sinh vien ${i + 1}: `));
    const sinhVien: Sinhvien = new Sinhvien(hoten, diem1, diem2, diem3);
    DSSinhvien.push(sinhVien);
}
for (let i = 0; i < DSSinhvien.length; i++){
    const sinhVien: Sinhvien = DSSinhvien[i];
    const diemtrungbinh: number = sinhVien.diemTB();
    // dung toFixed(2) de lam tron den chu so thap phan thu 2 
    console.log(`  - Điểm trung bình: ${diemtrungbinh.toFixed(2)}`);
}

// sort truoc khong xet th diemtb bang nhau roi xet toi th diemtb bang nhau de sort lai
// Gọi hàm sortdiem
// Gọi hàm sortdiem và gán kết quả vào mảng SortSV
SortSV = Sortdiem(DSSinhvien);

// In thông tin và điểm trung bình của từng sinh viên
for (let i = 0; i < SortSV.length; i++){
    console.log(`  - Rank cua sinh vien ${i + 1}:`);
    console.log(`    + Họ tên: ${SortSV[i].hoten}`);
    console.log(`    + Điểm trung bình: ${SortSV[i].diemTB().toFixed(2)}`);
    console.log("----------------------------------------");
}

// Hàm sắp xếp điểm
function Sortdiem(DSSinhvien: Sinhvien[]): Sinhvien[] { 
    let SortSV: Sinhvien[] = [...DSSinhvien];   
    for (let i = 0; i < SortSV.length; i++) {
        let min_pos = i;
        for (let j = i + 1; j < SortSV.length; j++) {
            if (SortSV[j].diemTB() < SortSV[min_pos].diemTB()) {
                min_pos = j;
            }
        }
        // Hoán đổi vị trí
        let temp = SortSV[i];
        SortSV[i] = SortSV[min_pos];
        SortSV[min_pos] = temp;
    }
    
    for (let i = 0; i < SortSV.length; i++) {
        for (let j = i + 1; j < SortSV.length; j++) {
            if (SortSV[i].diemTB() === SortSV[j].diemTB()) {
                // xet th neu 2 diemtb bang nhau
                // neu diem1[i] > diem1[j] thi giu nguyen i 
                // nguoc lai thi doi j len cho i 
                if (SortSV[i].diem1 > SortSV[j].diem1) {
                    let temp = SortSV[i];
                    SortSV[i] = SortSV[j];
                    SortSV[j] = temp;
                } 
                // case diem1 bang nhau ma diem2 lon hon thi swap i vs j 
                else if (SortSV[i].diem1 === SortSV[j].diem1 && SortSV[i].diem2 > SortSV[j].diem2) {
                    let temp = SortSV[i];
                    SortSV[i] = SortSV[j];
                    SortSV[j] = temp;
                }
                else if (SortSV[i].diem1 < SortSV[j].diem1){
                    let temp = SortSV[i];
                    SortSV[i] = SortSV[j];
                    SortSV[j] = temp;
                }
            }
        }
    }
    
    return SortSV;
}
for (let i = 0; i < SortSV.length; i++){
    console.log(SortSV[i])
}



