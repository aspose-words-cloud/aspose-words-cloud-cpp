//PostDocumentSaveAsRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "SaveOptionsData.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PostDocumentSaveAsRequest{
    public: 
    PostDocumentSaveAsRequest(
        utility::string_t name,
                std::shared_ptr<SaveOptionsData> saveOptionsData,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> fontsLocation
        );

    public:
        utility::string_t name;
        std::shared_ptr<SaveOptionsData> saveOptionsData;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
        boost::optional<utility::string_t> fontsLocation;
};

}
}
}
}
