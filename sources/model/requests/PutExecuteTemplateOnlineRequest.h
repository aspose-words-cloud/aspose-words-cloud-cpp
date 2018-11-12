//PutExecuteTemplateOnlineRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "HttpContent.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutExecuteTemplateOnlineRequest{
    public: 
    PutExecuteTemplateOnlineRequest(
        std::shared_ptr<HttpContent> _template,
                std::shared_ptr<HttpContent> data,
                boost::optional<utility::string_t> cleanup,
                boost::optional<bool> useWholeParagraphAsRegion,
                boost::optional<bool> withRegions,
                boost::optional<utility::string_t> documentFileName
        );

    public:
        std::shared_ptr<HttpContent> _template;
        std::shared_ptr<HttpContent> data;
        boost::optional<utility::string_t> cleanup;
        boost::optional<bool> useWholeParagraphAsRegion;
        boost::optional<bool> withRegions;
        boost::optional<utility::string_t> documentFileName;
};

}
}
}
}
