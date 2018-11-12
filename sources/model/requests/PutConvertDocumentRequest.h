//PutConvertDocumentRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "HttpContent.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutConvertDocumentRequest{
    public: 
    PutConvertDocumentRequest(
        std::shared_ptr<HttpContent> document,
                utility::string_t format,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> outPath,
                boost::optional<utility::string_t> documentFileName,
                boost::optional<utility::string_t> fontsLocation
        );

    public:
        std::shared_ptr<HttpContent> document;
        utility::string_t format;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> outPath;
        boost::optional<utility::string_t> documentFileName;
        boost::optional<utility::string_t> fontsLocation;
};

}
}
}
}
