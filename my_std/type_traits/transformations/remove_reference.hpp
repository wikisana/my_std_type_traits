#ifndef MY_STD_TYPE_TRAITS_TRANSFORMATIONS_REMOVE_REFERENCE_HPP
#define MY_STD_TYPE_TRAITS_TRANSFORMATIONS_REMOVE_REFERENCE_HPP

namespace my_std {

template <typename T>
struct remove_reference{
    using type = T;
};
template <typename T>
struct remove_reference<T&>{
    using type = T;
};
template <typename T>
struct remove_reference<T&&>{
    using type = T;
};
template <typename T>
using remove_reference_t = typename remove_reference<T>::type;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_TRANSFORMATIONS_REMOVE_REFERENCE_HPP
