#include<iostream>
#include<list>
using namespace std;

class sv {
private:
    string ID;
    string name;
    float GPA;
public:
    sv(string a ="", string b ="", double c =0.f) : ID(a), name(b), GPA(c) {}
    void in();
    void out();
    friend class svArr;
};
void sv::in() {
    cout << "\nID: ";
    getline(cin, ID);
    cout << "\nName: ";
    getline(cin, name);
    cout << "\nGPA: ";
    cin >> GPA;
}
void sv::out() {
    cout << "\nID: " << ID;
    cout << "\nname: " << name;
    cout << "\nGPA: " << GPA;
}

void swap(sv& a, sv& b) {
    sv temp;
    temp = a;
    a = b;
    b = temp;
}

class svArr {
private:
    list<sv> l;
public:
    void ArrIn(int n);
    void ArrOut();
    list<sv>::iterator search(string r_ID);
    void erase(string r_ID);
    void add(sv r_sv);
    void IDSort();
    // void nameSort();
    // void GPASort();
};

void svArr::ArrIn(int n) {
    while(n--) {
        sv temp;
        temp.in();
        cin.ignore();
        l.push_back(temp);
    }
    IDSort();
}

void svArr::ArrOut() {
    for(sv temp : l) temp.out();
}

list<sv>::iterator svArr::search(string r_ID) {
    for(list<sv>::iterator it = l.begin(); it != l.end(); ++it) {
        if(it->ID == r_ID) return it;
    }
    return l.end();
}

void svArr::erase(string r_ID) {
    list<sv>::iterator it = search(r_ID);
    if(it == l.end()) return;
    else l.erase(it);
}

void svArr::add(sv r_sv) {
    // tìm vị trí r thêm vào list
    list<sv>::iterator prev = l.begin();
    for(auto it = l.begin(); it != l.end(); ++it) {
        if(r_sv.ID < it->ID) {
            l.emplace(it, r_sv);
        }
    }

    // thêm vào cuối list r sort lại
    // l.push_back(r_sv);
    // IDSort();
}

void svArr::IDSort() {
    for(auto it = l.begin(); it != l.end(); ++it) {
        auto min = it;
        for(auto it2 = next(it); it2 != l.end(); ++it2) {
            if(it2->ID < min->ID) min = it2;
        }
        if(it != min) swap(*it, *min);
    }
}

int main() {
    svArr s;
    s.ArrIn(3);
    s.ArrOut();
    sv temp = {"3", "heo", 0};
    s.add(temp);
    s.ArrOut();
    cout << endl;
    system("pause");
    return 0;
}