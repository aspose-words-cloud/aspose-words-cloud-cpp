//UpdateBorderRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "Border.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class UpdateBorderRequest{
    public: 
    UpdateBorderRequest(
        utility::string_t name,
                std::shared_ptr<Border> borderProperties,
                utility::string_t nodePath,
                int32_t index,
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
        std::shared_ptr<Border> borderProperties;
        utility::string_t nodePath;
        int32_t index;
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
