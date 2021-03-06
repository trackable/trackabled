//------------------------------------------------------------------------------
/*
    This file is part of trackabled: https://github.com/trackable/trackabled
    Copyright (c) 2012, 2013 Trackable Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#include <BeastConfig.h>
#include <trackable/basics/CheckLibraryVersions.h>
#include <trackable/basics/impl/CheckLibraryVersionsImpl.h>
#include <trackable/beast/unit_test.h>

namespace trackable {
namespace version {

struct CheckLibraryVersions_test : beast::unit_test::suite
{
    void testBadOpenSSL()
    {
        testcase ("Out-of-Date OpenSSL");
        except ([&]{ checkOpenSSL("0.9.8-o"); });
        except ([&]{ checkOpenSSL("1.0.1-d"); });
        except ([&]{ checkOpenSSL("1.0.2-c"); });
    }

    void testBadBoost()
    {
        testcase ("Out-of-Date Boost");
        except ([&]{ checkBoost ("1.54.0"); });
    }

    void run()
    {
        unexcept ([&]{ checkLibraryVersions(); });

        testBadOpenSSL();
        testBadBoost();
    }
};

BEAST_DEFINE_TESTSUITE(CheckLibraryVersions, trackable_basics, trackable);

}  // namespace version
}  // namespace trackable
