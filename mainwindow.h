#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

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
private slots:
    void on_firstButton_clicked();

    void on_secondButton_clicked();

    void on_firstLine_inputRejected();

    void on_secondLine_inputRejected();

    void on_firstLine_editingFinished();

    void on_secondLine_editingFinished();

private:
    Ui::MainWindow *ui;
    // private methods
private:
    QStringList find_dublicates(fs::path &first_dir, fs::path &second_dir);
    void update_list();
};
#endif // MAINWINDOW_H
