/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2004, 2005, 2006, 2007 Ferdinando Ametrano
 Copyright (C) 2006 Katiuscia Manzoni
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl
 Copyright (C) 2003, 2004, 2005, 2006 StatPro Italia srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file timeunit.hpp
    \brief TimeUnit enumeration
*/

#ifndef quantlib_timeunit_hpp
#define quantlib_timeunit_hpp

#include <ql/qldefines.hpp>
#include <iosfwd>

#if (defined(__GNUC__) && !defined(__clang__)) && (((__GNUC__ == 6) && (__GNUC_MINOR__ < 1)) || (__GNUC__ < 6))
#include <functional>
#include <type_traits>
#endif

namespace QuantLib {

    //! Units used to describe time periods
    /*! \ingroup datetime */
    enum TimeUnit { Days,
                    Weeks,
                    Months,
                    Years,
                    Hours,
                    Minutes,
                    Seconds,
                    Milliseconds,
					Microseconds
    };

    /*! \relates TimeUnit */
    std::ostream& operator<<(std::ostream&,
                             const TimeUnit&);

}

#if (defined(__GNUC__) && !defined(__clang__)) && (((__GNUC__ == 6) && (__GNUC_MINOR__ < 1)) || (__GNUC__ < 6))

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=60970

namespace std {
    template<>
    struct hash<QuantLib::TimeUnit> {
        using underlying_type = std::underlying_type_t<QuantLib::TimeUnit>;
        std::size_t operator()(const QuantLib::TimeUnit& timeUnit) const noexcept {
            return std::hash<underlying_type>{}(static_cast<underlying_type>(timeUnit));
        }
    };
}

#endif

#endif
