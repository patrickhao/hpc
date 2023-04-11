#include <iostream>

// 也可以放在namespace中，将std命名空间中的cout和endl引入到该命名空间
namespace myspace {
using std::cout;
using std::endl;
} // namespace myspace

namespace myspace {
// 整个空间都可以使用cout和endl了
void func() { cout << "hello" << endl; }
} // namespace myspace

int main() {
  // 因为cout和endl的名称只引入到了myspace命名空间中，该空间都可以访问cout和endl
  // 但是global namespace仍然只能通过std::指定到cout和endl
  std::cout << "hello" << std::endl;

  return 0;
}
