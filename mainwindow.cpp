#include "mainwindow.h"
#include <QFileDialog>
#include "ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<std::string> MainWindow::find_dublicates(std::vector<fs::path> &first_dir,
                                                     std::vector<fs::path> &second_dir)
{
    std::vector<std::string> res;
    for (auto &first_path : first_dir) {
        std::ifstream first_stream{first_path.string(), std::ios::binary};
        for (auto &second_path : second_dir) {
            std::ifstream second_stream{second_path.string(), std::ios::binary};
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
                res.push_back(first_path.filename());
            }
        }
    }

    return res;
}

void MainWindow::update_list()
{
    ui->listOfDuplicates->clear();
    fs::path first_path{ui->firstLine->text()};
    fs::path second_path{ui->secondLine->text()};
    auto duplicates = find_dublicates(first_path, second_path);
    ui->listOfDuplicates->addItems(duplicates);
}
