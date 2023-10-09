#pragma once

#include <TDocStd_Application.hxx>


class App;
DEFINE_STANDARD_HANDLE(App, TDocStd_Application)
using AppPtr = opencascade::handle<App>;


class Document;
DEFINE_STANDARD_HANDLE(Document, TDocStd_Document)
using DocPtr = Handle(Document);