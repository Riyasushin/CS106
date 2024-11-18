#include "filemul.h"
#include "QDebug"



int readFromFile();
int readFileList();

/// 写入文件
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
