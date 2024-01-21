import * as readlineSync from 'readline-sync';
// mang a co m dong n cot 
// mang b co p dong k cot 
let m: number = parseInt(readlineSync.question("Nhap so dong cua mang a:"));
let n: number = parseInt(readlineSync.question("Nhap so cot cua mang a: "));
let p: number = parseInt(readlineSync.question("Nhap so dong cua mang b:"));
let k: number = parseInt(readlineSync.question("Nhap so cot cua mang b: "));
const a: number[][] = []; //a[m][n]
const b: number[][] = []; // b[p][k]
const c: number[][] = []; // c[m][k]
//arr.push(parseInt(readlineSync.question(Nhap phan tu thu ${i + 1}:)))
for (let i = 0; i < m; i++) {
    for (let j = 0; j < n;j++){
        a.push(parseInt(readlineSync.question(`Nhap phan tu thu co trong dong thu ${i + 1}`)));
    }
}
for (let i = 0; i < p; i++) {
    for (let j = 0; j < k;j++){
        b.push(parseInt(readlineSync.question(`Nhap phan tu thu co trong dong thu ${i + 1}`)));
    }
}
// c[i][j] = a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0]
for (let i = 0; i < m; i++){
    for (let j = 0; j < k; j++){
        // tich hai ma tran thi ma tran tich co dong a cot b
        // duyet vong for qua n lan de tinh c11 c12...
        // tich cong don de tim c11 c12 ... nen se duyet for qua n - 1 lan
        for (let k = 0; k < n; k++){
            c[i][j] += a[i][k]*b[k][j];
        }
    }
}
let sum: number = 0;
for (let i = 0; i < m; i++){
    for (let j = 0; j < k; j++){
        sum += c[i][j];
    }
}
