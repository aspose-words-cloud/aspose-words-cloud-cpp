//PutFieldRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "Field.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutFieldRequest{
    public: 
    PutFieldRequest(
        utility::string_t name,
                std::shared_ptr<Field> field,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> nodePath,
                boost::optional<utility::string_t> insertBeforeNode
        );

    public:
        utility::string_t name;
        std::shared_ptr<Field> field;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
        boost::optional<utility::string_t> revisionAuthor;
        boost::optional<utility::string_t> revisionDateTime;
        boost::optional<utility::string_t> nodePath;
        boost::optional<utility::string_t> insertBeforeNode;
};

}
}
}
}
