// dem so nguyen to trong mang gom n so nguyen duong 
function isPrime(num){
    if (num < 2){
        return false;
    }
    else {
        for (let i = 2; i <= Math.sqrt(num); i++) {
            if (num % i === 0){
                return false;

            }
        }
    }
    return true;
}
function countPrime(arr){
    let count = 0;
    for (let i = 0; i < arr.length; i++){
        if (isPrime(arr[i])){
            count++;
        }
    }
    return count;
}
let n = parseInt(prompt("Nhap vao so phan tu co trong mang: "));
let arr =[];
for (let i = 0; i < n; i++){
    let num = parseInt(prompt("Nhap phan tu thu " + (i + 1) + ":"));
    arr.push(arr[i]);
}
isPrime(arr);
let countSNT = countPrime(arr);
console.log("So nguye to co trong mang la: ${count}");




// tyopesccript 
import * as readlineSync from 'readline-sync';
function isPrime(number: number): boolean{
    if (number < 2){
        return false;
    }
    else{
        for (let i = 2; i < Math.sqrt(number); i++){
            if (number % i === 0){
                return false;
            }
        }
    }
    return true;
}
function countPrime(arr: number[]): number {
    let count = 0;
    for (let i = 0; i < arr.length; i++){
        if(isPrime(arr[i])){
            count++;
        }
    }
    return count;
}
let n: number = parseInt(readlineSync.question("Nhap so phan tu co trong mang:"));
const arr: number[] = [];
for (let i = 0; i < n; i++){
    arr.push(parseInt(readlineSync.question(Nhap phan tu thu ${i + 1}:)))
}
const countSNT: number = countPrime(arr);
console.log(`>>> So nguyen to co trong mang la ${countSNT}`)
