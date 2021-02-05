/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateFormFieldRequest.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_UpdateFormFieldRequest_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_UpdateFormFieldRequest_H_

#include "FormField.h"
#include "HttpContent.h"
#include "cpprest/details/basic_types.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class UpdateFormFieldRequest {
    public: 
 UpdateFormFieldRequest(
            utility::string_t name,
            int32_t index,
            std::shared_ptr<FormField> formField,
            boost::optional< utility::string_t > nodePath,
            boost::optional< utility::string_t > folder,
            boost::optional< utility::string_t > storage,
            boost::optional< utility::string_t > loadEncoding,
            boost::optional< utility::string_t > password,
            boost::optional< utility::string_t > destFileName,
            boost::optional< utility::string_t > revisionAuthor,
            boost::optional< utility::string_t > revisionDateTime
        );

        utility::string_t getName() const;
        void setName(utility::string_t name);

        int32_t getIndex() const;
        void setIndex(int32_t index);

        std::shared_ptr<FormField> getFormField() const;
        void setFormField(std::shared_ptr<FormField> formField);

        boost::optional< utility::string_t > getNodePath() const;
        void setNodePath(boost::optional< utility::string_t > nodePath);

        boost::optional< utility::string_t > getFolder() const;
        void setFolder(boost::optional< utility::string_t > folder);

        boost::optional< utility::string_t > getStorage() const;
        void setStorage(boost::optional< utility::string_t > storage);

        boost::optional< utility::string_t > getLoadEncoding() const;
        void setLoadEncoding(boost::optional< utility::string_t > loadEncoding);

        boost::optional< utility::string_t > getPassword() const;
        void setPassword(boost::optional< utility::string_t > password);

        boost::optional< utility::string_t > getDestFileName() const;
        void setDestFileName(boost::optional< utility::string_t > destFileName);

        boost::optional< utility::string_t > getRevisionAuthor() const;
        void setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor);

        boost::optional< utility::string_t > getRevisionDateTime() const;
        void setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime);

    private:
        utility::string_t m_Name;
        int32_t m_Index;
        std::shared_ptr<FormField> m_FormField;
        boost::optional< utility::string_t > m_NodePath;
        boost::optional< utility::string_t > m_Folder;
        boost::optional< utility::string_t > m_Storage;
        boost::optional< utility::string_t > m_LoadEncoding;
        boost::optional< utility::string_t > m_Password;
        boost::optional< utility::string_t > m_DestFileName;
        boost::optional< utility::string_t > m_RevisionAuthor;
        boost::optional< utility::string_t > m_RevisionDateTime;
};

}
}
}
}
}

#endif  /* ASPOSE_WORDS_CLOUD_API_MODELS_UpdateFormFieldRequest_H_ */
