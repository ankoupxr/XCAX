#pragma once

#include <Transfer_FinderProcess.hxx>
#include <XSControl_WorkSession.hxx>
#include <Transfer_TransientProcess.hxx>
#include <IGESCAFControl_Reader.hxx>
#include <IGESCAFControl_Writer.hxx>
#include <STEPCAFControl_Reader.hxx>
#include <STEPCAFControl_Writer.hxx>
#include <mutex>
#include <string>

template<typename CafReaderType>
bool cafGenericReadFile(CafReaderType& reader, const std::string& filepath)
{
    //readFile_prepare(reader);
    const IFSelect_ReturnStatus error = reader.ReadFile(filepath.c_str());
    return error == IFSelect_RetDone;
}


namespace IO 
{
	std::mutex& cafGlobalMutex() 
	{
		static std::mutex mutex;
		return mutex;
	};

#define MayoIO_CafGlobalScopedLock(name) \
    [[maybe_unused]] std::lock_guard<std::mutex> name(Mayo::IO::Private::cafGlobalMutex());

    Handle_XSControl_WorkSession cafWorkSession(const STEPCAFControl_Reader& reader) {
        return reader.Reader().WS();
    }

    Handle_XSControl_WorkSession cafWorkSession(const IGESCAFControl_Reader& reader) {
        return reader.WS();
    }

    bool cafReadFile(IGESCAFControl_Reader& reader, const std::string& filepath) {
        return cafGenericReadFile(reader, filepath);
    }

    bool cafReadFile(STEPCAFControl_Reader& reader, const std::string& filepath) {
        return cafGenericReadFile(reader, filepath);
    }


}