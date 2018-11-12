//CreateOrUpdateDocumentPropertyRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "DocumentProperty.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class CreateOrUpdateDocumentPropertyRequest{
    public: 
    CreateOrUpdateDocumentPropertyRequest(
        utility::string_t name,
                utility::string_t propertyName,
                std::shared_ptr<DocumentProperty> property,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        );

    public:
        utility::string_t name;
        utility::string_t propertyName;
        std::shared_ptr<DocumentProperty> property;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
        boost::optional<utility::string_t> revisionAuthor;
        boost::optional<utility::string_t> revisionDateTime;
};

}
}
}
}
