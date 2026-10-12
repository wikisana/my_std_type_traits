# TODO

## 已完成

- `add_const`、`add_volatile`、`add_cv` 及其 `_t` 别名
- `add_lvalue_reference`、`add_rvalue_reference` 及其 `_t` 别名
- `remove_pointer`、`add_pointer` 及其 `_t` 别名
- `remove_extent`、`remove_all_extents` 及其 `_t` 别名
- `is_object_v`、`is_scalar_v`、`is_compound_v`
- `void_t` 基础检测工具
- 上述 transformations 对普通类型、cv、引用、数组、函数和 `void` 的标准库对照测试

## 下一步：实现 decay

优先实现 `my_std/type_traits/transformations/decay.hpp`：

- 先令 `U = remove_reference_t<T>`
- 若 `U` 是数组，结果为 `add_pointer_t<remove_extent_t<U>>`
- 若 `U` 是函数，结果为 `add_pointer_t<U>`
- 其他情况结果为 `remove_cv_t<U>`
- 提供 `decay_t<T>`
- 与 `std::decay` 对照普通类型、cv/ref、数组和函数

现有的 remove/add cv、reference、pointer、extent 和类型查询已经满足
`decay` 的主要依赖，因此它适合作为下一步的组合型 trait。

## 后续顺序

1. 实现 `sign.hpp`：`make_signed` 和 `make_unsigned`。
2. 将根目录测试拆成按模块组织的测试文件，并覆盖正例、反例和 cv/ref 边界。
3. 完成 queries 后，再实现 constructible、assignable、destructible 和 invoke_result。

## 每个模块的验收标准

- 可以单独包含对应头文件，不依赖总入口的包含顺序。
- 使用 GCC 的 C++17 模式通过 `-Wall -Wextra -Wpedantic` 编译。
- 对照对应的 `std::type_traits`，覆盖普通类型、cv 类型、引用、数组、函数和成员指针。
- 新增公共 trait 时，同时提供结构体和标准命名形式的 `_t` 或 `_v` 辅助接口。
