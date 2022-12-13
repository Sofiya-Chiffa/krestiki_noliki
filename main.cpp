#include <iostream>
#include <random>
#include <ctime>

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

void hum_step(int a){
    int i = (a -1) / 3;
    int j = (a - 1) - ((a - 1) / 3 * 3);
    while (a > 9 || a < 1 || field[i][j] != '_'){
        cin >> a;
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
    int b;
    while (true){
        print_field(0);
        cin >> b;
        hum_step(b);
        print_field(0);
        if (check(0)){
            cout << "x won";
            break;
        }
        pc_step(0);
        if (check(0)){
            print_field(0);
            cout << "o won";
            break;
        }
    }
    return 0;
}