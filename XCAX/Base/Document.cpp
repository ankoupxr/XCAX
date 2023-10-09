#include <Document.h>

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
