//GetDocumentParagraphRunsRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class GetDocumentParagraphRunsRequest{
    public: 
    GetDocumentParagraphRunsRequest(
        utility::string_t name,
                utility::string_t paragraphPath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        );

    public:
        utility::string_t name;
        utility::string_t paragraphPath;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
};

}
}
}
}
