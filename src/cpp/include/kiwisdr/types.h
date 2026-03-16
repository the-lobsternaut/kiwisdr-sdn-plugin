#ifndef KIWISDR_TYPES_H
#define KIWISDR_TYPES_H

/**
 * kiwisdr-sdn-plugin Types
 * =======
 *
 * KiwiSDR global HF radio receiver network
 * Source: http://rx.linkfanel.net/
 *
 * Output: $KWI FlatBuffer-aligned binary records
 */

#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

namespace kiwisdr {

// ============================================================================
// Constants
// ============================================================================

static constexpr uint32_t VERSION = 1;

// ============================================================================
// Core Data Structures
// ============================================================================

struct Record {
    double timestamp;        // Unix epoch seconds
    double latitude;         // WGS84 degrees
    double longitude;        // WGS84 degrees
    double value;            // Primary measurement value
    std::string source_id;   // Source identifier
    std::string category;    // Classification/category
    std::string description; // Human-readable description
};

struct DataSet {
    uint32_t version;
    uint64_t fetch_timestamp;
    std::vector<Record> records;
};

// ============================================================================
// Parser interface
// ============================================================================

DataSet parse_json(const std::string& json_input);
std::string to_flatbuffers(const DataSet& data);
bool validate(const std::string& input);

} // namespace kiwisdr

#endif // KIWISDR_TYPES_H
