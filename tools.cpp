#include "tools.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QtCore/QRandomGenerator>
#include <vector>
#include <algorithm>
#include <random>
#include <QTextStream>
using namespace std;


 vector<int> tools::string_to_vector(const QString& input) {
    vector<int> result;
    QTextStream stream(const_cast<QString*>(&input));

    while (!stream.atEnd()) {
            QString item;
            stream >> item;
            item = item.trimmed();

            if (!item.isEmpty()) {
                int value = item.toInt();
                result.push_back(value);
            }
    }

    return result;
 }

void tools::write_results_to_file(QString results){
    QString filePath = "results.txt";

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << results;
        file.close();
    }
}

QString tools::get_output_from_file(){
    QString filePath = "output.txt";

    QString output;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        output = in.readAll();
        file.close();
    }
    return output;
}



QString tools::search_res_to_string(int result){
    if (result != -1){
        return QString::number(result) + "\n";
    }
    else{
        return "шукане число відсутнє в масиві!\n";
    }
}

QString tools::comparison_res_to_string(int comp){
    return "Кількість порівнянь: " + QString::number(comp) + "\n";
}

vector<int> tools::generate_sorted_array(int new_size) {
    vector<int> new_arr;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 80000);

    for (int i = 0; i < new_size; i++) {
        int new_num;
        bool unique;

        do {
            new_num = dist(gen);
            unique = true;

            for (int a = 0; a < i; a++) {
                if (new_arr[a] == new_num) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);

        new_arr.push_back(new_num);
    }

    std::sort(new_arr.begin(), new_arr.end());

    return new_arr;
}

QString tools::vector_to_string(vector<int> A) {
    QString str_array;
    for (int i = 0; i < A.size(); i++) {
        str_array += QString::number(A[i]);
        str_array += " ";
    }
    return str_array;
}

void tools::check_int(QString input) {
    if (input.isEmpty())
        throw "Рядкок пустий! Введіть число";


    for (int i = 0; i < input.length(); i++) {
        if (!input[i].isDigit()) {

            if (i == 0 && input[i] == '-') {
                continue;
            } else if(input[i] == ' '){
                for (i; i < input.length(); i++){
                    if(input[i] != ' '){
                        throw "Рядок введено невірно!";
                    }
                }
                break;
            }else {
                throw "Рядок введено невірно!";
            }
        }

    }
}
