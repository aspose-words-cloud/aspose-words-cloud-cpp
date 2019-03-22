
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XamlFixedSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_XamlFixedSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_XamlFixedSaveOptionsData_H_


#include "MetafileRenderingOptionsData.h"
#include "FixedPageSaveOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for xaml fixed save options
/// </summary>
class  XamlFixedSaveOptionsData
    : public FixedPageSaveOptionsData
{
public:
    XamlFixedSaveOptionsData();
    virtual ~XamlFixedSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// XamlFixedSaveOptionsData members

    /// <summary>
    /// Specifies the physical folder where resources (images and fonts) are saved when exporting a document to fixed page Xaml format. Default is null.
    /// </summary>
    utility::string_t getResourcesFolder() const;
    bool resourcesFolderIsSet() const;
    void unsetResourcesFolder();
    void setResourcesFolder(utility::string_t value);
    /// <summary>
    /// Specifies the name of the folder used to construct image URIs written into an fixed page Xaml document. Default is null.
    /// </summary>
    utility::string_t getResourcesFolderAlias() const;
    bool resourcesFolderAliasIsSet() const;
    void unsetResourcesFolderAlias();
    void setResourcesFolderAlias(utility::string_t value);

protected:
    utility::string_t m_ResourcesFolder;
    bool m_ResourcesFolderIsSet;
    utility::string_t m_ResourcesFolderAlias;
    bool m_ResourcesFolderAliasIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_XamlFixedSaveOptionsData_H_ */
