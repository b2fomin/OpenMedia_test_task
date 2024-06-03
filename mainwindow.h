#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <filesystem>
#include <string>
#include <vector>
namespace fs = std::filesystem;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //public methods
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // private fields
private:
    Ui::MainWindow *ui;
    // private methods
private:
    std::vector<std::string> find_dublicates(std::vector<fs::path> &first,
                                             std::vector<fs::path> &second);
};
#endif // MAINWINDOW_H
