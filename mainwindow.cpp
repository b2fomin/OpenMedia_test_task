#include "mainwindow.h"
#include <QFileDialog>
#include <QRegularExpressionValidator>
#include <QToolTip>
#include "ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression regExp;
    regExp.setPattern("/^[a-zA-Z]:\\\\(?:\\w+\\\\?)*$/");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator{regExp, this};
    ui->firstLine->setValidator(validator);
    ui->secondLine->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::find_dublicates(fs::path &first_dir, fs::path &second_dir)
{
    QStringList res;
    fs::recursive_directory_iterator first_it{first_dir};
    fs::recursive_directory_iterator second_it{second_dir};
    for (const auto &first_path : first_it) {
        if (first_path.is_directory())
            continue;
        std::ifstream first_stream{first_path.path().string(), std::ios::binary};
        for (const auto &second_path : second_it) {
            if (second_path.is_directory())
                continue;
            std::ifstream second_stream{second_path.path().string(), std::ios::binary};
            bool equal = true;
            do {
                if (first_stream.get() != second_stream.get()) {
                    equal = false;
                    break;
                }
            } while (!first_stream.eof() && !second_stream.eof());

            if (!first_stream.eof() || !second_stream.eof()) {
                equal = false;
            }
            if (equal) {
                res.push_back(QString(first_path.path().filename().string().data()));
            }
        }
    }

    return res;
}

void MainWindow::update_list()
{
    ui->listOfDuplicates->clear();
    if (ui->firstLine->text().isEmpty() || ui->secondLine->text().isEmpty())
        return;
    fs::path first_path{ui->firstLine->text().toStdString()};
    fs::path second_path{ui->secondLine->text().toStdString()};
    auto duplicates = find_dublicates(first_path, second_path);
    ui->listOfDuplicates->addItems(duplicates);
}

void MainWindow::on_firstButton_clicked()
{
    ui->firstLine->setText(QFileDialog::getExistingDirectory(this, "Choose a folder", "."));
    update_list();
}

void MainWindow::on_secondButton_clicked()
{
    ui->secondLine->setText(QFileDialog::getExistingDirectory(this, "Choose a folder", "."));
    update_list();
}

void MainWindow::on_firstLine_inputRejected()
{
    ui->firstLine->setText(ui->firstLine->text());
    QPoint point = QPoint(geometry().left() + ui->firstLine->geometry().left(),
                          geometry().top() + ui->firstLine->geometry().bottom());

    QToolTip::showText(point, "Invalid address");
}

void MainWindow::on_secondLine_inputRejected()
{
    ui->secondLine->setText(ui->secondLine->text());
    QPoint point = QPoint(geometry().left() + ui->secondLine->geometry().left(),
                          geometry().top() + ui->secondLine->geometry().bottom());

    QToolTip::showText(point, "Invalid address");
}

void MainWindow::on_firstLine_editingFinished()
{
    update_list();
}

void MainWindow::on_secondLine_editingFinished()
{
    update_list();
}
