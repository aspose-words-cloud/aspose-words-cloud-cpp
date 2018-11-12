//PostCompareDocumentRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "CompareData.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PostCompareDocumentRequest{
    public: 
    PostCompareDocumentRequest(
        utility::string_t name,
                std::shared_ptr<CompareData> compareData,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        );

    public:
        utility::string_t name;
        std::shared_ptr<CompareData> compareData;
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
