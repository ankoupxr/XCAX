#pragma once
# include <string>
#include <memory>
#include <Document.h>

class XRW
{
public:
	~XRW() = default;

	struct DocumentParams {
		DocPtr targetDocument;
		std::vector<std::filesystem::path> filePaths;
	};

};
