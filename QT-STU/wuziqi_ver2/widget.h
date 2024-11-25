#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QListWidget>
#include <QHBoxLayout>
#include <QDialog>
#include <QMessageBox>
#include "ut-files.h"
#include "board.h"


///// 登录界面和设计界面
///

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pvp_clicked();

    void on_load_clicked();

private:
    Ui::Widget *ui;
    /// 为什么不是Ui::
    Board *board;
    void openGame(std::string oldfiles);
};

/**
 * @brief The ItemListWindow class
 * 用来加载文件列表的窗口，因为是根据文件多少动态的不能写死
 * 可视化就不好用了
 * 只能自己写
 */

class ItemListWindow : public QDialog {
    Q_OBJECT

public:
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
            // 为每个项添加文字和按钮
            qDebug() << "成功加载到项目 " << QString::fromStdString(filelist[i]);

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
        qDebug() << "加载项目: " << itemIndex;
        // 在这里执行加载项目的代码
    }

private:
    std::vector<std::string> filelist;
};


class WifiListWidget : public QListWidget
{
public:
    WifiListWidget(QWidget* parent = nullptr) : QListWidget(parent)
    {
        // 设置列表的显示模式为Icon模式
        setViewMode(QListView::IconMode);
        setIconSize(QSize(200, 50));

        // 设置每一页最多显示4个项，并禁用滚动条
        setFlow(QListView::TopToBottom);
        setWrapping(true);
        setResizeMode(QListView::Adjust);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        // 添加示例项
        QPixmap signalIcon(":/wifi_signal.png");
        QPixmap lockIcon(":/wifi_lock.png");

        for (int i = 0; i < 10; ++i)
        {
            QString name = QString("Wifi %1").arg(i + 1);

            // 创建信号标签
            QLabel* signalLabel = new QLabel;
            signalLabel->setPixmap(signalIcon.scaled(20, 20, Qt::KeepAspectRatio));

            // 创建Wi-Fi名称标签
            QLabel* nameLabel = new QLabel("name");

            // 创建锁标签
            QLabel* lockLabel = new QLabel;
            lockLabel->setPixmap(lockIcon.scaled(20, 20, Qt::KeepAspectRatio));

            // 创建布局并添加控件
            QHBoxLayout* layout = new QHBoxLayout;
            layout->addWidget(signalLabel);
            layout->addWidget(nameLabel);
            layout->addWidget(lockLabel);
            layout->addStretch(); // 添加弹性空间以调整控件位置

            // 创建小部件用于承载布局
            QWidget* widget = new QWidget;
            widget->setLayout(layout);

            // 创建并设置列表项
            QListWidgetItem* item = new QListWidgetItem;
            item->setSizeHint(QSize(200, 50)); // 设置项的显示大小
            setItemWidget(item, widget); // 将自定义控件设置为列表项的显示部件

            // 将项添加到列表中
            addItem(item);
        }
    }
};

#endif // WIDGET_H
