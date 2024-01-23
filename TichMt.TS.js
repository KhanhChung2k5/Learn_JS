function isPrime1(num) {
    if (num <= 1)
        return false;
    for (var i = 2; i <= Math.sqrt(num); i++) {
        if (num % i === 0) {
            return false;
        }
    }
    return true;
}
function countPrimesInArray(arr) {
    var count = 0;
    for (var i = 0; i < arr.length; i++) {
        if (isPrime1(arr[i])) {
            count++;
        }
    }
    return count;
}
// Nhập mảng từ người dùng
var n1 = parseInt(prompt("Nhập số phần tử của mảng:") || "0");
var arr1 = [];
for (var i = 0; i < n1; i++) {
    var num = parseInt(prompt("Nhập phần tử thứ " + (i + 1) + ":") || "0");
    arr1.push(num);
}
// Kiểm tra và đếm số nguyên tố trong mảng
var primeCount = countPrimesInArray(arr1);
console.log("Mảng vừa nhập là:", arr1);
console.log("Số lượng số nguyên tố trong mảng là:", primeCount);
