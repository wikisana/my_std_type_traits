#ifndef MY_STD_TYPE_TRAITS_OPERATIONS_INVOKE_RESULT_HPP
#define MY_STD_TYPE_TRAITS_OPERATIONS_INVOKE_RESULT_HPP

namespace my_std {

template <typename Fn, typename... Args>
struct invoke_result;

template <typename Fn, typename... Args>
struct is_invocable;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_OPERATIONS_INVOKE_RESULT_HPP
