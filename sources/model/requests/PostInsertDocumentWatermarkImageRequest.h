//PostInsertDocumentWatermarkImageRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "HttpContent.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PostInsertDocumentWatermarkImageRequest{
    public: 
    PostInsertDocumentWatermarkImageRequest(
        utility::string_t name,
                boost::optional<std::shared_ptr<HttpContent>> imageFile,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<double> rotationAngle,
                boost::optional<utility::string_t> image
        );

    public:
        utility::string_t name;
        boost::optional<std::shared_ptr<HttpContent>> imageFile;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
        boost::optional<utility::string_t> revisionAuthor;
        boost::optional<utility::string_t> revisionDateTime;
        boost::optional<double> rotationAngle;
        boost::optional<utility::string_t> image;
};

}
}
}
}
