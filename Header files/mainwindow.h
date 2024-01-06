#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>
#include <QString>
#include <vector>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonGenerateArray_clicked();
    void on_ButtonSearch_clicked();

    QString check_Methods_Chosen(int search_key, vector<int> array);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
