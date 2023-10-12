
#include <algorithm>
#include <codecvt>
#include <sstream>
#include <vector>
#include <stringcov.h>





    DoubleToStringOperation::DoubleToStringOperation(double value)
        : m_value(value)
    {
    }

    DoubleToStringOperation& DoubleToStringOperation::locale(const std::locale& l)
    {
        m_opts.locale = l;
        return *this;
    }

    DoubleToStringOperation& DoubleToStringOperation::decimalCount(int c)
    {
        m_opts.decimalCount = c;
        return *this;
    }

    DoubleToStringOperation& DoubleToStringOperation::removeTrailingZeroes(bool on)
    {
        m_opts.removeTrailingZeroes = on;
        return *this;
    }

    DoubleToStringOperation& DoubleToStringOperation::roundToZero(bool on)
    {
        m_opts.roundToZero = on;
        return *this;
    }

    DoubleToStringOperation::operator std::string()
    {
        return to_stdString(m_value, m_opts);
    }

    std::string DoubleToStringOperation::get() const
    {
        return to_stdString(m_value, m_opts);
    }

    DoubleToStringOperation to_stdString(double value)
    {
        DoubleToStringOperation op(value);
        return op;
    }
