#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <QString>
using namespace std;

namespace tools {
    void write_results_to_file(QString results);
    QString get_output_from_file();

    QString search_res_to_string(int result);
    QString comparison_res_to_string(int result);

    QString vector_to_string(vector<int> A);
    vector<int> generate_sorted_array(int new_size);
    vector<int> string_to_vector(const QString& input);

    void check_int(QString input);
}

#endif // TOOLS_H
