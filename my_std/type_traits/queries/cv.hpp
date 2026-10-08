#ifndef MY_STD_TYPE_TRAITS_QUERIES_CV_HPP
#define MY_STD_TYPE_TRAITS_QUERIES_CV_HPP

#include "my_std/type_traits/core/integral_constant.hpp"
namespace my_std {

template <typename T>
struct is_const : false_type{};
template <typename T>
struct is_const<const T> : true_type{};

template <typename T>
inline constexpr bool is_const_v = is_const<T>::value;


template <typename T>
struct is_volatile : false_type{};
template <typename T>
struct is_volatile<volatile T> : true_type{};

template <typename T>
inline constexpr bool is_volatile_v = is_volatile<T>::value;


}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_QUERIES_CV_HPP
