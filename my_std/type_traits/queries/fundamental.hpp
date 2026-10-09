#ifndef MY_STD_TYPE_TRAITS_QUERIES_FUNDAMENTAL_HPP
#define MY_STD_TYPE_TRAITS_QUERIES_FUNDAMENTAL_HPP

#include "my_std/type_traits/core/enable_if.hpp"
#include "my_std/type_traits/core/integral_constant.hpp"
#include "my_std/type_traits/queries/is_same.hpp"
#include "my_std/type_traits/transformations/remove_cv.hpp"
#include <cstddef>

namespace my_std {

template <typename T, typename = void>
struct is_void : false_type{};
template <typename T>
struct is_void <T, enable_if_t<is_same_v<remove_cv_t<T>, void>>>: true_type{};
template <typename T>
inline constexpr bool is_void_v = is_void<T>::value;

template <typename T, typename = void>
struct is_null_pointer: false_type{};
template <typename T>
struct is_null_pointer<T, enable_if_t<is_same_v<std::nullptr_t, remove_cv_t<T>>>>: true_type{};
template <typename T>
inline constexpr bool is_null_pointer_v = is_null_pointer<T>::value;

namespace detail{
    template <typename T>
    struct is_integral: false_type{};
    template <>
    struct is_integral<int>: true_type{};
    template <>
    struct is_integral<long>: true_type{};
    template <>
    struct is_integral<long long>: true_type{};
    template <>
    struct is_integral<char>: true_type{};
    template <>
    struct is_integral<signed char>: true_type{};
    #if __cplusplus >= 202003L
    template <>
    struct is_integral<char8_t>: true_type{};
    #endif
    template <>
    struct is_integral<char16_t>: true_type{};
    template <>
    struct is_integral<char32_t>: true_type{};
    template <>
    struct is_integral<bool>: true_type{};
    template <>
    struct is_integral<unsigned int>: true_type{};
    template <>
    struct is_integral<unsigned long>: true_type{};
    template <>
    struct is_integral<unsigned long long>: true_type{};
    template <>
    struct is_integral<unsigned char>: true_type{};
    template <>
    struct is_integral<wchar_t>: true_type{};
    template <>
    struct is_integral<short>: true_type{};
    template <>
    struct is_integral<unsigned short>: true_type{};
    template <typename T>
    struct is_floating_point: false_type{};
    template <>
    struct is_floating_point<float>: true_type{};
    template <>
    struct is_floating_point<double>: true_type{};
    template <>
    struct is_floating_point<long double>: true_type{};
} //namespace detail

template <typename T>
struct is_integral: detail::is_integral<remove_cv_t<T>>{};
template <typename T>
inline constexpr bool is_integral_v = is_integral<T>::value;


template <typename T>
struct is_floating_point: detail::is_floating_point<remove_cv_t<T>>{};
template <typename T>
inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

template <typename T, typename = void>
struct is_arithmetic : false_type{};
template <typename T>
struct is_arithmetic<T, enable_if_t<is_integral_v<T> || is_floating_point_v<T>>>: true_type{};
template <typename T>
inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;
 


template <typename T, typename = void>
struct is_fundamental: false_type{};
template <typename T>
struct is_fundamental<T, enable_if_t<is_void_v<T> || is_arithmetic_v<T> || is_null_pointer_v<T>>>: true_type{};
template <typename T>
inline constexpr bool is_fundamental_v = is_fundamental<T>::value;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_QUERIES_FUNDAMENTAL_HPP
