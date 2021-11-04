#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <ctime>
#include <condition_variable>
std::mutex sync;

struct fullData
{
    float h;
    float v;
    float t;
    fullData() {}
    fullData(float inputH, float inputV, float inputT) : h(inputH), v(inputV), t(inputT) {}
};

void flightData(std::vector<fullData> &memory, float v0, float y0, float &h, float &v, float &t, float freqT)
{
    float g = 9.8;
    h = y0 + v0 * t - 9.8 * (t * t) / 2;
    v = v0 - g * t;
    t += freqT;
    do
    {
        fullData takt(h, v, t);

        sync.lock();
        memory.push_back(takt);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        sync.unlock();
        h = y0 + v0 * t - 9.8 * (t * t) / 2;
        v = v0 - g * t;
        t += freqT;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    } while (h >= 0);
    h = 0;
    v = 0;
    fullData takt(h, v, t);
    memory.push_back(takt);
}

void printData(std::vector<fullData> &memory)
{
    fullData back;
    do
    {

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        sync.lock();
        back = memory.back();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        sync.unlock();
        std::cout << "\nt: " << back.t << " h: " << back.h << " v: " << back.v;

    } while (back.h > 0);
}

int main(int argc, char *argv[])
{
    unsigned int start_time = clock();
    float t = 0;
    float freq = 0.1;
    float h = 0;
    float v;
    float m = 0;
    float v0 = 100;
    float y0 = 0;
    std::vector<fullData> memory;
    std::thread dataThr(flightData, std::ref(memory), v0, y0, std::ref(h), std::ref(v), std::ref(t), freq);
    std::thread printThr(printData, std::ref(memory));
    dataThr.join();
    printThr.join();
    // flightData(memory, v0, y0, h, v, t, freq);
    // printData(memory);
    unsigned int end_time = clock();
    // std::cout << "\n"
    //          << end_time - start_time;
}
