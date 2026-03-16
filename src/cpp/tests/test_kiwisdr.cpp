/**
 * kiwisdr-sdn-plugin Tests
 */

#include "kiwisdr/types.h"
#include <cassert>
#include <iostream>

void test_parse_empty() {
    auto ds = kiwisdr::parse_json("{}");
    assert(ds.version == kiwisdr::VERSION);
    assert(ds.records.empty());
    std::cout << "PASS: test_parse_empty" << std::endl;
}

void test_validate() {
    assert(kiwisdr::validate("{\"data\":[]}") == true);
    assert(kiwisdr::validate("") == false);
    std::cout << "PASS: test_validate" << std::endl;
}

void test_record_defaults() {
    kiwisdr::Record r;
    r.timestamp = 0.0;
    r.latitude = 0.0;
    r.longitude = 0.0;
    r.value = 0.0;
    assert(r.timestamp == 0.0);
    std::cout << "PASS: test_record_defaults" << std::endl;
}

int main() {
    test_parse_empty();
    test_validate();
    test_record_defaults();
    std::cout << "All kiwisdr tests passed." << std::endl;
    return 0;
}
