#pragma once

/*!
  \file print_ip.h
  \brief Определения шаблонных функций печати ip адреса.
*/

#include <iostream>
#include <type_traits>

/*!
  \brief Метафункция, определяющая является ли проверяемый тип котейнером из стандартной библиотеки.
*/
template <typename T, typename = void>
struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin()),
                                  decltype(std::declval<T>().end())>>
  : std::true_type {};

/*!
  \brief Шаблонная функция печати ip адреса, заданного контейнером из стандартной библиотеки.
  \param[in] ip IP адрес.
*/
template <
  typename T,
  typename std::enable_if<is_iterable<T>::value>::type* = nullptr
>
void printIp(const T &ip)
{
  if (ip.size() == 0)
    return;
  auto item = ip.begin();

  std::cout << *item;

  for (++item; item != ip.end(); item++)
    std::cout << '.' << *item;
}

/*!
  \brief Функция печати ip адреса, заданного строкой.
  \param[in] ip IP адрес.
*/
void printIp(const std::string &ip)
{
  std::cout << ip;
}

/*!
  \brief Шаблонная функция печати ip адреса, заданного любым целочисленным типом.
  \param[in] ip IP адрес.
*/
template <
  typename T,
  typename std::enable_if<std::is_integral<T>::value>::type* =nullptr
>
void printIp(T ip)
{
  typename std::make_unsigned<T>::type unsignedIp = ip;

  for (auto i = sizeof(T) - 1; i > 0; i--) {
    auto a = 8 * i;
    auto b = unsignedIp >> a;
    auto highByte = b & 0xFF;

    std::cout << highByte;
    std::cout << '.';
  }

  std::cout << (unsignedIp & 0xFF);
}
