/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * See the NOTICE file(s) distributed with this work for additional information regarding         *
 * copyright ownership.                                                                           *
 *                                                                                                *
 * This program and the accompanying materials are made available under the terms of the Eclipse  *
 * Public License 2.0 which is available at http://www.eclipse.org/legal/epl-2.0                  *
 *                                                                                                *
 * SPDX-License-Identifier: EPL-2.0                                                               *
 **************************************************************************************************/

#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

namespace keyple {
namespace core {
namespace util {
namespace cpp {

class Arrays {
private:
    std::vector<char> privateArray;

public:
    static bool equals(const std::vector<char>& a1, const std::vector<char>& a2)
    {
        if (a1.size() != a2.size()) {
            return false;
        }

        for (auto i1 = a1.begin(), i2 = a2.begin(); i1 != a1.end();
            i1++, i2++) {
            if (*i1 != *i2)
                return false;
        }

        return true;
    }

    static bool equals(const std::vector<uint8_t>& a1, const std::vector<uint8_t>& a2)
    {
        if (a1.size() != a2.size()) {
            return false;
        }

        for (auto i1 = a1.begin(), i2 = a2.begin(); i1 != a1.end();
            i1++, i2++) {
            if (*i1 != *i2)
                return false;
        }

        return true;
    }

    static int hashCode(const std::vector<char> a)
    {
        int hash = 0;

        for (auto i = a.begin(); i != a.end(); i++)
            hash ^= *i;

        return hash;
    }

    static int hashCode(const std::vector<uint8_t> a)
    {
        int hash = 0;

        for (auto i = a.begin(); i != a.end(); i++)
            hash ^= *i;

        return hash;
    }

    static std::vector<char> copyOfRange(const std::vector<char>& original,
                                         const int from,
                                         const  int to)
    {
        std::vector<char> vec;

        std::copy(original.begin() + from, original.begin() + to, std::back_inserter(vec));

        return vec;
    }

    static std::vector<uint8_t> copyOfRange(const std::vector<uint8_t>& original,
                                            const int from,
                                            const int to)
    {
        std::vector<uint8_t> vec;

        std::copy(original.begin() + from, original.begin() + to, std::back_inserter(vec));

        return vec;
    }

    static bool containsAll(std::vector<std::string> a, std::vector<std::string> b)
    {
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        return std::includes(a.begin(), a.end(), b.begin(), b.end());
    }
};

}
}
}
}
