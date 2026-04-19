#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string toLoc(int r, int c) {
    string s = "";
    s += (char)('A' + r);
    s += (char)('1' + c);
    return s;
}

bool isPathClear(int r1, int c1, int r2, int c2, const vector<vector<string>>& board) {
    int dr = (r2 > r1) ? 1 : (r2 < r1 ? -1 : 0);
    int dc = (c2 > c1) ? 1 : (c2 < c1 ? -1 : 0);
    int r = r1 + dr;
    int c = c1 + dc;
    while (r != r2 || c != c2) {
        if (board[r][c] != "_") return false;
        r += dr;
        c += dc;
    }
    return true;
}

bool canCapture(int r1, int c1, int r2, int c2, const vector<vector<string>>& board) {
    char p = board[r1][c1][0];
    int dr = abs(r1 - r2);
    int dc = abs(c1 - c2);

    if (p == 'K') return (dr <= 1 && dc <= 1);
    if (p == 'N') return (dr * dc == 2);
    if (p == 'R') return (r1 == r2 || c1 == c2) && isPathClear(r1, c1, r2, c2, board);
    if (p == 'B') return (dr == dc) && isPathClear(r1, c1, r2, c2, board);
    if (p == 'Q') return (r1 == r2 || c1 == c2 || dr == dc) && isPathClear(r1, c1, r2, c2, board);
    return false;
}

struct Move {
    string moveStr;
    string loc1, loc2;
    int r1, c1, r2, c2;
};

bool solve(vector<vector<string>>& board, int size, int remaining, vector<string>& path, char targetPiece) {
    if (remaining == 1) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != "_") return board[i][j][0] == targetPiece;
            }
        }
        return false;
    }

    vector<Move> moves;
    for (int r1 = 0; r1 < size; r1++) {
        for (int c1 = 0; c1 < size; c1++) {
            if (board[r1][c1] == "_") continue;
            for (int r2 = 0; r2 < size; r2++) {
                for (int c2 = 0; c2 < size; c2++) {
                    if (board[r2][c2] == "_" || (r1 == r2 && c1 == c2)) continue;
                    
                    if (canCapture(r1, c1, r2, c2, board)) {
                        string l1 = toLoc(r1, c1);
                        string l2 = toLoc(r2, c2);
                        string mStr = string(1, board[r1][c1][0]) + ": " + l1 + " -> " + l2;
                        moves.push_back({mStr, l1, l2, r1, c1, r2, c2});
                    }
                }
            }
        }
    }

    sort(moves.begin(), moves.end(), [](const Move& a, const Move& b) {
        if (a.loc1 != b.loc1) return a.loc1 < b.loc1;
        return a.loc2 < b.loc2;
    });

    for (auto& m : moves) {
        string attacker = board[m.r1][m.c1];
        string victim = board[m.r2][m.c2];

        board[m.r2][m.c2] = attacker;
        board[m.r1][m.c1] = "_";
        path.push_back(m.moveStr);

        if (solve(board, size, remaining - 1, path, targetPiece)) return true;

        path.pop_back();
        board[m.r1][m.c1] = attacker;
        board[m.r2][m.c2] = victim;
    }
    return false;
}

int main() {
    int size, nPieces;
    if (!(cin >> size >> nPieces)) return 0;

    vector<vector<string>> board(size, vector<string>(size, "_"));
    for (int i = 0; i < nPieces; i++) {
        char p; string loc;
        cin >> p >> loc;
        int r = loc[0] - 'A';
        int c = loc[1] - '1';
        board[r][c] = string(1, p);
    }

    char priorities[] = {'B', 'K', 'N', 'Q', 'R'};
    bool found = false;

    for (char p : priorities) {
        vector<string> path;
        if (solve(board, size, nPieces, path, p)) {
            for (const string& step : path) cout << step << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "No solution" << endl;

    return 0;
}