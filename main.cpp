#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

char field[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
char pl;
char pc;

void print_field(int a){
    cout << endl;
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
    cout <<endl;
}

int hum_id(string a){
    int ch = 0;
    while (true){
        ch = 0;
        for (int i=0;i<a.length();++i){
            if (!isdigit(a[0])){
                ch = 1;
                break;
            }
        }
        if (ch == 0){
            return stoi(a);
        }
        cin >> a;
    }
}

void hum_step(string b){
    int a = hum_id(b);
    int i = (a -1) / 3;
    int j = (a - 1) - ((a - 1) / 3 * 3);
    while (a > 9 || a < 1 || field[i][j] != '_'){
        cin >> b;
        a = hum_id(b);
        i = (a -1) / 3;
        j = (a - 1) - ((a - 1) / 3 * 3);
    }
    field[i][j] = 'x';
}

void pc_step(int a){
    if (field[0][0] == field[0][1] && field[0][0] != '_' && field[0][2] == '_'){
        field[0][2] = 'o';
    }
    else if (field[0][0] == field[0][2] && field[0][0] != '_' && field[0][1] == '_'){
        field[0][1] = 'o';
    }
    else if (field[0][1] == field[0][2] && field[0][1] != '_' && field[0][0] == '_'){
        field[0][0] = 'o';
    }
    else if (field[0][0] == field[1][0] && field[0][0] != '_' && field[2][0] == '_'){
        field[2][0] = 'o';
    }
    else if (field[0][0] == field[2][0] && field[0][0] != '_' && field[1][0] == '_'){
        field[1][0] = 'o';
    }
    else if (field[1][0] == field[2][0] && field[1][0] != '_' && field[0][0] == '_'){
        field[0][0] = 'o';
    }
    else if (field[0][0] == field[1][1] && field[0][0] != '_' && field[2][2] == '_'){
        field[2][2] = 'o';
    }
    else if (field[0][0] == field[2][2] && field[0][0] != '_' && field[1][1] == '_'){
        field[1][1] = 'o';
    }
    else if (field[2][2] == field[1][1] && field[1][1] != '_' && field[0][0] == '_'){
        field[0][0] = 'o';
    }


    else if (field[2][2] == field[1][2] && field[2][2] != '_' && field[0][2] == '_'){
        field[0][2] = 'o';
    }
    else if (field[2][2] == field[0][2] && field[0][2] != '_' && field[1][2] == '_'){
        field[1][2] = 'o';
    }
    else if (field[1][2] == field[0][2] && field[0][2] != '_' && field[2][2] == '_'){
        field[2][2] = 'o';
    }
    else if (field[2][2] == field[2][1] && field[2][2] != '_' && field[2][0] == '_'){
        field[2][0] = 'o';
    }
    else if (field[2][2] == field[2][0] && field[2][2] != '_' && field[2][1] == '_'){
        field[2][1] = 'o';
    }
    else if (field[2][0] == field[2][1] && field[2][0] != '_' && field[2][2] == '_'){
        field[2][2] = 'o';
    }


    else if (field[0][2] == field[1][1] && field[0][2] != '_' && field[2][0] == '_'){
        field[2][0] = 'o';
    }
    else if (field[2][0] == field[0][2] && field[2][0] != '_' && field[1][1] == '_'){
        field[1][1] = 'o';
    }
    else if (field[2][0] == field[1][1] && field[2][0] != '_' && field[0][2] == '_'){
        field[0][2] = 'o';
    }


    else if (field[1][0] == field[1][1] && field[1][0] != '_' && field[1][2] == '_'){
        field[1][2] = 'o';
    }
    else if (field[1][0] == field[1][2] && field[1][0] != '_' && field[1][1] == '_'){
        field[1][1] = 'o';
    }
    else if (field[1][2] == field[1][1] && field[1][1] != '_' && field[1][0] == '_'){
        field[1][0] = 'o';
    }
    else if (field[0][1] == field[1][1] && field[0][1] != '_' && field[2][1] == '_'){
        field[2][1] = 'o';
    }
    else if (field[0][1] == field[2][1] && field[2][1] != '_' && field[1][1] == '_'){
        field[1][1] = 'o';
    }
    else if (field[2][1] == field[1][1] && field[2][1] != '_' && field[0][1] == '_'){
        field[0][1] = 'o';
    }


    else if (field[0][0] == '_'){
        field[0][0] = 'o';
    }
    else if (field[0][2] == '_'){
        field[0][2] = 'o';
    }
    else if (field[2][2] == '_'){
        field[2][2] = 'o';
    }
    else if (field[2][0] == '_'){
        field[2][0] = 'o';
    }

}

int check(int a){
    if (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != '_'){
        return 1;
    }
    if (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[0][0] != '_'){
        return 1;
    }
    if (field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][0] != '_'){
        return 1;
    }
    if (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[1][1] != '_'){
        return 1;
    }
    if (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[0][2] != '_'){
        return 1;
    }
    if (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[0][1] != '_'){
        return 1;
    }
    if (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][2] != '_'){
        return 1;
    }
    if (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][1] != '_'){

        return 1;
    }
    if (field[0][0] != '_' && field[0][1] != '_' && field[0][2] != '_' && field[1][0] != '_' &&
    field[1][1] != '_' && field[1][2] != '_' && field[2][0] != '_' && field[2][1] != '_' && field[2][2] != '_'){
        return -1;
    }
    return 0;
}

int main()
{
    srand(time(0));
    int r = rand();
    if (r % 2 == 0){
        pl = 'x';
        pc = 'o';
    }
    else {
        pl = '0';
        pc = 'x';
    }
    string b;
    while (true){
        print_field(0);
        cin >> b;
        hum_step(b);
        print_field(0);
        if (check(0) == 1){
            cout << "x won";
            break;}
        if (check(0) == -1){
            cout << "nobody win";
            break;
        }
        pc_step(0);
        if (check(0) == 1){
            print_field(0);
            cout << "o won";
            break;}
        if (check(0) == -1){
            cout << "nobody win";
            break;
        }
    }
    return 0;
}
