//InsertTableRowRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "TableRowInsert.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class InsertTableRowRequest{
    public: 
    InsertTableRowRequest(
        utility::string_t name,
                utility::string_t tablePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<std::shared_ptr<TableRowInsert>> row
        );

    public:
        utility::string_t name;
        utility::string_t tablePath;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
        boost::optional<utility::string_t> revisionAuthor;
        boost::optional<utility::string_t> revisionDateTime;
        boost::optional<std::shared_ptr<TableRowInsert>> row;
};

}
}
}
}
