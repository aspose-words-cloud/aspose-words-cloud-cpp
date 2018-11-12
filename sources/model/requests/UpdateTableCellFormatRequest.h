//UpdateTableCellFormatRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "TableCellFormat.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class UpdateTableCellFormatRequest{
    public: 
    UpdateTableCellFormatRequest(
        utility::string_t name,
                utility::string_t tableRowPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<std::shared_ptr<TableCellFormat>> format
        );

    public:
        utility::string_t name;
        utility::string_t tableRowPath;
        int32_t index;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
        boost::optional<utility::string_t> revisionAuthor;
        boost::optional<utility::string_t> revisionDateTime;
        boost::optional<std::shared_ptr<TableCellFormat>> format;
};

}
}
}
}
