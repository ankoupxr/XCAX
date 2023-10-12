#include <Document.h>


Document::Document(const AppPtr& app)
    : TDocStd_Document("XBinDoc"),
    m_app(app)
{

}

Document::~Document()
{
}

const char* Document::ConvertToFormat(Document::FormatType format)
{
    if (format == FormatType::Binary) 
    {
        return "XBinary";
    }

    if (format == FormatType::Xml)
    {
        return "XXml";
    }

    return nullptr;
}


const std::string& Document::Name() const
{
    return m_name;
}

void Document::SetName(std::string name)
{
    this->m_name = name;
}