#pragma once

#include <array>

template <typename T, size_t N>
inline std::array<T, N> operator+ (const std::array<T, N> &arr_1, const std::array<T, N> &arr_2)
{
    std::array<T, N> sum;
    for (int i{}; i < (int) sum.size(); i++) { sum[i] = arr_1[i] + arr_2[i]; }
    return sum;
}

template <typename T, size_t N>
inline std::array<T, N> operator- (const std::array<T, N> &arr_1, const std::array<T, N> &arr_2)
{
    std::array<T, N> sub;
    for (int i{}; i < (int) sub.size(); i++) { sub[i] = arr_1[i] - arr_2[i]; }
    return sub;
}

template <typename T, size_t N>
inline std::array<T, N> operator* (const std::array<T, N> &arr_1, const std::array<T, N> &arr_2)
{
    T prod;
    for (int i{}; i < (int) arr_1.size(); i++) { prod += arr_1[i] * arr_2[i]; }
    return prod;
}

template <typename T, size_t N>
inline std::array<T, N> operator* (const std::array<T, N> &arr_1, const T c)
{
    std::array<T, N> arr;
    for (int i{}; i < (int) arr.size(); i++) { arr[i] = arr_1[i] * c; }
    return arr;
}

template <typename T, size_t N>
inline std::array<T, N> operator* (const T c, const std::array<T, N> &arr_2)
{
    std::array<T, N> arr;
    for (int i{}; i < (int) arr.size(); i++) { arr[i] = c *  arr_2[i]; }
    return arr;
}

template <typename T, size_t N>
inline std::array<T, N> operator/ (const std::array<T, N> &arr_1, const T c)
{
    std::array<T, N> arr;
    for (int i{}; i < (int) arr.size(); i++) { arr[i] = arr_1[i] / c; }
    return arr;
}

template <typename T, size_t N>
inline std::array<T, N> operator+= (std::array<T, N> &arr_1, const std::array<T, N> &arr_2)
{
    for (int i{}; i < (int) arr_1.size(); i++) { arr_1[i] += arr_2[i]; }
    return arr_1;
}

template <typename T, size_t N>
inline std::array<T, N> operator-= (std::array<T, N> &arr_1, const std::array<T, N> &arr_2)
{
    for (int i{}; i < (int) arr_1.size(); i++) { arr_1[i] -= arr_2[i]; }
    return arr_1;
}

template <typename T, size_t N>
inline std::array<T, N> operator*= (std::array<T, N> &arr_1, const T c)
{
    for (int i{}; i < (int) arr_1.size(); i++) { arr_1[i] *= c; }
    return arr_1;
}

template <typename T, size_t N>
inline std::array<T, N> operator/= (std::array<T, N> &arr_1, const T c)
{
    for (int i{}; i < (int) arr_1.size(); i++) { arr_1[i] /= c; }
    return arr_1;
}
