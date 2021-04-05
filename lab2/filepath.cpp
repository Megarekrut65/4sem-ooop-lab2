#include "filepath.h"

const std::string FilePath::sorting_diagram_log_file = "Logs/sorting_diagram_log.txt";
std::size_t FilePath::count_size(const std::string& path)
{
    std::ifstream file(path);
    file.seekg(0, std::ios_base::end);
    std::size_t sizef = size_t(file.tellg());
    file.close();
    return sizef;
}
void FilePath::clear_file(const std::string& path)
{
    std::ofstream file(path);
    file.close();
}
