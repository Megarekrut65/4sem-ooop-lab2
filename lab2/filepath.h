#ifndef FILEPATH_H
#define FILEPATH_H
#include <string>
#include <fstream>
class FilePath
{
public:
    static std::string sorting_diagram_log_file;
    static std::size_t count_size(const std::string& path);
    static std::size_t clear_file(const std::string& path);
};

#endif // FILEPATH_H
