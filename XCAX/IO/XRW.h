#pragma once
# include <string>
#include <memory>


class XRW
{
public:
	virtual ~XRW() = default;

    // Reads file at path 'fp' into memory using indicator to report progress
    // Returns 'true' on success
    virtual bool readFile(const std::string& fp) = 0;
};

// Abstract base class for all reader factories
class FactoryReader {
public:
    virtual ~FactoryReader() = default;

};