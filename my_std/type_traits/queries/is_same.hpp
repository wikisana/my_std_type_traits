#ifndef MY_STD_TYPE_TRAITS_QUERIES_IS_SAME_HPP
#define MY_STD_TYPE_TRAITS_QUERIES_IS_SAME_HPP

#include <my_std/type_traits/core/integral_constant.hpp>

namespace my_std {

template <typename T, typename U>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T>: true_type{};

template <typename T, typename U>
inline constexpr bool is_same_v = is_same<T, U>::value;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_QUERIES_IS_SAME_HPP
