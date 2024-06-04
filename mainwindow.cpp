#include "mainwindow.h"
#include <QFileDialog>
#include <QRegularExpressionValidator>
#include <QToolTip>
#include "ui_mainwindow.h"
#include <fstream>
#include <iterator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QRegularExpression regExp;
    // regExp.setPattern("^?:[a-zA-Z]\:|\\\\[\w\s\.]+\\[\w\s\.$]+)\\(?:[\w\s\.]+\\)*)(?<BaseName>[\w\s\.]*?)$");
    // QRegularExpressionValidator *validator = new QRegularExpressionValidator{regExp, this};
    // ui->firstLine->setValidator(validator);
    // ui->secondLine->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::find_dublicates(fs::path &first_dir, fs::path &second_dir)
{
    fs::recursive_directory_iterator begin_first{first_dir}, end_first;
    std::size_t first_count = std::distance(begin_first, end_first) - 1;

    fs::recursive_directory_iterator begin_second{second_dir}, end_second;
    std::size_t second_count = std::distance(begin_second, end_second) - 1;

    if (!first_count || !second_count) {
        return QStringList{};
    }

    std::size_t count = first_count * second_count;
    ui->progressBar->setMaximum(count);

    QStringList res;
    fs::recursive_directory_iterator first_it{first_dir};

    for (const auto &first_path : first_it) {
        if (fs::is_directory(first_path.status())) {
            ui->progressBar->setValue(ui->progressBar->value() + second_count);
            continue;
        }
        std::ifstream first_stream{first_path.path().string(), std::ios::binary};
        fs::recursive_directory_iterator second_it{second_dir};
        for (const auto &second_path : second_it) {
            ui->progressBar->setValue(ui->progressBar->value() + 1);
            if (fs::is_directory(second_path.status()))
                continue;
            std::ifstream second_stream{second_path.path().string(), std::ios::binary};
            auto filename = QString(first_path.path().filename().string().data());
            if (fs::file_size(first_path.path()) == fs::file_size(second_path.path())
                && !res.contains(filename)
                && std::equal(std::istreambuf_iterator<char>(first_stream.rdbuf()),
                              std::istreambuf_iterator<char>(),
                              std::istreambuf_iterator<char>(second_stream.rdbuf()))) {
                res.push_back(filename);
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
    if (!fs::exists(first_path) || !fs::exists(second_path))
        return;
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

// void MainWindow::on_firstLine_inputRejected()
// {
//     ui->firstLine->setText(ui->firstLine->text());
//     QPoint point = QPoint(geometry().left() + ui->firstLine->geometry().left(),
//                           geometry().top() + ui->firstLine->geometry().bottom());

//     QToolTip::showText(point, "Invalid address");
// }

// void MainWindow::on_secondLine_inputRejected()
// {
//     QPoint point = QPoint(geometry().left() + ui->secondLine->geometry().left(),
//                           geometry().top() + ui->secondLine->geometry().bottom());

//     QToolTip::showText(point, "Invalid address");
// }

void MainWindow::on_firstLine_editingFinished()
{
    update_list();
}

void MainWindow::on_secondLine_editingFinished()
{
    update_list();
}
