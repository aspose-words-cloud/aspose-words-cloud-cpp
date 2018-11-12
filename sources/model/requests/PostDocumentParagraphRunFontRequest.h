//PostDocumentParagraphRunFontRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "Font.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PostDocumentParagraphRunFontRequest{
    public: 
    PostDocumentParagraphRunFontRequest(
        utility::string_t name,
                std::shared_ptr<Font> fontDto,
                utility::string_t paragraphPath,
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
        std::shared_ptr<Font> fontDto;
        utility::string_t paragraphPath;
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
