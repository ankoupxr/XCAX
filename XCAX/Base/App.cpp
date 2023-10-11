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


DocPtr App::CreateDocFile(Document::FormatType docFormat)
{
    const char* docNameFormat = Document::ConvertToFormat(docFormat);
    Handle(CDM_Document) stdDoc;
    this->NewDocument(docNameFormat,stdDoc);
    return DocPtr::DownCast(stdDoc);
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
        this->AddedDocumentSignal(doc);
    }
}
