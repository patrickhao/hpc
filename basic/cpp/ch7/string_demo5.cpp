#include <iostream>
#include <string>

int main() {
  std::string str1 {"012345"};
  std::string str2 {"insert"};

  // 插入位置在3之前
  str1.insert(3, str2);
  std::cout << str1 << std::endl;

  // the insertion of a substring of a string object into another string object
  str1 = "012345";
  // 插入str2从0位置开始的前三个字符
  str1.insert(3, str2, 1, 3);
  std::cout << str1 << std::endl;

  str1 = "012345";
  // 注意两种表示下参数含义的不同
  // 如果是null-terminated string，就前五个字符
  // 如果是string，就是从index 5开始到结束
  str1.insert(3, "abcde", 3);
  str2 = "abcde";
  str1.insert(0, str2, 3); // 可以看到与上面的取法不同了
  std::cout << str1 << std::endl;

  str1 = "012345";
  // 插入6个'*'字符
  str1.insert(3, 6, '*');
  std::cout << str1 << std::endl;

  // 替换字符串
  std::string text {"Smith, where Jones had had \"had had\", had had \"had\"."};

  // 替换text中13开始，长度为5的子串，即"Jones"
  text.replace(13, 5, "Gruntfuttock");
  std::cout << text << std::endl;

  // 其余的操作也和insert相同
  str1 = "012345";
  str1.replace(1, 1, "abcde", 1, 2);
  std::cout << str1 << std::endl;

  str1 = "012345";
  // 这里是null-terminated string，不是string，因此是取前3个字符
  str1.replace(1, 1, "abcde", 3);
  std::cout << str1 << std::endl;
  
  str1 = "012345";
  str1.replace(1, 1, 3, '*');
  std::cout << str1 << std::endl;

  // 删除子串
  std::string str3 = "012345";
  str3.erase(0, 3);
  std::cout << str3 << std::endl;

  str3 = "012345";
  // 除了前3个字符其余的全部移除
  // 注意区分，这不是移除某个位置的字符串，如果需要移除某个位置的字符串，使用erase(i, 1)
  str3.erase(3);
  std::cout << str3 << std::endl;

  str3 = "012345";
  // 清空字符串
  str3.clear();
  std::cout << str3 << std::endl;

  str3 = "012345";
  // 清空字符串，效果相当于clear()
  str3.erase();
  std::cout << str3 << std::endl;

  // c++20中的新功能，移除所有字符'0'
  // str3 = "100000001";
  // std::erase(str3, '0');
  // std::cout << str3 << std::endl;

  return 0;
}