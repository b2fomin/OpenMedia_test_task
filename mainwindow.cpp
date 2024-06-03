#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

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

std::vector<std::string> MainWindow::find_dublicates(std::vector<fs::path> &first_arr,
                                                     std::vector<fs::path> &second_arr)
{
    std::vector<std::string> res;
    for (auto &first_path : first_arr) {
        std::ifstream first_stream{first_path.string(), std::ios::binary};
        for (auto &second_path : second_arr) {
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
