#include <iostream>
#include <vector>

using namespace std;

int pos(int y, int x) {
    return y*8 + x;
}

pair<int,int> posToYX(int p) {
    return {p/8, p%8};
}

int main() {
    int k, q, n, y, x;
    char board[64];

    // y,x
    vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};

    while (cin >> k >> q >> n) {
        // cout << k << " " << q << " " << n << endl;
    
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[pos(i,j)] = '0';
            }
        }

        if (k == q) {
            cout << "Illegal state" << endl;
            continue;
        }

        board[k] = 'K';

        for (auto iter : directions) {
            auto p = posToYX(k);
            y = p.first + iter.first;
            x = p.second + iter.second;

            if (y >= 0 && y < 8 && x >= 0 && x < 8) {
                board[pos(y,x)] = 'k';
            }
        }

        board[q] = 'Q';

        for (auto iter : directions) {
            for (int i = 1; i < 9; i++) {
                auto p = posToYX(q);
                y = p.first + (i * iter.first);
                x = p.second + (i * iter.second);

                if (y >= 0 && y < 8 && x >= 0 && x < 8) {
                    if (board[pos(y,x)] == 'k') {
                        board[pos(y,x)] = 'n';
                    }
                    else if (board[pos(y,x)] == 'K') {
                        break;
                    }
                    else
                    {
                        board[pos(y,x)] = 'q';
                    }
                }
            }
        }

        // for (int i = 0; i < 8; i++) {
        //  for (int j = 0; j < 8; j++) {
        //      cout << board[pos(i,j)] << " ";
        //  }
        //  cout << endl;
        // }

        if (board[n] == 'n') {
            cout << "Move not allowed" << endl;
            continue;
        }
        else if (board[n] != 'q') {
            cout << "Illegal move" << endl;
            continue;
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[pos(i,j)] = '0';
            }
        }

        // queen is now at new position
        q = n;

        board[k] = 'K';

        for (auto iter : directions) {
            auto p = posToYX(k);
            y = p.first + iter.first;
            x = p.second + iter.second;

            if (y >= 0 && y < 8 && x >= 0 && x < 8) {
                board[pos(y,x)] = 'k';
            }
        }

        board[q] = 'Q';

        for (auto iter : directions) {
            for (int i = 1; i < 9; i++) {
                auto p = posToYX(q);
                y = p.first + (i * iter.first);
                x = p.second + (i * iter.second);

                if (y >= 0 && y < 8 && x >= 0 && x < 8) {
                    if (board[pos(y,x)] == 'k') {
                        board[pos(y,x)] = 'n';
                        break;
                    }
                    board[pos(y,x)] = 'q';
                }
            }
        }

        bool done = false;

        for (auto iter : directions) {
            auto p = posToYX(k);
            y = p.first + iter.first;
            x = p.second + iter.second;

            if (y >= 0 && y < 8 && x >= 0 && x < 8) {
                if (board[pos(y,x)] != 'n') {
                    cout << "Continue" << endl;
                    done = true;
                    break;
                }
            }
        }

        if (done) {
            continue;
        }

        cout << "Stop" << endl;
        continue;
    }

    // for (int i = 0; i < 8; i++) {
    //  for (int j = 0; j < 8; j++) {
    //      cout << board[pos(i,j)] << " ";
    //  }
    //  cout << endl;
    // }
}

