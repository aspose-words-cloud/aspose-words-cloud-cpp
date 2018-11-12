//GetHeaderFooterOfSectionRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class GetHeaderFooterOfSectionRequest{
    public: 
    GetHeaderFooterOfSectionRequest(
        utility::string_t name,
                int32_t headerFooterIndex,
                int32_t sectionIndex,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> filterByType
        );

    public:
        utility::string_t name;
        int32_t headerFooterIndex;
        int32_t sectionIndex;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> filterByType;
};

}
}
}
}
