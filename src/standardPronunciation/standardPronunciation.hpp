#ifndef STANDARD_PRONUNCIATION_HPP
#define STANDARD_PRONUNCIATION_HPP

#include "rules/rules.types.hpp" // Include Nullable, Syllables
#include <string>
#include <vector>

using namespace EsHangul::StandardPronunciation::Rules;

namespace EsHangul {
namespace StandardPronunciation {

/**
 * @brief Options for the standardizePronunciation function.
 */
struct Options {
    bool hardConversion; ///< Whether to apply hard consonant assimilation (경음화)
};

/**
 * @brief Represents non-Hangul characters with their index and the character.
 */
struct NotHangul {
    int index;             ///< The position of the non-Hangul character in the original string.
    std::wstring syllable; ///< The non-Hangul character.
};

/**
 * @brief Represents the parameters required for applying transformation rules.
 */
struct ApplyParameters {
    Syllable currentSyllable;        ///< The current syllable to be transformed.
    Nullable<Syllable> nextSyllable; ///< The next syllable to be transformed, if any.
    int index;                       ///< The index of the current syllable in the syllable array.
    std::wstring phrase;             ///< The original phrase string.
    Options options;                 ///< Transformation options.
};

/**
 * @brief 주어진 한글 문자열을 표준 발음으로 변환합니다.
 *
 * @param hangul 한글 문자열
 * @param options 변환 옵션
 * @param options.hardConversion 경음화 등의 된소리를 적용할지 여부를 설정합니다. 기본값은 true입니다.
 * @return 변환된 표준 발음 문자열을 반환합니다.
 */
std::wstring standardizePronunciation(const std::wstring& hangul, const Options& options = {true});

} // namespace StandardPronunciation
} // namespace EsHangul

#endif // STANDARD_PRONUNCIATION_HPP
