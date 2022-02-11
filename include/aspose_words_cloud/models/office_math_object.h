/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="office_math_object.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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
#include "./model_base.h"
#include "office_math_link.h"
#include "story_child_nodes.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with an OfficeMath object.
    /// </summary>
    class OfficeMathObject : public OfficeMathLink
    {
    public:
        /// <summary>
        /// Gets or sets the display format type of the OfficeMath object. This display format defines whether an equation is displayed inline with the text or displayed on its own line.
        /// </summary>
        enum class DisplayType
        { 
            DISPLAY,
            INLINE
        };

        /// <summary>
        /// Gets or sets the justification of the OfficeMath object.
        /// </summary>
        enum class Justification
        { 
            CENTER_GROUP,
            DEFAULT,
            CENTER,
            LEFT,
            RIGHT,
            INLINE
        };

        /// <summary>
        /// Gets or sets the type of the OfficeMath object.
        /// </summary>
        enum class MathObjectType
        { 
            O_MATH,
            O_MATH_PARA,
            ACCENT,
            BAR,
            BORDER_BOX,
            BOX,
            DELIMITER,
            DEGREE,
            ARGUMENT,
            ARRAY,
            FRACTION,
            DENOMINATOR,
            NUMERATOR,
            FUNCTION,
            FUNCTION_NAME,
            GROUP_CHARACTER,
            LIMIT,
            LOWER_LIMIT,
            UPPER_LIMIT,
            MATRIX,
            MATRIX_ROW,
            N_ARY,
            PHANTOM,
            RADICAL,
            SUBSCRIPT_PART,
            SUPERSCRIPT_PART,
            PRE_SUB_SUPERSCRIPT,
            SUBSCRIPT,
            SUB_SUPERSCRIPT,
            SUPERCRIPT
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~OfficeMathObject() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the content of a footnote.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StoryChildNodes > getContent() const;

        /// <summary>
        /// Gets or sets the content of a footnote.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setContent(std::shared_ptr< aspose::words::cloud::models::StoryChildNodes > value);


        /// <summary>
        /// Gets or sets the display format type of the OfficeMath object. This display format defines whether an equation is displayed inline with the text or displayed on its own line.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::DisplayType > getDisplayType() const;

        /// <summary>
        /// Gets or sets the display format type of the OfficeMath object. This display format defines whether an equation is displayed inline with the text or displayed on its own line.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDisplayType(std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::DisplayType > value);


        /// <summary>
        /// Gets or sets the justification of the OfficeMath object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::Justification > getJustification() const;

        /// <summary>
        /// Gets or sets the justification of the OfficeMath object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setJustification(std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::Justification > value);


        /// <summary>
        /// Gets or sets the type of the OfficeMath object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::MathObjectType > getMathObjectType() const;

        /// <summary>
        /// Gets or sets the type of the OfficeMath object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMathObjectType(std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::MathObjectType > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::StoryChildNodes > m_Content;
        std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::DisplayType > m_DisplayType;
        std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::Justification > m_Justification;
        std::shared_ptr< aspose::words::cloud::models::OfficeMathObject::MathObjectType > m_MathObjectType;
    };
}

