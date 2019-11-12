
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
    utility::string_t getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(utility::string_t value);
    /// <summary>
    /// True if it is a folder.
    /// </summary>
    bool isIsFolder() const;
        void setIsFolder(bool value);
    /// <summary>
    /// File or folder last modified .
    /// </summary>
    utility::datetime getModifiedDate() const;
    bool modifiedDateIsSet() const;
    void unsetModifiedDate();
    void setModifiedDate(utility::datetime value);
    /// <summary>
    /// File or folder size.
    /// </summary>
    int64_t getSize() const;
        void setSize(int64_t value);
    /// <summary>
    /// File or folder path.
    /// </summary>
    utility::string_t getPath() const;
    bool pathIsSet() const;
    void unsetPath();
    void setPath(utility::string_t value);

protected:
    utility::string_t m_Name;
    bool m_NameIsSet;
    bool m_IsFolder;
        utility::datetime m_ModifiedDate;
    bool m_ModifiedDateIsSet;
    int64_t m_Size;
        utility::string_t m_Path;
    bool m_PathIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_StorageFile_H_ */
