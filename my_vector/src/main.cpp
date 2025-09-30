// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "myvector.hpp"

static int passed = 0;
static int total_tests = 0;

void report_test(bool cond, const std::string &name) {
    ++total_tests;
    if (cond) {
        ++passed;
        std::cout << std::left << std::setw(40) << name << " ✅ TEST PASSED\n";
    } else {
        std::cout << std::left << std::setw(40) << name << " ❌ TEST FAILED\n";
    }
}

int main() {
    MyVector v;

    // ---------- Test 1: Initialization ----------
    myvector_init(&v, 4);
    report_test(myvector_size(&v) == 0, "Init: size == 0");
    report_test(myvector_capacity(&v) == 4, "Init: capacity == 4");

    // ---------- Test 2: Push back until resize happens (100 elements) ----------
    const int N = 100;
    for (int i = 0; i < N; ++i) {
        myvector_push_back(&v, i);
    }

    // After pushing 100 elements
    report_test(myvector_size(&v) == (size_t)N, "PushBack: size == 100");
    report_test(myvector_capacity(&v) >= (size_t)N, "PushBack: capacity >= 100");

    // Check element values at start / middle / end
    bool first_ok = (v.data[0] == 0);
    bool mid_ok = (v.data[N/2] == N/2);
    bool last_ok = (v.data[N-1] == N-1);
    report_test(first_ok, "Values: first element correct");
    report_test(mid_ok, "Values: middle element correct");
    report_test(last_ok, "Values: last element correct");

    // remember capacity before inserts/erases
    size_t cap_before_ops = myvector_capacity(&v);

    // ---------- Test 3: Insert at different positions ----------
    // Insert at start
    size_t size_before = myvector_size(&v);
    myvector_insert(&v, 0, -1);
    report_test(myvector_size(&v) == size_before + 1, "Insert start: size increased");
    report_test(v.data[0] == -1, "Insert start: value at index 0 == -1");
    report_test(v.data[1] == 0, "Insert start: previous first moved to index 1");

    // Insert in middle
    size_t mid_index = myvector_size(&v) / 2;
    myvector_insert(&v, mid_index, 12345);
    report_test(v.data[mid_index] == 12345, "Insert middle: value placed at middle index");

    // Insert at end (index == size)
    size_t before_end_insert = myvector_size(&v);
    myvector_insert(&v, before_end_insert, 99999);
    report_test(v.data[myvector_size(&v)-1] == 99999, "Insert end: appended value 99999");

    // ---------- Test 4: Erase from different positions ----------
    // Erase start (index 0) - should remove -1
    size_t size_before_erase = myvector_size(&v);
    myvector_erase(&v, 0);
    report_test(myvector_size(&v) == size_before_erase - 1, "Erase start: size decreased");
    report_test(v.data[0] == 0, "Erase start: new first is previous 0");

    // Erase the middle element we inserted (12345)
    // find it
    bool found = false;
    size_t found_idx = 0;
    for (size_t i = 0; i < myvector_size(&v); ++i) {
        if (v.data[i] == 12345) { found = true; found_idx = i; break; }
    }
    report_test(found, "Erase middle: 12345 found before erase");
    if (found) {
        size_t sz_before = myvector_size(&v);
        myvector_erase(&v, found_idx);
        report_test(myvector_size(&v) == sz_before - 1, "Erase middle: size decreased after erase");
        // ensure 12345 not present anymore
        bool still_here = false;
        for (size_t i = 0; i < myvector_size(&v); ++i) {
            if (v.data[i] == 12345) { still_here = true; break; }
        }
        report_test(!still_here, "Erase middle: 12345 removed");
    }

    // Erase last (where 99999 was)
    // find 99999 (should be last)
    bool last_found = false;
    size_t last_index = 0;
    for (size_t i = 0; i < myvector_size(&v); ++i) {
        if (v.data[i] == 99999) { last_found = true; last_index = i; break; }
    }
    report_test(last_found, "Erase end: 99999 found before erase");
    if (last_found) {
        size_t sz_before2 = myvector_size(&v);
        myvector_erase(&v, last_index);
        report_test(myvector_size(&v) == sz_before2 - 1, "Erase end: size decreased after erase");
        // ensure 99999 not present
        bool still_here2 = false;
        for (size_t i = 0; i < myvector_size(&v); ++i) {
            if (v.data[i] == 99999) { still_here2 = true; break; }
        }
        report_test(!still_here2, "Erase end: 99999 removed");
    }

    // ---------- Test 5: Pop back until empty ----------
    // We'll pop until size == 0 (but check size before each pop to avoid underflow)
    bool pop_ok = true;
    while (myvector_size(&v) > 0) {
        size_t s_before = myvector_size(&v);
        // capture last element for spot-check (not strictly required)
        int last_val = v.data[s_before - 1];
        myvector_pop_back(&v);
        size_t s_after = myvector_size(&v);
        if (s_after != s_before - 1) {
            pop_ok = false;
            break;
        }
        // optional: ensure last value is no longer accessible at old index
        if (s_after > 0 && v.data[s_after - 1] == last_val && s_after == s_before - 1) {
            // this condition doesn't indicate error necessarily; data reuse allowed.
            // we won't mark failure for memory reuse.
        }
    }
    report_test(pop_ok && myvector_size(&v) == 0, "Pop back: popped until empty");

    // ---------- Test 6: Clear functionality ----------
    // push some elements, call clear, check size==0 and capacity unchanged
    size_t cap_before_clear;
    myvector_push_back(&v, 10);
    myvector_push_back(&v, 20);
    myvector_push_back(&v, 30);
    cap_before_clear = myvector_capacity(&v);
    myvector_clear(&v);
    report_test(myvector_size(&v) == 0, "Clear: size == 0 after clear");
    report_test(myvector_capacity(&v) == cap_before_clear, "Clear: capacity unchanged after clear");

    // ---------- Test 7: Size and capacity invariants ----------
    // size must always be <= capacity
    bool invariant_ok = (myvector_size(&v) <= myvector_capacity(&v));
    report_test(invariant_ok, "Invariant: size <= capacity");

    // ---------- Test 8: Print function (visual) ----------
    // Refill and print some to visually inspect (test considered passed if function runs)
    for (int i = 0; i < 10; ++i) myvector_push_back(&v, i + 1000);
    std::cout << "\n-- myvector_print output (visual check) --\n";
    myvector_print(&v);
    std::cout << "-- end print --\n";
    report_test(true, "Print function: executed (visual check)");

    // ---------- Final cleanup ----------
    myvector_destroy(&v);
    report_test(v.data == nullptr, "Destroy: data nullptr after destroy");
    report_test(myvector_size(&v) == 0 && myvector_capacity(&v) == 0, "Destroy: size & capacity zero after destroy");

    // ---------- Summary ----------
    std::cout << "\nSUMMARY: Passed " << passed << " / " << total_tests << " tests.\n";
    if (passed == total_tests) {
        std::cout << "ALL TESTS PASSED ✅\n";
    } else {
        std::cout << (total_tests - passed) << " test(s) failed ❌\n";
    }

    return 0;
}
