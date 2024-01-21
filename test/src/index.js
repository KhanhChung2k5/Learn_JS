"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
const readlineSync = __importStar(require("readline-sync"));
function isPrime(number) {
    if (number < 2) {
        return false;
    }
    else {
        for (let i = 2; i < Math.sqrt(number); i++) {
            if (number % i === 0) {
                return false;
            }
        }
    }
    return true;
}
function countPrime(arr) {
    let count = 0;
    for (let i = 0; i < arr.length; i++) {
        if (isPrime(arr[i])) {
            count++;
        }
    }
    return count;
}
let n = parseInt(readlineSync.question("Nhap so phan tu co trong mang:"));
const arr = [];
for (let i = 0; i < n; i++) {
    arr.push(parseInt(readlineSync.question(`Nhap phan tu thu ${i + 1}:`)));
}
const countSNT = countPrime(arr);
console.log(`>>> So nguyen to co trong mang la ${countSNT}`);
