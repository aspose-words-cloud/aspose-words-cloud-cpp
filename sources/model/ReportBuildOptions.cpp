/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReportBuildOptions.cpp">
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

#include "ReportBuildOptions.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ReportBuildOptions::ReportBuildOptions(const utility::string_t& value) : m_value(value)
{

}

ReportBuildOptions::ReportBuildOptions() : m_value(_XPLATSTR(""))
{

}

ReportBuildOptions::~ReportBuildOptions()
{

}

const utility::string_t& ReportBuildOptions::getValue() const
{
    return m_value;
}

 const std::shared_ptr< ReportBuildOptions > ReportBuildOptions::None = std::shared_ptr< ReportBuildOptions >(new ReportBuildOptions(_XPLATSTR("None")));

 const std::shared_ptr< ReportBuildOptions > ReportBuildOptions::AllowMissingMembers = std::shared_ptr< ReportBuildOptions >(new ReportBuildOptions(_XPLATSTR("AllowMissingMembers")));

 const std::shared_ptr< ReportBuildOptions > ReportBuildOptions::RemoveEmptyParagraphs = std::shared_ptr< ReportBuildOptions >(new ReportBuildOptions(_XPLATSTR("RemoveEmptyParagraphs")));

 const std::shared_ptr< ReportBuildOptions > ReportBuildOptions::InlineErrorMessages = std::shared_ptr< ReportBuildOptions >(new ReportBuildOptions(_XPLATSTR("InlineErrorMessages")));

void ReportBuildOptions::validate()
{
    // TODO: implement validation
}

web::json::value ReportBuildOptions::toJson() const
{
    return ModelBase::toJson(m_value);
}

void ReportBuildOptions::fromJson(web::json::value& val)
{
    // TODO: not implemented
}

void ReportBuildOptions::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    // TODO: not implemented
}

void ReportBuildOptions::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: not implemented
}
}
}
}
}
}
