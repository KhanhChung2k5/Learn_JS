// xor là phep toan logic khi co 1 trong 2 gia tri la true thi tra ve ket qua la true con 
// neu ca hai cung la true or cung false thi tra ve dap an false 
// co 2 case la chuoi true false or so sanh tung cap bit nhi phan neu so sanh 2 chuoi nhi phan 
// a ^ b : XOR
// khoi tao ham de thuc hien toa tu XOR
function xor_2_string(a: any, b: any): any {
    //dap an tra ve la 1 chuoi rong 
    let s: any = '';
    //duyet vong for cho toi nho hon length cua 2 chuoi 
    // 2 chuoi co do dai bang nhau 
    for (let i = 0; i < Math.max(a.length, b.length); i++){
        // 
        s += String.fromCharCode((a.charCodeAt(i) || 0) ^ (b.charCodeAt(i) || 0)
        );
    }
    return s;
}
let a: any = '882837393'
let b: any = 'KKKKKKKKK'
console.log(xor_2_string(a, b));
