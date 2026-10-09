#ifndef MY_STD_TYPE_TRAITS_QUERIES_REFERENCE_HPP
#define MY_STD_TYPE_TRAITS_QUERIES_REFERENCE_HPP

#include "my_std/type_traits/core/integral_constant.hpp"

namespace my_std {

template <typename T>
struct is_lvalue_reference:false_type{};
template <typename T>
struct is_lvalue_reference<T&>:true_type{};
template <typename T>
inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

template <typename T>
struct is_rvalue_reference:false_type{};
template <typename T>
struct is_rvalue_reference<T&&>:true_type{};
template <typename T>
inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;

template <typename T>
struct is_reference:false_type{};
template <typename T>
struct is_reference<T&>:true_type{};
template <typename T>
struct is_reference<T&&>:true_type{};
template <typename T>
inline constexpr bool is_reference_v = is_reference<T>::value;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_QUERIES_REFERENCE_HPP
