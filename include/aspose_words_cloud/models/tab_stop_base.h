/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="tab_stop_base.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Base class for paragraph format tab stop DTO.
    /// </summary>
    class TabStopBase : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the alignment of text at this tab stop.
        /// </summary>
        enum class Alignment
        { 
            LEFT,
            CENTER,
            RIGHT,
            DECIMAL,
            BAR,
            LIST,
            CLEAR
        };

        /// <summary>
        /// Gets or sets the type of the leader line displayed under the tab character.
        /// </summary>
        enum class Leader
        { 
            NONE,
            DOTS,
            DASHES,
            LINE,
            HEAVY,
            MIDDLE_DOT
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TabStopBase() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the alignment of text at this tab stop.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TabStopBase::Alignment > getAlignment() const;

        /// <summary>
        /// Gets or sets the alignment of text at this tab stop.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAlignment(std::shared_ptr< aspose::words::cloud::models::TabStopBase::Alignment > value);


        /// <summary>
        /// Gets or sets the type of the leader line displayed under the tab character.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TabStopBase::Leader > getLeader() const;

        /// <summary>
        /// Gets or sets the type of the leader line displayed under the tab character.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLeader(std::shared_ptr< aspose::words::cloud::models::TabStopBase::Leader > value);


        /// <summary>
        /// Gets or sets the position of the tab stop in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getPosition() const;

        /// <summary>
        /// Gets or sets the position of the tab stop in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPosition(std::shared_ptr< double > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::TabStopBase::Alignment > m_Alignment;
        std::shared_ptr< aspose::words::cloud::models::TabStopBase::Leader > m_Leader;
        std::shared_ptr< double > m_Position;
    };
}

