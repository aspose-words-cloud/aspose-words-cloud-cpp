//PostExecuteTemplateRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PostExecuteTemplateRequest{
    public: 
    PostExecuteTemplateRequest(
        utility::string_t name,
                utility::string_t data,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> cleanup,
                boost::optional<bool> useWholeParagraphAsRegion,
                boost::optional<bool> withRegions,
                boost::optional<utility::string_t> destFileName
        );

    public:
        utility::string_t name;
        utility::string_t data;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> cleanup;
        boost::optional<bool> useWholeParagraphAsRegion;
        boost::optional<bool> withRegions;
        boost::optional<utility::string_t> destFileName;
};

}
}
}
}
