
#ifndef SYMENGINE_NUMERICS_TYPES_H
#define SYMENGINE_NUMERICS_TYPES_H

#include <symengine/dict.h>

namespace SymEngine
{
namespace Numerics
{
namespace SE = ::SymEngine;

namespace types
{
/**
 * Type definition for a value substitution map.
 *
 * This is the equivalent to a
 * <tt>std::map<SE::RCP<const SE::Basic>,  SE::RCP<const SE::Basic> ></tt>.
 */
typedef SE::map_basic_basic substitution_map_t;

/**
 * Type definition for a vector of symbols.
 *
 * This is the equivalent to a
 * <tt>std::vector<SE::RCP<const SE::Basic>></tt>.
 */
typedef SE::vec_basic symbol_vector_t;
}

} // namespace Numerics
} // namespace SymEngine

#endif // SYMENGINE_NUMERICS_TYPES_H
