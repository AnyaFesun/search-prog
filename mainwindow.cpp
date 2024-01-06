#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtWidgets>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "gradualmethod.h"
#include "methodfibonacci.h"
#include "interpolationsearch.h"
#include "hashsearch.h"
#include <vector>
#include "tools.h"
using namespace std;


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

void MainWindow::on_ButtonGenerateArray_clicked()
{
    QString input_size = ui->size->text();

    int size;
    try{
        tools::check_int(input_size);
        size = input_size.toInt();
        if (size < 1000) {
            throw "Мінімальний розмір масиву 1000!";
        }
        if (size > 30000) {
            throw "Максимальний допустимий розмір масиву 30 тис!";
        }
    }
    catch (const char* message){
        QMessageBox::warning(this, "Невірний ввід",  message);
        return;
    }

    vector<int> array = tools::generate_sorted_array(size);

    QString text = tools::vector_to_string(array);

    QTextEdit* textEdit = new QTextEdit();
    textEdit->setPlainText(text);
    textEdit->setReadOnly(true);
    ui->scrollArea->setWidget(textEdit);
}


void MainWindow::on_ButtonSearch_clicked()
{
    QString input_key = ui->search_key->text();

    int search_key;
    try{
        tools::check_int(input_key);
        search_key = input_key.toInt();
        if(!ui->checkGradualMethod->isChecked() && !ui->checkMethodFibonacci->isChecked()
            && !ui->checkInterpolationSearch->isChecked()&& !ui->checkHashSearch->isChecked())
            throw "Не вибрано жоден з методів!";

        if (ui->scrollArea->widget() &&  ui->scrollArea->widget()->children().isEmpty())
             throw "Покищо не задано масив! Згенеруйте масив!";
    }
    catch (const char* message){
        QMessageBox::warning(this, "Помилка!",  message);
        return;
    }


    QWidget* viewport = ui->scrollArea->viewport();
    QTextEdit* textEdit = viewport->findChild<QTextEdit*>();
    QString text = textEdit->toPlainText();
    vector<int> array = tools::string_to_vector(text);

    QString search_issue = check_Methods_Chosen(search_key, array);

    QTextEdit* textEdit_2 = new QTextEdit();
    textEdit_2->setPlainText(search_issue);
    textEdit_2->setReadOnly(true);
    ui->scrollAreaResults->setWidget(textEdit_2);

    search_issue += text;
    tools::write_results_to_file(search_issue);
}

QString MainWindow::check_Methods_Chosen(int search_key, vector<int> array){
    QString search_issue = "Шукане число: " + QString::number(search_key) + "\n";
    if(ui->checkGradualMethod->isChecked()){
        GradualMethod gradual;
        search_issue += "\nПослідовний метод: " + tools::search_res_to_string(gradual.Search(array, search_key));
        search_issue += tools::comparison_res_to_string(gradual.GetComparisons());
    }

    if(ui->checkMethodFibonacci->isChecked()){
        MethodFibonacci fibonacci;
        search_issue += "\nПошук Фібоначчі: " +  tools::search_res_to_string(fibonacci.Search(array, search_key));
        search_issue += tools::comparison_res_to_string(fibonacci.GetComparisons());
    }

    if(ui->checkInterpolationSearch->isChecked()){
        InterpolationSearch interpolisation;
        search_issue += "\nІнтерполяційний пошук: " + tools::search_res_to_string(interpolisation.Search(array, search_key));
        search_issue += tools::comparison_res_to_string(interpolisation.GetComparisons());
    }

    if(ui->checkHashSearch->isChecked()){
        HashSearch hashsearch;
        search_issue += "\nМетодом Хеш-функції: " + tools::search_res_to_string(hashsearch.Search(array, search_key));
        search_issue += tools::comparison_res_to_string(hashsearch.GetComparisons());
    }

    return search_issue;
}


