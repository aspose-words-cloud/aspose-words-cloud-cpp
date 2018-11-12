//PutDocumentSaveAsTiffRequest.h
#include "cpprest/details/basic_types.h"
#undef U
#include "TiffSaveOptionsData.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutDocumentSaveAsTiffRequest{
    public: 
    PutDocumentSaveAsTiffRequest(
        utility::string_t name,
                std::shared_ptr<TiffSaveOptionsData> saveOptions,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> resultFile,
                boost::optional<bool> useAntiAliasing,
                boost::optional<bool> useHighQualityRendering,
                boost::optional<double> imageBrightness,
                boost::optional<utility::string_t> imageColorMode,
                boost::optional<double> imageContrast,
                boost::optional<utility::string_t> numeralFormat,
                boost::optional<int32_t> pageCount,
                boost::optional<int32_t> pageIndex,
                boost::optional<utility::string_t> paperColor,
                boost::optional<utility::string_t> pixelFormat,
                boost::optional<double> resolution,
                boost::optional<double> scale,
                boost::optional<utility::string_t> tiffCompression,
                boost::optional<utility::string_t> dmlRenderingMode,
                boost::optional<utility::string_t> dmlEffectsRenderingMode,
                boost::optional<utility::string_t> tiffBinarizationMethod,
                boost::optional<bool> zipOutput,
                boost::optional<utility::string_t> fontsLocation
        );

    public:
        utility::string_t name;
        std::shared_ptr<TiffSaveOptionsData> saveOptions;
        boost::optional<utility::string_t> folder;
        boost::optional<utility::string_t> storage;
        boost::optional<utility::string_t> loadEncoding;
        boost::optional<utility::string_t> password;
        boost::optional<utility::string_t> destFileName;
        boost::optional<utility::string_t> resultFile;
        boost::optional<bool> useAntiAliasing;
        boost::optional<bool> useHighQualityRendering;
        boost::optional<double> imageBrightness;
        boost::optional<utility::string_t> imageColorMode;
        boost::optional<double> imageContrast;
        boost::optional<utility::string_t> numeralFormat;
        boost::optional<int32_t> pageCount;
        boost::optional<int32_t> pageIndex;
        boost::optional<utility::string_t> paperColor;
        boost::optional<utility::string_t> pixelFormat;
        boost::optional<double> resolution;
        boost::optional<double> scale;
        boost::optional<utility::string_t> tiffCompression;
        boost::optional<utility::string_t> dmlRenderingMode;
        boost::optional<utility::string_t> dmlEffectsRenderingMode;
        boost::optional<utility::string_t> tiffBinarizationMethod;
        boost::optional<bool> zipOutput;
        boost::optional<utility::string_t> fontsLocation;
};

}
}
}
}
