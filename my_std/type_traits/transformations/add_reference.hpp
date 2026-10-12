#ifndef MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ADD_REFERENCE_HPP
#define MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ADD_REFERENCE_HPP

#include "my_std/type_traits/core/type_identity.hpp"
#include "my_std/type_traits/core/void_t.hpp"

namespace my_std {

template <typename T, typename = void>
struct add_lvalue_reference : type_identity<T> {};
template <typename T>
struct add_lvalue_reference<T, void_t<T&>> : type_identity<T&> {};
template <typename T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

template <typename T, typename = void>
struct add_rvalue_reference : type_identity<T> {};
template <typename T>
struct add_rvalue_reference<T, void_t<T&&>> : type_identity<T&&> {};
template <typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_TRANSFORMATIONS_ADD_REFERENCE_HPP
