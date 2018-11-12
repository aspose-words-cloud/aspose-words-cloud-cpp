//PostChangeDocumentProtectionRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "ProtectionRequest.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PostChangeDocumentProtectionRequest{
    public: 
    PostChangeDocumentProtectionRequest(
        utility::string_t name,
                std::shared_ptr<ProtectionRequest> protectionRequest,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        );

    public:
        utility::string_t name;
        std::shared_ptr<ProtectionRequest> protectionRequest;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
};

}
}
}
}
