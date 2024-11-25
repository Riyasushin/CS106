// #include "widget.h"

#include "qboxlayout.h"
#include "qlabel.h"
#include "qlistwidget.h"
#include <QApplication>
#include <QToolButton>
#include "QtWidgets"

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     // Widget w;
//     // w.show();

//     // 创建主窗口
//     QWidget window;
//     window.setWindowTitle("Wifi List");

//     // 创建列表控件
//     WifiListWidget* listWidget = new WifiListWidget(&window);
//     listWidget->setGeometry(10, 10, 220, 230);

//     // 创建翻页按钮
//     QToolButton* prevButton = new QToolButton(&window);
//     prevButton->setIcon(QIcon(":/prev_page.png"));
//     prevButton->setGeometry(10, 250, 30, 30);

//     QToolButton* nextButton = new QToolButton(&window);
//     nextButton->setIcon(QIcon(":/next_page.png"));
//     nextButton->setGeometry(200, 250, 30, 30);

//     window.show();


//     return a.exec();
// }


class WifiListItem : public QListWidgetItem
{
public:
    WifiListItem(const QString name, const QPixmap signalIcon, const QPixmap lockIcon)
    {
        // 设置列表项的大小
        setSizeHint(QSize(200, 50));

        // 创建列表项中的控件
        QLabel* signalLabel = new QLabel;
        signalLabel->setPixmap(signalIcon.scaled(20, 20, Qt::KeepAspectRatio));
        QLabel* nameLabel = new QLabel(name);
        QLabel* lockLabel = new QLabel;
        lockLabel->setPixmap(lockIcon.scaled(20, 20, Qt::KeepAspectRatio));

        // 创建布局
        QHBoxLayout* layout = new QHBoxLayout;
        layout->addWidget(signalLabel);
        layout->addWidget(nameLabel);
        layout->addWidget(lockLabel);
        layout->addStretch();

        // 创建一个小部件，用于放置布局
        QWidget* widget = new QWidget;
        widget->setLayout(layout);

        // 设置列表项的小部件
        widget->setLayout(layout);
    }
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
            QString name = QString::fromStdString("hhhhhhhhhhhhhh");
            WifiListItem* item = new WifiListItem(name, signalIcon, lockIcon);
            addItem(item);

        }
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("Wifi List");

    // 创建列表控件
    WifiListWidget* listWidget = new WifiListWidget(&window);
    listWidget->setGeometry(10, 10, 220, 230);

    // // 创建翻页按钮
    // QToolButton* prevButton = new QToolButton(&window);
    // prevButton->setIcon(QIcon(":/prev_page.png"));
    // prevButton->setGeometry(10, 250, 30, 30);

    // QToolButton* nextButton = new QToolButton(&window);
    // nextButton->setIcon(QIcon(":/next_page.png"));
    // nextButton->setGeometry(200, 250, 30, 30);

    window.show();
    return app.exec();
}

