#pragma once

#include <vector>
#include <memory>
#include <climits>
#include <cmath>
#include <chrono>

typedef std::chrono::high_resolution_clock Time;

#define TIME_START      auto _time_start = Time::now();
#define TIME_STOP       auto _time_end   = Time::now();
#define TIME_CACL       auto _time_elapsed_seconds =  \
                            std::chrono::duration_cast<std::chrono::duration<double>>(_time_end - _time_start); \
                        auto _time_result_nanoseconds = \
                         std::chrono::duration_cast<std::chrono::nanoseconds>(_time_elapsed_seconds).count();
#define TIME_PASS               state.SetIterationTime(_time_result_nanoseconds);

#define TIME_FINISH_PASS        TIME_STOP \
                                TIME_CACL \
                                TIME_PASS

class BenchState;
class BenchTest;
std::vector<std::shared_ptr<BenchTest>> _benchTests;

class BenchTest {
public:
    BenchTest(void (*f)(BenchState&), std::string testName) {
        funct = f;
        this->testName = testName;
    }
    BenchTest* Args(int first, int second) {
        _state.push_back(std::make_shared<BenchState>(first, second));
        return this;
    }

    void FunctCall(BenchState& state) {
        funct(state);
    }

    std::vector<std::shared_ptr<BenchState> >& getStates() {
        return _state;
    }

    std::string getTestName() const {
        return testName;
    }
private:
    void (*funct)(BenchState&) = nullptr;
    std::vector<std::shared_ptr<BenchState> > _state;
    std::string testName;
};

class BenchState {
private:
    int size = 0;
    long time_result = 0;
    int val1 = 0;
    int val2 = 0;
public:
    BenchState(int val1, int val2) {
        this->val1 = val1;
        this->val2 = val2;
    }
    int range(int pos) const{
        if (pos == 0) {
            return val1;
        } else if (pos == 1) {
            return val2;
        }
        return 0;
    }
    void SetIterationTime(const long time) {
        this->time_result = time;
    }

    long GetInterTime() const {
        return this->time_result;
    }
};

BenchTest* BENCH(void (*f)(BenchState&), std::string test_name) {
    _benchTests.push_back(std::make_shared<BenchTest>(f, test_name));
    return _benchTests.back().get();
}


void BENCH_RUN() {
    printf("[BENCH]%22s/%-10s%-12s%-12s%-12s%-12s%-10sTime iterations\n",
     "TestName", "AlgInter", "Time (ms)", "Time (ns)", "Dt (ns)", "Max (ns)", "Min (ns)");
    printf("=====================================================================================================================================\n");
    char templ[] =
           "[BENCH]%22s/%-10d%-12ld%-12ld%-12ld%-12ld%-10ldTested on %d iterations\n";
    for (auto& test : _benchTests) {
        for (auto& state : test->getStates()) {
            int iterations = state->range(0);
            int algorithm_runs = state->range(1);
            long* time_result = new long[iterations];
            for (size_t i = 0; i < iterations; i++) {
                usleep(100);
                test->FunctCall(*state);
                time_result[i] = state->GetInterTime();
                // printf("%ld\n", state->GetInterTime());
            }

            long final_time = 0;
            long time_dt = 0;
            long max_time = LONG_MIN;
            long min_time = LONG_MAX;
            for (int i = 0; i < iterations; i++) {
                final_time += time_result[i];

                if (time_result[i] > max_time) {
                    max_time = time_result[i];
                } else if (time_result[i] < min_time) {
                    min_time = time_result[i];
                }
            }
            final_time = final_time / iterations;

            for (int i = 0; i < iterations; i++) {
                time_dt += std::abs(time_result[i] - final_time);
            }
            time_dt = std::sqrt(time_dt);

            long final_time_ms = (long)(final_time / 1e+6);
            printf(templ, test->getTestName().c_str(), algorithm_runs, final_time_ms, final_time, time_dt, max_time, min_time, iterations);
            delete[] time_result;
        }
    }
}
