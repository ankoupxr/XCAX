#pragma once

#include <TDocStd_Application.hxx>

#include <CDF_DirectoryIterator.hxx>
#include <Standard_Version.hxx>
#include <functional>
#include <Document.h>

class App;
DEFINE_STANDARD_HANDLE(App, TDocStd_Application)
using AppPtr = Handle(App);

class App : public TDocStd_Application
{
public:
	~App();

	static const AppPtr& GetInstance();

	struct DocumentIterator : private CDF_DirectoryIterator
	{
		DocumentIterator(const AppPtr& app);
		DocumentIterator(const AppPtr* app);
		bool HasNext() const;
		void Next();
		DocPtr current() const;
		int currentIndex() const { return m_currentIndex; }
	private:
		int m_currentIndex = 0;
	};


private:

};
