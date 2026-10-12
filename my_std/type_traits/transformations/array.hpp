#ifndef MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ARRAY_HPP
#define MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ARRAY_HPP

#include "my_std/type_traits/core/type_identity.hpp"
#include <cstddef>

namespace my_std {

template <typename T>
struct remove_extent : type_identity<T> {};
template <typename T>
struct remove_extent<T[]> :type_identity<T> {};
template <typename T, std::size_t N>
struct remove_extent<T[N]> :type_identity<T> {};
template <typename T>
using remove_extent_t = typename remove_extent<T>::type;

template <typename T>
struct remove_all_extents : type_identity<T> {};
template <typename T, std::size_t N>
struct remove_all_extents <T[N]> :type_identity<typename remove_all_extents<T>::type> {};
template <typename T>
struct remove_all_extents <T[]> : type_identity<typename remove_all_extents<T>::type> {};
template <typename T>
using remove_all_extents_t = typename remove_all_extents<T>::type;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ARRAY_HPP
