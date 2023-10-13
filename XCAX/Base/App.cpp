#include <App.h>
#include <BinXCAFDrivers_DocumentRetrievalDriver.hxx>
#include <BinXCAFDrivers_DocumentStorageDriver.hxx>
#include <XCAFApp_Application.hxx>
#include <XmlXCAFDrivers_DocumentRetrievalDriver.hxx>
#include <XmlXCAFDrivers_DocumentStorageDriver.hxx>

App::App()
{
}


const AppPtr& App::GetInstance()
{
    static AppPtr appPtr;
    if (!appPtr) {
        appPtr = new App;
        const char strFougueCopyright[] = "Copyright (c) 2023";
        appPtr->DefineFormat(
            "XBinary", "Binary for OCAF documents", "xb",
            new BinXCAFDrivers_DocumentRetrievalDriver(),
            new BinXCAFDrivers_DocumentStorageDriver
        );
        appPtr->DefineFormat(
            "XXml", "XML for OCAF documents", "xx",
            new XmlXCAFDrivers_DocumentRetrievalDriver(),
            new XmlXCAFDrivers_DocumentStorageDriver(strFougueCopyright)
        );
    }
    return appPtr;
}

int App::DocumentCount() const
{
    return this->NbDocuments();
}

void App::NewDocument(const TCollection_ExtendedString&, Handle(CDM_Document)& outDocument)
{
    // TODO: check format == "mayo" if not throw exception
    // Extended from TDocStd_Application::NewDocument() implementation, ensure that in future
    // OpenCascade versions this code is still compatible!
    DocPtr newDoc = new Document(this);
    CDF_Application::Open(newDoc); // Add the document in the session
    this->AddDocument(newDoc);
    outDocument = newDoc;
}

DocPtr App::CreateDocFile(Document::FormatType docFormat)
{
    const char* docNameFormat = Document::ConvertToFormat(docFormat);
    Handle(CDM_Document) stdDoc;
    this->NewDocument(docNameFormat,stdDoc);
    auto _docPtr = DocPtr::DownCast(stdDoc);
    return _docPtr;
}

DocPtr App::EditDocFile(const std::filesystem::path& filepath, PCDM_ReaderStatus* ptrReadStatus)
{
    Handle_TDocStd_Document stdDoc;
    const PCDM_ReaderStatus readStatus = 
        this->Open(TCollection_ExtendedString(filepath.c_str()), stdDoc);
    if (ptrReadStatus)
        *ptrReadStatus = readStatus;

    DocPtr doc = DocPtr::DownCast(stdDoc);
    //this->AddDocument(doc);
    return doc;
}

App::~App()
{

}

void App::AddDocument(const DocPtr& doc)
{
    if (!doc.IsNull()) 
    {
        doc->SetIdentify(m_seqDocumentIdentifier.fetch_add(1));
        m_mapIdentifierDocument.insert({ doc->Identify(),doc });
        this->InitDocument(doc);
        //doc->initXCaf();
    }
}


DocPtr App::FindDocumentByName(std::string name) const
{
    std::string docIndex;
    for (char c : name) {
        if (std::isdigit(c)) {
            docIndex += c;
        }
    }
    int index = std::stoi(docIndex);
    auto itFound = m_mapIdentifierDocument.find(index);
    return itFound != m_mapIdentifierDocument.cend() ? itFound->second : DocPtr();
}