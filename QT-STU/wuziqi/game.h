#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>



class Game
{

public:
    Game();



    struct Move{
        bool bai; // 是白的还是黑的
        int x, y;  /// 用十六进制存，爽
        int allDirections[8]; /// 代表上下左右等八个方向，为了判断有没有五子连珠   -1 为初始值
    };

    bool getWhoTurn();
    int loadGame(const std::vector<Game::Move> his);

    /// TODO 判断能不能落子
    bool canMakeMove(int x, int y);

    /// 落子，添加数据，判断输赢，前提是这里合法
    void MakeMove(int x, int y);

    // TODO 判断赢了没有
    bool isOver();
    bool win();
    int getWinner();

    /// GIVE AN API FOR vector "history"
    std::vector<Game::Move>* getChequers();


    /// todo 判断平局
    bool tie();



    void restart();
    void huiqi();

    static std::string GAMEFILESUF;

private:

    int grid[17][17] = {}; /// 0 : 未利用 ， 1 ： 黑子， 2 ： 白子
    bool isGameOver = false;



    // 下棋的历史记录，用于判断输赢和保存为文件
    std::vector<Move> history;



    enum Mode{
        Bot, /// AI
        Man,
    };

    bool nowWhite = false;// 判断是那方出
    void changeTurn(); // 下棋后更改，确定轮到哪方下了

    bool inbound(int x, int y);
    bool islegal(int x, int y);
    const int steps[4][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}};


    inline void setVis(int & x, int& y);
    inline bool hasused(int x, int y);
    ////////////////////.,
    const int next131111[6] = {};
    const int next113111[6] = {};
    const int next111311[6] = {};
    const int next111131[6] = {};
    ///////////////////
    const int next03110[5] = {};
    const int next01310[5] = {};
    const int next01130[5] = {};
    /////////////////
    const int next01113[5] = {};
    const int next11130[5] = {};

    const int next01131[5] = {};
    const int next11310[5] = {};

    const int next01311[5] = {};
    const int next13110[5] = {};

    const int next03111[5] = {};
    const int next31110[5] = {};
};

std::string Game::GAMEFILESUF = ".dat";

#endif // GAME_H
