import * as readlineSync from 'readline-sync';
function Sum(a: number[], n: number): number{
    // dung de quy de tinh tich cac ptu trong n ma khong dung vong for 
    // giai thua thi bang n * f(N-1) // 5 * 5 -1 * 4 - 1 * 3 - 1 .....
    // tinh tich cac ptu trong mang se la a[n -1] * a[n -1 -1]
    if (a.length === 0) return 0;
    // neu do dai cua maNG A = 0 THI kq tra ve 0 
    return a[n - 1] * Sum(a, n -1);
}
let n: number = parseInt(readlineSync.question("Nhap so nguyen duong co trong mang a: "));
const a: number[] = []; //a[n]
for (let i = 0; i < n; i++) {
    // duyet qua vong for de nhap cac so nguyen duong co trong mang
    a.push(parseInt(readlineSync.question(`Nhap so nguyen duong thu ${i + 1 }`)));
}
// ko dung for dung de quy tinh tch cac ptu trong mang function (a: number[]): number
const Tich: number = Sum(a, n);
console.log(`>>> Tich la ${Tich}`);