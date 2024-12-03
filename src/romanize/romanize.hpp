#ifndef ROMANIZE_HPP
#define ROMANIZE_HPP

#include <string>

namespace EsHangul {
namespace Romanize {

/**
 * @brief Converts a given Hangul string to its Romanized representation.
 *
 * This function standardizes the pronunciation of the input Hangul string, decomposes each syllable,
 * maps each component to its corresponding Roman alphabet representation, and assembles the final string.
 *
 * @param hangul The input Hangul string to be Romanized.
 * @return A `std::wstring` containing the Romanized version of the input string.
 *
 * @example
 * std::wstring romanized = romanize(L"안녕하세요"); // "annyeonghaseyo"
 */
std::wstring romanize(const std::wstring& hangul);

} // namespace Romanize
} // namespace EsHangul

#endif // ROMANIZE_HPP
