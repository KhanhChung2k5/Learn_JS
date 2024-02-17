#include <iostream>
#include <string>
using namespace std;
//ham chuyen tat ca cac ki tu trong chuoi s thanh in hoa 
void inhoa(string &s){
    for (int i = 0; i < s.size(); i++){
        s[i] = toupper(s[i]);
    }
}
// ham chuyen tat ca cac ki tu trong chuoi s thanh in thuong 
void inthuong(string &s){
    for (int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
}

int main(){
    string s;
    // cin chi nhap dc 1 sau kh co dau cach 
    getline(cin, s); // dung de nhap mot ham sau co ca dau cach 
    cout << s << endl;
    cout << s.size() << endl;
    // vi du dung string de nhap 5 hang gom cac ten khac nhau
    string res = "";
    string s;
    while(getline(cin, s)){
        res += s + "\n";
    }
    // vd 
    //khanh 
    //kiet
    // ngan
    cout << res << endl;
    // dung range base for loop de duyet string 
    for(char x: s){
        cout << x << ' ';
    }
    // dung insert de chen ki tu 
    s.insert(2, "@@@");
    //dung erase de xoa ki tu 
    s.erase(2); // xoa het cac ki tu tu chi so 2 
    s.erase(2, 4); // xoa 4 ki tu tu chi so 2 
    //cach de tim vi tri xuat hien cua ki tu 
    string s = "Khanh dev";
    string t = "dev";
    if(s.find(t) != string::npos){
            // neu tim thay dev o vi tri nao no se xuat ra so do 
        cout << s.find(t) << endl;
    }
    else{
         cout << "Not found" << endl;
            // neu khong co thi tra ve not found 
    }
    return 0;
    // in ra chu so dung giua cua string 
    string k = "12345";
    if (s.size() % 2 == 0){
        cout << "not found" << endl; // 1 chuoi string lenght chan thi khong co so dung giua 
    }
    else {
        cout << s[s.size() / 2] << endl;
    }


}
