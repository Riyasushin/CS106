#include "game.h"
#include <vector>

#define PUSHINGARBAGE {-1, -1, -1, -1, -1, -1, -1, -1}

Game::Game() {

}

bool Game::isWhite () {
    return isBai;
}

/// TODO 判断能不能落子
bool Game::canMakeMove(int x, int y) {
    //return Game::inbound(x, y) && Game::hasused(x, y) && Game::islegal(x, y);
    return true;
}

/// TODO 落子，添加数据，判断输赢，前提是这里合法
void Game::MakeMove(bool white, int x, int y) {

    history.push_back({white, x, y, PUSHINGARBAGE });
    setVis(x, y);


    for (int i = 0, len = history.size(); i< len - 1; ++i) {
        int x1 = history[i].x, y1 = history[i].y;
        int dx = x1 - x, dy = y1 - y;

        if (dx == 1 && dy == 0) {
            /// YOU
            history[len-1].allDirections[0] = i;
            history[i].allDirections[7] = len - 1;
        }  else if (dx == -1 && dy == 0) {
            /// ZUO
            history[len-1].allDirections[7] = i;
            history[i].allDirections[0] = len - 1;
        }  else if (dx == 0 && dy == 1) {
            /// xia
            history[len-1].allDirections[1] = i;
            history[i].allDirections[6] = len - 1;
        }  else if (dx == 0 && dy == -1) {
            /// shang
            history[len-1].allDirections[6] = i;
            history[i].allDirections[1] = len - 1;
        }  else if (dx == 1 && dy == 1) {
            /// youxiaq
            history[len-1].allDirections[2] = i;
            history[i].allDirections[5] = len - 1;
        }  else if (dx == 1 && dy == -1) {
            /// youshang
            history[len-1].allDirections[3] = i;
            history[i].allDirections[4] = len - 1;
        }  else if (dx == -1 && dy == 1) {
            /// zuoixia
            history[len-1].allDirections[4] = i;
            history[i].allDirections[3] = len - 1;
        }  else if (dx == -1 && dy == -1) {
            /// zuoshang
            history[len-1].allDirections[5] = i;
            history[i].allDirections[2] = len - 1;
        }
    }


}




bool inbound(int x, int y) {
    return x>= 0 && y >= 0 && x < 16 && y < 16;
}

inline bool Game::hasused(int x, int y) {
    return grid[x][y];
}

bool Game::islegal(int x, int y) {
    /// TODO
    return true;

}
inline void Game::setVis(int & x, int& y) {
    grid[x][y] = true;
}



//  判断赢了没有
int Game::win() {
    int id = history.size() - 1;
    if (id < 9)
        return false;
    for (int i = 0; i < 4; ++i) {
        int tot = 0;
        int temp = history[id].allDirections[i];
        while (temp != -1) {
            tot++;
            temp = history[temp].allDirections[i];
        }
        temp = history[id].allDirections[7 - i];
        while (temp != -1) {
            tot++;
            temp = history[temp].allDirections[7 - i];
        }

        if (tot == 4)///////////////////////
            return true;
    }

    return false;
}

bool Game::tie() {
    return history.size() == 225;
}

