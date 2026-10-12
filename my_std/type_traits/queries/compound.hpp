#ifndef MY_STD_TYPE_TRAITS_QUERIES_COMPOUND_HPP
#define MY_STD_TYPE_TRAITS_QUERIES_COMPOUND_HPP
#include "my_std/type_traits/core/enable_if.hpp"
#include "my_std/type_traits/core/integral_constant.hpp"
#include "my_std/type_traits/queries/fundamental.hpp"
#include "my_std/type_traits/queries/pointer.hpp"
#include "my_std/type_traits/queries/reference.hpp"
#include "my_std/type_traits/queries/cv.hpp"
#include <cstddef>
namespace my_std {

template <typename T>
struct is_array:false_type{};
template <typename T>
struct is_array<T[]>:true_type{};
template <typename T, std::size_t N>
struct is_array<T[N]>:true_type{};
template <typename T>
inline constexpr bool is_array_v = is_array<T>::value;

template <typename T>
struct is_enum: integral_constant<bool, __is_enum(T)> {};
template <typename T>
inline constexpr bool is_enum_v = is_enum<T>::value;
template <typename T>
struct is_union: integral_constant<bool, __is_union(T)> {};
template <typename T>
inline constexpr bool is_union_v = is_union<T>::value;

template <typename T>
struct is_class: integral_constant<bool, __is_class(T)> {};
template <typename T>
inline constexpr bool is_class_v = is_class<T>::value;
template <typename T>
struct is_function:bool_constant<!is_const_v<const T> && !is_reference_v<T>> {};
template <typename T>
inline constexpr bool is_function_v = is_function<T>::value;

template <typename T, typename = void>
struct is_object : false_type{};

template <typename T>
struct is_object<T, enable_if_t<!is_function_v<T> && !is_reference_v<T> && !is_void_v<T>>> : true_type{};
template <typename T>
inline constexpr bool is_object_v = is_object<T>::value;


template<typename T>
struct is_scalar :bool_constant<is_arithmetic_v<T> || is_enum_v<T> || is_pointer_v<T> || is_member_pointer_v<T> || is_null_pointer_v<T>>{};
template <typename T>
inline constexpr bool is_scalar_v = is_scalar<T>::value;

template <typename T>
struct is_compound : bool_constant<!is_fundamental_v<T>> {};

template <typename T>
inline constexpr bool is_compound_v = is_compound<T>::value;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_QUERIES_COMPOUND_HPP
