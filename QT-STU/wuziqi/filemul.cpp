#include "filemul.h"
#include "QDebug"



int readFromFile();

/// 读取当前路径下所有以SUF为结尾的文件
/// 用到了io.h 可能无可移植性
std::vector<std::string> readFileList(std::string suf) {

    std::vector<std::string> res;

    //文件句柄
    //注意：我发现有些文章代码此处是long类型，实测运行中会报错访问异常
    intptr_t hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;

    if ((hFile = _findfirst(suf.c_str(), &fileinfo)) != -1)
    {
        do
        {
            res.push_back(fileinfo.name);
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }

    return res;
}

/// 写入i文件
int filemul::writeToFile(const std::vector<Game::Move>* history, const std::string filename) {
    std::ofstream oss(filename.c_str());

    if (oss.is_open()) {
        qDebug() << "prompt" << std::filesystem::current_path().c_str() << " " << filename << "ready to open";
        oss << HashCode << std::endl;
        for (auto it = history->begin(), ed = history->end(); it != ed; ++it) {
            oss << " " << it->x << " " << it->y << " " << (it->bai ? "W" : "B");
            qDebug() << " " << it->x << " " << it->y << " " << (it->bai ? "W" : "B");
        }

        oss.close();
        return 1;
    } else {
        return 0;
    }

}


int filemul::readFromFile(std::string filename, Game& game) {
    std::ifstream  oss(filename.c_str());
    if (oss.is_open()) {
        std::string headcode;
        getline(oss, headcode);
        if (headcode == HashCode) {
            int x, y;
            char qizi;
            while (oss >> x >> y >>qizi) {
                game.MakeMove(x, y);
            }
        } else {
            return filemul::FILE_INVALID;
        }
    } else {
        qDebug() << "fail to open " << filename.c_str();
        return filemul::FILE_FAILED;
    }
}
