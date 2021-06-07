#include <iostream>
#include <vector>
#include <string>
using namespace std;

class board {

    class tile {
        short state;
    public:
        tile() { state = 0; }
        void change_state(int new_state) { state = new_state; };
        short get_state(void) { return state; }
    };

    int player_num = -1;
    tile board_array[3][3];

public:

    board() {
        for(int i = 0; i < 3; ++i)
            for(int g = 0; g < 3; ++g)
                board_array[i][g].change_state(0);
    }

    int get_player_num () {
        if (player_num == -1) {
            player_num = 1;
        } else if (player_num == 1) {
            player_num = -1;
        }
        return player_num;
    }

    int print_board(void) {
        cout << "  ---------\n";
        for(int i = 0; i < 3; ++i) {
            cout << i << " ";
            for(int g = 0; g < 3; ++g) {
                cout << "|";
                switch(board_array[i][g].get_state()) {
                case -1 :
                    cout << "X|";
                    break;
                case 0 :
                    cout << " |";
                    break;
                case 1 :
                    cout << "0|";
                    break;
                }
            }
            putchar('\n');
            cout << "  ---------";
            putchar('\n');
        }
        cout << "   A  B  C\n";
        return 0;
    }

    int get_move(void) {
        string move;
        short x, y;
        bool loop = true;
        while(loop) {
            cout << "(plyr="<< get_player_num() << ") " << "Enter move ::> ";
            cin >> move;

            if (move.length() > 2)
                cout << "Too many characters. Try again.";
            else
                break;
        }

        x = stoi(move);

        switch(move[1]) {
            case 'A' :
                y = 0;
                break;
            case 'B' :
                y = 1;
                break;
            case 'C' :
                y = 2;
                break;
        }
        board_array[x][y].change_state(get_player_num());
        return 0;
    }
};

int main(void) {
    board new_gameboard;
    new_gameboard.print_board();
    while(new_gameboard.get_move() == 0) {
        new_gameboard.print_board();
    }
    return 0;
}
