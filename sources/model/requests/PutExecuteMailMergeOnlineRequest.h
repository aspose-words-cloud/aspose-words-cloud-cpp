//PutExecuteMailMergeOnlineRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "HttpContent.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutExecuteMailMergeOnlineRequest{
    public: 
    PutExecuteMailMergeOnlineRequest(
        std::shared_ptr<HttpContent> _template,
                std::shared_ptr<HttpContent> data,
                boost::optional<bool> withRegions,
                boost::optional<utility::string_t> cleanup,
                boost::optional<utility::string_t> documentFileName
        );

    public:
        std::shared_ptr<HttpContent> _template;
        std::shared_ptr<HttpContent> data;
        boost::optional<bool> withRegions;
        boost::optional<utility::string_t> cleanup;
        boost::optional<utility::string_t> documentFileName;
};

}
}
}
}
