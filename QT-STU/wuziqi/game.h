#ifndef GAME_H
#define GAME_H

#include <vector>


class Game
{
public:
    Game();

    bool isWhite();

    /// TODO 判断能不能落子
    bool canMakeMove(int x, int y);

    /// 落子，添加数据，判断输赢，前提是这里合法
    void MakeMove(bool white, int x, int y);

    // TODO 判断赢了没有
    int win();


    /// todo 判断平局
    bool tie();

private:

    int grid[17][17] = {};


    struct Move{
        bool bai; // 是白的还是黑的
        int x, y;  /// 用十六进制存，爽
        int allDirections[8]; /// 代表上下左右等八个方向，为了判断有没有五子连珠
    };

    // 下棋的历史记录，用于判断输赢和保存为文件
    int tot = 0;
    std::vector<Move> history;



    enum Mode{
        Bot, /// AI
        Man,
    };

    bool isBai = false;// 判断是那方出


    bool inbound(int x, int y);

    bool islegal(int x, int y);


    inline void setVis(int & x, int& y);
    inline bool hasused(int x, int y);

};

#endif // GAME_H
