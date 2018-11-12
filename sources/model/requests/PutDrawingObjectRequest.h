//PutDrawingObjectRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "HttpContent.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutDrawingObjectRequest{
    public: 
    PutDrawingObjectRequest(
        utility::string_t name,
                utility::string_t drawingObject,
                std::shared_ptr<HttpContent> imageFile,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> nodePath
        );

    public:
        utility::string_t name;
        utility::string_t drawingObject;
        std::shared_ptr<HttpContent> imageFile;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
        boost::optional<utility::string_t> revisionAuthor;
        boost::optional<utility::string_t> revisionDateTime;
        boost::optional<utility::string_t> nodePath;
};

}
}
}
}
