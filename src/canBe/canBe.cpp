#include "canBe.hpp"
#include "_internal/constants.hpp"
#include "_internal/utils.hpp"

namespace EsHangul {
namespace CanBe {

/**
 * @brief 인자로 받은 문자가 초성으로 위치할 수 있는 문자인지 검사합니다.
 *
 * @param character 대상 문자
 * @return `true` if `character` is a valid Choseong, `false` otherwise.
 *
 * @example
 * canBeChoseong(L"ㄱ") // true
 * canBeChoseong(L"ㅃ") // true
 * canBeChoseong(L"ㄱㅅ") // false
 * canBeChoseong(L"ㅏ") // false
 * canBeChosung(L"가") // false
 */
bool canBeChoseong(const std::wstring& character)
{
    return _Internal::hasValueInReadOnlyStringList(_Internal::CHOSEONGS, character);
}

/**
 * @brief
 * 인자로 받은 문자가 중성으로 위치할 수 있는 문자인지 검사합니다.
 *
 * @param character 대상 문자
 * @return `true` if `character` is a valid Jungseong, `false` otherwise.
 *
 * @example
 * canBeJungseong(L"ㅏ") // true
 * canBeJungseong(L"ㅗㅏ") // true
 * canBeJungseong(L"ㅏㅗ") // false
 * canBeJungseong(L"ㄱ") // false
 * canBeJungseong(L"ㄱㅅ") // false
 * canBeJungseong(L"가") // false
 */
bool canBeJungseong(const std::wstring& character)
{
    return _Internal::hasValueInReadOnlyStringList(_Internal::JUNSEONGS, character);
}

/**
 * @brief 인자로 받은 문자가 종성으로 위치할 수 있는 문자인지 검사합니다.
 *
 * @param character 대상 문자
 * @return `true` if `character` is a valid Jongseong, `false` otherwise.
 *
 * @example
 * canBeJongseong(L"ㄱ") // true
 * canBeJongseong(L"ㄱㅅ") // true
 * canBeJongseong(L"ㅎㄹ") // false
 * canBeJongseong(L"가") // false
 * canBeJongseong(L"ㅏ") // false
 * canBeJongseong(L"ㅗㅏ") // false
 */
bool canBeJongseong(const std::wstring& character)
{
    return _Internal::hasValueInReadOnlyStringList(_Internal::JONGSEONGS, character);
}

} // namespace CanBe
} // namespace EsHangul
