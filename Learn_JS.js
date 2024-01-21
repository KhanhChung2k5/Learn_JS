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
