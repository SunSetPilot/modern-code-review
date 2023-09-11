#include <iostream>
using namespace std;


bool isWin(char game[3][3]){
    bool win = false;
    for (int i = 0; i < 3; i++) {
        if ((game[i][0] != ' ' && game[i][0] == game[i][1] && game[i][1] == game[i][2]) ||
        (game[0][i] != ' ' && game[0][i] == game[1][i] && game[1][i] == game[2][i])) win = true;
    }
    // diagonal
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] != ' ')) win = true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] != ' ')) win = true;
    return win;
}

int main(){
    int i, j;
    char game[3][3] = {{' ', ' ' , ' '},
                       {' ', ' ' , ' '},
                       {' ', ' ' , ' '} }; // Tic-tac-toe
    const char player1 = 'X';
    const char player2 = 'O';
    cout << player1 << " = Player 1" << endl << player2 <<" = Player 2" << endl;
    bool player2_turn = true; // false for player 1's player2_turn, true for player 2's player2_turn. Player 1 first.
    int n;
    for (n = 0; n < 9; n++){
        char character;
        player2_turn = !player2_turn;  // use the not-operator to change true to false or false to true.
        if (!player2_turn) {
            cout << "Player 1: ";
            character = player1;
        }
        else {
            cout << "Player 2: ";
            character = player2;
        }
        cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
        cin >> i >> j;
        while ((i < 1 || i > 3 || j < 1 || j > 3) || (game[i - 1][j - 1] == 'X' || game[i - 1][j - 1] == 'O')) {
            cout << "Invalid input! Try again." << endl;
            cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
            cin >> i >> j;
        }
        game[i - 1][j - 1] = character;
        if (isWin(game)){
            cout << "Win!" << endl;
            break; // need to terminate the problem
        }
    }
    if (n == 9) // all cells with i=1..3 and j=1..3 are filled in without a winner
        cout << "Tie!" << endl;

    // show the game to console
    for (auto & row : game) {
        for (int col = 0; col < 2; col++)
            cout << row[col] << " ";
        cout << endl;
    }
    return 0;
}
