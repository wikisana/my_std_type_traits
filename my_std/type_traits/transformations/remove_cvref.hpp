#ifndef MY_STD_TYPE_TRAITS_TRANSFORMATIONS_REMOVE_CVREF_HPP
#define MY_STD_TYPE_TRAITS_TRANSFORMATIONS_REMOVE_CVREF_HPP

#include "my_std/type_traits/transformations/remove_reference.hpp"
#include "my_std/type_traits/transformations/remove_cv.hpp"
namespace my_std {

template <typename T>
struct remove_cvref{
    using type = remove_cv_t<remove_reference_t<T>>;
};
template <typename T>
using remove_cvref_t = typename remove_cvref<T>::type;
}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_TRANSFORMATIONS_REMOVE_CVREF_HPP
