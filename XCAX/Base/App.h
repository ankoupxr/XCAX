#pragma once

#include <TDocStd_Application.hxx>

#include <CDF_DirectoryIterator.hxx>
#include <Standard_Version.hxx>
#include <functional>
#include <Document.h>
#include <Ptr.h>
#include <boost\signals2.hpp>
#include <ModelTreeWidget.h>
#include <VtkRender.h>
#include <QVTKOpenGLNativeWidget.h>
#include <BinXCAFDrivers_DocumentRetrievalDriver.hxx>
#include <BinXCAFDrivers_DocumentStorageDriver.hxx>
#include <XCAFApp_Application.hxx>
#include <XmlXCAFDrivers_DocumentRetrievalDriver.hxx>
#include <XmlXCAFDrivers_DocumentStorageDriver.hxx>

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

	void NewDocument(const TCollection_ExtendedString& format, Handle(CDM_Document)& outDoc) override;
	//void InitDocument(const opencascade::handle<CDM_Document>& doc) const override;

	void SetModelTree(ModelTreeWidget* modeltree) { m_modeltree = modeltree; };
	ModelTreeWidget* GetModelTree() { return m_modeltree; };
	void SetMainWin(QTVtkRender* vtkwindow) { m_vtkwindow = vtkwindow; };
	QTVtkRender* GetMainWin() const { return m_vtkwindow; };

	DocPtr FindDocumentByName(std::string name) const;
	void SetCurrentDocPtr(const DocPtr& doc) { m_currentDocPtr = doc; };
	DocPtr GetCurrentDocPtr()  const { return m_currentDocPtr; };
private:
	friend class Document;

	void AddDocument(const DocPtr& doc);

	std::atomic<int> m_seqDocumentIdentifier = {};
	std::unordered_map<int, DocPtr> m_mapIdentifierDocument;

	ModelTreeWidget* m_modeltree;
	QTVtkRender* m_vtkwindow;
	DocPtr m_currentDocPtr;
};
