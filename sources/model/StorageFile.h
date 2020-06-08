/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StorageFile.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_StorageFile_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_StorageFile_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// File or folder information
/// </summary>
class  StorageFile
    : public ModelBase
{
public:
    StorageFile();
    virtual ~StorageFile();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// StorageFile members

    /// <summary>
    /// File or folder name.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// True if it is a folder.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsFolder() const;
    bool isFolderIsSet() const;
    void unsetIsFolder();
    void setIsFolder(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// File or folder last modified DateTime.
    /// </summary>
    <DATA_TYPE_START>DateTime?<DATA_TYPE_END> getModifiedDate() const;
    bool modifiedDateIsSet() const;
    void unsetModifiedDate();
    void setModifiedDate(<DATA_TYPE_START>DateTime?<DATA_TYPE_END> value);
    /// <summary>
    /// File or folder size.
    /// </summary>
    <DATA_TYPE_START>long?<DATA_TYPE_END> getSize() const;
    bool sizeIsSet() const;
    void unsetSize();
    void setSize(<DATA_TYPE_START>long?<DATA_TYPE_END> value);
    /// <summary>
    /// File or folder path.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getPath() const;
    bool pathIsSet() const;
    void unsetPath();
    void setPath(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Name;
    bool m_NameIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsFolder;
    bool m_IsFolderIsSet;
    <DATA_TYPE_START>DateTime?<DATA_TYPE_END> m_ModifiedDate;
    bool m_ModifiedDateIsSet;
    <DATA_TYPE_START>long?<DATA_TYPE_END> m_Size;
    bool m_SizeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Path;
    bool m_PathIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_StorageFile_H_ */
