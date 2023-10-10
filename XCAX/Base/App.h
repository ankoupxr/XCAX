#pragma once

#include <TDocStd_Application.hxx>

#include <CDF_DirectoryIterator.hxx>
#include <Standard_Version.hxx>
#include <functional>
#include <Document.h>
#include <Ptr.h>


class App : public TDocStd_Application
{
public:
	App();
	~App();

	static const AppPtr& GetInstance();

	//struct DocumentIterator : private CDF_DirectoryIterator
	//{
	//	DocumentIterator(const AppPtr& app);
	//	DocumentIterator(const AppPtr* app);
	//	bool HasNext() const;
	//	void Next();
	//	DocPtr current() const;
	//	int currentIndex() const { return m_currentIndex; }
	//private:
	//	int m_currentIndex = 0;
	//};

	int DocumentCount() const;
	DocPtr CreateDocFile(Document::FormatType docFormat = Document::FormatType::Binary);
	DocPtr EditDocFile(const std::filesystem::path& filepath, PCDM_ReaderStatus* ptrReadStatus = nullptr);
	//void CloseDocFile(const DocPtr& doc);

	//void NewDocument(const TCollection_ExtendedString& format, Handle(CDM_Document)& outDoc) override;
	//void InitDocument(const opencascade::handle<CDM_Document>& doc) const override;



private:
	friend class Document;

	//void AddDocument(const DocPtr& doc);

};
