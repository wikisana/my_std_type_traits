#ifndef MY_STD_TYPE_TRAITS_CORE_TYPE_IDENTITY_HPP
#define MY_STD_TYPE_TRAITS_CORE_TYPE_IDENTITY_HPP

namespace my_std {

template <typename T>
struct type_identity{
    using type = T;
};

template <typename T>
using type_identity_t = typename type_identity<T>::type;
    
}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_CORE_TYPE_IDENTITY_HPP
