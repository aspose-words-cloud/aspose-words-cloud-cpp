//PostUpdateDocumentBookmarkRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "BookmarkData.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PostUpdateDocumentBookmarkRequest{
    public: 
    PostUpdateDocumentBookmarkRequest(
        utility::string_t name,
                std::shared_ptr<BookmarkData> bookmarkData,
                utility::string_t bookmarkName,
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
        std::shared_ptr<BookmarkData> bookmarkData;
        utility::string_t bookmarkName;
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
