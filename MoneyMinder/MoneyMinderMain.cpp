#define _CRT_SECURE_NO_WARNINGS

#include <sqlite3.h>
#include <wx/wx.h>
#include <spdlog/spdlog.h>
#include <cmath>
#include <matplot/matplot.h>

int main() {
    // Простая логика
    spdlog::info("MoneyMinder запущен");

    wxApp::SetInstance(new wxApp());
    wxEntryStart(0, nullptr);

    // SQLite3
    printf("%s\n", sqlite3_libversion());

    // Matplotlib++
    using namespace matplot;
    std::vector<double> x = logspace(-1, 2);
    std::vector<double> y1 = transform(x, [](auto x) { return pow(10, x); });
    std::vector<double> y2 =
        transform(x, [](auto x) { return 1 / pow(10, x); });
    loglog(x, y1, x, y2);

    show();

    wxEntryCleanup();
    return 0;
}
