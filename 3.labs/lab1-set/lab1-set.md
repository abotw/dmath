---
lab: 1
title: "Lab 1: 集合的并、交和差运算"
layout: page
last updated: 2024-11-14T14:02:00
date: 2024-11-14
parent: Labs
---
# Lab 1: 集合的并、交和差运算
{: .no_toc }

## Table of Contents
{: .no_toc .text-delta }

1. TOC
{:toc}

## 问题描述

编制一个能演示执行集合的并、交和差运算的程序。

## 基本要求

1. 集合的元素限定为小写字母字符 `[a-z]`。
2. 演示程序以用户和计算机的对话方式执行。

## 测试数据

```
set1 = "magazine"
set2 = "paper"
set1 + set2 = "aegimnprz"
set1 - set2 = "gimnz"
set1.intersect(2) = "ae"
```

```
set1 = "012oper4a6tion89"
set2 = "error data"
set1 + set2 = "adeinoprt"
set1 - set2 = "inp"
se1.intersect(set2) = "aeort"
```

## 实现提示

以有序链表表示集合。

## 选作内容

1. 集合的元素判定和子集判定运算。
2. 求集合的补集。
3. 集合的混合运算表达式求值。
4. 集合的元素类型推广到其他类型，甚至任意类型。

## 补充资料

- <https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1252/lectures/06-set-map/>
- <https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set>
- https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1252/lectures/06-set-map/slides
- http://acm2006.scusa.lsu.edu/doc/cppreference/cppset/all.html

| Methods                                                                                                     |                |                                                                                                                     |
| ----------------------------------------------------------------------------------------------------------- | -------------- | ------------------------------------------------------------------------------------------------------------------- |
| **[add(value)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:add)**                  | **O(log N)**   | **Adds an element to this set, if it was not already there.**                                                       |
| **[clear()](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:clear)**                   | **O(N)**       | **Removes all elements from this set.**                                                                             |
| **[contains(value)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:contains)**        | **O(log N)**   | **Returns `true` if the specified value is in this set.**                                                           |
| **[difference(otherSet)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:difference)** | **O(N log N)** | **Subtracts `otherSet` from this set. The difference removes those elements that appear in `otherSet`.**            |
| [equals(set)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:equals)                  | O(N)           | Returns `true` if the two sets contain the same elements.                                                           |
| [first()](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:first)                       | O(log N)       | Returns the first value in this set when considered in sorted order.                                                |
| **[intersect(otherSet)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:intersect)**   | **O(N log N)** | **Intersects `otherSet` with this set. The intersection retains only those elements also contained in `otherSet`.** |
| **[isEmpty()](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:isEmpty)**               | **O(1)**       | **Returns `true` if this set contains no elements.**                                                                |
| **[isSubsetOf(otherSet)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:isSubsetOf)** | **O(N)**       | **Returns `true` if this set is a subset of `otherSet`.**                                                           |
| [isSupersetOf(otherSet)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:isSupersetOf) | O(N)           | Returns `true` if this set is a superset of `otherSet`.                                                             |
| [last()](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:last)                         | O(log N)       | Returns the last value in this set when considered in sorted order.                                                 |
| [mapAll(fn)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:mapAll)                   | O(N)           | Calls `fn(value)` for each element of this set.                                                                     |
| **[remove(value)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:remove)**                | **O(log N)**       | **Removes an element from this set.**                                                                                   |
| **[size()](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:size)**                     | **O(1)**       | **Returns the number of elements in this set.**                                                                     |
| **[toString()](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:toString)**             | **O(N)**       | **Returns a printable string representation of this set.**                                                          |
| **[unionWith(otherSet)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Method:unionWith)**   | **O(N log N)** | **Unions `otherSet` with this set. The union adds all elements from `otherSet`.**                                   |

| Operators                                                                                                    |                |                                                                                |
| ------------------------------------------------------------------------------------------------------------ | -------------- | ------------------------------------------------------------------------------ |
| **[for (ValueType elem : set)](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:foreach)** | **O(N)**           | **Iterates through the elements in a set.**                                        |
| [set1 == set2](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:==)                    | O(N)           | Evaluates to `true` if `set1` and `set2` contain the same elements.            |
| [set1 != set2](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:!=)                    | O(N)           | Evaluates to `true` if `set1` and `set2` are different.                        |
| [set + value](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:+)                      | O(N)           | Creates a new set which is the union of `set` with the single `value`.         |
| **[set1 + set2](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:+)**                  | **O(N log N)** | **Creates a new set which is the union of `set1` with `set2`.**                |
| [set += value](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:+=)                    | O(log N)       | Adds the single `value` to `set`.                                              |
| [set1 += set2](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:+=)                    | O(N log N)     | Adds all of the elements from `set2` to `set1`.                                |
| [set - value](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:-)                      | O(N)           | Creates a new set which contains all values in `set` minus `value`.            |
| **[set1 - set2](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:-)**                  | **O(N log N)** | **Creates a new set containing the elements in `set1` that aren't in `set2`.** |
| [set -= value](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:-=)                    | O(log N)       | Removes the single `value` from `set`.                                         |
| [set1 -= set2](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:-=)                    | O(N log N)     | Removes the elements of `set2` from `set1`.                                    |
| [set1 * set2](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:*)                      | O(N log N)     | Creates a new set which is the intersection of `set1` and `set2`.              |
| [set1 *= set2](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:*=)                    | O(N log N)     | Removes any elements from `set1` that are not present in `set2`.               |
| **[ostream << set](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:%3C%3C)**          | **O(N)**       | **Outputs the contents of `set` to the given output stream.**                  |
| **[istream >> set](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/Set#Operator:%3E%3E)**          | **O(N log N)** | **Reads the contents of the given input stream into `set`.**                   |


