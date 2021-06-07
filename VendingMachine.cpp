#include <iostream>
#include <string>

using namespace std;
class VendingMachine
{
private:
    string name;
    int price;
    int total = 0;
public:
    VendingMachine() {};
    void purchase(double v1);
    void menu();
    void upgrademenu();
    string getName();
    double getPrice();
    double getTotal();
    void setName(string n) {
        name = n;
    }
    void setPrice(int p) {
        price = p;
    }
    void setTotal(int t) {
        int num;
        int count;
        int menu[4] = { 1200, 1400, 1800, price };

        while (1)
        {
            cout << "번호를 선택해주세요 : ";
            cin >> num;

            if (num < 5) {
                cout << "구매할 수량을 입력해주세요 :";
                cin >> count;
                num = num - 1;

                t = t + menu[num] * count;
                total = t;
            }
            else
                break;
        }
    }
    int returngap = 200;
};
void VendingMachine::menu() {

    cout << "==========SWING 자판기==========" << endl;
    cout << "1. 코카콜라 : 1200원" << endl;
    cout << "2. 칠성 사이다 : 1400원" << endl;
    cout << "3. 미에로 화이바 : 1800원" << endl;
    cout << "4. 준비중" << endl;
    cout << "5. 계산" << endl;
    cout << "6. 종료" << endl;

    cout << endl;
    cout << "추가할 음료 이름을 입력해주세요:";

}
void VendingMachine::upgrademenu() {

    cout << "==========SWING 자판기==========" << endl;
    cout << "1. 코카콜라 : 1200원" << endl;
    cout << "2. 칠성 사이다 : 1400원" << endl;
    cout << "3. 미에로 화이바 : 1800원" << endl;
    cout << "4. " << name << " : " << price << "원" << endl;
    cout << "5. 계산" << endl;
    cout << "6. 종료" << endl;

}

void VendingMachine::purchase(double v1) {
    int cost;
    cout << "계산 중입니다. 기다려주세요 . . . ." << endl;
    cout << endl;
re:
    cout << "총금액 : " << total << endl;
    cout << "지폐를 입력하세요:";
    cin >> cost;

    if (total == cost) {
        cout << endl;
        cout << "거스름돈이 없습니다. 안녕히가세요" << endl;
        cout << "거기에 남은 거스름돈 (100원 개수) :" << returngap << endl;
    }

    else if (total > cost) {
        cout << "금액이 부족합니다. 다시 넣어주세요." << endl;
        goto re;
    }

    else {

        int x;
        x = total % 100;

        if (x == 0) {
            if (20000 >= cost - total) {
                cout << "거스름돈입니다" << endl;
                cout << "100원 : " << ((cost - total) / 100) << "개" << endl;
                cout << "거기에 남은 거스름돈(100원 개수):" << returngap - ((cost - total) / 100) << endl;
                cout << "==========SWING 자판기==========" << endl;

            }

            else {
                cout << "거스름돈입니다" << endl;
                cout << "기기내의 잔돈이 부족합니다. 010-xxxx-xxxx로 연락주세요" << endl;
                cout << "거기에 남은 거스름돈(100원 개수) :  0개" << endl;
                cout << "==========SWING 자판기==========" << endl;
            }
        }

        else {
            cout << "거스름돈은 100원만 가능합니다." << endl;
            cout << "100원 : " << ((cost - total) / 100) << "개" << endl;
            cout << "거기에 남은 거스름돈(100원 개수):" << returngap - ((cost - total) / 100) << endl;
            cout << "==========SWING 자판기==========" << endl;

        }
    }
}

int main(){

    VendingMachine z;
    VendingMachine* w;
    w = &z;

    string n;
    w->menu();
    cin >> n;
    z.setName(n);
    int p;
    cout << "판매할 가격을 입력하세요 : ";
    cin >> p;
    z.setPrice(p);
    z.upgrademenu();
    z.setTotal(0);
    z.purchase(0);

}
