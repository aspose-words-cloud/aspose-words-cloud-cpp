//GetAvailableFontsRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class GetAvailableFontsRequest{
    public: 
    GetAvailableFontsRequest(
        boost::optional<utility::string_t> fontsLocation
        );

    public:
        boost::optional<utility::string_t> fontsLocation;
};

}
}
}
}
