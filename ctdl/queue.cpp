#include<iostream>
#include<queue>
using namespace std;

 int STT = 0;

class phieuNopTien{
    private:
        int stt;
        string hoten;
        string sotien;
    public:
        phieuNopTien(string name ="", string money =""){
            stt = ++STT;
            hoten = name;
            sotien = money;
        }
        void input(){
            stt = ++STT;
            cout << "\nHo va ten: ";
            getline(cin, hoten);
            cout << "\nSo tien nop: ";
            getline(cin, sotien);
        }
        void output(){
            cout << "\nStt: " << stt;
            cout << "\nHo va ten: " << hoten;
            cout << "\nSo tien dong: " << sotien;
        }
};

int main(){

    phieuNopTien lucChuong = {"lucChuong", "21000"};
    phieuNopTien anhThu = {"anhThu", "13000"};
    phieuNopTien yenTra = {"yenTra", "24000"};
    queue<phieuNopTien> q;
    phieuNopTien last;
    int count = 0;

    // them mot sinh vien vao hang doi
    q.push(lucChuong);
    q.push(anhThu);
    q.push(yenTra);
    duyet mot sv trong hang doi
    if(q.empty()) cout << "\nHang doi rong";
    else {
        last = q.front();
        q.pop();
        ++count;
    }
    // So sv da nop tien
    cout << "\nCo " << count << " sinh vien da nop tien";
    // So sv dang doi nop tien
    cout << "\nCo " << q.size() << " sinh vien dang doi nop tien";
    // sv vua moi nop tien
    cout << "\nThong tin sinh vien vua nop tien:";
    last.output();
    cout << endl;
    system("pause");
    return 0;
}