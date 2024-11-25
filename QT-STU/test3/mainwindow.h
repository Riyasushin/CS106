#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QListWidget>
#include <QHBoxLayout>
#include <QDialog>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE



// 弹出窗口的类
class ItemListWindow : public QDialog {
    Q_OBJECT

public:
    // 构造函数
    ItemListWindow(QWidget *parent = nullptr, const std::vector<std::string>& list = {})
        : QDialog(parent), filelist(list) {

        // 设置主窗口的布局
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        // 上半部分的 QLabel 提示词
        QLabel *label = new QLabel("请选择一个项目进行加载", this);
        mainLayout->addWidget(label);

        // 下半部分的 QListWidget
        QListWidget *listWidget = new QListWidget(this);
        mainLayout->addWidget(listWidget);

        // 向列表中添加项目并为每个项目创建一个按钮
        for (size_t i = 0, len = filelist.size(); i < len; ++i) {
            // 创建列表项文本（你可以在这里将文本设置为文件名或其他信息）
            QListWidgetItem *item = new QListWidgetItem();  // 没有文本
            QWidget *itemWidget = new QWidget();
            QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);

            // 左侧的 QLabel
            QLabel *itemLabel = new QLabel(QString::number(i + 1) + ": " + QString::fromStdString(filelist[i]), itemWidget);

            // 右侧的 "载入" 按钮
            QPushButton *loadButton = new QPushButton("载入", itemWidget);
            connect(loadButton, &QPushButton::clicked, [this, i]() {
                loadItemFunction(i);  // 绑定函数，传递项目索引
                this->accept();  // 关闭弹出窗口
            });

            // 将控件添加到布局
            itemLayout->addWidget(itemLabel);
            itemLayout->addWidget(loadButton);
            itemWidget->setLayout(itemLayout);

            // 将自定义控件设置为列表项的 widget
            listWidget->setItemWidget(item, itemWidget);
        }
    }

private slots:
    void loadItemFunction(int itemIndex) {
        // 执行加载项目的逻辑
        qDebug() << "加载项目: " << itemIndex;
    }

private:
    std::vector<std::string> filelist;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void openItemListWindow() {
        // 创建并显示新窗口
        std::vector<std::string> list = {"Project 1", "Project 2", "Project 3"};
        ItemListWindow *window = new ItemListWindow(nullptr, list);
        window->setWindowTitle("项目列表");
        window->resize(400, 300);
        window->exec(); // 使用 exec() 使其成为模态对话框
    }
};
#endif // MAINWINDOW_H
