#pragma once
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

/* ---------- constants */

constexpr unsigned char k_unsigned_char_max = 255;
constexpr char k_char_max = 127;
constexpr char k_char_min = -128;
constexpr long k_char_bits = 8;
constexpr long k_char_bits_bits = 3;

constexpr unsigned char k_byte_max = 255;
constexpr long k_byte_bits = 8;
constexpr long k_byte_bits_bits = 3;

constexpr wchar_t k_wchar_max = 0x7FFFu;
constexpr long k_wchar_bits = 16;
constexpr long k_wchar_bits_bits = 4;

constexpr unsigned short k_unsigned_short_min = 0;
constexpr unsigned short k_unsigned_short_max = 65535;
constexpr short k_short_max = 32767;
constexpr short k_short_min = -32768;
constexpr long k_short_bits = 16;
constexpr long k_short_bits_bits = 4;

constexpr unsigned int k_unsigned_int_min = 0;
constexpr unsigned int k_unsigned_int_max = 4294967295;
constexpr int k_int_max = 2147483647;
constexpr int k_int_min = -2147483648;
constexpr int k_int_bits = 32;
constexpr int k_int_bits_bits = 5;

constexpr unsigned long k_unsigned_long_min = 0;
constexpr unsigned long k_unsigned_long_max = 4294967295;
constexpr long k_long_max = 2147483647;
constexpr long k_long_min = -2147483648;
constexpr long k_long_bits = 32;
constexpr long k_long_bits_bits = 5;

constexpr long k_milliseconds_per_second = 1000;
constexpr long k_seconds_per_minute = 60;
constexpr long k_minutes_per_hour = 60;
constexpr long k_hours_per_day = 24;

constexpr long k_kilo = 1024;
constexpr long k_meg = 1048576;
constexpr long k_gig = 1073741824;
constexpr size_t k_kilo_as_size_t = 1024;
constexpr size_t k_meg_as_size_t = 1048576;
constexpr size_t k_gig_as_size_t = 1073741824;

enum e_none_sentinel
{
    NONE = -1,
};

#endif // __CONSTANTS_H__
