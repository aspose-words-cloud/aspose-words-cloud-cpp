/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsTiffRequest.h">
*   Copyright (c) 2019 Aspose.Words for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/
#pragma once
#ifndef _H
#define _H 

#include "cpprest/details/basic_types.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class SaveAsTiffRequest{
    public: 
     SaveAsTiffRequest(
                                                  boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<>                 boost::optional<> 
        );

         getName() const;
        void setName( );

         getSaveOptions() const;
        void setSaveOptions( );

        boost::optional<> getFolder() const;
        void setFolder(boost::optional<> );

        boost::optional<> getStorage() const;
        void setStorage(boost::optional<> );

        boost::optional<> getLoadEncoding() const;
        void setLoadEncoding(boost::optional<> );

        boost::optional<> getPassword() const;
        void setPassword(boost::optional<> );

        boost::optional<> getUseAntiAliasing() const;
        void setUseAntiAliasing(boost::optional<> );

        boost::optional<> getUseHighQualityRendering() const;
        void setUseHighQualityRendering(boost::optional<> );

        boost::optional<> getImageBrightness() const;
        void setImageBrightness(boost::optional<> );

        boost::optional<> getImageColorMode() const;
        void setImageColorMode(boost::optional<> );

        boost::optional<> getImageContrast() const;
        void setImageContrast(boost::optional<> );

        boost::optional<> getNumeralFormat() const;
        void setNumeralFormat(boost::optional<> );

        boost::optional<> getPageCount() const;
        void setPageCount(boost::optional<> );

        boost::optional<> getPageIndex() const;
        void setPageIndex(boost::optional<> );

        boost::optional<> getPaperColor() const;
        void setPaperColor(boost::optional<> );

        boost::optional<> getPixelFormat() const;
        void setPixelFormat(boost::optional<> );

        boost::optional<> getResolution() const;
        void setResolution(boost::optional<> );

        boost::optional<> getScale() const;
        void setScale(boost::optional<> );

        boost::optional<> getTiffCompression() const;
        void setTiffCompression(boost::optional<> );

        boost::optional<> getDmlRenderingMode() const;
        void setDmlRenderingMode(boost::optional<> );

        boost::optional<> getDmlEffectsRenderingMode() const;
        void setDmlEffectsRenderingMode(boost::optional<> );

        boost::optional<> getTiffBinarizationMethod() const;
        void setTiffBinarizationMethod(boost::optional<> );

        boost::optional<> getZipOutput() const;
        void setZipOutput(boost::optional<> );

        boost::optional<> getFontsLocation() const;
        void setFontsLocation(boost::optional<> );
    private:
         m_;
         m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
        boost::optional<> m_;
};

}
}
}
}
}

#endif
