#ifndef FILEMUL_H
#define FILEMUL_H



#include "game.h"
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <QDebug>
#include <ios>
#include <io.h>

class filemul
{
public:

    static int readFromFile(std::string filename, Game& game);
    static std::vector<std::string> readFileList(std::string suf);
    static int writeToFile(const std::vector<Game::Move>* history, const std::string filename);

    static const int FILE_INVALID = 404; /// 读取到的不是我的文件，特征码不对
    static const int FILE_FAILED = 401; /// 没有读取成功


private:
    filemul();

};

#endif // FILEMUL_H
