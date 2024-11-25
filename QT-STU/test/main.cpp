#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QListWidget>
#include <QHBoxLayout>
#include <QDialog>
#include <QMessageBox>

class ItemListWindow : public QDialog {
    Q_OBJECT

public:
    ItemListWindow(QWidget *parent = nullptr) : QDialog(parent) {
        // 设置主窗口的布局
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        // 上半部分的 QLabel 提示词
        QLabel *label = new QLabel("请选择一个项目进行加载", this);
        mainLayout->addWidget(label);

        // 下半部分的 QListWidget
        QListWidget *listWidget = new QListWidget(this);
        mainLayout->addWidget(listWidget);

        // 向列表中添加项目并为每个项目创建一个按钮
        for (int i = 1; i <= 5; ++i) {
            // 为每个项添加文字和按钮
            QListWidgetItem *item = new QListWidgetItem("项目 " + QString::number(i));
            QWidget *itemWidget = new QWidget();
            QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);

            QLabel *itemLabel = new QLabel("项目 " + QString::number(i), itemWidget);
            QPushButton *loadButton = new QPushButton("载入", itemWidget);
            connect(loadButton, &QPushButton::clicked, [i]() {
                loadItemFunction(i);  // 这里绑定函数
            });

            itemLayout->addWidget(itemLabel);
            itemLayout->addWidget(loadButton);
            itemWidget->setLayout(itemLayout);

            listWidget->setItemWidget(item, itemWidget);
        }
    }

private:
    void loadItemFunction(int itemIndex) {
        QMessageBox::information(this, "Action", "加载了项目: " + QString::number(itemIndex));
    }
};

// 主窗口
class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // 设置布局
        QVBoxLayout *layout = new QVBoxLayout(this);

        // 创建按钮并连接到弹出窗口
        QPushButton *openWindowButton = new QPushButton("打开项目列表", this);
        connect(openWindowButton, &QPushButton::clicked, this, &MainWindow::openItemListWindow);

        layout->addWidget(openWindowButton);
        setLayout(layout);
    }

private slots:
    void openItemListWindow() {
        // 创建并显示新窗口
        ItemListWindow *window = new ItemListWindow();
        window->setWindowTitle("项目加载");
        window->resize(400, 300);
        window->exec(); // 使用 exec() 使其成为模态对话框
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("主窗口");
    window.resize(300, 200);
    window.show();

    return app.exec();
}

#include "main.moc"
