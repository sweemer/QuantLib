/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2023 Jonathan Sweemer

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

/*! \file hash_combine.hpp
    \brief Adaptation of boost::hash_combine
*/

#ifndef quantlib_hash_combine_hpp
#define quantlib_hash_combine_hpp

#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>

namespace QuantLib {

    namespace detail {

        template <std::size_t Bits>
        struct hash_mix_impl;

        template <>
        struct hash_mix_impl<64> {
            inline static std::uint64_t fn(std::uint64_t x) {
                std::uint64_t const m = (std::uint64_t(0xe9846af) << 32) + 0x9b1a615d;

                x ^= x >> 32;
                x *= m;
                x ^= x >> 32;
                x *= m;
                x ^= x >> 28;

                return x;
            }
        };

        template <>
        struct hash_mix_impl<32> {
            inline static std::uint32_t fn(std::uint32_t x) {
                std::uint32_t const m1 = 0x21f0aaad;
                std::uint32_t const m2 = 0x735a2d97;

                x ^= x >> 16;
                x *= m1;
                x ^= x >> 15;
                x *= m2;
                x ^= x >> 15;

                return x;
            }
        };

        inline std::size_t hash_mix(std::size_t v) {
            return hash_mix_impl<sizeof(std::size_t) * CHAR_BIT>::fn(v);
        }

    }

    template <class T>
    inline void hash_combine(std::size_t& seed, const T& v) {
        seed = detail::hash_mix(seed + 0x9e3779b9 + std::hash<T>()(v));
    }

}

#endif
