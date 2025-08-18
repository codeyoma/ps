#include <iostream>
using namespace std;

#ifdef LOCAL
#define LOG clog
#else
struct nullstream : ostream {
  nullstream() : ostream(nullptr) {}
};
nullstream LOG;
#endif

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>

int main() {
  //   logic
}
