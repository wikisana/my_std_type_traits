#ifndef MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ADD_CV_HPP
#define MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ADD_CV_HPP

#include "my_std/type_traits/core/type_identity.hpp"

namespace my_std {

template <typename T>
struct add_const : type_identity<const T> {};
template <typename T>
using add_const_t = typename add_const<T>::type;

template <typename T>
struct add_volatile : type_identity<volatile T> {};
template <typename T>
using add_volatile_t = typename add_volatile<T>::type;

template <typename T>
struct add_cv : type_identity<typename add_const<typename add_volatile<T>::type>::type> {};
template <typename T>
using add_cv_t = typename add_cv<T>::type;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ADD_CV_HPP
