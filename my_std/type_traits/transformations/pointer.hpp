#ifndef MY_STD_TYPE_TRAITS_TRANSFORMATIONS_POINTER_HPP
#define MY_STD_TYPE_TRAITS_TRANSFORMATIONS_POINTER_HPP

#include "my_std/type_traits/core/type_identity.hpp"
#include "my_std/type_traits/core/void_t.hpp"
#include "my_std/type_traits/transformations/remove_reference.hpp"
namespace my_std {

template <typename T>
struct remove_pointer : type_identity<T> {};
template <typename T>
struct remove_pointer<T*> : type_identity<T> {};
template <typename T>
struct remove_pointer<T* const> : type_identity<T> {};
template <typename T>
struct remove_pointer<T* volatile> : type_identity<T> {};
template <typename T>
struct remove_pointer<T* const volatile> : type_identity<T> {};
template <typename T>
using remove_pointer_t = typename remove_pointer<T>::type;

template <typename T, typename = void>
struct add_pointer : type_identity<T> {};
template <typename T>
struct add_pointer<T, void_t<remove_reference_t<T>*>>
    : type_identity<remove_reference_t<T>*> {};
template <typename T>
using add_pointer_t = typename add_pointer<T>::type;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_TRANSFORMATIONS_POINTER_HPP
