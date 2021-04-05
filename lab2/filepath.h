#ifndef FILEPATH_H
#define FILEPATH_H
#include <string>
#include <fstream>

/*!
*   \brief Class with addition file functions
*/
class FilePath
{
public:
    static const std::string sorting_diagram_log_file;/*!< Path of log file of sorting diagram*/
    /*!
    *   \brief Returns size of file
    */
    static std::size_t count_size(const std::string& path);
    /*!
    *   \brief Clears file
    */
    static void clear_file(const std::string& path);
};

#endif // FILEPATH_H
