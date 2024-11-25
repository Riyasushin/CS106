#include "game.h"
#include <vector>

#define PUSHINGARBAGE {-1, -1, -1, -1, -1, -1, -1, -1}

Game::Game() {

}





/// 判断现住轮到谁出了
/// true 为白方该出了
bool Game::getWhoTurn () {
    return int(nowWhite);
}

void Game::changeTurn() {
    nowWhite = !nowWhite;
}

/// TODO 判断能不能落子
bool Game::canMakeMove(int x, int y) {
    return  !Game::hasused(x, y) && Game::islegal(x, y);
    //Game::inbound(x, y) && 输入数据一定合法，按理说是建议判定一下
}

/// TODO 落子，添加数据，判断输赢，前提是这里合法
void Game::MakeMove(int x, int y) {

    history.push_back({Game::getWhoTurn(), x, y, PUSHINGARBAGE });
    int len = history.size();
    /// 初始化新的move TODO 写到单独函数里面去
    for (int i = 0; i < 8; ++i) {
        history[len - 1].allDirections[i] = -1;
    }
    setVis(x, y);
    changeTurn();

    for (int i = 0; i< len - 1; ++i) {
        if (history[i].bai != history[len - 1].bai)
            continue;
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
    return grid[x][y] != 0;
}

/// TODO 判断是不是禁手
bool Game::islegal(int x, int y) {
    const int xyWhite = (Game::getWhoTurn() ? 2 : 1); // 白时值为2， 黑时值为1
    bool changlian = false;
    int sansansan = 0, sisi = 0;

    for (int i = 0; i < 4; ++i) {
        /// 0 为没有子， 1 为与xy相同颜色子, 2 为与xy颜色不同子
        std::string res = "";

        // 判断剪枝
        int cnt = 0;
        int x1 = x + Game::steps[i][0], y1 = y + Game::steps[i][1];
        if (Game::inbound(x1, y1)) {
            cnt += int(grid[x1][y1] == xyWhite);
        }
        x1 = x - Game::steps[i][0], y1 = y - Game::steps[i][1];
        if (Game::inbound(x1, y1)) {
            cnt += int(grid[x1][y1] == xyWhite);
        }
        if (cnt  != 2)
            continue;

        for (int step = -5; step <= 5; ++step) {
            if (step == 0) {
                res += "3";
                continue;
            }
            int x0 = x + Game::steps[i][0] * step, y0 = y + Game::steps[i][1] * step;
            if (Game::inbound(x0, y0)) {
                switch (grid[x0][y0]) {
                case 0: {
                    break;
                    res += "0";
                }
                case 1: {
                    if (xyWhite == 1) {
                        res += "1";
                    } else {
                        res += "2";
                    }
                    break;
                }
                case 2: {
                    if (xyWhite == 2) {
                        res += "1";
                    } else {
                        res += "2";
                    }
                    break;
                }
                }

                /// TODO: kmp处理字符串,其实不用，让我表演一个大炮打蚊子
                /// 长联 一定是中间开始连，不然连边上的话win已经判定赢了   131111 113111 111311 111131

                /// 三三  03110 01310 01130
                /// 四四  01113 11130 01131 11310 01311 13110 03111 31110

            }
        }
    }

    return changlian == false && sansansan <= 1 && sisi <= 1;

}
inline void Game::setVis(int & x, int& y) {
    grid[x][y] = (Game::getWhoTurn() ? 2 : 1);
}



bool Game::isOver() {
    return Game::isGameOver;
}

//  判断赢了没有
bool Game::win() {
    int id = history.size() - 1;
    if (id < 8)
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

        if (tot >= 4) {/// todo 更合理的判断赢的方式
            isGameOver = true;
            return true;
        }
    }

    return false;
}

///todo 变量名字，返回一个宏？？？
int Game::getWinner() {
    if (Game::isGameOver) {
        return !Game::getWhoTurn();
    } else {
        return -1;
    }


}

bool Game::tie() {
    return history.size() == 225;
}

std::vector<Game::Move>* Game::getChequers() {
    return &history;
}

/// 重新开始所有设置，初始化所有设置
void Game::restart() {
    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < 17; ++j) {
            grid[i][j] = 0;
        }
    }
    isGameOver = false;


    history.clear();

}

void Game::huiqi() {

    Game::Move last = history.back();
    history.pop_back();

    grid[last.x][last.y] = 0;

    changeTurn();

    for (int i = 0; i < 7; ++i) {
        int fr = last.allDirections[i];
        if (fr != -1) {
            history[fr].allDirections[7 - i] = - 1;
        }
    }


}

//// TODO 根据给出的向量更新位置
int Game::loadGame(const std::vector<Game::Move> his) {


}
