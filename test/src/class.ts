class Student {
    name: string;
    diemtoan: number;
    diemvan: number;
    diemav: number;
    constructor(name: string, diemtoan: number, diemvan: number, diemav: number){
        this.name = name;
        this.diemtoan = diemtoan;
        this.diemvan = diemvan;
        this.diemav = diemav;
    }
    public diemtbmon(){
        return this.diemtong() /3;
    }
    private diemtong(){
        return this.diemav + this.diemtoan + this.diemvan;
    }
}
let Ckdev = new Student("KHANH", 10, 9, 8);
Ckdev.diemtbmon();

