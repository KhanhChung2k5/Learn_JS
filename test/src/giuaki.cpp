#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
// todo: cau truc cua thoi gian
struct mTime
{               //? mytimne
    int hour;   //? gio
    int minute; //? phut
};
// todo: cau truc cua khung gio
struct timeRange
{
    int week;      //? Tuan
    int dayInWeek; //? 1 <= day <= 7
    mTime start;   //?time bat dau
    mTime end;     //? time ket thuc
};
// todo: cau truc du lieu member dung de luu thong tin cua nguoi tham gia nghiem thu
struct member
{
    string name;               //? ten
    string academicrank;       //? hoc ham
    string degree;             //? hoc vi
    timeRange *availablehours; //? khung gio co san
    int hourCount;             //?So luong khung gio co san
};
// todo: cau truc du lieu luu thong tin ve hoi dong nghiem thu cho mot khoa
struct acceptancecommittee
{
    string department;      //? ten khoa
    int numofmember;        //? SO luong giang vien cua 1 khoa
    member *boardmembers;   //? thanh vien hoi dong
    int numofintendtime;    //? so luong lich to chuc hoi dong cua khoa do
    timeRange *intendtimes; //? thoi gian du kien: example: "Friday: 13:00 - 17:30"
};

// todo: Ham kiem tra xem co bi trung lich to chuc cua hai hoi dong
// TODO: Ta se co tong cong la 6 test case de check xem co bi overlap time hay khong
//? Case 1: Trung end: 8h -> 10h && 9h -> 10h .... => (8 - 10) * (9 - 10) = 2 > 0
//? Case 2: Trung start: 8h -> 10h && 8h -> 11h .... => (8 - 11) * (8 - 10) = 6 > 0
//? Case 3: Con cua doan do: 8h -> 11h && 9h -> 10h .... => (8 - 10) * (9 - 11) = 4 > 0
//? Case 4 : Kep : 8h -> 11h && 9h -> 12h .... => (8 - 12) * (9 - 11) = 8 > 0
//?Case 5: Trung ca start va end : 7h -> 10 && 7h -> 10h ... => (7 - 10) * (7 - 10) = 9 > 0
//? Case 6 : 0 trung: 8h -> 10h && 10h -> 11h .... => (8 - 11) * (10 - 10) = 0
//? Case 7: 0 trung : 8h -> 10h && 11h -> 13h .... => (8 - 13) * (11 - 10) = -5 < 0
bool overlapTime(timeRange time1, timeRange time2)
{
    //? Xử lý logic kiểm tra trùng lịch tổ chức
    // todo: trong truong hop neu co 2 buoi to chuc trung nhau thi doi 1 buoi qua tuan sau
    //? Ta se doi ve chung 1 don vi thoi gian la phut
    // todo: Tuan thi ta chi tinh them tu tuan thu 2 con ngay cung tinh tu ngaY THU 2
    //? Nen o day ta se tru 1 roi quy doi sang phut se ra dung don vi phut o ngay tuan do
    int startTime1 = (time1.week - 1) * 7 * 24 * 60 + (time1.dayInWeek - 1) * 24 * 60 + time1.start.hour * 60 + time1.start.minute;
    int endTime1 = (time1.week - 1) * 7 * 24 * 60 + (time1.dayInWeek - 1) * 24 * 60 + time1.end.hour * 60 + time1.end.minute;

    int startTime2 = (time2.week - 1) * 7 * 24 * 60 + (time2.dayInWeek - 1) * 24 * 60 + time2.start.hour * 60 + time2.start.minute;
    int endTime2 = (time2.week - 1) * 7 * 24 * 60 + (time2.dayInWeek - 1) * 24 * 60 + time2.end.hour * 60 + time2.end.minute;

    return (startTime1 - endTime2) * (startTime2 - endTime1) > 0;
}
acceptancecommittee *inputInformation()
{
    int n = 7;                 //? so khoa
    int hcnt;                  //?hourcount           //? so luong khung gio co san cua thanh vien hoi dong
    int numberoforganizations; //? so luong to chuc hoi dong cua 1 khoa
    acceptancecommittee *reports = new acceptancecommittee[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhập tên khoa: ";
        //? Nhap vao ten khoa ta se co tong cong 7 khoa tat ca
        // 1.Khoa Công nghệ Thông tin
        // 2. Khoa Luật
        // 3. Khoa Môi trường
        // 4. Khoa Nghệ thuật
        // 5. Khoa Ngoại ngữ
        // 6. Khoa Quản trị Kinh doanh
        // 7. Khoa Thư viện – Văn phòng
        getline(cin, reports[i].department);
        int m; //? m la so luong thanh vien hoi dong co trong 1 khoa
        cout << "Nhập số lượng thành viên hội đồng: ";
        cin >> m;
        // TODO: Theo yeu cau thi moi khoa can co it nhat 3 thanh vien de moi hoi dong can co it nhat 3 thanh vien tham gia
        while (m < 3)
        {
            cout << "Nhap lại số lượng thành viên hội đồng: ";
            cin >> m;
        }
        //? doc dau xuong dong
        cin.ignore();
        reports[i].boardmembers = new member[m];
        for (int j = 0; j < m; j++)
        {
            // TODO: nhap thong tin thanh vien
            cout << "Nhập tên giảng viên thứ " << j + 1 << ": ";
            //? Nhap vao ten cua thanh vien hoi dong
            getline(cin, reports[i].boardmembers[j].name);
            cout << "Nhập học hàm của giảng viên thứ " << j + 1 << ": ";
            //? Nhap vao hoc ham cua thanh vien hoi dong
            getline(cin, reports[i].boardmembers[j].academicrank);
            cout << "Nhập học vị của giảng viên thứ " << j + 1 << ": ";
            //? Nhap vao hoc vi cua thanh vien hoi dong
            getline(cin, reports[i].boardmembers[j].degree);
            cout << "Nhập số lượng khung giờ có sẵn của giảng viên thứ " << j + 1 << ": ";
            cin >> hcnt;
            cin.ignore();
            //? Nhap khung gio co san
            reports[i].boardmembers[j].availablehours = new timeRange[hcnt];
            reports[i].numofmember = hcnt;
            //? khung gio co san : Thu 2 8h -> 10h
            // TODO: rbash là hour bat dau, rbasm là minute bat dau, rbaeh la hour ket thuc, rbaem la phut ket thuc, rbad là ngày mấy trong tuần, rbaw là tuần mấy
            int rbash, rbasm, rbaeh, rbaem, rbad;
            for (int k = 0; k < hcnt; k++)
            {
                cout << "Nhập ngày của khung giờ thứ " << k + 1 << ": ";
                cin >> rbad;
                // TODO: Ta chi nhan thoi gian tu thu 2 toi thu 6 la tu ngay 1 toi ngay thu 5 trong 7 ngay trong tuan
                //? Neu vuout qua nhung ngay do thi ta khong nhan dau vao
                while (rbad < 1 || rbad > 5)
                {
                    cout << "Nhập lại ngày trong tuan tu 1 toi 5: ";
                    cin >> rbad;
                }
                cout << "Nhập giờ bắt đầu: ";
                cin >> rbash;
                // TODO:Thoi gian cuoc hop chi nam trong khoang tu 8 toi 17h, phut chi nam trong khoang tu 1 toi 60
                while (rbash < 8 || rbash > 17)
                {
                    cout << "Ngoài giờ quy định.Vui lòng nhập lại giờ từ 8 tới 17: ";
                    cin >> rbash;
                }
                cout << "Nhập phút bắt đầu: ";
                cin >> rbasm;
                // TODO: Thoi gian phut chi tu 0 toi 60 phút nếu vượt ngoài phải nhập lại
                while (rbasm < 0 || rbasm > 60)
                {
                    cout << "Vượt phạm vi.Nhập lại phút từ 0 tới 60: ";
                    cin >> rbasm;
                }
                cout << "Nhập giờ kết thúc: ";
                cin >> rbaeh;
                // TODO: Ngoài điều kiện tự như giờ bắt đầu thì ngoài cần phải nằm trong giờ hành chính ra thì cần phải lón hơn or bằng giờ bắt đầu
                while (rbaeh < 8 || rbaeh > 17 || rbaeh < rbash)
                {
                    cout << "Ngoài giờ quy định.Vui lòng nhập lại giờ từ 8 tới 17: ";
                    cin >> rbaeh;
                }
                cout << "Nhập phút kết thúc: ";
                cin >> rbaem;
                // TODO: Ta cũng sử dụng logic để check tương tự như ở giờ kết thúc
                while (rbaem < 0 || rbaem > 60 || rbaem < rbasm)
                {
                    cout << "Vượt phạm vi.Nhập lại phút từ 0 tới 60: ";
                    cin >> rbaem;
                }
                reports[i].boardmembers[j].availablehours->start.hour = rbash;
                reports[i].boardmembers[j].availablehours->start.minute = rbasm;
                reports[i].boardmembers[j].availablehours->end.hour = rbaeh;
                reports[i].boardmembers[j].availablehours->end.minute = rbaem;
                reports[i].boardmembers[j].availablehours->dayInWeek = rbad;
                reports[i].boardmembers[j].availablehours->week = 1;
            }
        }
        cout << "Nhập số lượng buổi tổ chức hội đồng nghiệm thu: ";
        cin >> numberoforganizations;
        cin.ignore();
        reports[i].numofintendtime = numberoforganizations;
        // TODO: Mang dong luu tru to hoi hoi dong
        reports->intendtimes = new timeRange[numberoforganizations];
        for (int l = 0; l < numberoforganizations; l++)
        {
            // TODO: rish2 là hour bat dau, rism2 là minute bat dau, rieh2 la hour ket thuc, riem2 la phut ket thuc, rid2 là ngày mấy trong tuần, riw2 là tuần mấy
            int rish, rism, rieh, riem, rid;
            cout << "Nhập ngày: ";
            cin >> rid;
            // TODO: Ta chi nhan thoi gian tu thu 2 toi thu 6 la tu ngay 1 toi ngay thu 5 trong 7 ngay trong tuan
            //? Neu vuout qua nhung ngay do thi ta khong nhan dau vao
            while (rid < 1 || rid > 5)
            {
                cout << "Ngày không hợp lệ, vui lòng nhập lại từ 1 tới 5: ";
                cin >> rid;
            }
            cout << "Nhập giờ bắt đầu: ";
            cin >> rish;
            // TODO:Thoi gian cuoc hop chi nam trong khoang tu 8 toi 17h, phut chi nam trong khoang tu 1 toi 60
            while (rish < 8 || rish > 17)
            {
                cout << "Ngoài giờ quy định.Vui lòng nhập lại giờ từ 8 tới 17: ";
                cin >> rish;
            }
            cout << "Nhập phút bắt đầu: ";
            cin >> rism;
            while (rism < 0 || rism > 60)
            {
                cout << "Vượt phạm vi.Nhập lại phút từ 0 tới 60: ";
                cin >> rism;
            }
            cout << "Nhap gio ket thuc cua buoi hop do: ";
            cin >> rieh;
            // TODO: Ngoài điều kiện tự như giờ bắt đầu thì ngoài cần phải nằm trong giờ hành chính ra thì cần phải lón hơn or bằng giờ bắt đầu
            while (rieh < 8 || rieh > 17 || rieh < rish)
            {
                cout << "Thoi gian ket thuc khong hop le vui long nhap lai: ";
                cin >> rieh;
            }
            cout << "Nhap phut ket thuc cau buoi hop do: ";
            cin >> riem;
            // TODO: Ta cũng sử dụng logic để check tương tự như ở giờ kết thúc
            while (riem < 0 || riem > 60 || riem < rism)
            {
                cout << "Thoi gian ket thuc khong hop le vui long nhap lai: ";
                cin >> riem;
            }
            reports[i].intendtimes[l].start.hour = rish;
            reports[i].intendtimes[l].start.minute = rism;
            reports[i].intendtimes[l].end.hour = rieh;
            reports[i].intendtimes[l].end.minute = riem;
            reports[i].intendtimes[l].dayInWeek = rid;
            reports[i].intendtimes[l].week = 1; // TODO: gia su rang lich du kien la tuan dau tien
        }
    }
    return reports;
}
acceptancecommittee *readFromFile(const string &filename, int n)
{
    // TODO: doc file
    ifstream file(filename);
    // TODO:CHECk xem co the mo file hay khong
    if (!file.is_open())
    {
        cout << "Không thể mở file." << endl;
        return nullptr;
    }

    //? SO luong khoa
    // TODO: Khởi tạo mảng acceptancecommittee
    acceptancecommittee *reports = new acceptancecommittee[n];
    //? Duyet qua tung khoa va nhap thong tin cho tung khoa
    for (int i = 0; i < n; ++i)
    {
        getline(file, reports[i].department); //? Đọc tên khoa
        file >> reports[i].numofmember;       //? Đọc số lượng thành viên
        file.ignore();                        //? Đọc bỏ dấu xuống dòng
        // TODO: Khởi tạo mảng các giảng vien
        reports[i].boardmembers = new member[reports[i].numofmember];

        //? Duyet qua tung thanh vien va nhap vao thong tin cua cac thanh vien do
        for (int j = 0; j < reports[i].numofmember; ++j)
        {
            getline(file, reports[i].boardmembers[j].name);         //? Đọc tên giảng viên
            getline(file, reports[i].boardmembers[j].academicrank); //? Đọc học hàm giảng viên
            getline(file, reports[i].boardmembers[j].degree);       //? Đọc học vị giảng viên
            file >> reports[i].boardmembers[j].hourCount;           //? Đọc số lượng khung giờ có sẵn của giang viên
            file.ignore();                                          //? Đọc bỏ dấu xuống dòng de tranh loi khi su dung getline
            // TODO: Khởi tạo mảng khung giờ
            reports[i].boardmembers[j].availablehours = new timeRange[reports[i].boardmembers[j].hourCount];
            //? Duyet qua so luong khung gio co san cua tung giang vien
            for (int k = 0; k < reports[i].boardmembers[j].hourCount; ++k)
            { //? Lan luot la so tuan , ngay thu may trong tuan, bat dau may gio may phut, ket thuc may gio , may phut
                file >> reports[i].boardmembers[j].availablehours[k].week;
                file >> reports[i].boardmembers[j].availablehours[k].dayInWeek;
                file >> reports[i].boardmembers[j].availablehours[k].start.hour;
                file >> reports[i].boardmembers[j].availablehours[k].start.minute;
                file >> reports[i].boardmembers[j].availablehours[k].end.hour;
                file >> reports[i].boardmembers[j].availablehours[k].end.minute;
            }
        }
        //? Đọc số lượng buổi tổ chức hội đồng
        file >> reports[i].numofintendtime;
        file.ignore(); // Đọc bỏ dấu xuống dòng
        // TODO: Khởi tạo mảng thời gian dự kiến
        reports[i].intendtimes = new timeRange[reports[i].numofintendtime];
        //? Đọc thông tin cho từng buổi tổ chức hội đồng
        for (int l = 0; l < reports[i].numofintendtime; ++l)
        {
            // TODO: tuong tu nhu ở khung gio co san ta cung se co tuan thu may , ngay thu may trong tuan , bat dau may gio , may phut , ket thuc may gio, may phut
            file >> reports[i].intendtimes[l].week;
            file >> reports[i].intendtimes[l].dayInWeek;
            file >> reports[i].intendtimes[l].start.hour;
            file >> reports[i].intendtimes[l].start.minute;
            file >> reports[i].intendtimes[l].end.hour;
            file >> reports[i].intendtimes[l].end.minute;
        }
    }
    // todo: đóng file lại
    file.close();
    return reports;
}
void writeToFile(const string &filename, acceptancecommittee *reports)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Không thể tạo hoặc mở file." << endl;
        return;
    }

    // Ghi số lượng khoa vào file
    int n = 7;

    // Ghi thông tin cho từng khoa
    for (int i = 0; i < n; ++i)
    {
        file << reports[i].department << endl;  // Ghi tên khoa
        file << reports[i].numofmember << endl; // Ghi số lượng thành viên

        // Ghi thông tin cho từng thành viên
        for (int j = 0; j < reports[i].numofmember; ++j)
        {
            file << reports[i].boardmembers[j].name << endl;         // Ghi tên giảng viên
            file << reports[i].boardmembers[j].academicrank << endl; // Ghi học hàm
            file << reports[i].boardmembers[j].degree << endl;       // Ghi học vị
            file << reports[i].boardmembers[j].hourCount << endl;    // Ghi số lượng khung giờ

            // Ghi thông tin cho từng khung giờ
            for (int k = 0; k < reports[i].boardmembers[j].hourCount; ++k)
            {
                file << reports[i].boardmembers[j].availablehours[k].week << " ";
                file << reports[i].boardmembers[j].availablehours[k].dayInWeek << " ";
                file << reports[i].boardmembers[j].availablehours[k].start.hour << " ";
                file << reports[i].boardmembers[j].availablehours[k].start.minute << " ";
                file << reports[i].boardmembers[j].availablehours[k].end.hour << " ";
                file << reports[i].boardmembers[j].availablehours[k].end.minute << endl;
            }
        }

        // Ghi số lượng buổi tổ chức hội đồng
        file << reports[i].numofintendtime << endl;

        // Ghi thông tin cho từng buổi tổ chức hội đồng
        for (int l = 0; l < reports[i].numofintendtime; ++l)
        {
            file << reports[i].intendtimes[l].week << " ";
            file << reports[i].intendtimes[l].dayInWeek << " ";
            file << reports[i].intendtimes[l].start.hour << " ";
            file << reports[i].intendtimes[l].start.minute << " ";
            file << reports[i].intendtimes[l].end.hour << " ";
            file << reports[i].intendtimes[l].end.minute << endl;
        }
    }
    file.close();
}
// todo: tạo hàm xếp lịch tự động
void automaticScheduling(acceptancecommittee *listReport)
{
    int n = 7; //? n : la so khoa
    // TODO: sap xep thoi gian trong 1 khoa sao cho khong trung
    //? Duyet qua tung khoa va check xem trong khoa co ton tai cap thoi gian to chuc nao b i overlap hay khong
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < listReport[i].numofintendtime; j++)
        {
            for (int k = j + 1; k < listReport[i].numofintendtime; k++)
            {
                if (overlapTime(listReport[i].intendtimes[j], listReport[i].intendtimes[k]))
                {
                    // TODO: Neu thoi gian to chuc bi opverlap ta se doi lich to chuc do qua tuan tiep theo
                    listReport[i].intendtimes[k].week += 1;
                }
            }
        }
    }
    // TODO: sau khi da xep lich sao cho giua cac lich to chuc cua 1 khoa khong co lich trung thi ta tiep tuc xet trung giua cac khoa
    // TODO: Ta se duyet 2 khoa khac nhau xem co bi overlaptime hay khong
    for (int i = 0; i < n; i++)
    {
        //? i va j la 2 khoa cac nhau
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < listReport[i].numofintendtime; k++)
            { //? k va l la 2 lich to chuc cua 2 khoa do
                for (int l = k + 1; l < listReport[j].numofintendtime; l++)
                {
                    if (overlapTime(listReport[i].intendtimes[k], listReport[j].intendtimes[l]))
                    {
                        listReport[j].intendtimes[l].week += 1;
                    }
                }
            }
        }
    }
    // todo: duyet qua tung khoa
    for (int i = 0; i < n; i++)
    {
        //? duyet qua cac thoi gian du kien to chuc hop hoi dong
        for (int j = 0; j < listReport[i].numofintendtime; j++)
        {
            //? gan bien dem cntmember de dem so luong giang vien co the tham gia vao 1 buoi hop hoi dong
            int cntmember = 0;
            //? duyet qua so giang vien co trong khoa
            for (int k = 0; k < listReport[i].numofmember; k++)
            {
                //
                timeRange intendTime = listReport[i].intendtimes[j];
                for (int l = 0; l < listReport[i].boardmembers[k].hourCount; l++)
                {
                    timeRange memberAvailableTime = listReport[i].boardmembers[k].availablehours[l];
                    // timeRange intendTime = listReport[i].intendtimes[l];
                    if (memberAvailableTime.dayInWeek == intendTime.dayInWeek &&
                        ((memberAvailableTime.start.hour < intendTime.start.hour) ||
                         (memberAvailableTime.start.hour == intendTime.start.hour &&
                          memberAvailableTime.start.minute <= intendTime.start.minute)) &&
                        (memberAvailableTime.end.hour >= intendTime.end.hour ||
                         (memberAvailableTime.end.hour == intendTime.end.hour &&
                          memberAvailableTime.end.minute >= intendTime.end.minute)))
                    {
                        cntmember++;
                        break;
                    }
                }
            }
            if (cntmember < 3)
            {
                {
                    // Xóa thông tin của buổi họp khỏi mảng intendtimes
                    for (int m = j; m < listReport[i].numofintendtime - 1; m++)
                    {
                        listReport[i].intendtimes[m] = listReport[i].intendtimes[m + 1];
                    }
                    listReport[i].numofintendtime--; // Giảm số lượng buổi họp
                    j--;                             // Đảm bảo duyệt qua lại buổi họp mới được di chuyển lên sau khi xóa
                }
            }
        }
    }
}
// TODO: Search
//? Nhap vao khoa va ten giang vien tra ve cac lich hoi dong ma giang vien do tham gia
void Searchinf(acceptancecommittee *ListReport)
{
    // TODO: Sdepartment : ten cua khoa co giang vien can tra, Sname: Ten cua giang vien do
    string Sdepartment;
    string Sname;
    int n = 7; //? So khoa hien co
    cout << "Nhap vao ten khoa: ";
    getline(cin, Sdepartment);
    cin.ignore();
    cout << "Nhap ten cua giang vien do: ";
    getline(cin, Sname);
    // //? Duyet qua cac khoa
    for (int i = 0; i < n; i++)
    {
        // TODO: Neu co 1 khoa giong ten khoa da nhap vao thi da tium thay khoa do
        if (ListReport->department == Sdepartment)
        {
            cout << "Find department: " << Sdepartment << endl;
            // TODO: Tiep tuc duyet tiep qua cac giang vien co trong khoa do
            for (int j = 0; j < ListReport[i].numofmember; j++)
            {
                // TODO: Neu ton tai ten cua giang vien nao khop voi ten giang vien can tim thi da tim thay, tra ve cac lich hop cua giang vien do
                if (ListReport[i].boardmembers[j].name == Sname)
                {
                    // TODO: Duyet qua so luong khung gio co san cua giang vien
                    for (int k = 0; k < ListReport[i].boardmembers[j].hourCount; k++)
                    {
                        // TODO: Ta gan ten bien lai de khi xu ly code đỡ dài dòng và dễ xử lý
                        timeRange memberAvailableTime = ListReport[i].boardmembers[j].availablehours[k];
                        for (int l = 0; l < ListReport[i].numofintendtime; l++)
                        { // TODO: Tuong tu nhu o tren ta cung se gan ten bien lai
                            timeRange intendTime = ListReport[i].intendtimes[l];
                            // TODO: Truoc tien ta can check xem no co trung ngay nhau hay khong
                            if (memberAvailableTime.dayInWeek == intendTime.dayInWeek &&
                                ((memberAvailableTime.start.hour < intendTime.start.hour) ||
                                 (memberAvailableTime.start.hour == intendTime.start.hour &&
                                  memberAvailableTime.start.minute <= intendTime.start.minute)) &&
                                (memberAvailableTime.end.hour >= intendTime.end.hour ||
                                 (memberAvailableTime.end.hour == intendTime.end.hour &&
                                  memberAvailableTime.end.minute >= intendTime.end.minute)))
                            {
                                cout << "Tuần: " << intendTime.week << " ";
                                cout << "Thứ: " << intendTime.dayInWeek + 1 << " ";
                                cout << "Khung giờ: " << intendTime.start.hour << ":" << intendTime.start.minute << " -> ";
                                cout << intendTime.end.hour << ":" << intendTime.end.minute;
                            }
                        }
                    }
                }
            }
            break;
        }
    }
}
// TODO: Ham hei thi lich hoi dong da duoc sap xep cua moi khoa
void showmeetingschedule(acceptancecommittee *ListReport, int n)
{
    cout << "Lịch hội đồng nghiệm thu:\n";
    //? Duyệt qua từng khoa
    for (int i = 0; i < n; i++)
    {
        // TODO: Xuất ra tên khoa sau đó lần lượt là các lịch họp của khoa đó
        cout << "Khoa: " << ListReport[i].department << endl;
        // todo: Xuất ra các giảng viên có trong khoa đó
        cout << "Danh sách các thành viên hội đồng: \n";
        for (int j = 0; j < ListReport[i].numofmember; ++j)
        {
            cout << "Tên: " << ListReport[i].boardmembers[j].name << " "
                 << "Học hàm: " << ListReport[i].boardmembers[j].academicrank << " "
                 << "Học vị: " << ListReport[i].boardmembers[j].degree << endl;
        }
        cout << "Thời gian dự kiến:\n";
        // TODO: Duyệt qua các thòiw gian dự kiến họp và xuất ra màn hinh
        for (int j = 0; j < ListReport[i].numofintendtime; ++j)
        {
            cout << "Tuần: " << ListReport[i].intendtimes[j].week << " "
                 << "Thứ: " << ListReport[i].intendtimes[j].dayInWeek + 1 << " " << ListReport[i].intendtimes[j].start.hour << ":" << ListReport[i].intendtimes[j].start.minute << "-" << ListReport[i].intendtimes[j].end.hour << ":" << ListReport[i].intendtimes[j].end.minute << endl;
        }
    }
}
// TODO: Dung & de dung tham chieu de
int main()
{
    acceptancecommittee *ListReport = readFromFile("checkcase1.txt", 7);
    if (ListReport != nullptr)
    {
        automaticScheduling(ListReport);
        showmeetingschedule(ListReport, 7);
        Searchinf(ListReport);
        // writeToFile("okokokoko.txt", ListReport);

        // Giải phóng bộ nhớ đã cấp phát
        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < ListReport[i].numofmember; ++j)
            {
                delete[] ListReport[i].boardmembers[j].availablehours;
            }
            delete[] ListReport[i].boardmembers;
            delete[] ListReport[i].intendtimes;
        }
        delete[] ListReport;
    }

    return 0;
}